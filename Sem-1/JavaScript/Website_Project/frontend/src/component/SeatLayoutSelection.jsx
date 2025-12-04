import React, { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';

// NOTE: You must ensure the CSS for .custom-checkbox, .checkmark, 
// .screen_icon, etc., is imported or loaded globally for the layout and icons to display correctly.
// Example: import './SeatLayout.css'; 

// --- 1. Static Style Definitions ---
// These styles are partially extracted from your original CSS for inline use.
const seatLayoutStyles = {
	form: { textAlign: 'center', minWidth: '800px' },
	screenIcon: { width: '30%', minWidth: '300px', margin: '20px auto' },
	preInline: { display: 'inline', fontSize: '18px' },
	checkmark: { cursor: 'default' },
	checkmark1: { backgroundColor: '#F7FFE5' },
	priceLevel: { margin: '1px auto' }
};


export default function SeatLayoutSelection() {
	const navigate = useNavigate();

	// --- 2. State Hooks for Data and Selection ---
	const [movieData, setMovieData] = useState({});
	const [cinemaData, setCinemaData] = useState({});
	const [timesData, setTimesData] = useState({});

	// Dynamic Seat Data from API
	const [seatStructure, setSeatStructure] = useState([]);
	const [noSeatsArray, setNoSeatsArray] = useState([]);
	const [bookedSeatsName, setBookedSeatsName] = useState([]);
	const [selectedSeats, setSelectedSeats] = useState([]);

	// Calculated Prices and Levels
	const [seatPrices, setSeatPrices] = useState([]);
	const [priceLevelLabels, setPriceLevelLabels] = useState([]);

	// NEW: Map to link seat row letter (A, B, C) to the price tier index (0, 1, 2)
	const [rowPriceMap, setRowPriceMap] = useState({});

	// --- 3. Data Fetching and Initialization ---
	useEffect(() => {
		const storedCinemaId = sessionStorage.getItem("selectedCinemaId");
		const storedMoviePrice = parseFloat(sessionStorage.getItem("selectedMoviePrice") || 0);
		const storedPriceLevels = sessionStorage.getItem("selectedCinemaPriceLevel");

		// Load data from sessionStorage
		setMovieData({
			title: sessionStorage.getItem("selectedMovieName"),
			rating: sessionStorage.getItem("SelectedMovieRating"),
		});
		setCinemaData({
			name: sessionStorage.getItem("selectedCinemaName"),
		});
		setTimesData({
			show_time: sessionStorage.getItem("selectedTime"),
		});

		// Initialize user-selected seats (if returning from previous step)
		const initialSelected = sessionStorage.getItem("selectedSeats");
		if (initialSelected) {
			try {
				setSelectedSeats(JSON.parse(initialSelected));
			} catch (e) {
				console.error("Error parsing selectedSeats from sessionStorage:", e);
			}
		}

		// --- Price Calculation ---
		if (storedPriceLevels) {
			const levels = storedPriceLevels.split(',').map(p => parseInt(p.trim()));
			const labels = ['Silver :', 'Gold :', 'Platinum :'].slice(0, levels.length);

			const calculatedPrices = levels.map(p => storedMoviePrice + p);
			setSeatPrices(calculatedPrices);
			setPriceLevelLabels(labels);
		}

		// --- API Data Fetching (Corrected Parsing Logic) ---
		const fetchSeatData = async () => {
			if (!storedCinemaId) return;

			try {
				const res = await fetch(`http://localhost:5000/api/movie/seat/${storedCinemaId}`, { method: "POST" });
				const data = await res.json();

				if (data.status && data.rows && data.rows.length > 0) {
					const rowData = data.rows[0];
					let parsedSeatStructure = [];

					// 1. Seat Structure Parsing
					if (rowData.seat_structure && typeof rowData.seat_structure === 'string') {
						const jsonString = rowData.seat_structure.replace(/'/g, '"');
						try {
							parsedSeatStructure = JSON.parse(jsonString);
						} catch (e) {
							console.error("Error parsing seat structure JSON:", e);
						}
					} else if (Array.isArray(rowData.seat_structure)) {
						parsedSeatStructure = rowData.seat_structure;
					}
					setSeatStructure(parsedSeatStructure);

					// 2. Build the Row-to-Price-Tier Map (NEW LOGIC)
					let currentTierIndex = -1;
					const newRowPriceMap = {};
					parsedSeatStructure.forEach(row => {
						if (row.length === 1 && typeof row[0] === 'number') {
							currentTierIndex = row[0]; // Tier marker found: [0], [1], etc.
						} else if (Array.isArray(row) && row.length > 0) {
							const rowLetter = row[0].substring(0, 1);
							if (rowLetter && currentTierIndex !== -1) {
								newRowPriceMap[rowLetter] = currentTierIndex;
							}
						}
					});
					setRowPriceMap(newRowPriceMap);


					// 3. No Seats Parsing
					let noSeats = rowData.no_seat;
					if (typeof noSeats === 'string') {
						noSeats = noSeats
							.replace(/[\[\]']/g, '')
							.split(',')
							.map(name => name.trim())
							.filter(name => name.length > 0);
					}
					setNoSeatsArray(noSeats || []);

					// 4. Booked Seats Parsing
					let bookedNames = rowData.booked_seats_name;
					if (typeof bookedNames === 'string') {
						bookedNames = bookedNames.split(',').map(name => name.trim()).filter(name => name.length > 0);
					}
					setBookedSeatsName(bookedNames || []);
				}
			} catch (error) {
				console.error("Error during initial data fetch:", error);
			}
		};

		fetchSeatData();
	}, []);

	// --- 4. Total Price Calculation Function (NEW) ---
	const calculateTotalPrice = () => {
		if (selectedSeats.length === 0 || seatPrices.length === 0) {
			return 0;
		}

		const total = selectedSeats.reduce((sum, seatName) => {
			// Extract the row letter (e.g., 'D11' -> 'D')
			const rowLetter = seatName.substring(0, 1);

			// Find the price tier index (e.g., 'D' -> 1)
			const priceTierIndex = rowPriceMap[rowLetter];

			// Find the corresponding price (e.g., seatPrices[1] -> 260)
			// Use 0 if the map or price is missing (shouldn't happen with correct data)
			const price = seatPrices[priceTierIndex] || 0;

			return sum + price;
		}, 0);

		return total;
	};

	// --- 5. Component Functions (Seat Select/Submit) ---
	const handleSeatSelect = (seatName) => {
		if (bookedSeatsName.includes(seatName) || noSeatsArray.includes(seatName)) {
			return;
		}

		setSelectedSeats(prevSeats => {
			if (prevSeats.includes(seatName)) {
				return prevSeats.filter(name => name !== seatName);
			} else {
				return [...prevSeats, seatName];
			}
		});
	};

	const handleSubmit = (e) => {
		e.preventDefault();

		if (selectedSeats.length === 0) {
			alert("Please select at least one seat.");
			return;
		}

		const finalPrice = calculateTotalPrice();

		// Store final data before navigation
		sessionStorage.setItem('selectedSeats', JSON.stringify(selectedSeats));
		sessionStorage.setItem('finalTotalPrice', finalPrice.toString());

		navigate('/Payment', {
			state: {
				selectedSeats: selectedSeats,
				totalPrice: finalPrice, // Pass the calculated total price
				movie_id: sessionStorage.getItem("selectedMovieID"),
				cinema_id: sessionStorage.getItem("selectedCinemaId")
			}
		});
	};

	// --- 6. Conditional Rendering Logic (Seat Rows) ---
	const seatRows = [];

	seatStructure.forEach((row, rowIndex) => {

		// CHECK 1: Price Level Header Logic (Handles [0], [1], [2] markers)
		if (row.length === 1 && typeof row[0] === 'number') {
			const levelMarker = row[0];

			if (levelMarker < priceLevelLabels.length) {
				seatRows.push(
					// Render the price level name and the calculated price
					<p key={`price-${rowIndex}`} style={seatLayoutStyles.priceLevel}>
						{priceLevelLabels[levelMarker]} &nbsp;₹{seatPrices[levelMarker] || '---'}
					</p>
				);
			}
			return;
		}

		// CHECK 2: Seat Row Rendering Logic
		const rowSeats = [];
		const firstSeatName = row[0];
		const rowAlphabet = firstSeatName ? firstSeatName.substring(0, 1) : '';

		if (row.length > 0) {
			rowSeats.push(
				<span key={`row-label-${rowIndex}`}>
					<pre className="space" >{rowAlphabet}</pre>
				</span>
			);
		}

		// Iterate through seats in the row
		row.forEach((seatName) => {
			const isNoSeat = noSeatsArray.includes(seatName);
			const isBooked = bookedSeatsName.includes(seatName);
			const isSelected = selectedSeats.includes(seatName);

			if (isNoSeat) {
				rowSeats.push(
					<span key={seatName} className="custom-checkbox" style={{ opacity: 0 }}></span>
				);
			} else if (isBooked) {
				rowSeats.push(
					<label key={seatName} className="custom-checkbox" >
						<input type="checkbox" checked={true} disabled={true} />
						<span className="checkmark" style={{ backgroundColor: '#f1c40f', cursor: 'default' }}></span>
					</label>
				);
			} else {
				rowSeats.push(
					<label key={seatName} className="custom-checkbox" >
						<input
							type="checkbox"
							name="select_seats[]"
							value={seatName}
							checked={isSelected}
							onChange={() => handleSeatSelect(seatName)}
						/>
						<span className="checkmark"></span>
					</label>
				);
			}
		});

		// Push the entire row with a line break
		seatRows.push(
			<div key={`row-wrap-${rowIndex}`} style={{ whiteSpace: 'nowrap' }}>
				{rowSeats}
				<br />
			</div>
		);
	});

	// Render the column numbers below the seats
	const firstSeatRow = seatStructure.find(row => Array.isArray(row) && row.length > 1);
	const totalColumns = firstSeatRow ? firstSeatRow.length : 0;

	const seatCountNumbers = [];
	for (let i = 1; i <= totalColumns; i++) {
		seatCountNumbers.push(
			<span key={`col-num-${i}`} className="custom-checkbox1">
				<span className="checkmark1">
					<pre className="number">{i}</pre>
				</span>
			</span>
		);
	}


	// --- 7. JSX Component Return ---
	return (
		<div className="container p-0 mt-2" id="show_movies">

			{/* Movie Info Header */}
			<div className="border border-2 border-info rounded ps-3 pt-2">
				<h5 style={{ display: 'inline-block' }}>{movieData.title}</h5>
				<span className="ms-2 ps-1 pe-1 pt-0 text-muted border border-1 border-secondary rounded-circle">{movieData.rating}</span>
				<p className="m-0 pb-1">{cinemaData.name} &nbsp;|&nbsp; {sessionStorage.getItem("selectedDate")} &nbsp;|&nbsp; {timesData.show_time}</p>
			</div>

			{/* Seat Selection Area */}
			<div className="border border-2 border-info rounded mt-2 pt-2 pb-2">
				<h4 className="ps-3" style={{ display: 'inline-block' }}>Select Your Seats:-</h4>

				{/* Seat Legend */}
				<div className="pe-3" style={{ float: 'right' }}>
					<div style={{ display: 'inline-block' }}>
						{/* Available Seats */}
						<div className="custom-checkbox" style={{ marginRight: '0.3rem', display: 'inline-block', verticalAlign: 'middle' }}>
							<span className="checkmark" style={{ top: '-10px' }}></span>
						</div>
						<span style={{ verticalAlign: 'middle', marginRight: '1rem' }}>Available Seats</span>
					</div>
					<div style={{ display: 'inline-block' }}>
						{/* Booked Seats */}
						<div className="custom-checkbox mr-2" style={{ marginLeft: '1.1rem', marginRight: '0.3rem', display: 'inline-block', verticalAlign: 'middle' }}>
							<span className="checkmark" style={{ backgroundColor: '#f1c40f', top: '-10px' }}></span>
						</div>
						<span style={{ verticalAlign: 'middle' }}>Booked Seats</span>
					</div>
				</div>

				{/* Seat Layout and Screen */}
				<div className="col-12 overflow-auto p-0">
					<form id="existingForm" onSubmit={handleSubmit} style={seatLayoutStyles.form}>

						{/* Screen Icon (Using embedded SVG for better control/display) */}
						<div className="screen_icon" style={seatLayoutStyles.screenIcon}>
							<svg viewBox="0 0 376 44" fill="none" xmlns="http://www.w3.org/2000/svg" version="1.1">
								<g transform="rotate(180, 188, 22)">
									<path d="M334.718 2.00062C228 10.0004 148 10.0004 39.6559 2.00062L16 30.9996C148 38.9999 228 38.9999 360 30.9996L334.718 2.00062Z" fill="#ff1b5e20"></path>
									<path d="M16 30.9996L39.6559 2.00062C148 10.0004 228 10.0004 334.718 2.00062L360 30.9996M16 30.9996L19.0003 35.9999C148 44 228 44 357 35.9999L360 30.9996M16 30.9996C148 38.9999 228 38.9999 360 30.9996" stroke="#101010" strokeOpacity="0.22"></path>
									<path d="M332 5.49907C229 13.0005 145.5 13.0005 42.5 5.5009L23 28.5009C143 36.5005 232 36.501 351.923 28.4991L332 5.49907Z" fill="#b9e5f8ff"></path>
								</g>
								<text x="50%" y="60%" textAnchor="middle" dominantBaseline="middle" style={{ fill: "rgb(51, 51, 51)", fontFamily: "Arial, sans-serif", fontSize: "12px", fontWeight: 700, letterSpacing: "0.5px" }}>
									SCREEN THIS WAY
								</text>
							</svg>
						</div>

						{/* Seat Map (Generated dynamically) */}
						<div className="seat-map">
							{seatRows}
						</div>

						{/* Column Count Numbers */}
						<div className="count">
							{seatCountNumbers}
						</div>

						{/* Submit Button (Uses Dynamic Total Price) */}
						<input
							className="btn btn-primary mt-2"
							type="submit"
							style={{ width: '50%' }}
							value={`Booking (${selectedSeats.length} Seats Selected, Total Price ₹${calculateTotalPrice()})`}
						/>
					</form>
				</div>
			</div>
		</div>
	);
}


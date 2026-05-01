import React, { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';

export default function SeatLayoutSelection() {

	const navigate = useNavigate();

	const [movieData, setMovieData] = useState({});
	const [cinemaData, setCinemaData] = useState({});
	const [timesData, setTimesData] = useState({});

	const [seatStructure, setSeatStructure] = useState([]);
	const [noSeatsArray, setNoSeatsArray] = useState([]);
	const [bookedSeatsName, setBookedSeatsName] = useState([]);
	const [selectedSeats, setSelectedSeats] = useState([]);

	const [seatPrices, setSeatPrices] = useState([]);
	const [priceLevelLabels, setPriceLevelLabels] = useState([]);

	const [rowPriceMap, setRowPriceMap] = useState({});

	useEffect(() => {
		const storedCinemaId = sessionStorage.getItem("selectedCinemaId");
		const storedMoviePrice = parseFloat(sessionStorage.getItem("selectedMoviePrice") || 0);
		const storedPriceLevels = sessionStorage.getItem("selectedCinemaPriceLevel");

		setMovieData({
			title: sessionStorage.getItem("selectedMovieName"),
			rating: sessionStorage.getItem("selectedMovieRating"),
		});
		setCinemaData({
			name: sessionStorage.getItem("selectedCinemaName"),
		});
		setTimesData({
			show_time: sessionStorage.getItem("selectedTime"),
		});

		if (storedPriceLevels) {
			const levels = storedPriceLevels.split(',').map(p => parseInt(p.trim()));
			const labels = ['Silver :', 'Gold :', 'Platinum :'].slice(0, levels.length);

			const calculatedPrices = levels.map(p => storedMoviePrice + p);
			setSeatPrices(calculatedPrices);
			setPriceLevelLabels(labels);
		}

		const fetchSeatData = async () => {
			if (!storedCinemaId) return;

			try {
				const res = await fetch(`http://localhost:5000/api/movie/seat/${storedCinemaId}`, { method: "POST" });
				const data = await res.json();

				if (data.status && data.rows && data.rows.length > 0) {
					const rowData = data.rows[0];

					sessionStorage.setItem("selectedSeatID", rowData.id);
					let parsedSeatStructure = [];

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

					let currentTierIndex = -1;
					const newRowPriceMap = {};
					parsedSeatStructure.forEach(row => {
						if (row.length === 1 && typeof row[0] === 'number') {
							currentTierIndex = row[0];
						} else if (Array.isArray(row) && row.length > 0) {
							const rowLetter = row[0].substring(0, 1);
							if (rowLetter && currentTierIndex !== -1) {
								newRowPriceMap[rowLetter] = currentTierIndex;
							}
						}
					});
					setRowPriceMap(newRowPriceMap);

					let noSeats = rowData.no_seat;
					if (typeof noSeats === 'string') {
						noSeats = noSeats
							.replace(/[\[\]']/g, '')
							.split(',')
							.map(name => name.trim())
							.filter(name => name.length > 0);
					}
					setNoSeatsArray(noSeats || []);

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

	const calculateTotalPrice = () => {
		if (selectedSeats.length === 0 || seatPrices.length === 0) {
			return 0;
		}

		const total = selectedSeats.reduce((sum, seatName) => {
			const rowLetter = seatName.substring(0, 1);
			const priceTierIndex = rowPriceMap[rowLetter];
			const price = seatPrices[priceTierIndex] || 0;

			return sum + price;
		}, 0);

		return total;
	};

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

		sessionStorage.setItem('selectedSeats', JSON.stringify(selectedSeats));
		sessionStorage.setItem('finalTotalPrice', finalPrice.toString());

		navigate("/Payment"); // go to Payment page

	};

	const seatRows = [];

	seatStructure.forEach((row, rowIndex) => {

		if (row.length === 1 && typeof row[0] === 'number') {
			const levelMarker = row[0];

			if (levelMarker < priceLevelLabels.length) {
				seatRows.push(
					<p key={`price-${rowIndex}`} style={{ margin: '0px auto' }}>
						{priceLevelLabels[levelMarker]} &nbsp;₹{seatPrices[levelMarker] || '---'}
					</p>
				);
			}
			return;
		}

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


	return (
		<div className="container p-0 mt-2" id="show_movies">

			<div className="border border-2 border-info rounded ps-3 pt-2">
				<h5 style={{ display: 'inline-block' }}>{movieData.title}</h5>
				<span className="ms-2 ps-1 pe-1 pt-0 text-muted border border-1 border-secondary rounded-circle">{movieData.rating}</span>
				<p className="m-0 pb-1">{cinemaData.name} &nbsp;|&nbsp; {sessionStorage.getItem("selectedDate")} &nbsp;|&nbsp; {timesData.show_time}</p>
			</div>

			<div className="border border-2 border-info rounded mt-2 pt-2 pb-2">
				<h4 className="ps-3" style={{ display: 'inline-block' }}>Select Your Seats:-</h4>

				<div className="pe-3" style={{ float: 'right' }}>
					<div style={{ display: 'inline-block' }}>
						<div className="custom-checkbox" style={{ marginRight: '0.3rem', display: 'inline-block', verticalAlign: 'middle' }}>
							<span className="checkmark" style={{ top: '-10px' }}></span>
						</div>
						<span style={{ verticalAlign: 'middle', marginRight: '1rem' }}>Available Seats</span>
					</div>
					<div style={{ display: 'inline-block' }}>
						<div className="custom-checkbox mr-2" style={{ marginLeft: '1.1rem', marginRight: '0.3rem', display: 'inline-block', verticalAlign: 'middle' }}>
							<span className="checkmark" style={{ backgroundColor: '#f1c40f', top: '-10px' }}></span>
						</div>
						<span style={{ verticalAlign: 'middle' }}>Booked Seats</span>
					</div>
				</div>

				{/* Seat Layout and Screen */}
				<div className="col-12 overflow-auto p-0">
					<form>
						<div className="screen_icon">
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

						<div className="count">
							{seatCountNumbers}
						</div>

						<button className="btn btn-primary mt-2" onClick={handleSubmit} style={{ width: '50%' }}>
							{`Booking (${selectedSeats.length} Seats Selected, Total Price ₹${calculateTotalPrice()})`}
						</button>

					</form>
				</div>
			</div>
		</div>
	);
}


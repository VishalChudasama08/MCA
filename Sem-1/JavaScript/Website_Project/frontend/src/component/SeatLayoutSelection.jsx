import React, { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';

export default function SeatLayoutSelection() {
	const navigate = useNavigate();

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
	const [priceLevelLabels, setPriceLevelLabels] = useState([]); // ['Silver :', 'Gold :', 'Platinum :']

	useEffect(() => {
		const fetchSeatData = async () => {
			setMovieData({
				title: localStorage.getItem("SelectedMovieName"),
				rating: localStorage.getItem("SelectedMovieRating"),
			});

			setCinemaData({
				name: localStorage.getItem("selectedCinemaName"),
			});
			setTimesData({
				show_time: localStorage.getItem("selectedTime"),
			});
			const storedCinemaId = localStorage.getItem("selectedCinemaId");
			const storedMoviePrice = parseFloat(localStorage.getItem("SelectedMoviePrice") || 0);
			const storedPriceLevels = localStorage.getItem("selectedCinemaPriceLevel");

			if (storedPriceLevels) {
				// Price levels from LocalStorage: "40,80,130"
				const levels = storedPriceLevels.split(',').map(p => parseInt(p.trim()));
				const labels = ['Silver :', 'Gold :', 'Platinum :'].slice(0, levels.length);

				const calculatedPrices = levels.map(p => storedMoviePrice + p);
				setSeatPrices(calculatedPrices);
				setPriceLevelLabels(labels);
			}

			if (!storedCinemaId) {
				console.error("Cinema ID not found in localStorage.");
				return;
			}

			try {
				const res = await fetch(`http://localhost:5000/api/movie/seat/${storedCinemaId}`, { method: "POST" });
				const data = await res.json();

				if (data.status && data.rows && data.rows.length > 0) {
					const rowData = data.rows[0];

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

					let noSeats = rowData.no_seat;
					if (typeof noSeats === 'string') {
						noSeats = noSeats
							.replace(/[\[\]']/g, '') // Remove brackets and single quotes
							.split(',')
							.map(name => name.trim())
							.filter(name => name.length > 0);
					}
					setNoSeatsArray(noSeats || []);


					// 3. Booked Seats Name (Reserved seats)
					let bookedNames = rowData.booked_seats_name;
					if (typeof bookedNames === 'string') {
						bookedNames = bookedNames.split(',').map(name => name.trim()).filter(name => name.length > 0);
					}
					setBookedSeatsName(bookedNames || []);

				} else {
					console.error("API returned no data or status is false.");
				}
			} catch (error) {
				console.error("Error during initial data fetch:", error);
			}
		};

		fetchSeatData();
	}, []); // Run once on component mount


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

		localStorage.setItem('selectedSeats', JSON.stringify(selectedSeats));
		localStorage.setItem('seatPrices', JSON.stringify(seatPrices));

		navigate('/Payment', {
			state: {
				selectedSeats: selectedSeats,
				movie_id: localStorage.getItem("SelectedMovieID"),
				cinema_id: localStorage.getItem("selectedCinemaId")
			}
		});
	};

	const seatRows = [];
	let priceLevelIndex = 0;

	seatStructure.forEach((row, rowIndex) => {
		if (row.length === 1 && typeof row[0] === 'number') {
			const levelMarker = row[0];
			// Display the price level information
			if (levelMarker < priceLevelLabels.length) {
				seatRows.push(
					<p key={`price-${rowIndex}`} style={{ margin: '1px auto' }}>
						{priceLevelLabels[levelMarker]} {seatPrices[levelMarker] || '---'}
					</p>
				);
				priceLevelIndex++;
			}
			return;
		}

		const rowSeats = [];

		// Add the row alphabet label (e.g., 'A', 'B') - use the first character of the first seat name
		const firstSeatName = row[0];
		const rowAlphabet = firstSeatName ? firstSeatName.substring(0, 1) : '';

		if (row.length > 0) {
			rowSeats.push(
				<span key={`row-label-${rowIndex}`}>
					<pre className="space" >{rowAlphabet}</pre>
					{/* style={seatLayoutStyles.preInline} */}
				</span>
			);
		}

		row.forEach((seatName, seatIndex) => {
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
						{/* style={{ ...seatLayoutStyles.customCheckbox, cursor: 'default' }} */}
						<input type="checkbox" checked={true} disabled={true} id={`seat-${seatName}`} />
						<span className="checkmark" style={{ backgroundColor: '#f1c40f', cursor: 'default' }}></span>
					</label>
				);
			} else {
				rowSeats.push(
					<label key={seatName} className="custom-checkbox" >
						{/* style={seatLayoutStyles.customCheckbox} */}
						<input
							type="checkbox"
							id={`seat-${seatName}`}
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

	const firstSeatRow = seatStructure.find(row => row.length > 1 && !isNaN(row[0]) === false);
	const totalColumns = firstSeatRow ? firstSeatRow.length : 0;

	const seatCountNumbers = [];
	for (let i = 1; i <= totalColumns; i++) {
		seatCountNumbers.push(
			<span key={`col-num-${i}`} className="custom-checkbox1">
				<span className="checkmark1" >
					<pre className="number" >{i}</pre>
				</span>
			</span>
		);
	}

	return (
		<div className="container p-0 mt-2" id="show_movies">

			{/* Movie Info Header */}
			<div className="border border-2 border-info rounded ps-3 pt-2">
				<h5 style={{ display: 'inline-block' }}>{movieData.title}</h5>
				<span className="ms-2 ps-1 pe-1 pt-0 text-muted border border-1 border-secondary rounded-circle">{movieData.rating}</span>
				<p className="m-0 pb-1">{cinemaData.name} &nbsp;|&nbsp; {localStorage.getItem("selectedDate")} &nbsp;|&nbsp; {timesData.show_time}</p>
			</div>

			{/* Seat Selection Area */}
			<div className="border border-2 border-info rounded mt-2 pt-2 pb-2">
				<h4 className="ps-3" style={{ display: 'inline-block' }}>Select Your Seats:-</h4>

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
					<form id="existingForm" onSubmit={handleSubmit}>

						{/* Screen Icon */}
						<div className="screen_icon">
							<img src="images/screen-icon-180.svg" className="img-fluid" style={{ transform: 'rotate(180deg)', width: '100%' }} alt="screen-icon" />
						</div>

						{/* Seat Map (Generated dynamically) */}
						<div className="seat-map">
							{seatRows}
						</div>

						{/* Column Count Numbers */}
						<div className="count">
							{seatCountNumbers}
						</div>

						{/* Submit Button */}
						<input className="btn btn-primary mt-2" type="submit" style={{ width: '50%' }} value={`Booking (${selectedSeats.length} Seats Selected)`} />
					</form>
				</div>
			</div>
		</div>
	);
}


// import { useState, useEffect } from "react";
// import Showtime from "./Showtime";

// export default function DateAndCinema() {
// 	const today = new Date().toLocaleDateString("en-GB", { day: "numeric", month: "short" });
// 	const tomorrow = new Date(Date.now() + 86400000).toLocaleDateString("en-GB", { day: "numeric", month: "short" });
// 	const dayAfter = new Date(Date.now() + 2 * 86400000).toLocaleDateString("en-GB", { day: "numeric", month: "short" });

// 	const [selectedCinema, setSelectedCinema] = useState(null);
// 	function openCinemaModal(cinema) {
// 		setSelectedCinema(cinema);

// 		// Bootstrap modal open
// 		const modal = new window.bootstrap.Modal(document.getElementById("cinemaModal"));
// 		modal.show();
// 	}

// 	const [allCinema, setAllCinema] = useState([]);
// 	const [allTimes, setAllTimes] = useState([]);
// 	const [groupedTimes, setGroupedTimes] = useState({});
// 	const [loading, setLoading] = useState(true);

// 	async function showCinema(selectDate) {
// 		console.log(selectDate);
// 		const res = await fetch("http://localhost:5000/api/movie/allCinema/", { method: "POST" });
// 		const data = await res.json();
// 		if (!data.status) {
// 			alert(data.message);
// 		}
// 		setAllCinema(data.rows);
// 		// console.log(typeof allCinema, allCinema, typeof allCinema[0], allCinema[0], allCinema[0].name)
// 		if (data.rows.length > 0) {
// 			const timeData = await fetch("http://localhost:5000/api/movie/dateWiseCinema", { method: "POST" });
// 			const times = await timeData.json();
// 			setAllTimes(times.rows)
// 			console.log(allTimes);


// 			for (const key in allTimes) {
// 				console.log(allTimes[key]);

// 			}

// 		}
// 	}

// 	useEffect(() => {
// 		showCinema('2025-12-01');
// 		// eslint-disable-next-line react-hooks/exhaustive-deps
// 	}, []);

// 	function getRandomLanguage(str) {
// 		if (!str) return ""; // prevent crashing
// 		// Split by comma → trim spaces → remove empty values
// 		const parts = str.split(",").map(s => s.trim()).filter(Boolean);
// 		// Pick random index
// 		const randomIndex = Math.floor(Math.random() * parts.length);

// 		return parts[randomIndex];
// 	}



// 	return (
// 		<div className="my-1" id="show_Cinema_Date">
// 			<div className="border border-2 border-info rounded p-1" style={{ display: 'flex', flexFlow: 'row' }}>
// 				<h4 className="mt-2 ms-3">Select Date : </h4>
// 				<button id="autoclick" onClick={() => { showCinema('2025-12-01') }} type="button" className="btn btn-outline-info m-2 buttons">{today}</button>
// 				<button id="autoclick" onClick={() => { showCinema('2025-12-02') }} type="button" className="btn btn-outline-info m-2 buttons">{tomorrow}</button>
// 				<button id="autoclick" onClick={() => { showCinema('2025-12-03') }} type="button" className="btn btn-outline-info m-2 buttons">{dayAfter}</button>
// 			</div>

// 			<div className="border border-2 border-info rounded mt-2 pt-1 pb-1">
// 				<table className="table m-0">
// 					<tbody>
// 						<tr>
// 							<th>Cinema Name</th>
// 							<th>Language</th>
// 							<th>Show Times</th>
// 							<th>Info</th>
// 						</tr>
// 						{allCinema?.map((cinema) => (
// 							<tr key={cinema.id}>
// 								<td>{cinema.name}</td>
// 								<td>{getRandomLanguage(localStorage.getItem("MovieLanguage"))}</td>
// 								<td>
// 									{/* need grouped time is showing here */}
// 								</td>
// 								<td>
// 									<img src="images/circle-info-solid.svg" alt="information logo" style={{ opacity: 0.6, width: 25, cursor: "pointer" }} onClick={() => openCinemaModal(cinema)} />
// 								</td>
// 							</tr>
// 						))}
// 					</tbody>
// 				</table>
// 			</div>

// {/* Bootstrap Modal */}
// <div className="modal fade" id="cinemaModal" tabIndex="-1" aria-hidden="true">
// 	<div className="modal-dialog">
// 		<div className="modal-content">
// 			<div className="modal-header">
// 				<h5 className="modal-title">Cinema Info</h5>
// 				<button type="button" className="btn-close" data-bs-dismiss="modal"></button>
// 			</div>

// 			<div className="modal-body">
// 				<p><strong>Name:</strong> {selectedCinema?.name}</p><hr style={{ opacity: 0.2 }} />
// 				<p><strong>Facilities:</strong> {selectedCinema?.facilities}</p><hr style={{ opacity: 0.2 }} />
// 				<p><strong>Location:</strong> {selectedCinema?.location}</p>
// 			</div>
// 		</div>
// 	</div>
// </div>


// 			<Showtime />
// 		</div>
// 	)
// }


// const groupTimesByCinema = (timesArray, requiredDate) => {
// 	const groupedData = {};

// 	timesArray.forEach(time => {
// 		// 1. Filter: Only include records matching the required date
// 		if (time.show_date === requiredDate) {
// 			const cinemaId = time.cinema_id;

// 			// 2. Group: Initialize the array for the cinema_id if it doesn't exist
// 			if (!groupedData[cinemaId]) {
// 				groupedData[cinemaId] = [];
// 			}

// 			// 3. Collect the show_time data for that cinema
// 			groupedData[cinemaId].push(time.show_time);
// 		}
// 	});

// 	return groupedData;
// };

















import React, { useState, useEffect } from "react";
import { Link } from "react-router-dom";
// Removed import Showtime from "./Showtime" as its logic is now merged here.

// --- Utility function to group and filter the data ---
// This function takes the raw array and groups show_times by cinema_id
const groupTimesByCinema = (timesArray, requiredDate) => {
	const groupedData = {};

	timesArray.forEach(time => {
		// 1. Filter: Only include records matching the required date
		if (time.show_date === requiredDate) {
			// Ensure cinemaId is a string to match object keys
			const cinemaId = String(time.cinema_id);

			// 2. Group: Initialize the array for the cinema_id if it doesn't exist
			if (!groupedData[cinemaId]) {
				groupedData[cinemaId] = [];
			}

			// 3. Collect the show_time data for that cinema
			groupedData[cinemaId].push(time.show_time);
		}
	});

	return groupedData;
};

export default function DateAndCinema() {
	const today = new Date(Date.now() + 86400000).toLocaleDateString("en-GB", { day: "numeric", month: "short" });
	const tomorrow = new Date(Date.now() + 2 * 86400000).toLocaleDateString("en-GB", { day: "numeric", month: "short" });
	const dayAfter = new Date(Date.now() + 3 * 86400000).toLocaleDateString("en-GB", { day: "numeric", month: "short" });

	const todayFormatted = new Date(Date.now() + 86400000).toLocaleDateString('en-GB', { day: '2-digit', month: '2-digit', year: 'numeric' });
	const tomorrowFormatted = new Date(Date.now() + 2 * 86400000).toLocaleDateString('en-GB', { day: '2-digit', month: '2-digit', year: 'numeric' });
	const dayAfterFormatted = new Date(Date.now() + 3 * 86400000).toLocaleDateString('en-GB', { day: '2-digit', month: '2-digit', year: 'numeric' });

	const [rawDate, setRawDate] = useState('2025-12-01');
	const [selectedDate, setSelectedDate] = useState(todayFormatted);
	console.log(today, tomorrow, dayAfter, rawDate, selectedDate);

	const [allCinema, setAllCinema] = useState([]);
	const [allTimes, setAllTimes] = useState([]);
	const [groupedTimes, setGroupedTimes] = useState({});
	const [loading, setLoading] = useState(true);

	const [selectedCinema, setSelectedCinema] = useState(null);
	function openCinemaModal(cinema) {
		setSelectedCinema(cinema);
		const modal = new window.bootstrap.Modal(document.getElementById("cinemaModal"));
		modal.show();
	}

	// Function to fetch all cinemas and ALL showtime data (runs once)
	const fetchAllData = async (initialDate) => {
		try {
			const res = await fetch("http://localhost:5000/api/movie/allCinema/", { method: "POST" });
			const data = await res.json();
			if (data.status) {
				setAllCinema(data.rows);
			} else {
				console.error("Error fetching cinema data:", data.message);
			}

			const timeData = await fetch("http://localhost:5000/api/movie/dateWiseCinema", { method: "POST" });
			const times = await timeData.json();
			if (times.rows) {
				setAllTimes(times.rows);
			}

			setRawDate(initialDate);

		} catch (error) {
			console.error("Error during initial data fetch:", error);
		} finally {
			setLoading(false);
		}
	};

	// Fetch Raw Data (Runs only once on component mount)
	useEffect(() => {
		fetchAllData('2025-12-01');
	}, []);

	useEffect(() => {
		if (allTimes.length > 0 && rawDate) {
			const processedData = groupTimesByCinema(allTimes, rawDate);
			setGroupedTimes(processedData);
		} else if (allTimes.length === 0 && !loading) {
			setGroupedTimes({});
		}
	}, [allTimes, rawDate, loading]);

	function getRandomLanguage(str) {
		if (!str) return "";
		const parts = str.split(",").map(s => s.trim()).filter(Boolean);
		const randomIndex = Math.floor(Math.random() * parts.length);

		return parts[randomIndex];
	}

	function selectedData(selectedTime, selectedCinemaId, selectedCinemaName) {
		localStorage.setItem("selectedTime", selectedTime);
		localStorage.setItem("selectedDate", selectedDate);
		localStorage.setItem("selectedCinemaId", selectedCinemaId);
		localStorage.setItem("selectedCinemaName", selectedCinemaName);
		localStorage.setItem("selectedCinemaPriceLevel", allCinema[selectedCinemaId - 1].price_level);
	}

	if (loading) {
		return <div className="p-4 text-center text-lg font-semibold text-blue-600">Loading cinema and showtime data...</div>;
	}

	return (
		<div className="my-1 font-inter">
			<div className="border border-2 border-info rounded p-1">
				<h4 className="font-semibold d-inline mt-1 mx-3">Select Date:</h4>
				{/* {Object.entries(apiDates).map(([label, date]) => (
					<button key={date} onClick={() => handleDateSelect(date)} className={`btn px-3 m-2 ${rawDate === date ? 'btn-info' : 'btn-outline-secondary'} `}>
						<strong>{label}</strong>
					</button>
				))} */}
				<button id="autoclick" onClick={() => { setRawDate('2025-12-01'); setSelectedDate(todayFormatted) }} type="button" className={`btn ${rawDate === '2025-12-01' ? 'btn-info' : 'btn-outline-secondary'} m-2 buttons`}>{today}</button>
				<button id="autoclick" onClick={() => { setRawDate('2025-12-02'); setSelectedDate(tomorrowFormatted) }} type="button" className={`btn ${rawDate === '2025-12-02' ? 'btn-info' : 'btn-outline-secondary'} m-2 buttons`}>{tomorrow}</button>
				<button id="autoclick" onClick={() => { setRawDate('2025-12-03'); setSelectedDate(dayAfterFormatted) }} type="button" className={`btn ${rawDate === '2025-12-03' ? 'btn-info' : 'btn-outline-secondary'} m-2 buttons`}>{dayAfter}</button>
			</div>

			<div className="border border-2 border-info rounded mt-2 pt-1 pb-1">
				<table className="table m-0">
					<thead>
						<tr>
							<th>Cinema Name</th>
							<th>Language</th>
							<th>Show Times</th>
							<th>Info</th>
						</tr>
					</thead>
					<tbody>
						{allCinema?.map((cinema) => {
							const cinemaIdStr = String(cinema.id);
							const timesForCinema = groupedTimes[cinemaIdStr] || [];

							return (
								<tr key={cinema.id} >
									<td>{cinema.name}</td>
									<td>{getRandomLanguage(localStorage.getItem("MovieLanguage"))}</td>

									<td>
										{timesForCinema.length > 0 ? (
											timesForCinema.map((time, index) => (
												<Link to="/SeatLayoutAndSelection" key={index} className="btn btn-outline-warning mx-1 btn-sm" onClick={() => selectedData(time, cinema.id, cinema.name)}>{time}</Link>
											))
										) : (
											<span className="text-red-500 text-xs font-medium">No shows found</span>
										)}
									</td>

									{/* info button */}
									<td>
										<svg onClick={() => openCinemaModal(cinema)} style={{ opacity: 0.6, width: 25, cursor: "pointer" }} fill="currentColor" viewBox="0 0 20 20" xmlns="http://www.w3.org/2000/svg">
											<path fillRule="evenodd" d="M18 10a8 8 0 11-16 0 8 8 0 0116 0zm-7-4a1 1 0 11-2 0 1 1 0 012 0zM9 9a1 1 0 000 2v3a1 1 0 001 1h1a1 1 0 100-2v-3a1 1 0 00-1-1H9z" clipRule="evenodd"></path>
										</svg>
									</td>
								</tr>
							);
						})}
					</tbody>
				</table>
			</div>

			{/* Bootstrap Modal */}
			<div className="modal fade" id="cinemaModal" tabIndex="-1" aria-hidden="true">
				<div className="modal-dialog">
					<div className="modal-content">
						<div className="modal-header">
							<h5 className="modal-title">Cinema Info</h5>
							<button type="button" className="btn-close" data-bs-dismiss="modal"></button>
						</div>

						<div className="modal-body">
							<p><strong>Name:</strong> {selectedCinema?.name}</p><hr style={{ opacity: 0.2 }} />
							<p><strong>Facilities:</strong> {selectedCinema?.facilities || "Not specified"} </p><hr style={{ opacity: 0.2 }} />
							<p><strong>Location:</strong> {selectedCinema?.location || "Not specified"} </p>
						</div>
					</div>
				</div>
			</div>

		</div>
	)
}
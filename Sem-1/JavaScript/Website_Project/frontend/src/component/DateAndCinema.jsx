import React, { useState, useEffect } from "react";
import { Link } from "react-router-dom";
const groupTimesByCinema = (timesArray, requiredDate) => {
	const groupedData = {};

	timesArray.forEach(time => {
		if (time.show_date === requiredDate) {
			const cinemaId = String(time.cinema_id);

			if (!groupedData[cinemaId]) {
				groupedData[cinemaId] = [];
			}

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
	// console.log(today, tomorrow, dayAfter, rawDate, selectedDate);

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
		sessionStorage.setItem("selectedTime", selectedTime);
		sessionStorage.setItem("selectedDate", selectedDate);
		sessionStorage.setItem("selectedCinemaId", selectedCinemaId);
		sessionStorage.setItem("selectedCinemaName", selectedCinemaName);
		sessionStorage.setItem("selectedCinemaPriceLevel", allCinema[selectedCinemaId - 1].price_level);
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
				<table className="table m-0" style={{ "--bs-table-bg": "transparent", "--bs-table-accent-bg": "transparent" }}>
					<thead>
						<tr>
							<th>Cinema Name</th>
							<th>Language</th>
							<th>Show Times</th>
							<th>Details</th>
						</tr>
					</thead>
					<tbody>
						{allCinema?.map((cinema) => {
							const cinemaIdStr = String(cinema.id);
							const timesForCinema = groupedTimes[cinemaIdStr] || [];

							return (
								<tr key={cinema.id} >
									<td>{cinema.name}</td>
									<td>{getRandomLanguage(sessionStorage.getItem("movieLanguage"))}</td>

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
										<svg onClick={() => openCinemaModal(cinema)} style={{ opacity: 0.5, width: 25, cursor: "pointer" }} fill="currentColor" viewBox="0 0 20 20" xmlns="http://www.w3.org/2000/svg">
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
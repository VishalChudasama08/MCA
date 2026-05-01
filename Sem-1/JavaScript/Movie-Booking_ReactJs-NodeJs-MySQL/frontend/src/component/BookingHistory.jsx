import React, { useEffect, useState } from 'react'
import { useNavigate } from 'react-router-dom';

export default function BookingHistory() {
	const [bookingData, setBookingData] = useState([])

	const navigate = useNavigate();

	useEffect(() => {
		if (sessionStorage.getItem("token")) {
			const userData = JSON.parse(sessionStorage.getItem("userDetail"));
			const userID = userData.id;

			const getHistoryURL = `http://localhost:5000/api/movie/getBookingHistory/${userID}`;
			async function getHistory() {
				try {
					const res = await fetch(getHistoryURL, { method: "POST" });
					const data = await res.json();

					if (data.status) {
						setBookingData(data.rows);
					}
					// console.log(data);
				} catch (error) {
					console.log(error);

				}
			}
			getHistory();
		} else {
			alert('Hey there, you need to be logged in to book movie.');
			navigate("/Login");
		}
	}, [])
	// console.log(bookingData);

	return (
		<div className="container p-0">
			<div className="card mx-auto" id="history_table"> {/* style={{position: 'absolute', top: 60}} */}
				<div className="card-header text-center h5" id="user_head">Booking History</div>
				<div className="card-body p-0">
					<table className="table table-hover m-0" id="historyId">
						<thead>
							<tr>
								<th>#</th>
								<th>Movie Name</th>
								<th>Cinema Name</th>
								<th>Booked Seats</th>
								<th>Price</th>
								<th>Date</th>
								<th>Status</th>
							</tr>
						</thead>
						<tbody>
							{
								bookingData?.map((row, i) => (
									<tr key={i}>
										<td><strong>{i + 1}</strong></td>
										<td>{row.movies_title}</td>
										<td>{row.cinema_name}</td>
										<td>{row.booked_seats_name}</td>
										<td>{row.total_price}</td>
										<td>{(row.booking_date).split("T")[0].split('-').reverse().join('/')}</td>
										{row.status === "Booking successful." ? <td style={{ color: 'green' }}>{row.status}</td> : <td style={{ color: 'red' }}>{row.status}</td>}

									</tr>
								))
							}
						</tbody>
					</table>
				</div>
			</div>
		</div>
	)
}

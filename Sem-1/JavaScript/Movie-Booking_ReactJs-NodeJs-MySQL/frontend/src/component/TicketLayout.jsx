import React from 'react'

export default function TicketLayout() {
	return (
		<div className="container ticket-layout" id="show_movies">
			<h2>Booking Successful!</h2>;
			<p><strong>Movie Title:</strong> {sessionStorage.getItem("selectedMovieName")}</p>
			<p><strong>Theater:</strong> {sessionStorage.getItem("selectedCinemaName")}</p>
			<p><strong>Location:</strong> {sessionStorage.getItem("selectedCinemaLocation")}</p>
			<p><strong>Show Date:</strong> {sessionStorage.getItem("selectedDate")}</p>
			<p><strong>Show Time:</strong> {sessionStorage.getItem("selectedTime")}</p>
			<p><strong>Seats:</strong> {JSON.parse(sessionStorage.getItem("selectedSeats")).join(', ')}</p>
			<p><strong>Total Price:</strong> &#8377;{parseFloat(sessionStorage.getItem("finalTotalPrice"))}</p>
		</div>
	)
}

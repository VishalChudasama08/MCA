import React, { useEffect, useState } from 'react';
import { useLocation } from 'react-router-dom';

export default function Payment() {
	// 1. Initialize the useLocation hook
	const location = useLocation();

	// 2. Access the state object
	const navigationState = location.state;

	// Define state variables to hold the received data (optional, but good practice)
	const [bookingDetails, setBookingDetails] = useState(null);

	useEffect(() => {
		if (navigationState) {
			// Destructure the values directly from the navigation state object
			const { selectedSeats, movie_id, cinema_id, totalPrice, times_id } = navigationState;

			// Log the data to verify
			console.log("Seats Selected:", selectedSeats);
			console.log("Movie ID:", movie_id);
			console.log("Cinema ID:", cinema_id);
			console.log("Cinema ID:", totalPrice);
			console.log("Cinema ID:", times_id);
			// Assuming you also pass times_id (though not shown in your example, 
			// the previous component logic was setting it in sessionStorage)

			setBookingDetails({ selectedSeats, movie_id, cinema_id });
		} else {
			// Handle the case where the user navigated directly or state was lost
			console.warn("No navigation state found. Redirecting or showing error.");
			// Optionally, navigate back to the seat selection page if data is crucial
		}
	}, [navigationState]); // Rerun effect if the location state changes

	if (!bookingDetails) {
		return <div>Loading booking details...</div>;
	}
	console.log(JSON.parse(sessionStorage.getItem("userDetail")));

	return (
		<div>
			<h2>Checkout / Payment Details</h2>
			<p>Movie ID: {bookingDetails.movie_id}</p>
			<p>Cinema ID: {bookingDetails.cinema_id}</p>
			<p>Total Price: {bookingDetails.totalPrice}</p>
			<p>Times ID: {bookingDetails.times_id}</p>
			<p>Selected Seats ({bookingDetails.selectedSeats.length}): {bookingDetails.selectedSeats.join(', ')}</p>
			<p>User Details {JSON.parse(sessionStorage.getItem("userDetail")).name}</p>
			{/* ... Rest of your payment form ... */}
		</div>
	);
}
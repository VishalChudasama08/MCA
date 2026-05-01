import React, { useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';

export default function Payment() {
	const navigate = useNavigate();

	const [bookingDetails, setBookingDetails] = useState({ userId: "", movieName: "", cinemaName: "", numberOfSeats: 0, totalPrice: 0, selectSeats: "" });

	const [seatUpdateData, setSeatUpdateData] = useState({ selectSeats: "", numberOfSeats: 0, seatID: 0 });

	const [activePaymentMethod, setActivePaymentMethod] = useState("card");

	useEffect(() => {
		setActivePaymentMethod("card");

		const userDetail = JSON.parse(sessionStorage.getItem("userDetail"));
		const selectedSeatsArray = JSON.parse(sessionStorage.getItem("selectedSeats"));
		const selectedSeatsString = selectedSeatsArray.join(', ');
		// console.log(selectedSeatsString);

		setBookingDetails({
			userId: userDetail.id,
			movieName: sessionStorage.getItem("selectedMovieName"),
			cinemaName: sessionStorage.getItem("selectedCinemaName"),
			numberOfSeats: selectedSeatsArray.length,
			totalPrice: parseFloat(sessionStorage.getItem("finalTotalPrice")),
			selectSeats: selectedSeatsString
		})
		setSeatUpdateData({
			selectSeats: selectedSeatsString,
			numberOfSeats: selectedSeatsArray.length,
			seatID: parseFloat(sessionStorage.getItem("selectedSeatID"))
		})

	}, []);

	// console.log(bookingDetails, typeof bookingDetails.selectSeats, typeof JSON.stringify(sessionStorage.getItem("selectedSeats")));
	// console.log(JSON.parse(sessionStorage.getItem("userDetail")));

	async function handlePayment() {
		let add = false, update = false;

		try {
			const res = await fetch("http://localhost:5000/api/movie/booking", {
				method: "POST",
				headers: { "Content-Type": "application/json" },
				body: JSON.stringify(bookingDetails)
			});
			const data = await res.json();
			if (data.status) {
				add = true
			}
			// console.log(data);
		} catch (error) {
			console.log(error);
		}

		try {
			const id = parseFloat(sessionStorage.getItem("selectedSeatID"));
			const seatUpdateURL = `http://localhost:5000/api/movie/seatUpdate/${id}`;
			// console.log(seatUpdateURL);
			const res = await fetch(seatUpdateURL, {
				method: "POST",
				headers: { "Content-Type": "application/json" },
				body: JSON.stringify(seatUpdateData)
			})
			const data = await res.json();
			if (data.status) {
				update = true
			}
			// console.log(data);
		} catch (error) {
			console.log(error);
		}

		if (add && update) {
			navigate("/Ticket");
		} else {
			alert("Ticket Not booked bue to same error")
		}
	}

	return (
		<div className="container border border-2 border-info rounded" id="show_movies">
			<div className="row text-center">
				<div className="col-2 border-2 border-info border-bottom">
					<h5 className="pt-2">Payment Methods</h5>
				</div>
				<div className="col border-2 border-info border-start border-bottom">
					<h5 className="pt-2">Payment Information</h5>
				</div>
			</div>
			<div className="row">
				<div className="col-2 p-0 text-center">
					<div className="border-2 border-info border-bottom" id="card-div">
						<button onClick={() => { setActivePaymentMethod("card") }} className="my-1 px-5 btn btn-outline-info" id="card"><strong>Card</strong></button>
					</div>
					<div onClick={() => { setActivePaymentMethod("upi") }} className="border-2 border-info border-bottom" id="upi-div">
						<button className="my-1 px-5 btn btn-outline-info" id="upi"><strong>UPI</strong></button>
					</div>
				</div>
				<div className="col-3 p-0 text-center border-2 border-info border-start"></div>
				<div className="col pt-4 pb-2 m-0">
					{activePaymentMethod === "card" ? (
						<div id="show_card">
							<div className="row row-cols-lg-auto g-3">
								<div>
									<label htmlFor="username_number" className="form-label">Enter Card Number:</label>
								</div>
								<div style={{ marginTop: 12 }}>
									<input type="number" className="form-control" id="username_number" name="username_number" required />
								</div>
							</div>
							<div className="mt-3">
								<label htmlFor="expiry-date">Expiry Date: </label>
								<select name="month" defaultValue="v1" className="p-1 border border-2 rounded ms-3">
									<option disabled hidden value="v1">Select month</option>
									<option value="01">01</option>
									<option value="02">02</option>
									<option value="03">03</option>
									<option value="04">04</option>
									<option value="05">05</option>
									<option value="06">06</option>
									<option value="07">07</option>
									<option value="08">08</option>
									<option value="09">09</option>
									<option value="10">10</option>
									<option value="11">11</option>
									<option value="12">12</option>
								</select>
								<select name="year" defaultValue="v2" className="p-1 border border-2 rounded ms-3">
									<option disabled hidden value="v2">Select year</option>
									<option value="2026">2026</option>
									<option value="2027">2027</option>
									<option value="2028">2028</option>
									<option value="2029">2029</option>
									<option value="2030">2030</option>
								</select>
							</div>
							<div className="row row-cols-lg-auto g-3 mt-1">
								<div>
									<label htmlFor="cvv">CVV:</label>
								</div>
								<div style={{ marginTop: 10 }}>
									<input type="number" className="form-control" id="cvv" placeholder="XXX" required />
								</div>
							</div>
						</div>
					) : (
						<div id="show_upi">
							<div id="show_qr">
								<img src="images/qr_code.png" alt="qr-code" style={{ width: 250, margin: '1rem' }} />
							</div>
							<p className="ms-3">Scan to pay with any UPI app</p>
						</div>
					)}
					{/* <Link to="/Ticket" type="button" className="btn btn-primary mt-3" onClick={handlePayment} >Pay &#8377;{bookingDetails.totalPrice}</Link> */}
					<button type="button" className="btn btn-primary mt-3" onClick={handlePayment}>Pay &#8377;{bookingDetails.totalPrice}</button>
				</div>
			</div>
		</div>
	);
}
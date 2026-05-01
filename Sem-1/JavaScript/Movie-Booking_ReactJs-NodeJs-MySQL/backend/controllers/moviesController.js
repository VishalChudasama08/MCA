import { db } from "../config/db.js";

export const getAllMovies = async (req, res) => {
	const [rows] = await db.query("SELECT * FROM movies");
	console.log(rows[0].title, "- from getAllMovies");
	res.json({ status: true, message: "Here all movies", rows });
}

export const getThisMovie = async (req, res) => {
	const { id } = req.params;
	const [rows] = await db.query("SELECT * FROM movies WHERE id=?", [id]);
	console.log(rows[0].title, "- from getThisMovie");

	if (rows.length === 0) {
		return res.json({ status: false, message: "Movie not found" });
	}

	res.json({ status: true, message: "Movie found", rows });
}

export const getAllCinema = async (req, res) => {
	const [rows] = await db.query("SELECT * FROM cinema");
	if (rows.length === 0) {
		return res.json({ status: false, message: "No any cinema available" });
	}
	console.log(rows[0].name, "- from getAllCinema");
	res.json({ status: true, message: "All cinema", rows })
}

export const dateWiseCinema = async (req, res) => {
	const [rows] = await db.query("SELECT * FROM times");
	if (rows.length === 0) {
		return res.json({ status: false, message: "Not available" })
	}
	console.log(rows[0].show_time, "- from dateWiseCinema");
	res.json({ status: true, message: "All times", rows })
}

export const getSeatLayout = async (req, res) => {
	const { id } = req.params;
	const [rows] = await db.query("SELECT * FROM seats WHERE cinema_id=?", [id]);
	console.log(rows[0].total_seats, "- from getSeatLayout");

	if (rows.length === 0) {
		return res.json({ status: false, message: "Seat Layout Not available" });
	}

	res.json({ status: true, message: "Layout found", rows });
}

export const addOnHistory = async (req, res) => {
	const { userId, movieName, cinemaName, numberOfSeats, totalPrice, selectSeats } = req.body;

	try {
		await db.query(
			"INSERT INTO bookings (user_id, movies_title, cinema_name, number_of_seats, total_price, booked_seats_name, status) VALUES (?, ?, ?, ?, ?, ?, 'Booking successful.')",
			[userId, movieName, cinemaName, numberOfSeats, totalPrice, selectSeats]
		);
		console.log(userId, movieName, cinemaName, numberOfSeats, totalPrice, selectSeats, "- from addOnHistory");

		res.json({ status: true, message: "Booking Successfully" });

	} catch (err) {
		console.log(err);
		res.json({ status: false, message: "Error" });
	}
};

export const seatStructureUpdate = async (req, res) => {
	const { selectSeats, numberOfSeats } = req.body; // get from sended data (json)
	const { id } = req.params; // get from url

	const updateQuery = `
	UPDATE 
		seats 
	SET 
		available_seats = available_seats - ?, 
		booked_seats_name = CONCAT_WS(', ', booked_seats_name, ?) 
	WHERE 
	id = ?
	`; // CONCAT_WS(', ', booked_seats_name, ?) ==> to keep old value, and add on new value

	// console.log(updateQuery, numberOfSeats, selectSeats, id, "- from seatStructureUpdate");

	try {
		const [rows] = await db.query(updateQuery, [numberOfSeats, selectSeats, id]);

		console.log(`Rows affected: ${rows.affectedRows}  - from seatStructureUpdate`);
		// console.log(rows);
		res.json({ status: true, message: "Seat Update Successfully" })
	} catch (error) {
		res.json({ status: false, message: "Error on Seat Update" })
		console.error("Database error:", error);
	}

}

export const getHistory = async (req, res) => {
	const { id } = req.params;
	try {
		const [rows] = await db.query("SELECT * FROM bookings WHERE user_id = ?", [id])
		console.log(rows[0].status, " - from getHistory")

		res.json({ status: true, message: "Here your booking history", rows });
	} catch (error) {
		res.json({ status: false, message: "Error on get booking history" })
		console.log(error);
	}
}
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
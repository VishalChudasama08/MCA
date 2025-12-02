import { db } from "../config/db.js";

export const getAllMovies = async (req, res) => {
	const [rows] = await db.query("SELECT * FROM movies");
	console.log(rows[0], "- from getAllMovies");
	res.json({ status: true, message: "Here all movies", rows });
}

export const getThisMovie = async (req, res) => {
	const { id } = req.params;
	const [rows] = await db.query("SELECT * FROM movies WHERE id=?", [id]);
	console.log(rows, "- from getThisMovie");

	if (rows.length === 0) {
		return res.json({ status: false, message: "Movie not found" });
	}

	res.json({ status: true, message: "Movie found", rows });
} 
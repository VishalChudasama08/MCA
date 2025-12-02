import express from "express";
import { getAllMovies, getThisMovie } from "../controllers/moviesController.js";

const router = express.Router();

router.get("/allMovies", getAllMovies);
router.post("/getThisMovie/:id", getThisMovie);

export default router;
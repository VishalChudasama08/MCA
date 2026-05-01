import express from "express";
import { getAllMovies, getThisMovie, getAllCinema, dateWiseCinema, getSeatLayout, addOnHistory, seatStructureUpdate, getHistory } from "../controllers/moviesController.js";

const router = express.Router();

router.get("/allMovies", getAllMovies);
router.post("/getThisMovie/:id", getThisMovie);
router.post("/allCinema", getAllCinema);
router.post("/dateWiseCinema", dateWiseCinema);
router.post("/seat/:id", getSeatLayout);
router.post("/booking", addOnHistory);
router.post("/seatUpdate/:id", seatStructureUpdate);
router.post("/getBookingHistory/:id", getHistory);

export default router;
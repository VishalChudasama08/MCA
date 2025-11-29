import express from "express";
import cors from "cors";
import dotenv from "dotenv";
import "./config/db.js";

dotenv.config();
const app = express();
const PORT = 5000;
app.use(cors());
app.use(express.json());

// Routes
import authRoutes from "./routes/authRoutes.js";
app.use("/api/auth", authRoutes);

import userRoutes from "./routes/userRoutes.js";
app.use("/api/users", userRoutes);

app.listen(PORT, () => 
  console.log(`Server running → http://localhost:${PORT}`)
);

import { db } from "../config/db.js";
import bcrypt from "bcrypt";
import jwt from "jsonwebtoken";

// REGISTER
export const register = async (req, res) => {
  const { name, email, password } = req.body;

  try {
    const hash = bcrypt.hashSync(password, 10);

    await db.query(
      "INSERT INTO users (name, email, password) VALUES (?, ?, ?)",
      [name, email, hash]
    );

    res.json({ status: true, message: "Registered Successfully" });

  } catch (err) {
    res.json({ status: false, message: "Email Already Exists!" });
  }
};

// LOGIN
export const login = async (req, res) => {
  const { email, password } = req.body;

  const [rows] = await db.query("SELECT * FROM users WHERE email=?", [email]);

  if (rows.length === 0)
    return res.json({ status: false, message: "User not found" });

  const user = rows[0];

  if (!bcrypt.compareSync(password, user.password))
    return res.json({ status: false, message: "Wrong Password" });

  const token = jwt.sign({ id: user.id }, "SECRET123", { expiresIn: "1d" });

  res.json({ status: true, message: "Login Success", token });
};

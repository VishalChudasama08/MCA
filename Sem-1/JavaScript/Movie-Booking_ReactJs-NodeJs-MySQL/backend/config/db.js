import mysql from "mysql2/promise";
import dotenv from "dotenv";
dotenv.config();

// Database connection parameters
const host = "127.0.0.1";
const user = "root";
const password = "";
const database = "v08";
const port = 3306;

async function initDB() {
  try {
    const pool = mysql.createPool({
      host,
      user,
      password,
      database,
      port,
      waitForConnections: true,
      connectionLimit: 10,
      queueLimit: 0
    });

    // quick sanity check
    const conn = await pool.getConnection();
    await conn.ping();
    conn.release();

    console.log("MySQL Connected ✔", { host, user, database, port });
    return pool;
  } catch (err) {
    console.error("MySQL connection failed — check .env credentials and that MySQL is running.");
    console.error(err);
    process.exit(1); // stop server, prevents cascading errors
  }
}

export const db = await initDB();

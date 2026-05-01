import {db} from "../config/db.js";

export const getAll = async(req,res)=>{
  const [rows] = await db.query("SELECT * FROM users");
  res.json(rows);
};

export const createUser = async(req,res)=>{
  const {name,email} = req.body;
  await db.query("INSERT INTO users(name,email) VALUES(?,?)",[name,email]);
  res.json({message:"User Added"});
};

export const updateUser = async(req,res)=>{
  const {id} = req.params;
  const {name,email} = req.body;
  await db.query("UPDATE users SET name=?,email=? WHERE id=?",[name,email,id]);
  res.json({message:"User Updated"});
};

export const deleteUser = async(req,res)=>{
  const {id} = req.params;
  await db.query("DELETE FROM users WHERE id=?",[id]);
  res.json({message:"User Deleted"});
};

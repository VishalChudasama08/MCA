import { useState } from "react";
import { useNavigate } from "react-router-dom";

export default function Register() {
  const [form, setForm] = useState({ name:"", email:"", password:"" });
  const navigate = useNavigate();

  const submit = async(e)=>{
    e.preventDefault();
    const res = await fetch("http://localhost:5000/api/auth/register",{
      method:"POST",
      headers:{ "Content-Type":"application/json" },
      body:JSON.stringify(form)
    });
    const data = await res.json();
    alert(data.message || data.status);
	 navigate("/login");
  };

  return (
    <div style={{padding:20}}>
      <h2>Register</h2>
      <input placeholder="Name" onChange={e=>setForm({...form,name:e.target.value})} /><br/>
      <input placeholder="Email" onChange={e=>setForm({...form,email:e.target.value})} /><br/>
      <input type="password" placeholder="Password"
             onChange={e=>setForm({...form,password:e.target.value})} /><br/>
      <button onClick={submit}>Register</button>
    </div>
  );
}

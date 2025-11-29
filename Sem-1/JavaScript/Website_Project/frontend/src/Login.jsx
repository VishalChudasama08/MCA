import { useState } from "react";
import { useNavigate } from "react-router-dom";

export default function Login() {
	const [form, setForm] = useState({ email: "", password: "" });
	const navigate = useNavigate();
	const submit = async (e) => {
		e.preventDefault();

		const res = await fetch("http://localhost:5000/api/auth/login", {
			method: "POST",
			headers: { "Content-Type": "application/json" },
			body: JSON.stringify(form)
		});

		const data = await res.json();
		alert(data.message);

		if (data.token) {
			localStorage.setItem("token", data.token);
		}
		navigate("/home");
	};

	return (
		<div style={{ padding: 20 }}>
			<h2>Login</h2>
			<input placeholder="Email" onChange={e => setForm({ ...form, email: e.target.value })} /><br />
			<input type="password" placeholder="Password"
				onChange={e => setForm({ ...form, password: e.target.value })} /><br />
			<button onClick={submit}>Login</button>
		</div>
	)
}

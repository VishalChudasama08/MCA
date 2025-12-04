import { useState } from "react";
import { useNavigate, Link } from "react-router-dom";

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
		// console.log(data);
		sessionStorage.setItem("userDetail", JSON.stringify(data.user));
		// console.log(typeof data.user);


		if (data.status) {
			navigate("/");
		} else {
			alert(data.message);
		}

		if (data.token) {
			sessionStorage.setItem("token", data.token);
		}
	};

	return (
		<div className="card mx-auto my-3" style={{ minWidth: 300, maxWidth: 600 }}>
			<div className="card-header text-center h5">User Login</div>
			<div className="card-body">
				<div className="mb-3">
					<label htmlFor="username" className="form-label">Username</label>
					<input type="email" onChange={e => setForm({ ...form, email: e.target.value })} placeholder="Enter Email" className="form-control" id="username" required />
				</div>
				<div className="mb-3">
					<label htmlFor="password" className="form-label">Password</label>
					<input type="password" onChange={e => setForm({ ...form, password: e.target.value })} placeholder="Enter Password" className="form-control" id="password" name="password" required />
				</div>
				<div className="d-flex mt-3 justify-content-between">
					<button onClick={submit} className="btn btn-outline-success" name="submit">Login</button>
					<Link className="btn btn-outline-primary" to="/Register">Register Anew</Link>
				</div>
				<div className="mt-2 ms-0">
					<Link to="/ForgotPassword">Forgot Password?</Link>
				</div>
			</div>
		</div>
	)
}

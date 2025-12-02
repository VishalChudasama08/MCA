import { useState } from "react";
import { useNavigate, Link } from "react-router-dom";

export default function Register() {
	const [registerData, setRegisterData] = useState({ name: "", email: "", password: "", mobile_number: "", confirmPassword: "" });
	const navigate = useNavigate();

	const submitRegisterForm = async (e) => {
		e.preventDefault();
		const res = await fetch("http://localhost:5000/api/auth/register", {
			method: "POST",
			headers: { "Content-Type": "application/json" },
			body: JSON.stringify(registerData)
		});
		const data = await res.json();

		if (data.message === "Registered Successfully") {
			navigate("/login");
		} else {
			alert(data.message || data.status);
			console.log(data);
		}
	};

	return (
		<div style={{ padding: 20 }}>
			<div className="card mx-auto my-5" style={{ minWidth: 300, maxWidth: 600 }}>
				<div className="card-header text-center">New User Registration Form</div>
				<div className="card-body">
					<div className="md-3 pb-2">
						<label htmlFor="name" className="form-label">Your Name :-</label>
						<input type="text" onChange={e => setRegisterData({ ...registerData, name: e.target.value })} className="form-control" id="name" name="name" required />
					</div>
					<div className="md-3 pb-2">
						<label htmlFor="email" className="form-label">Email (Username) :-</label>
						<input type="email" onChange={e => setRegisterData({ ...registerData, email: e.target.value })} className="form-control" id="email" name="email" required />
					</div>
					<div className="md-3 pb-2">
						<label htmlFor="password" className="form-label">Create Password :-</label>
						<input type="password" onChange={e => setRegisterData({ ...registerData, password: e.target.value })} className="form-control" id="password" name="password" required />
					</div>
					<div className="md-3 pb-2">
						<label htmlFor="confirmPassword" className="form-label">Confirm Password:- </label>
						<input type="password" className="form-control" id="confirmPassword" name="confirmPassword" onChange={e => setRegisterData({ ...registerData, confirmPassword: e.target.value })} autoComplete="new-password" required />
					</div>
					{registerData.confirmPassword.length !== 0 && registerData.password !== registerData.confirmPassword && (<small className="text-danger">{"Passwords do not match, Please confirm your password"}</small>)}
					{/* {registerData.confirmPassword.length + " " + registerData.password.length + " " + registerData.confirmPassword + " " + registerData.password} */}
					<div className="md-3 pb-2">
						<label htmlFor="mobile_number" className="form-label">Mobile Number :-</label>
						<input type="tel" onChange={e => setRegisterData({ ...registerData, mobile_number: e.target.value })} className="form-control" id="mobile_number" name="mobile_number" required />
					</div>
					{/* <div className="md-3 pb-2">
							<label htmlFor="security_question" className="form-label">Security Question :-</label>
							<select className="form-control" id="security_question" name="security_question" required>
							<option value="" disabled selected hidden>-- click to select security question--</option>
							<option>What is your nickname ?</option>
							<option>What is your birth month ?</option>
							<option>What was your favorite school teacher's name ?</option>
							<option>What's your favorite movie ?</option>
							<option>What's your favorite color ?</option>
							<option>What's your favorite number in 0 to 9 ?</option>
							<option>What city were you born in ?</option>
							<option>What was the name of your first childhood friend ?</option>
							</select>
							</div>
							<div className="md-3 pb-2">
							<label htmlFor="answer" className="form-label">Security Question Answer :-</label>
							<span style={{ float: "right", fontSize: "12px", paddingTop: "10px", opacity: 0.8 }}>Note: This is what you need to remember.</span>
							<input type="text" className="form-control" id="answer" name="answer" required />
							</div> */}
					<div className="col-12 d-flex justify-content-center mt-2">
						<button onClick={submitRegisterForm} type="submit" className="btn btn-outline-success">Register</button>
					</div>
					<div className="col-12 d-flex justify-content-center mt-2">
						If you are already registered then click here&nbsp;<Link to="/Login">log-in</Link>
					</div>
				</div>
			</div>
		</div>

	);
}

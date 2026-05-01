import { useEffect, useState } from "react";
import { Link, useLocation } from "react-router-dom";

const Navbar = () => {
	const [loginStatus, setLoginStatus] = useState(false);
	const location = useLocation();

	// console.log(location.pathname);

	function cheekStatus() {
		let userToken = sessionStorage.getItem("token");
		if (userToken) {
			setLoginStatus(true)
		} else {
			setLoginStatus(false);
		}
	}

	function handleLogout() {
		sessionStorage.clear();
		// sessionStorage.removeItem("token");
		cheekStatus();
	}

	useEffect(() => {
		cheekStatus();
	}, [location.pathname])

	return (
		<div className="container-flued mb-2" id="navbarDiv">
			<nav className="navbar navbar-expand-lg navbar-info bg-info border border-secondary rounded m-0 p-0">
				<div className="container-fluid py-0 px-1">
					<Link className="navbar-brand" to="/">
						<img src="images/bookAmovie_V08_Logo_R.png" style={{ width: 180 }} alt="Logo"></img>
					</Link>

					<button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
						<span className="navbar-toggler-icon"></span>
					</button>
					<div className="collapse navbar-collapse" id="navbarSupportedContent">
						<ul className="navbar-nav me-auto mb-2 mb-lg-0">
							<li className="nav-item ms-3">
								<Link className="nav-link active" to="/">Home</Link>
							</li>
							<li className="nav-item ms-3">
								<Link className="nav-link active" to="/Contact">Contact Us</Link>
							</li>
							<li className="nav-item ms-3">
								<Link className="nav-link active" to="/About">About</Link>
							</li>
						</ul>
						<ul className="navbar-nav ms-auto mb-2 mb-lg-0">
							{loginStatus === true ? (
								<>
									<li className="nav-item">
										<span className="nav-link active" style={{ cursor: "pointer" }} onClick={() => { handleLogout(); }}>Logout</span>
									</li>
									<li className="nav-item ms-3">
										<Link className="nav-link active" to="/BookingHistory" id="booking_history">Booking History</Link>
									</li>
									<li className="nav-item ms-3">
										<Link className="nav-link active" to="/Profile">Profile</Link>
										{/* <button className="nav-link active" style={{ border: "none", backgroundColor: 'transparent', width: "35px" }} type="button" id="show_profile_icon">  */}
										{/* <img src="images/user-solid.svg" alt="user icon" style={{ margin: 2 }} /> */}
										{/* <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 448 512"><path d="M224 256A128 128 0 1 0 224 0a128 128 0 1 0 0 256zm-45.7 48C79.8 304 0 383.8 0 482.3C0 498.7 13.3 512 29.7 512H418.3c16.4 0 29.7-13.3 29.7-29.7C448 383.8 368.2 304 269.7 304H178.3z" /></svg> */}
										{/* </button> */}
									</li>
								</>
							) : (
								<>
									<li className="nav-item ms-3">
										<Link className="nav-link active" to="/Login">Login</Link>
									</li>
									<li className="nav-item ms-3">
										<Link className="nav-link active" to="/Register">Register</Link>
									</li>
								</>
							)}
						</ul>
					</div>
				</div>
			</nav>
		</div>
	)
}

export default Navbar
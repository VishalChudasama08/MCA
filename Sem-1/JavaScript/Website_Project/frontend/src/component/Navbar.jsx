import { Link } from "react-router-dom";

const Navbar = () => {
	return (
		<nav className="navbar navbar-expand-lg navbar-light bg-light border border-secondary rounded m-0">
			<div className="container-fluid">
				<Link className="navbar-brand" to="/">
					<img src="images/bookAmovie_V08_logo.png" style={{ width: 180 }} alt="Logo"></img>
				</Link>

				<button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
					<span className="navbar-toggler-icon"></span>
				</button>
				<div className="collapse navbar-collapse" id="navbarSupportedContent">
					<ul className="navbar-nav me-auto mb-2 mb-lg-0">
						<li className="nav-item">
							<Link className="nav-link active" to="/Login">Login</Link>
						</li>
						<li className="nav-item">
							<Link className="nav-link active" to="/Register">Register</Link>
						</li>
						<li className="nav-item">
							<Link className="nav-link active" to="/Users">Users (Protected)</Link>
						</li>
						<li className="nav-item">
							<Link className="nav-link active" to="/About">About</Link>
						</li>
					</ul>
				</div>
			</div>
		</nav>
	)
}

export default Navbar
import { useEffect, useState } from 'react'
import { Link, useNavigate } from 'react-router-dom';

export default function MovieInfo() {
	const [info, setInfo] = useState([]);
	const navigate = useNavigate();

	useEffect(() => {
		async function getThisMovieData() {
			let id = sessionStorage.getItem("selectedMovieID");
			const res = await fetch(`http://localhost:5000/api/movie/getThisMovie/${id}`, { method: "POST" })
			const data = await res.json();
			// console.log(data);
			if (data.status) {
				setInfo(data.rows[0])
				sessionStorage.setItem("movieLanguage", data.rows[0].language);
			} else {
				alert(data.message);
			}
		}
		getThisMovieData();
		// eslint-disable-next-line react-hooks/exhaustive-deps
	}, [])

	function handleBook() {
		if (sessionStorage.getItem("token")) {
			navigate("/Date_Cinema")
		} else {
			const modal = new window.bootstrap.Modal(document.getElementById("loginModal"));
			modal.show();
		}
	}

	// remove modal effect
	const handleLoginClick = () => {
		const modalElement = document.getElementById("loginModal");

		if (modalElement && window.bootstrap && window.bootstrap.Modal) {
			const modalInstance = window.bootstrap.Modal.getInstance(modalElement);

			if (modalInstance) {
				modalInstance.hide();
			} else {
				document.body.classList.remove('modal-open');
				const backdrop = document.querySelector('.modal-backdrop');
				if (backdrop) {
					backdrop.remove();
				}
			}
		}
	};

	if (!info) {
		return <div className="text-center mt-5">Loading...</div>;
	}
	return (
		<div className="container border border-2 border-info rounded p-0 mx-auto my-3" id="show_movies">
			<div className="card">
				<div className="row">
					<div className="col-4">
						<img src={info.image_location} className="img-fluid rounded-start" style={{ width: '25rem' }} alt={info.title + "image"} />
					</div>
					<div className="col-8">
						<div className="row">
							<h4 className="card-title" style={{ height: '3rem', display: 'flex', alignItems: 'center' }}><strong>{info.title}</strong></h4>
							<div className="col-4">
								<p className="card-text mb-1"><strong>Director: </strong></p>
								<p className="card-text mb-1"><strong>Genres: </strong></p>
								<p className="card-text mb-1"><strong>Language: </strong></p>
								<p className="card-text mb-1"><strong>Duration: </strong></p>
								<p className="card-text mb-1"><strong>Rating: </strong></p>
								<p className="card-text mb-1"><strong>Release Date: </strong></p>
							</div>
							<div className="col-8">
								<p className="card-text mb-1">{info.director}</p>
								<p className="card-text mb-1">{info.genre}</p>
								<p className="card-text mb-1">{info.language}</p>
								<p className="card-text mb-1">{info.duration}</p>
								<p className="card-text mb-1">{info.rating}</p>
								<p className="card-text mb-1">{info.release_date}</p>
							</div>
							<p className="card-text mb-1"><strong>About the movie: </strong></p>
							<p className="card-text mb-1">{info.description}</p>
							{/* <Link to={"/Date_Cinema"} className="btn btn-outline-primary" style={{ width: '95%' }}>Booking</Link> */}
							<button onClick={() => { handleBook() }} className="btn btn-outline-primary" style={{ width: '95%' }}>Booking</button>
						</div>
					</div>
				</div>
			</div>


			{/* Bootstrap Modal */}
			<div className="modal fade" id="loginModal" tabIndex="-1" aria-hidden="true">
				<div className="modal-dialog">
					<div className="modal-content">
						<div className="modal-header">
							<h5>Please log in to continue.</h5>
							<button type="button" className="btn-close" data-bs-dismiss="modal"></button>
						</div>
						<div className="modal-body py-2 m-0">
							<strong className='m-0'>Hey there, you need to be logged in to book movie.</strong>
						</div>
						<div className="modal-footer">
							<button type="button" className="btn btn-secondary" data-bs-dismiss="modal">Close</button>
							<Link to="/Login" onClick={() => { handleLoginClick() }} type="button" className="btn btn-primary">Login</Link>
						</div>
					</div>
				</div>
			</div>
		</div>
	)
}

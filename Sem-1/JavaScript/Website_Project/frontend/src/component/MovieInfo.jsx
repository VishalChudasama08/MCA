import { useEffect, useState } from 'react'
import { Link } from 'react-router-dom';

export default function MovieInfo() {
	const [info, setInfo] = useState([]);
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
							<Link to={"/Date_Cinema"} className="btn btn-outline-primary" style={{ width: '95%' }}>Booking</Link>
						</div>
					</div>
				</div>
			</div>
		</div>
	)
}

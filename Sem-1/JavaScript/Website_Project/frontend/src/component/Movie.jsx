import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';

export default function Movie() {
	const [allMovies, setAllMovies] = useState([]);
	// const navigate = useNavigate();
	useEffect(() => {
		async function getAllMovies() {
			const res = await fetch("http://localhost:5000/api/movie/allMovies");
			const data = await res.json();
			setAllMovies(data);
			console.log(allMovies.rows);
		}
		getAllMovies();
		// eslint-disable-next-line react-hooks/exhaustive-deps
	}, [])

	async function selectMovieId(id) {
		localStorage.setItem("SelectedMovieID", id)
		localStorage.setItem("SelectedMovieName", allMovies.rows[id - 1].title)
		localStorage.setItem("SelectedMovieRating", allMovies.rows[id - 1].rating)
		localStorage.setItem("SelectedMoviePrice", allMovies.rows[id - 1].movie_price)
	}

	return (
		<div>
			{/* All Movies */}
			{allMovies.status && allMovies.rows.map((m, i) => (
				<div key={i} className="col-6 col-md-4 col-lg-3">
					<div className="card mb-4" style={{ border: "none" }}>
						{/* navigate(`/Movie/${i}`) */}
						<Link to={"/MovieInfo"} onClick={() => { selectMovieId(i + 1) }} style={{ border: "none", padding: 0 }}>
							<div className="ratio" style={{ "--bs-aspect-ratio": "calc(3 / 2 * 100%)" }}>
								<img src={m.image_location} className="img-fluid rounded" alt={m.image_location} />
							</div>
						</Link>
						<div className="card-body m-0 px-0 py-2" style={{ textIndent: 5 }}>
							<h5 className="card-title m-0">{m.title}</h5>
							<p className="card-text m-0">{m.genre}</p>
							<p className="card-text m-0">{m.rating}</p>
							<p className="card-text m-0">{m.language}</p>
						</div>
					</div>
				</div>
			))}
		</div>

	)
}


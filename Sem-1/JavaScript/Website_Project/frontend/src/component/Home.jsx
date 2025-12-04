import Navbar from './Navbar';
import { Outlet } from 'react-router-dom';

export default function Home() {
	return (
		<>
			<Navbar />
			<div className="container-lg" id="main">
				<Outlet /> {/* all route (that have inside of Home route)  will render here */}
			</div>
		</>

	)
}


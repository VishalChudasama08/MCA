import { Link, Outlet } from "react-router-dom"

export default function DateAndCinema() {
	const today = new Date().toLocaleDateString("en-GB", { day: "numeric", month: "short" });
	const tomorrow = new Date(Date.now() + 86400000).toLocaleDateString("en-GB", { day: "numeric", month: "short" });
	const dayAfter = new Date(Date.now() + 2 * 86400000).toLocaleDateString("en-GB", { day: "numeric", month: "short" });

	return (
		<div className="my-1" id="show_movies">
			<div className="border border-2 border-info rounded p-1" style={{ display: 'flex', flexFlow: 'row' }}>
				<h4 className="mt-2 ms-3">Select Date : </h4>
				<Link to="/1"><button id="autoclick" onClick="" type="button" className="btn btn-outline-info m-2 buttons">{today}</button></Link>
				<Link to="/next"><button id="autoclick" onClick="" type="button" className="btn btn-outline-info m-2 buttons">{tomorrow}</button></Link>
				<Link to="/3"><button id="autoclick" onClick="" type="button" className="btn btn-outline-info m-2 buttons">{dayAfter}</button></Link>
				{/* <?php
        $j = 1;
        $day1 = strtotime("+" . $j . " day", $today);
        while ($j < 4) {s
            $day = strtotime("+" . $j . " days", $today);
            $output = "";
            if ($j == 1) {
                $output = '<button id="autoclick" onclick="loadCinemas(\'cinema_and_times.php?id=' . $movie_id . '&date=' . date("d", $day1) . '\')" type="button" className="btn btn-outline-info m-2 buttons">' . date("d M", $day1) . '</button>';
            } else {
                $output = '<button onclick="loadCinemas(\'cinema_and_times.php?id=' . $movie_id . '&date=' . date("d", $day) . '\')" type="button" className="btn btn-outline-info m-2 buttons">' . date("d M", $day) . '</button>';
            }
            echo $output;
            $j++;
        }
        $day3 = strtotime("+" . $j . " days", $today);
        ?> */}

			</div>
			<div id="cinema_times_content">
				<Outlet />
			</div>
			<div id="cinema-info-modal" className="modal">
				<div className="cinema-info-modal">
					<div id="cinema-info"></div>
				</div>
			</div>
		</div>
	)
}

-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 06, 2025 at 08:01 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `v08`
--

-- --------------------------------------------------------

--
-- Table structure for table `bookings`
--

CREATE TABLE `bookings` (
  `id` int(11) UNSIGNED NOT NULL,
  `user_id` int(11) NOT NULL,
  `movies_title` varchar(250) NOT NULL,
  `cinema_name` varchar(255) NOT NULL,
  `number_of_seats` int(5) NOT NULL,
  `total_price` decimal(10,2) NOT NULL,
  `booking_date` timestamp NOT NULL DEFAULT current_timestamp(),
  `updated_at` timestamp NULL DEFAULT NULL ON UPDATE current_timestamp(),
  `booked_seats_name` text NOT NULL,
  `status` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `bookings`
--

INSERT INTO `bookings` (`id`, `user_id`, `movies_title`, `cinema_name`, `number_of_seats`, `total_price`, `booking_date`, `updated_at`, `booked_seats_name`, `status`) VALUES
(1, 1, 'Rampage', 'Galaxy Cinema: Rajkot', 3, 630.00, '2025-12-04 19:10:35', '2025-12-05 09:03:07', 'D2, D3, D4', 'Booking successful.'),
(2, 1, 'Rebel Moon - Part Two: The Scargiver', 'INOX: Reliance Mega Mall, Rajkot', 3, 630.00, '2025-12-04 21:22:52', '2025-12-05 09:03:12', 'F8, F9, F10', 'Booking successful.'),
(3, 3, 'Interstellar', 'Cosmoplex Multiplex: Rajkot', 2, 300.00, '2025-12-04 21:54:14', '2025-12-05 09:03:47', 'E5, E4', 'Booking successful.'),
(4, 1, 'Chaal Jeevi Laiye', 'Roongta Cinemas, Shyam Mandir Vesu: Surat', 1, 180.00, '2025-12-05 09:15:21', NULL, 'F6', 'Booking successful.'),
(5, 1, 'Pirates of the Caribbean: Dead Men Tell No Tales', 'Galaxy Cinema: Rajkot', 2, 520.00, '2025-12-05 09:44:46', NULL, 'E5, E4', 'Booking successful.'),
(6, 4, 'Avatar: The Way of Water', 'Cosmoplex Multiplex: Rajkot', 2, 660.00, '2024-07-15 23:05:45', '2024-07-16 02:02:12', 'H6, H7', 'Booking successful.'),
(7, 4, 'Fast X', 'Connplex Signature: Gandhinagar', 3, 410.00, '2024-07-15 23:06:52', '2024-07-16 02:02:18', 'D9, D10, F9', 'Booking successful.'),
(8, 4, 'Pirates of the Caribbean: Dead Men Tell No Tales', 'INOX: Reliance Mega Mall, Rajkot', 6, 1570.00, '2024-07-15 23:07:37', '2024-07-16 02:02:24', 'E5, F6, J8, J9, J10, J11', 'Booking successful.'),
(9, 4, 'Rebel Moon - Part Two: The Scargiver', 'Rajhans Cinemas: Gandhidham', 8, 1860.00, '2024-07-15 23:08:31', '2024-07-16 02:02:29', 'D14, D15, H9, H10, I4, I5, K10, K11', 'Booking successful.'),
(10, 4, 'Animal', 'Cinepolis Vandana: Rajkot', 6, 1060.00, '2024-07-15 23:10:02', '2024-07-16 02:02:35', 'C7, C8, F13, F14, H5, H6', 'Booking successful.'),
(11, 4, 'Hi Nanna', 'City Gold Cinema: Ahmedabad', 4, 680.00, '2024-07-15 23:12:45', '2024-07-16 01:59:42', 'H7, H10, H11, J8', 'Booking successful.'),
(12, 4, '12th Fail', 'City Gold Cinema: Ahmedabad', 1, 180.00, '2024-07-15 23:13:35', '2024-07-16 02:42:02', 'H6', 'Booking canceled.'),
(13, 4, 'Interstellar', 'Rajhans Cinemas: Gandhidham', 2, 260.00, '2024-07-15 23:37:22', '2024-07-16 02:37:02', 'D14, D15', 'Booking canceled.'),
(14, 4, 'Saiyar Mori Re', 'Mehul Cinemax: Jamnagar', 3, 480.00, '2024-07-15 23:48:18', '2024-07-16 01:59:57', 'K4, K5, K8', 'Booking canceled.');

-- --------------------------------------------------------

--
-- Table structure for table `cinema`
--

CREATE TABLE `cinema` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `location` varchar(255) NOT NULL,
  `facilities` text DEFAULT NULL,
  `created_at` timestamp NOT NULL DEFAULT current_timestamp(),
  `updated_at` timestamp NULL DEFAULT NULL ON UPDATE current_timestamp(),
  `price_level` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `cinema`
--

INSERT INTO `cinema` (`id`, `name`, `location`, `facilities`, `created_at`, `updated_at`, `price_level`) VALUES
(1, 'Cosmoplex Multiplex: Rajkot', 'Mota Mauva Road, Kalawad Road, Near Rangoli Park Restaurant, Rajkot, Gujarat 360001, India', 'Food Court', '2025-12-01 12:48:18', '2025-12-01 05:13:58', '20,80,130'),
(2, 'Connplex Signature: Gandhinagar', '301-308, Shreeji Signature, Sargasan, Near Reliance Crossroad, Gandhinagar, Gujarat 382028, India', 'Ticket Cancellation, F&B, MTicket, Parking Facility, Food Court', '2025-12-01 12:48:18', '2025-12-01 05:13:46', '10,40,90'),
(3, 'Cinepolis Vandana: Rajkot', 'Vandana Heritage 4th and 5th Floor, Opposite Atika Railway Crossing, Gondal Road, Rajkot, Gujarat 360004, India', 'F&B, MTicket, Parking Facility, Food Court', '2025-12-01 12:48:18', '2025-12-01 05:10:58', '20,50,100'),
(4, 'INOX: Reliance Mega Mall, Rajkot', 'INOX Leisure Ltd., 2nd Floor, Reliance Mall, 150 Feet Ring Road, Near Nana Mauva Circle, Rajkot, Gujarat 360005, India', 'Ticket Cancellation, F&B, MTicket', '2025-12-01 12:48:18', '2025-12-01 05:14:06', '30,60,100'),
(5, 'Mehul Cinemax: Jamnagar', '15, Street No.4, Shivam Park, Ajanta Society, Near - Hotel Vishal International, Jamnagar, Gujarat 361006, India', 'Food Court', '2025-12-01 12:48:18', '2025-12-01 05:11:27', '10,50,80'),
(6, 'Rajhans Cinemas: Gandhidham', 'Aditya Mall And Multiplex, DC 2, Gurukul Road, Gandhidham, Gujarat 370201, India', 'F&B, MTicket, Parking Facility, Food Court', '2025-12-01 12:48:18', '2025-12-01 05:14:33', '30,60,120'),
(7, 'City Gold Cinema: Ahmedabad', 'Jio Fashion Factory, B/h, NH228, Shyamal, Nehru Nagar, Ahmedabad, Gujarat, 380015', 'Ticket Cancellation, Food Court', '2025-12-01 12:48:18', '2025-12-01 05:04:18', '20,50,80'),
(8, 'Galaxy Cinema: Rajkot', 'Race Course Ring Road, Next To Police Commissioner Office, Rajkot, Gujarat, 360001', 'Ticket Cancellation, F&B, MTicket, Recliner Seats, Parking Facility, Food Court', '2025-12-01 12:48:18', '2025-12-01 05:14:40', '40,80,130'),
(9, 'Roongta Cinemas, Shyam Mandir Vesu: Surat', '5th Floor, Roongta Cinemas, Roongta Signature, Vesu, Opposite Shyam Baba Mandir, Surat, Gujarat 395007, India', 'Ticket Cancellation, F&B, MTicket, Food Court', '2025-12-01 12:48:18', '2025-12-01 05:11:50', '40,100,150'),
(10, 'Wide Angle: Mehsana', 'Nagalpur Village, Near Khari River Bridge, Mehsana, Gujarat 384002, India', 'Parking Facility, Food Court', '2025-12-01 12:48:18', '2025-12-01 05:12:46', '10,60,110');

-- --------------------------------------------------------

--
-- Table structure for table `movies`
--

CREATE TABLE `movies` (
  `id` int(11) NOT NULL,
  `title` varchar(255) NOT NULL,
  `genre` varchar(100) DEFAULT NULL,
  `duration` varchar(20) NOT NULL,
  `rating` varchar(10) DEFAULT NULL,
  `language` varchar(80) NOT NULL,
  `director` varchar(50) NOT NULL,
  `image_location` varchar(255) NOT NULL,
  `description` text NOT NULL,
  `release_date` varchar(20) NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT current_timestamp(),
  `updated_at` timestamp NULL DEFAULT NULL ON UPDATE current_timestamp(),
  `movie_price` int(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `movies`
--

INSERT INTO `movies` (`id`, `title`, `genre`, `duration`, `rating`, `language`, `director`, `image_location`, `description`, `release_date`, `created_at`, `updated_at`, `movie_price`) VALUES
(1, '12th Fail', 'Drama', '2h 27m', 'U', 'Hindi', 'Vidhu Vinod Chopra', 'images/12th_Fail.jpg', 'Based on Anurag Pathak`s bestselling novel of the same name, 12th Fail depicts the true story of an IPS officer Manoj Kumar Sharma hailing from a small town in Chambal, who fearlessly embraced the idea of restarting his academic journey and reclaiming his destiny at a place where millions of students attempt for the world`s toughest competitive exam, UPSC. The film is not just a chronicle of one man`s journey but a celebration of everyone who dared to look at failures as an opportunity to #Restart.', '3 November 2023', '2024-06-07 11:46:13', '2024-07-03 00:48:24', 100),
(2, 'Animal', 'Action, Crime, Drama', '3h 21m', 'A', 'Hindi', 'Sandeep Reddy Vanga', 'images/Animal.jpg', 'This is the story of a son whose love for his father knows no bounds. As their bond begins to fracture, a chain of extraordinary events unfold causing the son to undergo a remarkable transformation consumed by a thirst for vengeance.', '1 December 2023', '2024-06-07 11:46:13', '2024-07-03 05:05:01', 120),
(3, 'Avatar: The Way of Water', 'Action, Adventure, Fantasy, Sci-Fi', '3h 12m', 'UA', 'English, Hindi', 'James Cameron', 'images/Avatar_The_Way_of_Water.png', 'Set more than a decade after the events of the first film, \"Avatar The Way of Water\" begins to tell the story of the Sully family (Jake, Neytiri and their kids), the trouble that follows them, the lengths they go to keep each other safe, the battles they fight to stay alive and the tragedies they endure.', '16 December 2022', '2024-06-07 11:46:13', '2024-07-03 05:05:25', 200),
(4, 'Avengers: Endgame', 'Action, Adventure, Drama, Sci-Fi', '3h 1m', 'PG-13', 'English, Hindi', 'Anthony RussoJoe Russo', 'images/Avengers_EndGame.jpg', 'The grave course of events set in motion by Thanos that wiped out half the universe and fractured the Avengers ranks compels the remaining Avengers to take one final stand in Marvel Studios` grand conclusion to twenty-two films, \"Avengers: Endgame.\"', '26 April 2019', '2024-06-07 11:46:13', '2024-07-03 05:05:40', 200),
(5, 'Chaal Jeevi Laiye', 'Drama, Comedy', '2h 17m', 'U', 'Gujarati', 'Vipul Mehta', 'images/chaal-jivi_laiye.jpg', 'Aditya Parikh and his father Bipin Chandra Parikh begin to explore the meaning of life as they meet a stranger traveler named Ketki, who takes them on a journey of surprises and realizations that strengthens their bond with every situation that tests their drifting relationship.', '1 February 2019', '2024-06-07 11:46:13', '2024-07-03 05:05:51', 80),
(6, 'Fast X', 'Action, Adventure, Crime, Thriller', '2h 21m', 'PG-13', 'English, Hindi', 'Louis Leterrier', 'images/fast_x.jpg', 'Over many missions and against impossible odds, Dom Toretto and his family have outsmarted and outdriven every foe in their path. Now, they must confront the most lethal opponent they`ve ever faced. Fueled by revenge, a terrifying threat emerges from the shadows of the past to shatter Dom`s world and destroy everything -- and everyone -- he loves.', '18 May, 2023', '2024-06-07 11:46:13', '2024-07-03 05:06:03', 80),
(7, 'Hi Nanna', 'Drama, Family, Romantic', '2h 35m', 'UA', 'Hindi', 'Shouryuv', 'images/Hi_Nanna_2023.jpg', 'A doting father and his six-year-old`s lives alter when a woman befriends them and empathizes with their past.', '7 December 2023', '2024-06-07 11:46:13', '2024-07-03 05:06:21', 90),
(8, 'Interstellar', 'Action, Adventure, Sci-Fi', '2h 49m', 'PG-13', 'English, Hindi', 'Christopher Nolan', 'images/Interstellar_2014.jpg', 'A team of explorers travel beyond this galaxy through a newly discovered wormhole to discover whether mankind has a future among the stars.', '7 November 2014', '2024-06-07 11:46:13', '2024-07-03 05:06:41', 70),
(9, 'IO', 'Romance, Sci-Fi', '1h 36m', 'TV-14', 'English', 'Jonathan Helpert', 'images/io_movie.jpg', 'In a post-apocalyptic time, the earth has been rendered toxic, and most of humanity has abandoned the planet and colonised one of Jupiter`s moons, IO. But young scientist Sam Walden has stayed behind and dedicated herself to finding a way for human beings to survive on Earth. After sending out a radio transmission to see if she can locate anyone else, a man named Micah arrives. He believes there is no hope of survival and intends to take the final shuttle to IO in 48 hours.', '18 January 2019', '2024-06-07 11:46:13', '2024-07-03 05:06:54', 110),
(10, 'Pirates of the Caribbean: Dead Men Tell No Tales', 'Action, Adventure', '2h 9m', 'PG-13', 'English, Hindi', 'Joachim Rønning, Espen Sandberg', 'images/Pirate_of_the_Caribbean_Dead_Men_Tell_No_Tales.webp', 'To break the curse of Flying Dutchman, Captain Jack Sparrow and Henry Turner embark on a mission to find the Trident of Poseidon. They also try to stop Captain Salazar who intends to rule the seas.', '26 May 2017', '2024-06-07 11:46:13', '2024-07-03 05:07:06', 180),
(11, 'Raabta', 'Action, Romantic', '2h 27m', 'UA', 'Hindi', 'James Cameron', 'images/raaabta_2017.jpg', 'When two souls meet, they are united and that connection lasts forever. A seemingly ordinary boy and girl meet and are instantly drawn to each other in an inexplicable way. Shiv is an easy come-easy go Punjabi from Amritsar, Saira is a beautiful, quirky, slightly odd chocolatier, who has strange dreams. When they meet in her chocolate shop in Budapest, there is an electric connection sparked between them. As a beautiful relationship builds and they fall in love with each other, we are lead to see why.', '9 June 2017', '2024-06-07 11:46:13', '2024-07-03 05:07:17', 80),
(12, 'Rampage', 'Action, Adventure', '1h 47m', 'PG-13', 'English, Hindi', 'Brad Peyton', 'images/Rampage.jpg', 'A primatologist teams up with a genetic engineer to stop a gigantic group of animals, including an albino gorilla whom he befriended, after the animals are exposed to an experimental pathogen.', '13 April 2018', '2024-06-07 11:46:13', '2024-07-03 05:07:28', 130),
(13, 'Rebel Moon - Part Two: The Scargiver', 'Action, Adventure, Fantasy, Sci-Fi', '2h 2m', 'PG-13', 'English, Hindi', 'Zack Snyder', 'images/Rebel_Moon_Part_Two_The_Scargiver.webp', 'A colony on the edge of the galaxy fights for survival against a tyrannical ruling force, relying on the efforts of a small group of rebels.', '12 April 2024', '2024-06-07 11:46:13', '2024-07-03 05:07:35', 150),
(14, 'Saiyar Mori Re', 'Drama, Romantic', '2h 45m', 'U', 'Gujarati', 'Vishal Vada Vala', 'images/Saiyar_Mori_Re_2022.png', 'Hari lives at a Gaushala with his bapu and transgender faiba. One fine day, while substituting for an odd job he sees Leela for the first time and instantly falls for her. They gradually fall in love but will it stay forever? What will happen when they separate?', '8 July 2022', '2024-06-07 11:46:13', '2024-07-03 05:07:45', 80),
(15, 'Thugs of Hindostan', 'Action, Adventure', '2h 44m', 'UA', 'Hindi', ' Vijay Krishna Acharya', 'images/Thugs-of-Hindostan.jpg', 'Vijay Krishna Acharya (Victor), the writer-director of the all-time YRF blockbuster Dhoom:3, teams up once again with Aamir Khan in Thugs of Hindostan along with Amitabh Bachchan to give the audience a never seen before experience of larger than life filmmaking! This YRF film holds a double bonanza by bringing together Amitabh Bachchan and Aamir Khan together for the first time ever. That in itself, is film lore in making! The film is set to treat audiences across age groups with the biggest jaw-dropping action sequences seen by audiences on screen to date. With its edge-of-the-seat thrills and an epic adventure and war on the seas, the film is set to light up this Diwali.', '8 November 2018', '2024-06-07 11:46:13', '2024-07-03 05:07:55', 50),
(16, 'Zara Hatke Zara Bachke', 'Comedy, Romance, Drama', '2h 12m', 'UA', 'Hindi', 'Laxman Utekar', 'images/Zara_Hatke_Zara_Bachke.jpg', 'Kapil and Somya are a happily married couple from Indore who live in a joint family and decide to get a divorce one fine day. Things don`t go as planned as their family gets to know of it, and thus begins a comedy of errors.', '2 June 2023', '2024-06-07 11:46:13', '2024-07-03 05:08:06', 80);

-- --------------------------------------------------------

--
-- Table structure for table `seats`
--

CREATE TABLE `seats` (
  `id` int(11) NOT NULL,
  `cinema_id` int(11) NOT NULL,
  `total_seats` int(11) NOT NULL,
  `seat_structure` text DEFAULT NULL,
  `no_seat` text DEFAULT NULL,
  `available_seats` int(11) DEFAULT NULL,
  `booked_seats_name` text DEFAULT NULL,
  `created_at` timestamp NOT NULL DEFAULT current_timestamp(),
  `updated_at` timestamp NULL DEFAULT NULL ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `seats`
--

INSERT INTO `seats` (`id`, `cinema_id`, `total_seats`, `seat_structure`, `no_seat`, `available_seats`, `booked_seats_name`, `created_at`, `updated_at`) VALUES
(1, 10, 176, '[[0], [\'A1\', \'A2\', \'A3\', \'A4\', \'A5\', \'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\', \'A12\', \'A13\', \'A14\', \'A15\', \'A16\', \'A17\', \'A18\', \'A19\', \'A20\', \'A21\', \'A22\', \'A23\', \'A24\', \'A25\'], [\'B1\', \'B2\', \'B3\', \'B4\', \'B5\', \'B6\', \'B7\', \'B8\', \'B9\', \'B10\', \'B11\', \'B12\', \'B13\', \'B14\', \'B15\', \'B16\', \'B17\', \'B18\', \'B19\', \'B20\', \'B21\', \'B22\', \'B23\', \'B24\', \'B25\'], [1],  [\'C1\', \'C2\', \'C3\', \'C4\', \'C5\', \'C6\', \'C7\', \'C8\', \'C9\', \'C10\', \'C11\', \'C12\', \'C13\', \'C14\', \'C15\', \'C16\', \'C17\', \'C18\', \'C19\', \'C20\', \'C21\', \'C22\', \'C23\', \'C24\', \'C25\'], [\'D1\', \'D2\', \'D3\', \'D4\', \'D5\', \'D6\', \'D7\', \'D8\', \'D9\', \'D10\', \'D11\', \'D12\', \'D13\', \'D14\', \'D15\', \'D16\', \'D17\', \'D18\', \'D19\', \'D20\', \'D21\', \'D22\', \'D23\', \'D24\', \'D25\'], [\'E1\', \'E2\', \'E3\', \'E4\', \'E5\', \'E6\', \'E7\', \'E8\', \'E9\', \'E10\', \'E11\', \'E12\', \'E13\', \'E14\', \'E15\', \'E16\', \'E17\', \'E18\', \'E19\', \'E20\', \'E21\', \'E22\', \'E23\', \'E24\', \'E25\'], [2], [\'F1\', \'F2\', \'F3\', \'F4\', \'F5\', \'F6\', \'F7\', \'F8\', \'F9\', \'F10\', \'F11\', \'F12\', \'F13\', \'F14\', \'F15\', \'F16\', \'F17\', \'F18\', \'F19\', \'F20\', \'F21\', \'F22\', \'F23\', \'F24\', \'F25\'], [\'G1\', \'G2\', \'G3\', \'G4\', \'G5\', \'G6\', \'G7\', \'G8\', \'G9\', \'G10\', \'G11\', \'G12\', \'G13\', \'G14\', \'G15\', \'G16\', \'G17\', \'G18\', \'G19\', \'G20\', \'G21\', \'G22\', \'G23\', \'G24\', \'G25\'], [\'H1\', \'H2\', \'H3\', \'H4\', \'H5\', \'H6\', \'H7\', \'H8\', \'H9\', \'H10\', \'H11\', \'H12\', \'H13\', \'H14\', \'H15\', \'H16\', \'H17\', \'H18\', \'H19\', \'H20\', \'H21\', \'H22\', \'H23\', \'H24\', \'H25\'], [\'I1\', \'I2\', \'I3\', \'I4\', \'I5\', \'I6\', \'I7\', \'I8\', \'I9\', \'I10\', \'I11\', \'I12\', \'I13\', \'I14\', \'I15\', \'I16\', \'I17\', \'I18\', \'I19\', \'I20\', \'I21\', \'I22\', \'I23\', \'I24\', \'I25\']]', '[\'A1\', \'A2\', \'A3\', \'A13\', \'A23\', \'A24\', \'A25\', \'B1\', \'B2\', \'B3\', \'B13\', \'B23\', \'B24\', \'B25\', \'C1\', \'C2\', \'C13\', \'C24\', \'C25\', \'D1\', \'D2\', \'D13\', \'D24\', \'D25\', \'E1\', \'E2\', \'E13\', \'E24\', \'E25\', \'F1\', \'F7\', \'F13\', \'F19\', \'F25\', \'G1\', \'G7\', \'G13\', \'G19\', \'G25\', \'H1\', \'H7\', \'H13\', \'H19\', \'H25\', \'I1\', \'I7\', \'I13\', \'I19\', \'I25\']', 151, 'I20, F14, B17, B16, I4, I5, A11, A12, C4, E14, E15, G10, G11, G15, H16, H22, H23, J10, J11, D12, D14, D15, D16, F8, F9', '2025-12-03 12:34:33', NULL),
(2, 9, 120, '[[0], [\'A1\', \'A2\', \'A3\', \'A4\', \'A5\', \'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\', \'A12\', \'A13\'], [\'B1\', \'B2\', \'B3\', \'B4\', \'B5\', \'B6\', \'B7\', \'B8\', \'B9\', \'B10\', \'B11\', \'B12\', \'B13\'], [\'C1\', \'C2\', \'C3\', \'C4\', \'C5\', \'C6\', \'C7\', \'C8\', \'C9\', \'C10\', \'C11\', \'C12\', \'C13\'], [1], [\'D1\', \'D2\', \'D3\', \'D4\', \'D5\', \'D6\', \'D7\', \'D8\', \'D9\', \'D10\', \'D11\', \'D12\', \'D13\'], [\'E1\', \'E2\', \'E3\', \'E4\', \'E5\', \'E6\', \'E7\', \'E8\', \'E9\', \'E10\', \'E11\', \'E12\', \'E13\'], [\'F1\', \'F2\', \'F3\', \'F4\', \'F5\', \'F6\', \'F7\', \'F8\', \'F9\', \'F10\', \'F11\', \'F12\', \'F13\'], [\'G1\', \'G2\', \'G3\', \'G4\', \'G5\', \'G6\', \'G7\', \'G8\', \'G9\', \'G10\', \'G11\', \'G12\', \'G13\'], [\'H1\', \'H2\', \'H3\', \'H4\', \'H5\', \'H6\', \'H7\', \'H8\', \'H9\', \'H10\', \'H11\', \'H12\', \'H13\'], [2], [\'I1\', \'I2\', \'I3\', \'I4\', \'I5\', \'I6\', \'I7\', \'I8\', \'I9\', \'I10\', \'I11\', \'I12\', \'I13\'], [\'J1\', \'J2\', \'J3\', \'J4\', \'J5\', \'J6\', \'J7\', \'J8\', \'J9\', \'J10\', \'J11\', \'J12\', \'J13\']]', '[\'A7\', \'B7\', \'C7\', \'D7\', \'E7\', \'F7\', \'G7\', \'H7\', \'I7\', \'J7\']', 100, 'H13, J10, J11, C3, C5, C8, J9, J8, I6, I4, I5, G1, G2, B10, B11, D8, D9, D10, F6, F6', '2025-12-03 12:34:33', '2025-12-05 09:15:21'),
(3, 8, 80, '[[0], [\'A1\', \'A2\', \'A3\', \'A4\', \'A5\', \'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\', \'A12\'], [\'B1\', \'B2\', \'B3\', \'B4\', \'B5\', \'B6\', \'B7\', \'B8\', \'B9\', \'B10\', \'B11\', \'B12\'], [\'C1\', \'C2\', \'C3\', \'C4\', \'C5\', \'C6\', \'C7\', \'C8\', \'C9\', \'C10\', \'C11\', \'C12\'], [1], [\'D1\', \'D2\', \'D3\', \'D4\', \'D5\', \'D6\', \'D7\', \'D8\', \'D9\', \'D10\', \'D11\', \'D12\'], [\'E1\', \'E2\', \'E3\', \'E4\', \'E5\', \'E6\', \'E7\', \'E8\', \'E9\', \'E10\', \'E11\', \'E12\'], [\'F1\', \'F2\', \'F3\', \'F4\', \'F5\', \'F6\', \'F7\', \'F8\', \'F9\', \'F10\', \'F11\', \'F12\'], [2], [\'G1\', \'G2\', \'G3\', \'G4\', \'G5\', \'G6\', \'G7\', \'G8\', \'G9\', \'G10\', \'G11\', \'G12\'], [\'H1\', \'H2\', \'H3\', \'H4\', \'H5\', \'H6\', \'H7\', \'H8\', \'H9\', \'H10\', \'H11\', \'H12\']]', '[\'A6\', \'A7\', \'B6\', \'B7\', \'C6\', \'C7\', \'D6\', \'D7\', \'E6\', \'E7\', \'F6\', \'F7\', \'G6\', \'G7\', \'H6\', \'H7\']', 67, 'C8, C9, C10, H5, F8, G8, G9, F4, F3, F2, E9, E10, E5, E4', '2025-12-03 12:34:33', '2025-12-05 09:44:46'),
(4, 7, 142, '[[0], [\'A1\', \'A2\', \'A3\', \'A4\', \'A5\', \'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\', \'A12\', \'A13\', \'A14\', \'A15\', \'A16\'], [\'B1\', \'B2\', \'B3\', \'B4\', \'B5\', \'B6\', \'B7\', \'B8\', \'B9\', \'B10\', \'B11\', \'B12\', \'B13\', \'B14\', \'B15\', \'B16\'], [\'C1\', \'C2\', \'C3\', \'C4\', \'C5\', \'C6\', \'C7\', \'C8\', \'C9\', \'C10\', \'C11\', \'C12\', \'C13\', \'C14\', \'C15\', \'C16\'], [1], [\'D1\', \'D2\', \'D3\', \'D4\', \'D5\', \'D6\', \'D7\', \'D8\', \'D9\', \'D10\', \'D11\', \'D12\', \'D13\', \'D14\', \'D15\', \'D16\'], [\'E1\', \'E2\', \'E3\', \'E4\', \'E5\', \'E6\', \'E7\', \'E8\', \'E9\', \'E10\', \'E11\', \'E12\', \'E13\', \'E14\', \'E15\', \'E16\'], [\'F1\', \'F2\', \'F3\', \'F4\', \'F5\', \'F6\', \'F7\', \'F8\', \'F9\', \'F10\', \'F11\', \'F12\', \'F13\', \'F14\', \'F15\', \'F16\'], [\'G1\', \'G2\', \'G3\', \'G4\', \'G5\', \'G6\', \'G7\', \'G8\', \'G9\', \'G10\', \'G11\', \'G12\', \'G13\', \'G14\', \'G15\', \'G16\'], [2], [\'H1\', \'H2\', \'H3\', \'H4\', \'H5\', \'H6\', \'H7\', \'H8\', \'H9\', \'H10\', \'H11\', \'H12\', \'H13\', \'H14\', \'H15\', \'H16\'], [\'I1\', \'I2\', \'I3\', \'I4\', \'I5\', \'I6\', \'I7\', \'I8\', \'I9\', \'I10\', \'I11\', \'I12\', \'I13\', \'I14\', \'I15\', \'I16\'], [\'J1\', \'J2\', \'J3\', \'J4\', \'J5\', \'J6\', \'J7\', \'J8\', \'J9\', \'J10\', \'J11\', \'J12\', \'J13\', \'J14\', \'J15\', \'J16\']]', '[\'A8\', \'A9\', \'B8\', \'B9\', \'C8\', \'C9\', \'D8\', \'D9\', \'E8\', \'E9\', \'F8\', \'F9\', \'G8\', \'G9\', \'H8\', \'H9\', \'I8\', \'I9\']', 137, 'H7, H10, H11, J8, J9', '2025-12-03 12:17:40', NULL),
(5, 6, 144, '[[0], [\'A1\', \'A2\', \'A3\', \'A4\', \'A5\', \'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\', \'A12\', \'A13\', \'A14\', \'A15\', \'A16\', \'A17\', \'A18\'], [\'B1\', \'B2\', \'B3\', \'B4\', \'B5\', \'B6\', \'B7\', \'B8\', \'B9\', \'B10\', \'B11\', \'B12\', \'B13\', \'B14\', \'B15\', \'B16\', \'B17\', \'B18\'], [\'C1\', \'C2\', \'C3\', \'C4\', \'C5\', \'C6\', \'C7\', \'C8\', \'C9\', \'C10\', \'C11\', \'C12\', \'C13\', \'C14\', \'C15\', \'C16\', \'C17\', \'C18\'], [\'D1\', \'D2\', \'D3\', \'D4\', \'D5\', \'D6\', \'D7\', \'D8\', \'D9\', \'D10\', \'D11\', \'D12\', \'D13\', \'D14\', \'D15\', \'D16\', \'D17\', \'D18\'], [1], [\'E1\', \'E2\', \'E3\', \'E4\', \'E5\', \'E6\', \'E7\', \'E8\', \'E9\', \'E10\', \'E11\', \'E12\', \'E13\', \'E14\', \'E15\', \'E16\', \'E17\', \'E18\'], [\'F1\', \'F2\', \'F3\', \'F4\', \'F5\', \'F6\', \'F7\', \'F8\', \'F9\', \'F10\', \'F11\', \'F12\', \'F13\', \'F14\', \'F15\', \'F16\', \'F17\', \'F18\'], [\'G1\', \'G2\', \'G3\', \'G4\', \'G5\', \'G6\', \'G7\', \'G8\', \'G9\', \'G10\', \'G11\', \'G12\', \'G13\', \'G14\', \'G15\', \'G16\', \'G17\', \'G18\'], [\'H1\', \'H2\', \'H3\', \'H4\', \'H5\', \'H6\', \'H7\', \'H8\', \'H9\', \'H10\', \'H11\', \'H12\', \'H13\', \'H14\', \'H15\', \'H16\', \'H17\', \'H18\'], [2], [\'I1\', \'I2\', \'I3\', \'I4\', \'I5\', \'I6\', \'I7\', \'I8\', \'I9\', \'I10\', \'I11\', \'I12\', \'I13\', \'I14\', \'I15\', \'I16\', \'I17\', \'I18\'], [\'J1\', \'J2\', \'J3\', \'J4\', \'J5\', \'J6\', \'J7\', \'J8\', \'J9\', \'J10\', \'J11\', \'J12\', \'J13\', \'J14\', \'J15\', \'J16\', \'J17\', \'J18\'], [\'K1\', \'K2\', \'K3\', \'K4\', \'K5\', \'K6\', \'K7\', \'K8\', \'K9\', \'K10\', \'K11\', \'K12\', \'K13\', \'K14\', \'K15\', \'K16\', \'K17\', \'K18\']]', '[\'A1\', \'A2\', \'A3\', \'A9\', \'A10\', \'A16\', \'A17\', \'A18\', \'B1\', \'B2\', \'B3\', \'B9\', \'B10\', \'B16\', \'B17\', \'B18\', \'C1\', \'C2\', \'C3\', \'C9\', \'C10\', \'C16\', \'C17\', \'C18\', \'D1\', \'D2\', \'D3\', \'D9\', \'D10\', \'D16\', \'D17\', \'D18\', \'E1\', \'E6\', \'E13\', \'E18\', \'F1\', \'F6\', \'F13\', \'F18\', \'G1\', \'G6\', \'G13\', \'G18\', \'H1\', \'H6\', \'H13\', \'H18\', \'I6\', \'I13\', \'J6\', \'J13\', \'K6\', \'K13\']', 135, 'I7, I8, I9, H9, H10, I4, I5, K10, K11', '2025-12-03 12:37:34', NULL),
(6, 5, 280, '[[0], [\'A1\', \'A2\', \'A3\', \'A4\', \'A5\', \'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\', \'A12\', \'A13\', \'A14\', \'A15\', \'A16\', \'A17\', \'A18\', \'A19\', \'A20\', \'A21\', \'A22\', \'A23\', \'A24\'], [\'B1\', \'B2\', \'B3\', \'B4\', \'B5\', \'B6\', \'B7\', \'B8\', \'B9\', \'B10\', \'B11\', \'B12\', \'B13\', \'B14\', \'B15\', \'B16\', \'B17\', \'B18\', \'B19\', \'B20\', \'B21\', \'B22\', \'B23\', \'B24\'], [\'C1\', \'C2\', \'C3\', \'C4\', \'C5\', \'C6\', \'C7\', \'C8\', \'C9\', \'C10\', \'C11\', \'C12\', \'C13\', \'C14\', \'C15\', \'C16\', \'C17\', \'C18\', \'C19\', \'C20\', \'C21\', \'C22\', \'C23\', \'C24\'], [\'D1\', \'D2\', \'D3\', \'D4\', \'D5\', \'D6\', \'D7\', \'D8\', \'D9\', \'D10\', \'D11\', \'D12\', \'D13\', \'D14\', \'D15\', \'D16\', \'D17\', \'D18\', \'D19\', \'D20\', \'D21\', \'D22\', \'D23\', \'D24\'], [\'E1\', \'E2\', \'E3\', \'E4\', \'E5\', \'E6\', \'E7\', \'E8\', \'E9\', \'E10\', \'E11\', \'E12\', \'E13\', \'E14\', \'E15\', \'E16\', \'E17\', \'E18\', \'E19\', \'E20\', \'E21\', \'E22\', \'E23\', \'E24\'], [1], [\'F1\', \'F2\', \'F3\', \'F4\', \'F5\', \'F6\', \'F7\', \'F8\', \'F9\', \'F10\', \'F11\', \'F12\', \'F13\', \'F14\', \'F15\', \'F16\', \'F17\', \'F18\', \'F19\', \'F20\', \'F21\', \'F22\', \'F23\', \'F24\'], [\'G1\', \'G2\', \'G3\', \'G4\', \'G5\', \'G6\', \'G7\', \'G8\', \'G9\', \'G10\', \'G11\', \'G12\', \'G13\', \'G14\', \'G15\', \'G16\', \'G17\', \'G18\', \'G19\', \'G20\', \'G21\', \'G22\', \'G23\', \'G24\'], [\'H1\', \'H2\', \'H3\', \'H4\', \'H5\', \'H6\', \'H7\', \'H8\', \'H9\', \'H10\', \'H11\', \'H12\', \'H13\', \'H14\', \'H15\', \'H16\', \'H17\', \'H18\', \'H19\', \'H20\', \'H21\', \'H22\', \'H23\', \'H24\'], [\'I1\', \'I2\', \'I3\', \'I4\', \'I5\', \'I6\', \'I7\', \'I8\', \'I9\', \'I10\', \'I11\', \'I12\', \'I13\', \'I14\', \'I15\', \'I16\', \'I17\', \'I18\', \'I19\', \'I20\', \'I21\', \'I22\', \'I23\', \'I24\'], [\'J1\', \'J2\', \'J3\', \'J4\', \'J5\', \'J6\', \'J7\', \'J8\', \'J9\', \'J10\', \'J11\', \'J12\', \'J13\', \'J14\', \'J15\', \'J16\', \'J17\', \'J18\', \'J19\', \'J20\', \'J21\', \'J22\', \'J23\', \'J24\'], [2], [\'K1\', \'K2\', \'K3\', \'K4\', \'K5\', \'K6\', \'K7\', \'K8\', \'K9\', \'K10\', \'K11\', \'K12\', \'K13\', \'K14\', \'K15\', \'K16\', \'K17\', \'K18\', \'K19\', \'K20\', \'K21\', \'K22\', \'K23\', \'K24\'], [\'L1\', \'L2\', \'L3\', \'L4\', \'L5\', \'L6\', \'L7\', \'L8\', \'L9\', \'L10\', \'L11\', \'L12\', \'L13\', \'L14\', \'L15\', \'L16\', \'L17\', \'L18\', \'L19\', \'L20\', \'L21\', \'L22\', \'L23\', \'L24\'], [\'M1\', \'M2\', \'M3\', \'M4\', \'M5\', \'M6\', \'M7\', \'M8\', \'M9\', \'M10\', \'M11\', \'M12\', \'M13\', \'M14\', \'M15\', \'M16\', \'M17\', \'M18\', \'M19\', \'M20\', \'M21\', \'M22\', \'M23\', \'M24\'], [\'N1\', \'N2\', \'N3\', \'N4\', \'N5\', \'N6\', \'N7\', \'N8\', \'N9\', \'N10\', \'N11\', \'N12\', \'N13\', \'N14\', \'N15\', \'N16\', \'N17\', \'N18\', \'N19\', \'N20\', \'N21\', \'N22\', \'N23\', \'N24\'], [\'O1\', \'O2\', \'O3\', \'O4\', \'O5\', \'O6\', \'O7\', \'O8\', \'O9\', \'O10\', \'O11\', \'O12\', \'O13\', \'O14\', \'O15\', \'O16\', \'O17\', \'O18\', \'O19\', \'O20\', \'O21\', \'O22\', \'O23\', \'O24\']]', '[\'A6\', \'A7\', \'A16\', \'A17\', \'B6\', \'B7\', \'B16\', \'B17\', \'C6\', \'C7\', \'C16\', \'C17\', \'D6\', \'D7\', \'D16\', \'D17\', \'E6\', \'E7\', \'E16\', \'E17\', \'E21\', \'E22\', \'E23\', \'E24\', \'F6\', \'F7\', \'F16\', \'F17\', \'F21\', \'F22\', \'F23\', \'F24\', \'G6\', \'G7\', \'G16\', \'G17\', \'G21\', \'G22\', \'G23\', \'G24\', \'H6\', \'H7\', \'H16\', \'H17\', \'H21\', \'H22\', \'H23\', \'H24\', \'I6\', \'I7\', \'I16\', \'I17\', \'I21\', \'I22\', \'I23\', \'I24\', \'J6\', \'J7\', \'J16\', \'J17\', \'K6\', \'K7\', \'K16\', \'K17\', \'L6\', \'L7\', \'L16\', \'L17\', \'M6\', \'M7\', \'M16\', \'M17\', \'N6\', \'N7\', \'N16\', \'N17\', \'O6\', \'O7\', \'O16\', \'O17\']', 272, 'I9, I10, I11, I12, I13, I14, K11, K12', '2025-12-03 12:48:37', NULL),
(7, 4, 132, '[[0], [\'A1\', \'A2\', \'A3\', \'A4\', \'A5\', \'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\', \'A12\', \'A13\'], [\'B1\', \'B2\', \'B3\', \'B4\', \'B5\', \'B6\', \'B7\', \'B8\', \'B9\', \'B10\', \'B11\', \'B12\', \'B13\'], [\'C1\', \'C2\', \'C3\', \'C4\', \'C5\', \'C6\', \'C7\', \'C8\', \'C9\', \'C10\', \'C11\', \'C12\', \'C13\'], [\'D1\', \'D2\', \'D3\', \'D4\', \'D5\', \'D6\', \'D7\', \'D8\', \'D9\', \'D10\', \'D11\', \'D12\', \'D13\'], [\'E1\', \'E2\', \'E3\', \'E4\', \'E5\', \'E6\', \'E7\', \'E8\', \'E9\', \'E10\', \'E11\', \'E12\', \'E13\'],[1], [\'F1\', \'F2\', \'F3\', \'F4\', \'F5\', \'F6\', \'F7\', \'F8\', \'F9\', \'F10\', \'F11\', \'F12\', \'F13\'], [\'G1\', \'G2\', \'G3\', \'G4\', \'G5\', \'G6\', \'G7\', \'G8\', \'G9\', \'G10\', \'G11\', \'G12\', \'G13\'], [\'H1\', \'H2\', \'H3\', \'H4\', \'H5\', \'H6\', \'H7\', \'H8\', \'H9\', \'H10\', \'H11\', \'H12\', \'H13\'], [\'I1\', \'I2\', \'I3\', \'I4\', \'I5\', \'I6\', \'I7\', \'I8\', \'I9\', \'I10\', \'I11\', \'I12\', \'I13\'],[2], [\'J1\', \'J2\', \'J3\', \'J4\', \'J5\', \'J6\', \'J7\', \'J8\', \'J9\', \'J10\', \'J11\', \'J12\', \'J13\'], [\'K1\', \'K2\', \'K3\', \'K4\', \'K5\', \'K6\', \'K7\', \'K8\', \'K9\', \'K10\', \'K11\', \'K12\', \'K13\']]', '[\'A7\', \'B7\', \'C7\', \'D7\', \'E7\', \'F7\', \'G7\', \'H7\', \'I7\', \'J7\', \'K7\']', 121, 'J5, J6, E5, F6, J8, J9, J10, J11, F8, F9, F10', '2025-12-03 12:56:01', '2025-12-04 21:50:44'),
(8, 3, 126, '[[0], [\'A1\', \'A2\', \'A3\', \'A4\', \'A5\', \'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\', \'A12\', \'A13\', \'A14\', \'A15\', \'A16\', \'A17\', \'A18\'], [\'B1\', \'B2\', \'B3\', \'B4\', \'B5\', \'B6\', \'B7\', \'B8\', \'B9\', \'B10\', \'B11\', \'B12\', \'B13\', \'B14\', \'B15\', \'B16\', \'B17\', \'B18\'], [\'C1\', \'C2\', \'C3\', \'C4\', \'C5\', \'C6\', \'C7\', \'C8\', \'C9\', \'C10\', \'C11\', \'C12\', \'C13\', \'C14\', \'C15\', \'C16\', \'C17\', \'C18\'], [1], [\'D1\', \'D2\', \'D3\', \'D4\', \'D5\', \'D6\', \'D7\', \'D8\', \'D9\', \'D10\', \'D11\', \'D12\', \'D13\', \'D14\', \'D15\', \'D16\', \'D17\', \'D18\'], [\'E1\', \'E2\', \'E3\', \'E4\', \'E5\', \'E6\', \'E7\', \'E8\', \'E9\', \'E10\', \'E11\', \'E12\', \'E13\', \'E14\', \'E15\', \'E16\', \'E17\', \'E18\'], [\'F1\', \'F2\', \'F3\', \'F4\', \'F5\', \'F6\', \'F7\', \'F8\', \'F9\', \'F10\', \'F11\', \'F12\', \'F13\', \'F14\', \'F15\', \'F16\', \'F17\', \'F18\'], [2], [\'G1\', \'G2\', \'G3\', \'G4\', \'G5\', \'G6\', \'G7\', \'G8\', \'G9\', \'G10\', \'G11\', \'G12\', \'G13\', \'G14\', \'G15\', \'G16\', \'G17\', \'G18\'], [\'H1\', \'H2\', \'H3\', \'H4\', \'H5\', \'H6\', \'H7\', \'H8\', \'H9\', \'H10\', \'H11\', \'H12\', \'H13\', \'H14\', \'H15\', \'H16\', \'H17\', \'H18\'], [\'I1\', \'I2\', \'I3\', \'I4\', \'I5\', \'I6\', \'I7\', \'I8\', \'I9\', \'I10\', \'I11\', \'I12\', \'I13\', \'I14\', \'I15\', \'I16\', \'I17\', \'I18\']]', '[\'A1\', \'A2\', \'A9\', \'A10\', \'A17\', \'A18\', \'B1\', \'B2\', \'B9\', \'B10\', \'B17\', \'B18\', \'C1\', \'C2\', \'C9\', \'C10\', \'C17\', \'C18\', \'D1\', \'D9\', \'D10\', \'D18\', \'E1\', \'E9\', \'E10\', \'E18\', \'F1\', \'F9\', \'F10\', \'F18\', \'G9\', \'G10\', \'H9\', \'H10\', \'I9\', \'I10\']', 119, 'C7, C8, F13, F14, H5, H6, H12', '2025-12-03 13:03:53', NULL),
(9, 2, 62, '[[0], [\'A1\', \'A2\', \'A3\', \'A4\', \'A5\', \'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\', \'A12\', \'A13\'], [\'B1\', \'B2\', \'B3\', \'B4\', \'B5\', \'B6\', \'B7\', \'B8\', \'B9\', \'B10\', \'B11\', \'B12\', \'B13\'], [\'C1\', \'C2\', \'C3\', \'C4\', \'C5\', \'C6\', \'C7\', \'C8\', \'C9\', \'C10\', \'C11\', \'C12\', \'C13\'], [1], [\'D1\', \'D2\', \'D3\', \'D4\', \'D5\', \'D6\', \'D7\', \'D8\', \'D9\', \'D10\', \'D11\', \'D12\', \'D13\'], [\'E1\', \'E2\', \'E3\', \'E4\', \'E5\', \'E6\', \'E7\', \'E8\', \'E9\', \'E10\', \'E11\', \'E12\', \'E13\'], [2], [\'F1\', \'F2\', \'F3\', \'F4\', \'F5\', \'F6\', \'F7\', \'F8\', \'F9\', \'F10\', \'F11\', \'F12\', \'F13\']]', '[\'A12\', \'A13\', \'B7\', \'B8\', \'B12\', \'B13\', \'C7\', \'C8\', \'C12\', \'C13\', \'D7\', \'D8\', \'D12\', \'D13\', \'E7\', \'E8\']', 52, 'D11, E9, E10, E11, F10, F11, F12, D9, D10, F9', '2025-12-03 13:09:25', NULL),
(10, 1, 70, '[[0], [\'A1\', \'A2\', \'A3\', \'A4\', \'A5\', \'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\'], [\'B1\', \'B2\', \'B3\', \'B4\', \'B5\', \'B6\', \'B7\', \'B8\', \'B9\', \'B10\', \'B11\'], [\'C1\', \'C2\', \'C3\', \'C4\', \'C5\', \'C6\', \'C7\', \'C8\', \'C9\', \'C10\', \'C11\'], [1], [\'D1\', \'D2\', \'D3\', \'D4\', \'D5\', \'D6\', \'D7\', \'D8\', \'D9\', \'D10\', \'D11\'], [\'E1\', \'E2\', \'E3\', \'E4\', \'E5\', \'E6\', \'E7\', \'E8\', \'E9\', \'E10\', \'E11\'], [\'F1\', \'F2\', \'F3\', \'F4\', \'F5\', \'F6\', \'F7\', \'F8\', \'F9\', \'F10\', \'F11\'], [2], [\'G1\', \'G2\', \'G3\', \'G4\', \'G5\', \'G6\', \'G7\', \'G8\', \'G9\', \'G10\', \'G11\'], [\'H1\', \'H2\', \'H3\', \'H4\', \'H5\', \'H6\', \'H7\', \'H8\', \'H9\', \'H10\', \'H11\']]', '[\'A6\', \'A7\', \'A8\', \'A9\', \'A10\', \'A11\', \'B6\', \'B7\', \'C6\', \'C7\', \'D6\', \'D7\', \'E6\', \'E7\', \'F6\', \'F7\', \'G6\', \'G7\']', 66, 'H6, H7, E5, E4', '2025-12-03 13:13:16', '2025-12-04 21:54:14');

-- --------------------------------------------------------

--
-- Table structure for table `times`
--

CREATE TABLE `times` (
  `id` int(11) NOT NULL,
  `cinema_id` int(11) NOT NULL,
  `show_time` text NOT NULL,
  `show_date` text NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT current_timestamp(),
  `updated_at` timestamp NULL DEFAULT NULL ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `times`
--

INSERT INTO `times` (`id`, `cinema_id`, `show_time`, `show_date`, `created_at`, `updated_at`) VALUES
(1, 1, '9:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(2, 1, '12:00 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(3, 1, '3:30 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(4, 1, '10:30 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(5, 1, '10:00 AM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(6, 1, '4:30 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(7, 1, '8:00 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(8, 1, '10:30 AM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(9, 1, '7:30 PM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(10, 2, '9:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(11, 2, '12:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(12, 2, '10:30 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(13, 2, '10:00 AM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(14, 2, '4:30 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(15, 2, '8:00 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(16, 2, '10:30 AM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(17, 2, '7:30 PM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(18, 3, '9:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(19, 3, '12:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(20, 3, '3:30 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(21, 3, '7:00 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(22, 3, '10:30 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(23, 3, '10:00 AM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(24, 3, '8:00 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(25, 3, '10:30 AM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(26, 4, '9:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(27, 4, '12:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(28, 4, '10:30 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(29, 4, '10:00 AM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(30, 4, '1:30 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(31, 4, '8:00 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(32, 4, '10:30 AM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(33, 4, '4:00 PM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(34, 4, '7:30 PM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(35, 5, '9:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(36, 5, '10:00 AM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(37, 5, '4:30 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(38, 5, '10:30 AM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(39, 6, '9:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(40, 6, '12:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(41, 6, '3:30 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(42, 6, '10:30 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(43, 6, '10:00 AM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(44, 6, '4:30 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(45, 6, '8:00 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(46, 6, '10:30 AM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(47, 6, '7:30 PM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(48, 7, '9:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(49, 7, '7:00 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(50, 7, '10:00 AM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(51, 7, '4:30 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(52, 7, '10:30 AM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(53, 7, '7:30 PM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(54, 8, '9:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(55, 8, '12:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(56, 8, '3:30 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(57, 8, '7:00 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(58, 8, '10:30 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(59, 8, '10:00 AM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(60, 8, '1:30 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(61, 8, '4:30 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(62, 8, '8:00 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(63, 8, '10:30 AM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(64, 8, '4:00 PM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(65, 8, '7:30 PM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(66, 9, '9:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(67, 9, '4:30 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(68, 9, '7:30 PM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(69, 10, '9:00 AM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(70, 10, '7:00 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(71, 10, '10:30 PM', '2025-12-01', '2025-12-04 12:48:18', NULL),
(72, 10, '10:00 AM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(73, 10, '4:30 PM', '2025-12-02', '2025-12-04 12:48:18', NULL),
(74, 10, '10:30 AM', '2025-12-03', '2025-12-04 12:48:18', NULL),
(75, 10, '7:30 PM', '2025-12-03', '2025-12-04 12:48:18', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `mobile_number` varchar(15) NOT NULL,
  `date` timestamp NOT NULL DEFAULT current_timestamp(),
  `modify_date` timestamp NULL DEFAULT NULL ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `name`, `email`, `password`, `mobile_number`, `date`, `modify_date`) VALUES
(1, 'vishal', 'vishal@gmail.com', '$2b$10$ZeWSeHNk/sm.3/WyFOXhd.hOV6SrGi7x1dflBkBrI2ZvVsb3mwtW6', '8320343610', '2025-12-02 14:59:25', NULL),
(2, 'vishal2', 'vishal2@gmail.com', '$2b$10$q37GE5V/5PoCJ...GgEHlugnYH73jZeLYUz2IVJuSgFqfNeTQA8Ry', '8320343610', '2025-12-02 14:59:58', NULL),
(3, 'vishal3', 'vishal3@gmail.com', '$2b$10$upj8xdKbN/Fa1QSC082ZEuWc51RCKl6noQfcIr6KQj2p1/Ocehfd6', '876543210', '2025-12-04 21:52:24', NULL),
(4, 'Nitin', 'nitin@gmail.com', '$2b$10$a9SY7/gg3DAa8OD/JJ1Uve9PlP6.C.gdxmPhpjkpw2xfA3mlvrbE.', '1234512345', '2025-12-05 09:57:07', NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `bookings`
--
ALTER TABLE `bookings`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_user_id` (`user_id`);

--
-- Indexes for table `cinema`
--
ALTER TABLE `cinema`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `seats`
--
ALTER TABLE `seats`
  ADD PRIMARY KEY (`id`),
  ADD KEY `cinema_id` (`cinema_id`);

--
-- Indexes for table `times`
--
ALTER TABLE `times`
  ADD PRIMARY KEY (`id`),
  ADD KEY `cinema_id` (`cinema_id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `bookings`
--
ALTER TABLE `bookings`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `seats`
--
ALTER TABLE `seats`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `bookings`
--
ALTER TABLE `bookings`
  ADD CONSTRAINT `fk_user_id` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

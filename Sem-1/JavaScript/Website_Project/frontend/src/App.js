import './App.css';
import { BrowserRouter, Routes, Route } from "react-router-dom";
import Home from "./component/Home";
import Register from "./component/authComponent/Register";
import Login from "./component/authComponent/Login";
import About from './component/About';
import ForgotPassword from './component/ForgotPassword';
import Movie from './component/Movie';
import MovieInfo from './component/MovieInfo';
import DateAndCinema from './component/DateAndCinema';
import SeatLayoutSelection from './component/SeatLayoutSelection';
import Payment from './component/Payment';
import Contact from './component/Contact';
import TicketLayout from './component/TicketLayout';


function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home />}>
          <Route index element={<Movie />} /> {/* Default content for / , no path only index*/}
          {/* ❗ Child routes MUST NOT have leading slash */}
          <Route path="Register" element={<Register />} />
          <Route path="Login" element={<Login />} />
          <Route path="Contact" element={<Contact />} />
          <Route path="About" element={<About />} />
          <Route path="ForgotPassword" element={<ForgotPassword />} />
          <Route path="MovieInfo" element={<MovieInfo />} />
          <Route path="Date_Cinema" element={<DateAndCinema />} />
          <Route path="SeatLayoutAndSelection" element={<SeatLayoutSelection />} />
          <Route path="Payment" element={<Payment />} />
          <Route path="Ticket" element={<TicketLayout />} />
        </Route>

      </Routes>
    </BrowserRouter >
  );
}

export default App;














// import React from 'react';
// import { BrowserRouter, Routes, Route, Link, Outlet, useLocation } from 'react-router-dom';

// // --- Level 3 Components (The Deepest Content) ---
// const StatsComponent = () => (
//   <div className="bg-green-50 p-6 rounded-lg border-2 border-green-200">
//     <h3 className="text-xl font-bold text-green-800 flex items-center gap-2">
//       <span>📊</span> Statistics View
//     </h3>
//     <p className="mt-2 text-gray-600">
//       This component is rendered inside the <strong>second</strong> nested Outlet.
//     </p>
//     <div className="mt-4 grid grid-cols-3 gap-4">
//       <div className="bg-white p-4 rounded shadow text-center">Active: 45</div>
//       <div className="bg-white p-4 rounded shadow text-center">Pending: 12</div>
//       <div className="bg-white p-4 rounded shadow text-center">Sold: 89</div>
//     </div>
//   </div>
// );

// const SettingsComponent = () => (
//   <div className="bg-purple-50 p-6 rounded-lg border-2 border-purple-200">
//     <h3 className="text-xl font-bold text-purple-800 flex items-center gap-2">
//       <span>⚙️</span> Settings View
//     </h3>
//     <p className="mt-2 text-gray-600">
//       This is a sibling to Stats, also rendered in the <strong>second</strong> Outlet.
//     </p>
//     <div className="mt-4 space-y-2">
//       <label className="flex items-center space-x-2">
//         <input type="checkbox" checked readOnly className="rounded" />
//         <span>Enable Notifications</span>
//       </label>
//       <label className="flex items-center space-x-2">
//         <input type="checkbox" className="rounded" />
//         <span>Dark Mode</span>
//       </label>
//     </div>
//   </div>
// );

// // --- Level 2 Component (The "Outlet inside Outlet" Parent) ---
// // This component acts as a layout for the "/dashboard" section
// const DashboardLayout = () => {
//   return (
//     <div className="border-2 border-blue-400 p-4 rounded-lg bg-white h-full">
//       <div className="mb-4 pb-4 border-b border-gray-200">
//         <h2 className="text-xl font-bold text-blue-700 mb-2">Level 2: Dashboard Layout</h2>
//         <p className="text-sm text-gray-500 mb-4">
//           This component contains the <strong>Second Outlet</strong>. Clicking buttons below switches content inside the blue box.
//         </p>

//         {/* Navigation for the Nested Outlet */}
//         <div className="flex gap-4">
//           <Link
//             to="stats"
//             className="px-4 py-2 bg-blue-100 hover:bg-blue-200 text-blue-800 rounded-md font-medium transition-colors"
//           >
//             Show Stats
//           </Link>
//           <Link
//             to="profile"
//             className="px-4 py-2 bg-purple-100 hover:bg-purple-200 text-purple-800 rounded-md font-medium transition-colors"
//           >
//             Show Settings
//           </Link>
//         </div>
//       </div>

//       {/* --- THE SECOND NESTED OUTLET --- */}
//       <div className="bg-gray-50 p-4 rounded-lg min-h-[200px] border border-dashed border-gray-400">
//         <p className="text-xs text-gray-400 font-mono mb-2 uppercase tracking-wider">Inside Dashboard Outlet</p>
//         <Outlet />
//       </div>
//     </div>
//   );
// };

// // --- Level 1 Component (The Main Layout) ---
// const MainLayout = () => {
//   const location = useLocation();

//   return (
//     <div className="min-h-screen bg-gray-100 p-8 font-sans">
//       <div className="max-w-4xl mx-auto bg-white shadow-xl rounded-xl overflow-hidden border-2 border-red-400">

//         {/* Top Navigation */}
//         <nav className="bg-slate-800 p-4 flex justify-between items-center">
//           <div className="font-bold text-lg flex items-center gap-2">
//             <span className="text-yellow-400 text-2xl">❖</span> MyApp
//           </div>
//           <div className="flex gap-6">
//             <Link to="/" className="hover:text-yellow-400 transition-colors flex items-center gap-1">
//               <span>🏠</span> Home
//             </Link>
//             <Link to="/dashboard" className="hover:text-yellow-400 transition-colors flex items-center gap-1">
//               <span>👤</span> Dashboard
//             </Link>
//           </div>
//         </nav>

//         <div className="p-6">
//           <h1 className="text-2xl font-bold text-red-600 mb-2">Level 1: Main Layout</h1>
//           <p className="mb-6 text-gray-600">
//             Current Path: <code className="bg-gray-200 px-2 py-1 rounded text-sm">{location.pathname}</code>
//           </p>

//           {/* --- THE FIRST OUTLET --- */}
//           <div className="bg-red-50 p-6 rounded-lg border border-dashed border-red-300">
//             <p className="text-xs text-red-400 font-mono mb-2 uppercase tracking-wider">Inside Main Outlet</p>
//             <Outlet />
//           </div>
//         </div>
//       </div>
//     </div>
//   );
// };

// // --- Simple Home Page (Rendered in First Outlet) ---
// const HomePage = () => (
//   <div className="text-center py-10">
//     <h2 className="text-3xl font-bold text-gray-700">Welcome Home</h2>
//     <p className="mt-4 text-gray-500">
//       Click <strong>"Dashboard"</strong> in the top navigation to see the nested Outlet example.
//     </p>
//     <Link to="/dashboard/stats" className="mt-6 inline-flex items-center px-6 py-3 bg-slate-800 rounded-lg hover:bg-slate-700 transition">
//       Go directly to Deep Nested Route <span className="ml-2">→</span>
//     </Link>
//   </div>
// );

// // --- Main App Component with Route Definitions ---
// export default function App() {
//   return (
//     <BrowserRouter>
//       <Routes>
//         {/* Level 1: Main Layout wrapping everything */}
//         <Route path="/" element={<MainLayout />}>

//           {/* Default Content for Level 1 */}
//           <Route index element={<HomePage />} />

//           {/* Level 2: Dashboard Layout (Has the 2nd Outlet) */}
//           <Route path="dashboard" element={<DashboardLayout />}>

//             {/* Level 3: Content rendered inside Dashboard's Outlet */}
//             <Route index element={<div className="text-gray-500 italic">Select an option above (Stats or Settings)</div>} />
//             <Route path="stats" element={<StatsComponent />} />
//             <Route path="profile" element={<SettingsComponent />} />

//           </Route>

//         </Route>
//       </Routes>
//     </BrowserRouter>
//   );
// }
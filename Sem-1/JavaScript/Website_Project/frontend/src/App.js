import './App.css';
import Register from "./Register";
import Login from "./Login";
import Users from "./Users";
import Home from "./Home";
import { BrowserRouter, Routes, Route, Link } from "react-router-dom";

function App() {
  return (
    <BrowserRouter>
      <div style={{padding:20}}>

        {/* Navigation */}
        <nav style={{marginBottom:20}}>
          <Link to="/register"><button>Register</button></Link>
          <Link to="/login"><button style={{marginLeft:10}}>Login</button></Link>
          <Link to="/users"><button style={{marginLeft:10}}>Users (Protected)</button></Link>
        </nav>

        {/* Routes */}
        <Routes>
          <Route path="/register" element={<Register/>} />
          <Route path="/login" element={<Login/>} />
          <Route path="/users" element={<Users/>} />
          <Route path="/home" element={<Home/>} />
        </Routes>

      </div>
    </BrowserRouter>
  );
}

export default App;

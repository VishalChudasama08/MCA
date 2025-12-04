import React, { useState } from "react";

// 🔥 Protected USERS Page
export default function Users() {
	const [users, setUsers] = useState([]);
	async function getUsers() {
		const res = await fetch("http://localhost:5000/api/users", {
			headers: { "Authorization": "Bearer " + sessionStorage.getItem("token") }
		});
		const data = await res.json();
		console.log(data);
		setUsers(data);
	}

	return (
		<div>
			<h2>Protected Users Page</h2>
			<button onClick={getUsers}>Get Users (Protected)</button>
			<table border={2} style={{ marginTop: 20, borderCollapse: "collapse", width: "100%", padding: "10px" }}>
				<thead>
					<tr>
						<th>Name</th>
						<th>Email</th>
						<th>Password</th>
						<th>Created At</th>
					</tr>
				</thead>
				<tbody>
					{users.map(u => (
						<tr key={u.id}>
							<td>{u.name}</td>
							<td>{u.email}</td>
							<td>{u.created_at}</td>
							<td>{u.password}</td>
						</tr>
					))}
				</tbody>
			</table>
		</div>
	);
}
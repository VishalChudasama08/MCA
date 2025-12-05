import React, { useEffect, useState } from 'react'

export default function Profile() {
	const [userDetail, setUserDetail] = useState({ name: "", email: "", mobile_number: "" });

	useEffect(() => {
		const userData = JSON.parse(sessionStorage.getItem("userDetail"));
		setUserDetail({
			name: userData.name,
			email: userData.email,
			mobile_number: userData.mobile_number
		})
	}, [])
	return (
		<div className="container">
			<div className="card mx-auto " style={{ minWidth: 300, maxWidth: 600 }}>
				<div className="card-header text-center h5" id="user_head">User Information</div>
				<div className="card-body" id="disabled_info">
					{/* <?php
                if (isset($_GET['profile']) && $_GET['profile'] == 'update') {
                    echo "<p style={{color: 'green'}}>Profile Information Update Successfully...</p>";
                }
                ?> */}
					<div className="mb-3">
						<label htmlFor="name" className="form-label">Name :</label>
						<input type="text" className="form-control" id="name" name="name" defaultValue={userDetail.name} disabled />
					</div>
					<div className="mb-3">
						<label htmlFor="username" className="form-label">Username :</label>
						<input type="email" className="form-control" id="username" name="username" defaultValue={userDetail.email} disabled />
					</div>
					<div className="mb-3">
						<label htmlFor="number" className="form-label">Mobile Number :</label>
						<input type="number" className="form-control" id="number" name="number" defaultValue={userDetail.mobile_number} disabled />
					</div>
				</div>
				{/* <form> */}
				{/* <div className="card-body" id="edit_info">
					<div className="mb-3">
						<label htmlFor="eName" className="form-label">Name :</label>
						<input type="text" className="form-control" id="eName" name="eName" defaultValue={userDetail.name} required />
					</div>
					<div className="mb-3">
						<label htmlFor="eUsername" className="form-label">Username :</label>
						<input type="email" className="form-control" id="eUsername" name="eUsername" defaultValue={userDetail.email} required />
					</div>
					<div className="mb-3">
						<label htmlFor="eNumber" className="form-label">Mobile Number :</label>
						<input type="number" className="form-control" id="eNumber" name="eNumber" defaultValue={userDetail.mobile_number} required />
					</div>
					<div className="">
						<button className="btn btn-primary" id="update" type="submit">Update</button>
					</div>
				</div> */}
				{/* </form> */}

			</div>

			{/* <div className="d-flex mb-3 justify-content-evenly pt-2">
				<button className="btn btn-primary" id="edit">Edit Profile</button>
				<button className="btn btn-primary" id="cancel">Cancel</button>
			</div> */}
		</div>
	)
}

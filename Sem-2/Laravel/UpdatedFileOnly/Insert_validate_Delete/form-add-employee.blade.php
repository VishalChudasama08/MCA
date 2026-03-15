@extends('layout')

@section('main-content')
<!-- ============================================================== -->
<!-- Page wrapper  -->
<!-- ============================================================== -->
<div class="page-wrapper">
	<!-- ============================================================== -->
	<!-- Bread crumb and right sidebar toggle -->
	<!-- ============================================================== -->
	<div class="page-breadcrumb">
		<div class="row">
			<div class="col-12 d-flex no-block align-items-center">
				<h4 class="page-title">Add New Employee Form</h4>
				<div class="ms-auto text-end">
					<nav aria-label="breadcrumb">
						<ol class="breadcrumb">
							<li class="breadcrumb-item"><a href="#">Home</a></li>
							<li class="breadcrumb-item active" aria-current="page">
								Library
							</li>
						</ol>
					</nav>
				</div>
			</div>
		</div>
	</div>
	<!-- ============================================================== -->
	<!-- End Bread crumb and right sidebar toggle -->
	<!-- ============================================================== -->
	<!-- ============================================================== -->
	<!-- Container fluid  -->
	<!-- ============================================================== -->
	<div class="container-fluid">
		<div class="card">


			<form method="POST" action="addEmployee" class="form-horizontal">
				@csrf
				<div class="card-body">
					<div class="form-group row">
						<label
							for="name"
							class="col-sm-3 text-end control-label col-form-label">Employee Name</label>
						<div class="col-sm-9">
							<input
								type="text"
								class="form-control"
								id="name"
								name="name"
								placeholder="Employee Name Here" />
						</div>
					</div>
					<div class="form-group row">
						<label
							for="JobTitle"
							class="col-sm-3 text-end control-label col-form-label">Job Title</label>
						<div class="col-sm-9">
							<input
								type="text"
								class="form-control"
								id="JobTitle"
								name="job_title"
								placeholder="Job Title Here" />
						</div>
					</div>
					<div class="form-group row">
						<label
							for="salary"
							class="col-sm-3 text-end control-label col-form-label">Salary</label>
						<div class="col-sm-9">
							<input
								type="number"
								class="form-control"
								id="salary"
								name="salary"
								placeholder="salary Here" />
						</div>
					</div>
					<div class="form-group row">
						<label class="col-md-3">Radio Buttons</label>
						<div class="col-md-9">
							<div class="form-check">
								<input
									type="radio"
									class="form-check-input"
									id="Active"
									name="status"
									value=1
									required />
								<label
									class="form-check-label mb-0"
									for="Active">Active</label>
							</div>
							<div class="form-check">
								<input
									type="radio"
									class="form-check-input"
									id="NotActive"
									name="status"
									value=2
									required />
								<label
									class="form-check-label mb-0"
									for="NotActive">Not Active</label>
							</div>
						</div>
					</div>
				</div>
				@if ($errors->any())
				<div class="alert alert-danger">
					<ul>
						@foreach ($errors->all() as $error)
						<li>{{ $error }}</li>
						@endforeach
					</ul>
				</div>
				@endif
				<div class="border-top">
					<div class="card-body">
						<button type="submit" class="btn btn-primary">
							Submit
						</button>
					</div>
				</div>
			</form>
		</div>
	</div>
	<!-- ============================================================== -->
	<!-- End Container fluid  -->
	<!-- ============================================================== -->
	<!-- ============================================================== -->
	<!-- footer -->
	<!-- ============================================================== -->
	<footer class="footer text-center">
		All Rights Reserved by Vishal. Designed and Developed by
		<a href="https://github.com/VishalChudasama08">Vishal</a>.
	</footer>
	<!-- ============================================================== -->
	<!-- End footer -->
	<!-- ============================================================== -->
</div>
<!-- ============================================================== -->
<!-- End Page wrapper  -->
<!-- ============================================================== -->
@endsection
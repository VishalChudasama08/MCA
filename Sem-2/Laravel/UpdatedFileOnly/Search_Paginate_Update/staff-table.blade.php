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
				<h4 class="page-title">Tables</h4>
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
		@if ($errors->any())
		<div class="alert alert-danger">
			<ul>
				@foreach ($errors->all() as $error)
				<li>{{ $error }}</li>
				@endforeach
			</ul>
		</div>
		@endif
		<div class="card">
			<div class="card-body">
				<h5 class="card-title mb-0">Filter</h5>
				<form action="staffTable" method="get">
					Name: <input type="text" name="name" id="FName">
					Position: <input type="text" name="position" id="FPosition">
					Office: <input type="text" name="office" id="FOffice">
					Salary: <input type="number" name="salary" id="FSalary">
					Age: <input type="number" name="age" id="FAge">
					<button type="submit">Search</button>
				</form>
			</div>
			<table class="table">
				<thead>
					<tr>
						<th scope="col">#</th>
						<th scope="col">Image</th>
						<th scope="col">Name</th>
						<th scope="col">Position</th>
						<th scope="col">Office</th>
						<th scope="col">Salary</th>
						<th scope="col">Age</th>
						<th scope="col">Start Date</th>
						<th scope="col">Update</th>
					</tr>
				</thead>
				<tbody>
					@foreach($staffs as $s)
					<!-- For array type data -->
					<tr>
						<th scope="row">{{$s['id']}}</th>
						<td><img src="{{$s['image']}}" alt="user" style="border-radius: 50%; width: 35px;" /></td>
						<td>{{$s['name']}}</td>
						<td>{{$s['position']}}</td>
						<td>{{$s['office']}}</td>
						<td>{{$s['salary']}}</td>
						<td>{{$s['age']}}</td>
						<td>{{$s['start_date']}}</td>
						<td><a href="{{url('editStaff', $s['id'])}}" class="btn btn-outline-warning btn-sm rounded">Edit</a></td>
					</tr>
					@endforeach
				</tbody>
			</table>
			<div class="paginate">
				{{$staffs->links()}}
			</div>

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
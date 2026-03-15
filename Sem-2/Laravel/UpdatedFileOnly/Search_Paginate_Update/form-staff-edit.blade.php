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
    
	    <div class="card">


		    <form method="POST" action="{{url('editStaffData')}}" class="form-horizontal">
				@csrf <input type="hidden" name="id" value="{{$staff->id}}"/>
                <div class="card-body">
                    <div class="row">
                        <div class="col-md-6">
					        <div class="form-group row">
                                <label
                                    for="name"
                                    class="col-sm-3 text-end control-label col-form-label">Name:</label>
                                <div class="col-sm-9">
                                    <input
                                        type="text"
                                        class="form-control"
                                        id="name"
                                        name="name"
                                        value="{{$staff->name}}" />
                                </div>
                            </div>
                            <div class="form-group row">
                                <label
                                    for="position"
                                    class="col-sm-3 text-end control-label col-form-label">Position:</label>
                                <div class="col-sm-9">
                                    <input
                                        type="text"
                                        class="form-control"
                                        id="position"
                                        name="position"
                                        value="{{$staff->position}}" />
                                </div>
                            </div>
					        <div class="form-group row">
                                <label
                                    for="office"
                                    class="col-sm-3 text-end control-label col-form-label">Office:</label>
                                <div class="col-sm-9">
                                    <input
                                        type="text"
                                        class="form-control"
                                        id="office"
                                        name="office"
                                        value="{{$staff->office}}" />
                                </div>
                            </div>
                        </div>
                        <div class="col-md-6">
                            <div class="form-group row">
                                <label
                                    for="age"
                                    class="col-sm-3 text-end control-label col-form-label">Age:</label>
                                <div class="col-sm-9">
                                    <input
                                        type="number"
                                        class="form-control"
                                        id="age"
                                        name="age"
                                        value="{{$staff->age}}" />
                                </div>
                            </div>
                            <div class="form-group row">
                                <label
                                    for="salary"
                                    class="col-sm-3 text-end control-label col-form-label">Salary:</label>
                                <div class="col-sm-9">
                                    <input
                                        type="number"
                                        class="form-control"
                                        id="salary"
                                        name="salary"
                                        value="{{$staff->salary}}" />
                                </div>
                            </div>
				        </div>
                    </div>
                </div> 
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
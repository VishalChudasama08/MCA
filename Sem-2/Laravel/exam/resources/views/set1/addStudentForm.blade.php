@extends('layout')

@section('content')
    <div class="content">
        <div class="container">
            <div class="row">
                <div class="col-lg-6">
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
                        <div class="card-header">Add Student Form</div>
                        <div class="card-body">
                            <form action="{{ url('set1/SaveStudent') }}" method="POST" enctype="multipart/form-data">
                                @csrf
                                Enter Name: <input class="my-2" type="text" name="name" required> <br>
                                Enter Email: <input class="my-2" type="email" name="email" required> <br>
                                Select Course:
                                <select name="course" required class="my-2">
                                    <option value="MCA">MCA</option>
                                    <option value="BCA">BCA</option>
                                    <option value="BBA">BBA</option>
                                    <option value="BCom">BCom</option>
                                    <option value="BSC">BSC</option>
                                    <option value="MSC">MSC</option>
                                </select> <br>
                                Enter Phone Number: <input class="my-2" type="tel" name="phone" required> <br>
                                Select Profile Photo: <input class="my-2" type="file" name="profile_image" required>
                                <br>
                                <button type="submit" class="btn btn-primary my-3">Save</button>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
@endsection

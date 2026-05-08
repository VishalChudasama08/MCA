@extends('layout')

@section('content')
    <div class="content">
        <div class="container">
            <div class="row">
                <div class="col-lg-6">
                    <div class="card">
                        <div class="card-header">Add Student Form</div>
                        <div class="card-body">
                            <form action="{{ url('set1/saveEditStudent') }}" method="POST" enctype="multipart/form-data">
                                @csrf
                                <input type="text" name="id" value="{{ $student->id }}" hidden>
                                Enter Name: <input class="my-2" type="text" name="name" value="{{ $student->name }}"
                                    required>
                                <br>
                                Enter Email: <input class="my-2" type="email" name="email"
                                    value="{{ $student->email }}" required>
                                <br>
                                Select Course:
                                <select name="course" required class="my-2">
                                    <option value="MCA" {{ $student->course == 'MCA' ? 'selected' : '' }}>MCA</option>
                                    <option value="BCA" {{ $student->course == 'BCA' ? 'selected' : '' }}>BCA</option>
                                    <option value="BBA" {{ $student->course == 'BBA' ? 'selected' : '' }}>BBA</option>
                                    <option value="BCom" {{ $student->course == 'BCom' ? 'selected' : '' }}>BCom</option>
                                    <option value="BSC" {{ $student->course == 'BSC' ? 'selected' : '' }}>BSC</option>
                                    <option value="MSC" {{ $student->course == 'MSC' ? 'selected' : '' }}>MSC</option>
                                </select> <br>
                                Enter Phone Number: <input class="my-2" type="tel" name="phone"
                                    value="{{ $student->phone }}" required> <br>
                                <button type="submit" class="btn btn-primary my-3">Save</button>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
@endsection

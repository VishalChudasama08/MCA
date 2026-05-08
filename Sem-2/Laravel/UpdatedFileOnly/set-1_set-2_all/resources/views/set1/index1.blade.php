@extends('layout')

@section('content')
    <!-- Main Content -->
    <main class="main-content">
        <div class="content">
            <div class="container">
                <div class="row">
                    <div class="col-md-12 page-header">
                        <h2 class="greeting my-3">Student Management System</h2>
                        <div class="row my-3">
                            <div class="col">
                                <a href="{{ url('set1/add-student') }}" class="btn btn-primary"> Add Student</a>
                            </div>
                            <div class="col">
                                @if (session('msg'))
                                    <div class="alert alert-success" id="msg">{{ session('msg') }}
                                    </div>
                                    <script>
                                        setTimeout(() => {
                                            document.getElementById('msg').style.display = 'none';
                                        }, 5000)
                                    </script>
                                @endif
                                @if ($errors->any())
                                    <div class="alert alert-danger">
                                        <ul>
                                            @foreach ($errors->all() as $error)
                                                <li>{{ $error }}</li>
                                            @endforeach
                                        </ul>
                                    </div>
                                @endif
                            </div>
                        </div>
                    </div>
                    <div class="col-md-12 col-lg-12">
                        <div class="card">
                            <div class="card-header">
                                <h2 class="card-title">All Students</h2>
                            </div>
                            <div class="table-container">
                                <table width="100%">
                                    <thead>
                                        <tr>
                                            <th>ID</th>
                                            <th>Photo</th>
                                            <th>Name</th>
                                            <th>Email</th>
                                            <th>Course</th>
                                            <th>Phone</th>
                                            <th>Edit</th>
                                            <th>Delete</th>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        @php $i = 1; @endphp
                                        @foreach ($students as $s)
                                            <tr>
                                                <td>{{ $i++ }}</td>
                                                <td><img src="{{ asset($s['profile_image']) }}" class=""
                                                        height="40px">
                                                </td>
                                                <td>{{ $s['name'] }}</td>
                                                <td>{{ $s['email'] }}</td>
                                                <td>{{ $s['course'] }}</td>
                                                <td>{{ $s['phone'] }}</td>
                                                <td><a href="{{ url('set1/edit-student', $s['id']) }}">Edit</a></td>
                                                <td><a href="{{ url('set1/delete-student', $s['id']) }}">Delete</a></td>
                                            </tr>
                                        @endforeach
                                    </tbody>
                                </table>
                                {{ $students->links() }}
                            </div>
                        </div>
                    </div>
                </div>
            </div>
    </main>
@endsection

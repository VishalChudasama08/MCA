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
                        <div class="card-header">Add Product Form</div>
                        <div class="card-body">
                            <form action="{{ url('set2/SaveProducts') }}" method="POST" enctype="multipart/form-data">
                                @csrf
                                Enter Name: <input class="my-2" type="text" name="name" required><br>
                                Select Category:
                                <select name="category" required class="my-2">
                                    <option value="Phone">Phone</option>
                                    <option value="Laptop">Laptop</option>
                                    <option value="Bike">Bike</option>
                                    <option value="Car">Car</option>
                                </select> <br>
                                Enter Price: <input class="my-2" type="text" name="price" required> <br>
                                Enter Phone Number: <input class="my-2" type="tel" name="quantity" required> <br>
                                Select Photo: <input class="my-2" type="file" name="product_image" required>
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

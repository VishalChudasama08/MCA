@extends('layout')

@section('content')
    <div class="content">
        <div class="container">
            <div class="row">
                <div class="col-lg-6">
                    <div class="card">
                        <div class="card-header">Add Product Form</div>
                        <div class="card-body">
                            <form action="{{ url('set2/saveEditProducts') }}" method="POST" enctype="multipart/form-data">
                                @csrf
                                <input type="text" name="id" value="{{ $product->id }}" hidden>
                                Enter Name: <input class="my-2" type="text" name="name" value="{{ $product->name }}"
                                    required>
                                <br>
                                Select Category:
                                <select name="category" required class="my-2">
                                    <option value="Phone" {{ $product->category == 'Phone' ? 'selected' : '' }}>Phone
                                    </option>
                                    <option value="Laptop" {{ $product->category == 'Laptop' ? 'selected' : '' }}>Laptop
                                    </option>
                                    <option value="Bike" {{ $product->category == 'Bike' ? 'selected' : '' }}>Bike
                                    </option>
                                    <option value="Car" {{ $product->category == 'Car' ? 'selected' : '' }}>Car</option>
                                </select> <br>
                                Enter Price: <input class="my-2" type="text" name="price"
                                    value="{{ $product->price }}" required>
                                <br>
                                Enter Phone Number: <input class="my-2" type="tel" name="quantity"
                                    value="{{ $product->quantity }}" required> <br>
                                <button type="submit" class="btn btn-primary my-3">Save</button>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
@endsection

@extends('layout')

@section('content')
    <!-- Main Content -->
    <main class="main-content">
        <div class="content">
            <div class="container">
                <div class="row">
                    <div class="col-md-12 page-header">
                        <h2 class="greeting">Product Management System</h2>
                        <div class="row mt-2">
                            <div class="col">
                                <a href="{{ url('set2/add-products') }}" class="btn btn-primary"> Add product</a>
                            </div>
                            <div class="col my-4">
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
                                <h2 class="card-title">Filter</h2>
                                <h3 class="card-title">Total Count: {{ $products->total() }}</h3>
                            </div>
                            <div class="card-body">
                                <form action="{{ url('/set2/filterProduct') }}" method="get">
                                    <span class="settings-title">Name:</span> <input type="text" name="name"
                                        class="me-2">
                                    <span class="settings-title">Category:</span> <select name="category" class="me-2">
                                        <option value="">select</option>
                                        <option value="Phone">Phone</option>
                                        <option value="Laptop">Laptop</option>
                                        <option value="Bike">Bike</option>
                                        <option value="Car">Car</option>
                                    </select>
                                    <span class="settings-title">Price:</span> <input type="number" name="price"
                                        class="me-2">
                                    <span class="settings-title">Quantity:</span> <input type="number" name="quantity"
                                        class="me-2">
                                    <button type="submit" class="btn btn-ghost">Apply</button>
                                </form>
                            </div>
                            <div class="table-container">
                                <table width="100%">
                                    <thead>
                                        <tr>
                                            <th>ID</th>
                                            <th>Photo</th>
                                            <th>Name</th>
                                            <th>Category</th>
                                            <th>Price</th>
                                            <th>Quantity</th>
                                            <th>Edit</th>
                                            <th>Delete</th>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        @php $i = 1; @endphp
                                        @foreach ($products as $p)
                                            <tr>
                                                <td>{{ $i++ }}</td>
                                                <td><img src="{{ asset($p['product_image']) }}" class=""
                                                        height="40px">
                                                </td>
                                                <td>{{ $p['name'] }}</td>
                                                <td>{{ $p['category'] }}</td>
                                                <td>{{ $p['price'] }}</td>
                                                <td>{{ $p['quantity'] }}</td>
                                                <td><a href="{{ url('set2/edit-products', $p['id']) }}">Edit</a>
                                                </td>
                                                <td><a href="{{ url('set2/delete-products', $p['id']) }}">Delete</a>
                                                </td>
                                            </tr>
                                        @endforeach
                                    </tbody>
                                </table>
                                <div class="mt-2">
                                    {{ $products->appends(request()->query())->links() }}
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
    </main>
@endsection

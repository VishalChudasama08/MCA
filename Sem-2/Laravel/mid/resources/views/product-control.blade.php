@extends('layout')
@section('main-header')
    <!-- Main Content -->
    <main class="main-content">


        <div class="add-product-form">
            <form action="{{ url('addProduct') }}" method="post">
                @csrf
                Name: <input type="text" name="name" id="name"><br>
                Price: <input type="number" name="price" id="price"><br>
                Qty: <input type="number" name="qty" id="qty"><br>
                <button type="submit" class="btn btn-primary">Add</button>
            </form>
        </div>

        @if (session('p_added'))
            <div style="color: green; margin: 10px;">{{ session('p_added') }}</div>
        @endif
        @if (session('p_deleted'))
            <div style="color: red; margin: 10px;">{{ session('p_deleted') }}</div>
        @endif
        @if (session('p_updated'))
            <div style="color: yellow; margin: 10px;">{{ session('p_updated') }}</div>
        @endif

        <div class="table-container">
            <table>
                <thead>
                    <tr>
                        <th>Index</th>
                        <th>Name</th>
                        <th>Price</th>
                        <th>Qty</th>
                        <th>Deleting</th>
                        <th>Updating</th>
                    </tr>
                </thead>
                <tbody>
                    @foreach ($data as $p)
                        <tr>
                            <td>{{ $p['id'] }}</td>
                            <td>{{ $p['p_name'] }}</td>
                            <td>{{ $p['p_price'] }}</td>
                            <td>{{ $p['p_qty'] }}</td>
                            <td><a href="{{ url('deleteThis', $p['id']) }}" style="color: red">Delete</a></td>
                            <td><a href="{{ url('edit-product', $p['id']) }}" style="color: yellow">Update</a></td>
                        </tr>
                    @endforeach
                </tbody>
            </table>
        </div>
    </main>
@endsection

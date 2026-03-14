<form action="{{ url('updateThis', $data->id) }}" method="post">
    @csrf

    Name: <input type="text" name="name" value="{{ $data->p_name }}"><br>

    Price: <input type="number" name="price" value="{{ $data->p_price }}"><br>

    Qty: <input type="number" name="qty" value="{{ $data->p_qty }}"><br>

    <button type="submit">Update</button>
</form>

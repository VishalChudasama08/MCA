<!DOCTYPE html>
<html>
<head>
    <title>Category Products</title>
</head>
<body>

<h1>Categories and Products</h1>

@foreach($data as $cat)

<h2>{{ $cat->name }}</h2>

<table border="1" cellpadding="5">
<tr>
    <th>Product Name</th>
    <th>Price</th>
    <th>Qty</th>
</tr>

@foreach($cat->products as $p)
<tr>
    <td>{{ $p->p_name }}</td>
    <td>{{ $p->p_price }}</td>
    <td>{{ $p->p_qty }}</td>
</tr>
@endforeach

</table>

<br>

@endforeach

</body>
</html>

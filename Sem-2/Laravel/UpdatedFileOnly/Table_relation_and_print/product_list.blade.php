<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <h1>Product List</h1>
    <table border="", width="60%">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Qty</th>
            <th>Price</th>
            <th>Category</th>
            <th>Added By</th>
        </tr>
        @foreach($data as $index=>$d)
        <tr>
            <td>{{ $index + 1}}</td>
            <td>{{ $d->name }}</td>
            <td>{{ $d->qty }}</td>
            <td>{{ $d->price }}</td>
            <td>{{ $d->category->name }}</td>
            <td>{{ $d->user->name }}</td>
        </tr>
        @endforeach
    </table>
</body>

</html>
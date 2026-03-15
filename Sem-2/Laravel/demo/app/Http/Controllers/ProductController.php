<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Models\Product;

class ProductController extends Controller
{
    public function productList()
    {
        $data = Product::with('category', 'user')->orderby('name', 'asc')->get();
        $total = $data->count();

        // print_r($data->toArray());die;

        return view("RelatedTable/product_list", compact("data", "total"));
    }
}

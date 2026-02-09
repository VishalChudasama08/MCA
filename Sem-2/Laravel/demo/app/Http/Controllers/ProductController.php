<?php

namespace App\Http\Controllers;

use App\Models\ProductsModel;
use Illuminate\Http\Request;

class ProductController extends Controller{
    public function getAllProduct(){
        $products = ProductsModel::all(); // get all products and
        return view('products-table', compact('products'));
    }
}

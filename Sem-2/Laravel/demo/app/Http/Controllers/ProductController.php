<?php

namespace App\Http\Controllers;

use App\Models\ProductsModel;
use Illuminate\Http\Request;

class ProductController extends Controller
{
    public function getAllProduct(){
        $products = ProductsModel::get(); // get all products and
        return view('tables_page', compact('products'));
    }
}

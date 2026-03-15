<?php

namespace App\Http\Controllers;

use App\Models\Category;
use Illuminate\Http\Request;

class CategoryController extends Controller
{
    public function showCategoryProducts()
    {
        // Load categories with their products
        $data = Category::with('products')->get();

        // echo "<pre>";
        // print_r($data->toArray());
        // echo "</pre>";
        // die;

        return view('RelatedTable/category', compact('data'));
    }
}

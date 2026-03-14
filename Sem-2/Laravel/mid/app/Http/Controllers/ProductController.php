<?php

namespace App\Http\Controllers;

use App\Models\Product;
use Illuminate\Http\Request;

class ProductController extends Controller
{
    public function addProduct(Request $req)
    {
        Product::create([
            'p_name' => $req->name,
            'p_price' => $req->price,
            'p_qty' => $req->qty
        ]);
        return redirect('listProduct')->with('p_added', 'New Product added successfully');
    }
    public function getAllProduct()
    {
        $data = Product::get();

        return view('product-control', compact('data'));
    }
    public function deleteThisProduct($id)
    {
        Product::where('id', $id)->delete();
        return redirect('listProduct')->with('p_deleted', 'Product deleted.');
    }

    public function getUpdateProductData($id)
    {
        $data = Product::find($id);
        return view('edit-product', compact('data'));
    }
    public function updateThisProduct(Request $req, $id)
    {
        Product::where('id', $id)->update([
            'p_name' => $req->name,
            'p_price' => $req->price,
            'p_qty' => $req->qty
        ]);

        return redirect('listProduct')->with('p_updated', 'Product Details Updated successfully');
    }
}

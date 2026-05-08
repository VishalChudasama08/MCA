<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Products;

class ProductsController extends Controller
{
    public function index(Request $req)
    {
        $query = Products::query();

        if ($req->filled('name')) {
            $query->where('name', 'LIKE', '%' . $req->name . '%');
        }
        if ($req->filled('category')) {
            $query->where('category', 'LIKE', '%' . $req->category . '%');
        }
        if ($req->filled('price')) {
            $query->where('price', 'LIKE', '%' . $req->price . '%');
        }
        if ($req->filled('quantity')) {
            $query->where('quantity', 'LIKE', '%' . $req->quantity . '%');
        }
        $products = $query->paginate(5);
        return view('set2.index2', compact('products'));
    }
    public function addProductsPage()
    {
        return view('set2.addProductForm');
    }
    public function editProductsPage($id)
    {
        $product = Products::find($id);
        return view('set2.editProductForm', compact('product'));
    }
    public function deleteProducts($id)
    {
        Products::find($id)->delete();
        return redirect('set2/index')->with('msg', "Product Deleted successfully");
    }

    public function addProducts(Request $req)
    {
        $req->validate([
            'name' => 'required',
            'price' => 'numeric',
            'quantity' => 'numeric',
            'product_image' => 'image'
        ]);
        // echo "<pre>";
        // echo $req->product_image->getClientOriginalExtension();
        // print_r($req->all());
        // die;

        $image = $req->product_image;
        $name = 'upload/' . time() . "." . $image->getClientOriginalExtension();
        $image->move(public_path('upload'), $name);

        Products::create([
            'name' => $req->name,
            'category' => $req->category,
            'price' => $req->price,
            'quantity' => $req->quantity,
            'product_image' => $name
        ]);

        return redirect('set2/index')->with('msg', "Product add successfully");
    }
    public function saveEditProducts(Request $req)
    {
        $product = Products::find($req->id);
        $product->name = $req->name;
        $product->category = $req->category;
        $product->price = $req->price;
        $product->quantity = $req->quantity;
        $product->save();
        return redirect('set2/index')->with('msg', "Product edited successfully");
    }
}

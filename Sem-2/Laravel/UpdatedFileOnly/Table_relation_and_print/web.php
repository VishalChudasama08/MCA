<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\AuthController;
use App\Http\Controllers\ProductController;
use App\Http\Controllers\CategoryController;

Route::get("/produts", [ProductController::class,'productList']);

Route::get('/', function () {
    return view('welcome');
});

Route::get('/login', function(){
    return view('loginPage');
});
Route::post('/loginNow', [AuthController::class, 'loginProcess']);

Route::get('/register', function(){
    return view('registerPage');
});
Route::post('/registerNow', [AuthController::class, 'registerProcess']);

Route::get('/logout', [AuthController::class, 'logoutProcess']);

Route::get('/adminPanel', function(){
    return view('adminPanel');
});
Route::get('/userPanel', function(){
    return view('userPanel');
});
Route::get('/sellerPanel', function(){
    return view('sellerPanel');
});


Route::get('/category-products', [CategoryController::class, 'showCategoryProducts']);
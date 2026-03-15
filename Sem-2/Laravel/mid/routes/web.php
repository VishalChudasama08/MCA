<?php

use App\Http\Controllers\ProductController;
use App\Http\Controllers\UserController;
use Illuminate\Support\Facades\Route;

// Route::get('/', function () {
//     return view('welcome');
// });

Route::get('/', function () {
    return view('index');
});
Route::get('/index', function () {
    return view('index');
});
Route::get('/projects', function () {
    return view('projects');
});
Route::get('/inbox', function () {
    return view('inbox');
});
Route::get('/analytics', function () {
    return view('analytics');
});
Route::get('/settings', function () {
    return view('settings');
});

Route::get('/adminDashboard', function () {
    return view('adminDashboard');
});


// login & register router's
Route::get('/login', function () {
    return view('login');
});
Route::get('/register', function () {
    return view('register');
});

Route::post('/loginNow', [UserController::class, 'loginPro']);
Route::post('registerNow', [UserController::class, 'registerPro']);
Route::get('logoutNow', [UserController::class, 'logout']);


// product router's

Route::get('/listProduct', [ProductController::class, 'getAllProduct']);
Route::post('/addProduct', [ProductController::class, 'addProduct']);
Route::get('/deleteThis/{id}', [ProductController::class, 'deleteThisProduct']);
Route::get('/edit-product/{id}', [ProductController::class, 'getUpdateProductData']);
Route::post('/updateThis/{id}', [ProductController::class, 'updateThisProduct']);

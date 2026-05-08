<?php

use App\Http\Controllers\AuthController;
use App\Http\Controllers\ProductsController;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\StudentController;

Route::get('login', [AuthController::class, 'login']);
Route::get('register', [AuthController::class, 'register']);
Route::get('logout', [AuthController::class, 'logout']);

Route::post('loginNow', [AuthController::class, 'loginNow']);
Route::post('registerNow', [AuthController::class, 'registerNow']);

// ======= Set-1 =======
Route::middleware(['isUser'])->group(function () {
    Route::get('/set1/index', [StudentController::class, 'index']);
    Route::get('/set1/add-student', [StudentController::class, 'addStudentPage']);
    Route::get('/set1/edit-student/{id}', [StudentController::class, 'editStudentPage']);
    Route::get('/set1/delete-student/{id}', [StudentController::class, 'deleteStudent']);

    Route::post('/set1/SaveStudent', [StudentController::class, 'addStudent']);
    Route::post('/set1/saveEditStudent', [StudentController::class, 'saveEditStudent']);
});

// ======= Set-2 =======
Route::middleware(['isAdmin'])->group(function () {
    Route::get('/set2/index', [ProductsController::class, 'index']);
    Route::get('/set2/add-products', [ProductsController::class, 'addProductsPage']);
    Route::get('/set2/edit-products/{id}', [ProductsController::class, 'editProductsPage']);
    Route::get('/set2/delete-products/{id}', [ProductsController::class, 'deleteProducts']);

    Route::post('/set2/SaveProducts', [ProductsController::class, 'addProducts']);
    Route::post('/set2/saveEditProducts', [ProductsController::class, 'saveEditProducts']);

    Route::get('/set2/filterProduct', [ProductsController::class, 'index']);
});



Route::get('/', function () {
    return view('index');
});

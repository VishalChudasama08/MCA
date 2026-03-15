<?php

use App\Http\Controllers\AuthController;

use App\Http\Controllers\ProductsController;
use App\Http\Controllers\EmployeeController;
use App\Http\Controllers\StaffController;

use App\Http\Controllers\ProductController;
use App\Http\Controllers\CategoryController;

use Illuminate\Support\Facades\Route;


// login & register Route's
Route::get('/login', function () {
    return view('loginPage');
});
Route::post('/loginNow', [AuthController::class, 'loginProcess']);

Route::get('/register', function () {
    return view('registerPage');
});
Route::post('/registerNow', [AuthController::class, 'registerProcess']);

Route::get('/logout', [AuthController::class, 'logoutProcess']);

Route::get('/adminPanel', function () {
    return view('adminPanel');
});
Route::get('/userPanel', function () {
    return view('userPanel');
});
Route::get('/sellerPanel', function () {
    return view('sellerPanel');
});



Route::get('/productTable', [ProductsController::class, 'getAllProduct']); // run getAllProduct function from ProductController class

Route::get('employeesTable', [EmployeeController::class, 'listEmployee']);
Route::get('addEmployeeForm', function () {
    return view('form-add-employee');
});
Route::post('addEmployee', [EmployeeController::class, 'addEmployee']);
Route::get('delEmp/{id}', [EmployeeController::class, 'deleteEmployee']);


Route::get('/staffTable', [StaffController::class, 'getStaff']);
Route::get('/editStaff/{id}', [StaffController::class, 'findStaff']);
Route::post('/editStaffData', [StaffController::class, 'editStaff']);



// Related Table Route's
Route::get("/products", [ProductController::class, 'productList']);
Route::get('/category-products', [CategoryController::class, 'showCategoryProducts']);

Route::get('/', function () {
    return view('Dashboard_page');
});

Route::get('/charts', function () {
    return view('charts_page');
});

Route::get('/widgets', function () {
    return view('widgets_page');
});

Route::get('/demo-tables', function () {
    return view('demo-tables');
});

Route::get('/grid', function () {
    return view('grid_page');
});

Route::get('/form-basic', function () {
    return view('form-basic_page');
});

Route::get('/form-wizard', function () {
    return view('form-wizard_page');
});

Route::get('/icon-material', function () {
    return view('icon-material_page');
});

Route::get('/icon-fontawesome', function () {
    return view('icon-fontawesome_page');
});

Route::get('/buttons', function () {
    return view('buttons_page');
});

Route::get('/elements', function () {
    return view('elements_page');
});

Route::get('/Dashboard2', function () {
    return view('Dashboard2_page');
});

Route::get('/gallery', function () {
    return view('gallery_page');
});

Route::get('/calendar', function () {
    return view('calendar_page');
});

Route::get('/invoice', function () {
    return view('invoice_page');
});

Route::get('/chat', function () {
    return view('chat_page');
});

Route::get('/authentication-login', function () {
    return view('authentication-login_page');
});

Route::get('/authentication-register', function () {
    return view('authentication-register_page');
});

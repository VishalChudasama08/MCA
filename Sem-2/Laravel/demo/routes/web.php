<?php

use Illuminate\Support\Facades\Route;

// Route::get('/', function () {
//     return view('welcome');
// });

Route::get('/', function(){
    return view('Dashboard_page');
});

Route::get('/charts', function(){
    return view('charts_page');
});

Route::get('/widgets', function(){
    return view('widgets_page');
});

Route::get('/tables', function(){
    return view('tables_page');
});

Route::get('/grid', function(){
    return view('grid_page');
});

Route::get('/form-basic', function(){
    return view('form-basic_page');
});

Route::get('/form-wizard', function(){
    return view('form-wizard_page');
});

Route::get('/icon-material', function(){
    return view('icon-material_page');
});

Route::get('/icon-fontawesome', function(){
    return view('icon-fontawesome_page');
});

Route::get('/buttons', function(){
    return view('buttons_page');
});

Route::get('/elements', function(){
    return view('elements_page');
});

Route::get('/Dashboard2', function(){
    return view('Dashboard2_page');
});

Route::get('/gallery', function(){
    return view('gallery_page');
});

Route::get('/calendar', function(){
    return view('calendar_page');
});

Route::get('/invoice', function(){
    return view('invoice_page');
});

Route::get('/chat', function(){
    return view('chat_page');
});

Route::get('/authentication-login', function(){
    return view('authentication-login_page');
});

Route::get('/authentication-register', function(){
    return view('authentication-register_page');
});
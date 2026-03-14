<?php

namespace App\Http\Controllers;

use App\Models\User;
use Illuminate\Http\Request;
use Auth;

class UserController extends Controller
{
    public function loginPro(Request $req)
    {
        if (Auth::attempt(['email' => $req->email, 'password' => $req->password])) {
            if (Auth::user()->user_type == 'admin') {
                return redirect('/adminDashboard');
            }
            if (Auth::user()->user_type == 'user') {
                return redirect('/index');
            }
        } else {
            return redirect('/login')->with('error', 'Login Failed');
        }
    }

    public function registerPro(Request $req)
    {
        User::create([
            'name' => $req->name,
            'email' => $req->email,
            'password' => $req->password
        ]);
        return redirect('login')->with('registerOkay', 'You Registration Successfully');
    }

    public function logout()
    {
        Auth::logout();
        return redirect('login');
    }
}

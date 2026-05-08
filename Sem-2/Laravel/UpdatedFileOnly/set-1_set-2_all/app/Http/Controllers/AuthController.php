<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\User;
use Auth;

class AuthController extends Controller
{
    public function login()
    {
        return view('login');
    }
    public function register()
    {
        return view('signup');
    }
    public function loginNow(Request $req)
    {
        $req->validate([
            'email' => 'required',
            'password' => 'required'
        ]);

        if (Auth::attempt(['email' => $req->email, 'password' => $req->password])) {
            if (Auth::user()->role == 'admin') {
                return redirect('set2/index')->with('msg', "Login Successfully");
            }
            if (Auth::user()->role == 'user') {
                return redirect('set1/index')->with('msg', "Login Successfully");
            }
        } else {
            return redirect('login')->with('wrong', "Username and password are wrong");
        }
    }
    public function registerNow(Request $req)
    {
        $req->validate([
            'name' => 'required',
            'email' => 'required',
            'password' => 'required'
        ]);
        User::create([
            'name' => $req->name,
            'email' => $req->email,
            'password' => $req->password
        ]);
        return redirect('login')->with('msg', "Registration successfully.");
    }
    public function logout()
    {
        Auth::logout();
        return redirect('/')->with('msg', 'Logout');
    }
}

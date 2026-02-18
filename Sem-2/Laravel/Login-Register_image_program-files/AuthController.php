<?php

namespace App\Http\Controllers;
use Auth;
use Illuminate\Http\Request;
use App\Models\User;

class AuthController extends Controller{
    public function loginProcess(Request $req){
        if(Auth::attempt(['email'=>$req->email, 'password'=>$req->password])){
            if(Auth::user()->user_type == 'admin'){
                return redirect('/adminPanel');
            }
            if(Auth::user()->user_type == 'user'){
                return redirect('/userPanel');
            }
            if(Auth::user()->user_type == 'seller'){
                return redirect('/sellerPanel');
            }
        } else {
            echo "Login Fail.";
        }
    }

    public function registerProcess(Request $req){
        $file = $req->image;
        $name = time().".".$file->getClientOriginalExtension();
        $file->move(public_path('upload'), $name); // move file on upload folder

        User::create([
            'name'=>$req->name,
            'email'=>$req->email,
            'password'=>$req->password,
            'image'=>$name
        ]);

        return redirect('/login');
    }

    public function logoutProcess(){
        Auth::logout();
        return redirect('/');
    }
}

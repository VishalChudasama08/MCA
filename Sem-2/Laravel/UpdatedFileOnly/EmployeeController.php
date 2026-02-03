<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\EmployeeModel;

class EmployeeController extends Controller{
    public function listEmployee(){
        $employees = EmployeeModel::get();
        return view('tables_page', compact('employees'));
    }
    public function addEmployee(Request $request){
        $request->validate([
            'name'=>'required|min:3|max:20|alpha',
            'salary'=>'required|min:10000|numeric'
        ]);
        // print_r($request->all());
        EmployeeModel::create([
            'name'=>$request->name,
            'job_title'=>$request->job_title,
            'salary'=>$request->salary,
            'status'=>$request->status
        ]);
        return redirect('tables');
    }
    public function deleteEmployee($id){
        EmployeeModel::where('id', $id)->delete();
        return redirect('tables');
    }
}

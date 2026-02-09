<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\StaffModel;

class StaffController extends Controller{
    public function getStaff(Request $request){
        $query = StaffModel::query();

        if($request->filled('name')){
            $query->where('name', 'LIKE', '%'.$request->name.'%');
        }
        if($request->filled('position')){
            $query->where('position', 'LIKE', '%'.$request->position.'%');
        }
        if($request->filled('office')){
            $query->where('office', 'LIKE', '%'.$request->office.'%');
        }
        if($request->filled('salary')){
            $query->where('salary', 'LIKE', '%'.$request->salary.'%');
        }
        if($request->filled('age')){
            $query->where('age', 'LIKE', '%'.$request->age.'%');
        }
        $staffs = $query->paginate(5);
        return view('staff-table', compact('staffs'));
    }
}

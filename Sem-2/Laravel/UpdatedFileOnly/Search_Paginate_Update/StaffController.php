<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\StaffModel;

class StaffController extends Controller
{
    public function getStaff(Request $request)
    {
        $query = StaffModel::query();

        if ($request->filled('name')) {
            $query->where('name', 'LIKE', '%' . $request->name . '%');
        }
        if ($request->filled('position')) {
            $query->where('position', 'LIKE', '%' . $request->position . '%');
        }
        if ($request->filled('office')) {
            $query->where('office', 'LIKE', '%' . $request->office . '%');
        }
        if ($request->filled('salary')) {
            $query->where('salary', 'LIKE', '%' . $request->salary . '%');
        }
        if ($request->filled('age')) {
            $query->where('age', 'LIKE', '%' . $request->age . '%');
        }

        $staffs = $query->paginate(5); // paginate with 5 record per query 

        return view('staff-table', compact('staffs'));
    }

    public function findStaff($id)
    {
        $staff = StaffModel::find($id);

        return view('form-staff-edit', compact('staff'));
    }

    public function editStaff(Request $request)
    {
        // echo "<pre>";
        // print_r($request->all());
        // echo "<pre>";
        // die;

        $staff = StaffModel::find($request->id);

        $staff->name = $request->name;
        $staff->position = $request->position;
        $staff->office = $request->office;
        $staff->age = $request->age;
        $staff->salary = $request->salary;

        $staff->save();

        return redirect('staffTable');
    }
}

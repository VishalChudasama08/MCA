<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Students;

class StudentController extends Controller
{
    public function index()
    {
        $students = Students::paginate(8);

        return view('set1.index1', compact('students'));
    }
    public function addStudentPage()
    {
        return view('set1.addStudentForm');
    }
    public function editStudentPage($id)
    {
        $student = Students::find($id);
        // echo "<pre>";
        // print_r($student->toArray());
        // echo $student->name;
        // die;
        return view('set1.editStudentForm', compact('student'));
    }
    public function saveEditStudent(Request $req)
    {
        $student = Students::find($req->id);
        $student->name = $req->name;
        $student->email = $req->email;
        $student->course = $req->course;
        $student->phone = $req->phone;

        $student->save();

        return redirect('set1/index')->with('msg', "Student edited successfully");
    }
    public function deleteStudent($id)
    {
        Students::find($id)->delete();
        return redirect('set1/index')->with('msg', "Student deleted successfully");
    }

    public function addStudent(Request $req)
    {
        $req->validate([
            'name' => 'required',
            'email' => 'unique:students',
            'number' => 'numeric',
            'profile_image' => 'image'
        ]);

        $image = $req->profile_image;
        $name = "upload/" . time() . "." . $image->getClientOriginalExtension();
        $image->move(public_path('upload'), $name);

        // echo "<pre>";
        // print_r($req->all());
        // echo $req->name;
        // echo $name;
        // die;

        Students::insert([
            'name' => $req->name,
            'email' => $req->email,
            'course' => $req->course,
            'phone' => $req->phone,
            'profile_image' => $name
        ]);

        return redirect('set1/index')->with('msg', "Student added successfully");
    }
}

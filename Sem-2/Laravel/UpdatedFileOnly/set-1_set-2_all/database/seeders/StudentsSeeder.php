<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use App\Models\Students;

class StudentsSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        Students::insert([
            [
                'name' => 'student-1', 
                'email' => 's1@gmail.com',
                'course' => 'MCA', 
                'phone' => 9876543210, 
                'profile_image' => 'assets\img\download.svg'
            ],
            [
                'name' => 'student-2',
                'email' => 's2@gmail.com',
                'course' => 'BCA',
                'phone' => 9876543211,
                'profile_image' => 'assets/img/download.svg'
            ],
            [
                'name' => 'student-3',
                'email' => 's3@gmail.com',
                'course' => 'BBA',
                'phone' => 9876543212,
                'profile_image' => 'assets/img/download.svg'
            ],
            [
                'name' => 'student-4',
                'email' => 's4@gmail.com',
                'course' => 'BSC',
                'phone' => 9876543213,
                'profile_image' => 'assets/img/download.svg'
            ],
            [
                'name' => 'student-4',
                'email' => 's5@gmail.com',
                'course' => 'MSC',
                'phone' => 9876543214,
                'profile_image' => 'assets/img/download.svg'
            ]
        ]);
    }
}

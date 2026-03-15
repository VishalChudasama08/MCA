<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class StaffModel extends Model{
    protected $table = 'staff';
    protected $fillable = ['name', 'image', 'position', 'office', 'age', 'start_date', 'salary'];
}

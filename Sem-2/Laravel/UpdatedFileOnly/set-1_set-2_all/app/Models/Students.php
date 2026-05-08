<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Students extends Model
{
    protected $table = 'students';
    protected $fillable = ['name', 'email', 'course', 'phone', 'profile_image'];
}

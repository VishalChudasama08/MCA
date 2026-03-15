<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use App\Models\Category;
use App\Models\User;

class Product extends Model{
    use HasFactory;

    protected $table = 'product';
    protected $fillable = ['name', 'qty', 'price', 'cat_id', 'user_id'];
    
    public function category(){
        return $this->belongsto(Category::class, 'cat_id');
    }

    public function user(){
        return $this->belongsto(User::class, 'user_id');
    }
}

<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class ProductsModel extends Model {
    protected $table = 'products'; // table name 
    protected $fillable = ['p_name', 'p_price', 'p_qty']; //
}

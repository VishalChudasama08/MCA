<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        Schema::create('students', function (Blueprint $table) {
            $table->id();
            //Id , name , email (unique) ,course , phone ,profile_image
            $table->string('name');
            $table->string('email')->unique();
            $table->enum('course', ['MCA', 'BCA', 'BBA', 'BCom', 'BSC', 'MSC']);
            $table->float('phone');
            $table->string('profile_image');
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('students');
    }
};

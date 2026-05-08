<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use App\Models\Products;

class ProductsSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        Products::insert([
            // Phone
            [
                'name' => 'iPhone 15',
                'category' => 'Phone',
                'price' => 79999,
                'quantity' => 10,
                'product_image' => 'upload/phone.jpg'
            ],
            [
                'name' => 'Samsung S24',
                'category' => 'Phone',
                'price' => 74999,
                'quantity' => 8,
                'product_image' => 'upload/phone.jpg'
            ],
            [
                'name' => 'OnePlus 12',
                'category' => 'Phone',
                'price' => 64999,
                'quantity' => 12,
                'product_image' => 'upload/phone.jpg'
            ],
            [
                'name' => 'Realme GT',
                'category' => 'Phone',
                'price' => 35999,
                'quantity' => 15,
                'product_image' => 'upload/phone.jpg'
            ],
            [
                'name' => 'Redmi Note 13',
                'category' => 'Phone',
                'price' => 19999,
                'quantity' => 20,
                'product_image' => 'upload/phone.jpg'
            ],

            // Laptop
            [
                'name' => 'MacBook Air M3',
                'category' => 'Laptop',
                'price' => 114999,
                'quantity' => 5,
                'product_image' => 'upload/laptop.jpg'
            ],
            [
                'name' => 'Dell XPS 15',
                'category' => 'Laptop',
                'price' => 99999,
                'quantity' => 4,
                'product_image' => 'upload/laptop.jpg'
            ],
            [
                'name' => 'HP Pavilion',
                'category' => 'Laptop',
                'price' => 65999,
                'quantity' => 9,
                'product_image' => 'upload/laptop.jpg'
            ],
            [
                'name' => 'Lenovo Legion',
                'category' => 'Laptop',
                'price' => 88999,
                'quantity' => 6,
                'product_image' => 'upload/laptop.jpg'
            ],
            [
                'name' => 'Asus ROG',
                'category' => 'Laptop',
                'price' => 124999,
                'quantity' => 3,
                'product_image' => 'upload/laptop.jpg'
            ],

            // Bike
            [
                'name' => 'Royal Enfield Classic 350',
                'category' => 'Bike',
                'price' => 210000,
                'quantity' => 7,
                'product_image' => 'upload/bike.jpg'
            ],
            [
                'name' => 'KTM Duke 390',
                'category' => 'Bike',
                'price' => 320000,
                'quantity' => 5,
                'product_image' => 'upload/bike.jpg'
            ],
            [
                'name' => 'Yamaha R15',
                'category' => 'Bike',
                'price' => 185000,
                'quantity' => 11,
                'product_image' => 'upload/bike.jpg'
            ],
            [
                'name' => 'Honda Shine',
                'category' => 'Bike',
                'price' => 95000,
                'quantity' => 18,
                'product_image' => 'upload/bike.jpg'
            ],
            [
                'name' => 'TVS Raider',
                'category' => 'Bike',
                'price' => 105000,
                'quantity' => 14,
                'product_image' => 'upload/bike.jpg'
            ],

            // Car
            [
                'name' => 'Hyundai Creta',
                'category' => 'Car',
                'price' => 1450000,
                'quantity' => 4,
                'product_image' => 'upload/car.jpg'
            ],
            [
                'name' => 'Mahindra Scorpio',
                'category' => 'Car',
                'price' => 1750000,
                'quantity' => 3,
                'product_image' => 'upload/car.jpg'
            ],
            [
                'name' => 'Tata Nexon',
                'category' => 'Car',
                'price' => 1200000,
                'quantity' => 6,
                'product_image' => 'upload/car.jpg'
            ],
            [
                'name' => 'Maruti Swift',
                'category' => 'Car',
                'price' => 850000,
                'quantity' => 9,
                'product_image' => 'upload/car.jpg'
            ],
            [
                'name' => 'Toyota Fortuner',
                'category' => 'Car',
                'price' => 4200000,
                'quantity' => 2,
                'product_image' => 'upload/car.jpg'
            ]
        ]);
    }
}

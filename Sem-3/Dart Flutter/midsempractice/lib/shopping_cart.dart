import 'package:flutter/material.dart';

class ShoppingCart extends StatefulWidget {
  const ShoppingCart({super.key});

  @override
  State<ShoppingCart> createState() => _ShoppingCartState();
}

class _ShoppingCartState extends State<ShoppingCart> {
  final List<Map<String, dynamic>> products = [
    {"name": "Flutter Handbook", "price": 450, "qty": 1},
    {"name": "Wireless Mouse", "price": 650, "qty": 0},
    {"name": "Mechanical Keyboard", "price": 2200, "qty": 0},
    {"name": "USB Cable", "price": 150, "qty": 2},
  ];

  int getTotalPrice() {
    int total = 0;
    for (var item in products) {
      total += (item["price"] as int) * (item["qty"] as int);
    }
    return total;
  }

  void incrementQty(int index) {
    setState(() {
      products[index]["qty"]++;
    });
  }

  void decrementQty(int index) {
    setState(() {
      if (products[index]["qty"] > 0) {
        products[index]["qty"]--;
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Shopping Cart"),
        backgroundColor: Colors.blue,
        centerTitle: true,
      ),
      body: Column(
        children: [
          Expanded(
            child: ListView.builder(
              itemCount: products.length,
              itemBuilder: (context, index) {
                final product = products[index];
                return Card(
                  margin: const EdgeInsets.symmetric(horizontal: 12, vertical: 6),
                  child: ListTile(
                    leading: const CircleAvatar(
                      backgroundColor: Colors.blue,
                      child: Icon(Icons.shopping_bag, color: Colors.white),
                    ),
                    title: Text(
                      product["name"],
                      style: const TextStyle(fontWeight: FontWeight.bold),
                    ),
                    subtitle: Text("Price: Rs. ${product['price']}"),
                    trailing: Row(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        IconButton(
                          icon: const Icon(Icons.remove_circle_outline, color: Colors.red),
                          onPressed: () => decrementQty(index),
                        ),
                        Text(
                          "${product['qty']}",
                          style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                        ),
                        IconButton(
                          icon: const Icon(Icons.add_circle_outline, color: Colors.green),
                          onPressed: () => incrementQty(index),
                        ),
                      ],
                    ),
                  ),
                );
              },
            ),
          ),
          Container(
            padding: const EdgeInsets.all(20),
            decoration: BoxDecoration(
              color: Colors.white,
              border: Border(top: BorderSide(color: Colors.grey.shade300, width: 1)),
            ),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text(
                  "Total: Rs. ${getTotalPrice()}",
                  style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold, color: Colors.blue),
                ),
                ElevatedButton(
                  style: ElevatedButton.styleFrom(backgroundColor: Colors.green),
                  onPressed: () {
                    ScaffoldMessenger.of(context).showSnackBar(
                      SnackBar(content: Text("Order placed! Total: Rs. ${getTotalPrice()}")),
                    );
                  },
                  child: const Text("Checkout", style: TextStyle(color: Colors.white)),
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}

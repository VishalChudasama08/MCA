import 'package:flutter/material.dart';

class AdminDashboardApp extends StatefulWidget {
  const AdminDashboardApp({super.key});

  @override
  State<AdminDashboardApp> createState() => _AdminDashboardAppState();
}

class _AdminDashboardAppState extends State<AdminDashboardApp> {
  int totalUsers = 120;
  int totalOrders = 45;
  int totalRevenue = 58000;

  String selectedFilter = "All";
  final List<String> filters = ["All", "Pending", "Completed"];

  final List<Map<String, String>> ordersList = [
    {"id": "#101", "customer": "Rahul Sharma", "status": "Completed", "amount": "Rs. 1,200"},
    {"id": "#102", "customer": "Priya Patel", "status": "Pending", "amount": "Rs. 850"},
    {"id": "#103", "customer": "Amit Joshi", "status": "Completed", "amount": "Rs. 2,400"},
    {"id": "#104", "customer": "Sneha Shah", "status": "Pending", "amount": "Rs. 600"},
  ];

  void addOrder() {
    setState(() {
      totalOrders++;
      totalRevenue += 500;
      ordersList.insert(0, {
        "id": "#10${ordersList.length + 1}",
        "customer": "New Customer",
        "status": "Pending",
        "amount": "Rs. 500",
      });
    });
  }

  void addUser() {
    setState(() {
      totalUsers++;
    });
  }

  @override
  Widget build(BuildContext context) {
    final filteredOrders = selectedFilter == "All"
        ? ordersList
        : ordersList.where((o) => o["status"] == selectedFilter).toList();

    return Scaffold(
      appBar: AppBar(
        title: const Text("Admin Dashboard"),
        backgroundColor: Colors.blue.shade800,
        centerTitle: true,
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            // Row of metric counters (Direct inline Cards as taught in class)
            Row(
              children: [
                Expanded(
                  child: Card(
                    color: Colors.white,
                    child: Padding(
                      padding: const EdgeInsets.all(12.0),
                      child: Column(
                        children: [
                          const Icon(Icons.people, size: 36, color: Colors.blue),
                          const SizedBox(height: 8),
                          Text(
                            "$totalUsers",
                            style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold, color: Colors.blue),
                          ),
                          const SizedBox(height: 4),
                          const Text("Users", style: TextStyle(fontSize: 12, color: Colors.grey)),
                        ],
                      ),
                    ),
                  ),
                ),
                Expanded(
                  child: Card(
                    color: Colors.white,
                    child: Padding(
                      padding: const EdgeInsets.all(12.0),
                      child: Column(
                        children: [
                          const Icon(Icons.shopping_cart, size: 36, color: Colors.orange),
                          const SizedBox(height: 8),
                          Text(
                            "$totalOrders",
                            style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold, color: Colors.orange),
                          ),
                          const SizedBox(height: 4),
                          const Text("Orders", style: TextStyle(fontSize: 12, color: Colors.grey)),
                        ],
                      ),
                    ),
                  ),
                ),
                Expanded(
                  child: Card(
                    color: Colors.white,
                    child: Padding(
                      padding: const EdgeInsets.all(12.0),
                      child: Column(
                        children: [
                          const Icon(Icons.currency_rupee, size: 36, color: Colors.green),
                          const SizedBox(height: 8),
                          Text(
                            "Rs.$totalRevenue",
                            style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold, color: Colors.green),
                          ),
                          const SizedBox(height: 4),
                          const Text("Revenue", style: TextStyle(fontSize: 12, color: Colors.grey)),
                        ],
                      ),
                    ),
                  ),
                ),
              ],
            ),
            const SizedBox(height: 15),

            // Action buttons to update counters
            Row(
              children: [
                Expanded(
                  child: ElevatedButton.icon(
                    onPressed: addOrder,
                    icon: const Icon(Icons.add, color: Colors.white, size: 18),
                    label: const Text("New Order", style: TextStyle(color: Colors.white)),
                    style: ElevatedButton.styleFrom(backgroundColor: Colors.orange),
                  ),
                ),
                const SizedBox(width: 10),
                Expanded(
                  child: ElevatedButton.icon(
                    onPressed: addUser,
                    icon: const Icon(Icons.person_add, color: Colors.white, size: 18),
                    label: const Text("New User", style: TextStyle(color: Colors.white)),
                    style: ElevatedButton.styleFrom(backgroundColor: Colors.blue),
                  ),
                ),
              ],
            ),
            const SizedBox(height: 20),

            // Filter row
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                const Text(
                  "Recent Orders",
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
                ),
                Row(
                  children: filters.map((f) {
                    bool isSelected = selectedFilter == f;
                    return Padding(
                      padding: const EdgeInsets.only(left: 6.0),
                      child: InkWell(
                        onTap: () {
                          setState(() {
                            selectedFilter = f;
                          });
                        },
                        child: Container(
                          padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 5),
                          decoration: BoxDecoration(
                            color: isSelected ? Colors.blue.shade800 : Colors.grey.shade200,
                            borderRadius: BorderRadius.circular(15),
                          ),
                          child: Text(
                            f,
                            style: TextStyle(
                              color: isSelected ? Colors.white : Colors.black87,
                              fontSize: 12,
                              fontWeight: isSelected ? FontWeight.bold : FontWeight.normal,
                            ),
                          ),
                        ),
                      ),
                    );
                  }).toList(),
                ),
              ],
            ),
            const SizedBox(height: 10),

            // Order list filtered
            Expanded(
              child: ListView.builder(
                itemCount: filteredOrders.length,
                itemBuilder: (context, index) {
                  final order = filteredOrders[index];
                  bool isPending = order["status"] == "Pending";
                  return Card(
                    child: ListTile(
                      leading: CircleAvatar(
                        backgroundColor: isPending ? Colors.orange.shade100 : Colors.green.shade100,
                        child: Icon(
                          isPending ? Icons.hourglass_top : Icons.check,
                          color: isPending ? Colors.orange : Colors.green,
                        ),
                      ),
                      title: Text("${order['customer']} (${order['id']})"),
                      subtitle: Text("Status: ${order['status']}"),
                      trailing: Text(
                        "${order['amount']}",
                        style: const TextStyle(fontWeight: FontWeight.bold),
                      ),
                    ),
                  );
                },
              ),
            ),
          ],
        ),
      ),
    );
  }
}

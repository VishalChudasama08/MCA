import 'package:flutter/material.dart';

class ExpenseTracker extends StatefulWidget {
  const ExpenseTracker({super.key});

  @override
  State<ExpenseTracker> createState() => _ExpenseTrackerState();
}

class _ExpenseTrackerState extends State<ExpenseTracker> {
  final List<Map<String, dynamic>> expenses = [
    {"title": "College Books", "amount": 850.0},
    {"title": "Bus Pass", "amount": 350.0},
  ];

  final TextEditingController titleController = TextEditingController();
  final TextEditingController amountController = TextEditingController();

  double getTotalExpense() {
    double total = 0.0;
    for (var item in expenses) {
      total += item["amount"] as double;
    }
    return total;
  }

  void addExpense() {
    String title = titleController.text.trim();
    double? amount = double.tryParse(amountController.text.trim());

    if (title.isEmpty || amount == null || amount <= 0) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text("Please enter a valid title and positive amount"),
          backgroundColor: Colors.red,
        ),
      );
      return;
    }

    setState(() {
      expenses.add({"title": title, "amount": amount});
      titleController.clear();
      amountController.clear();
    });
  }

  void deleteExpense(int index) {
    setState(() {
      expenses.removeAt(index);
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Expense Tracker"),
        backgroundColor: Colors.blue,
        centerTitle: true,
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            Card(
              color: Colors.blue.shade50,
              elevation: 2,
              child: Padding(
                padding: const EdgeInsets.all(16.0),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    const Text(
                      "Total Expenses:",
                      style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
                    ),
                    Text(
                      "Rs. ${getTotalExpense().toStringAsFixed(2)}",
                      style: const TextStyle(
                        fontSize: 22,
                        fontWeight: FontWeight.bold,
                        color: Colors.red,
                      ),
                    ),
                  ],
                ),
              ),
            ),
            const SizedBox(height: 15),
            TextField(
              controller: titleController,
              decoration: const InputDecoration(
                labelText: "Expense Title (e.g. Lunch)",
                prefixIcon: Icon(Icons.description),
                border: OutlineInputBorder(),
              ),
            ),
            const SizedBox(height: 10),
            TextField(
              controller: amountController,
              keyboardType: TextInputType.number,
              decoration: const InputDecoration(
                labelText: "Amount (Rs.)",
                prefixIcon: Icon(Icons.currency_rupee),
                border: OutlineInputBorder(),
              ),
            ),
            const SizedBox(height: 12),
            SizedBox(
              width: double.infinity,
              height: 45,
              child: ElevatedButton(
                onPressed: addExpense,
                style: ElevatedButton.styleFrom(backgroundColor: Colors.blue),
                child: const Text(
                  "Add Expense",
                  style: TextStyle(color: Colors.white, fontSize: 16),
                ),
              ),
            ),
            const SizedBox(height: 15),
            const Divider(),
            Expanded(
              child: expenses.isEmpty
                  ? const Center(
                      child: Text(
                        "No expenses recorded yet",
                        style: TextStyle(color: Colors.grey),
                      ),
                    )
                  : ListView.builder(
                      itemCount: expenses.length,
                      itemBuilder: (context, index) {
                        final item = expenses[index];
                        return Card(
                          child: ListTile(
                            leading: const CircleAvatar(
                              backgroundColor: Colors.redAccent,
                              child: Icon(Icons.money_off, color: Colors.white),
                            ),
                            title: Text(
                              item["title"],
                              style: const TextStyle(fontWeight: FontWeight.bold),
                            ),
                            subtitle: Text("Rs. ${(item['amount'] as double).toStringAsFixed(2)}"),
                            trailing: IconButton(
                              icon: const Icon(Icons.delete, color: Colors.red),
                              onPressed: () => deleteExpense(index),
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

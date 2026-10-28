import 'package:flutter/material.dart';

class CounterApp extends StatefulWidget {
  const CounterApp({super.key});

  @override
  State<CounterApp> createState() => _CounterAppState();
}

class _CounterAppState extends State<CounterApp> {
  int count = 0;

  void increment() {
    setState(() {
      count++;
    });
  }

  void decrement() {
    setState(() {
      if (count > 0) {
        count--;
      }
    });
  }

  void reset() {
    setState(() {
      count = 0;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Counter Application"),
        backgroundColor: Colors.blue,
        centerTitle: true,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const Text(
              "Current Count:",
              style: TextStyle(fontSize: 20, color: Colors.grey),
            ),
            const SizedBox(height: 10),
            Text(
              "$count",
              style: const TextStyle(
                fontSize: 60,
                fontWeight: FontWeight.bold,
                color: Colors.blue,
              ),
            ),
            const SizedBox(height: 30),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                ElevatedButton(
                  onPressed: decrement,
                  style: ElevatedButton.styleFrom(backgroundColor: Colors.red),
                  child: const Text("- Decrement", style: TextStyle(color: Colors.white)),
                ),
                const SizedBox(width: 15),
                ElevatedButton(
                  onPressed: reset,
                  style: ElevatedButton.styleFrom(backgroundColor: Colors.grey),
                  child: const Text("Reset", style: TextStyle(color: Colors.white)),
                ),
                const SizedBox(width: 15),
                ElevatedButton(
                  onPressed: increment,
                  style: ElevatedButton.styleFrom(backgroundColor: Colors.green),
                  child: const Text("+ Increment", style: TextStyle(color: Colors.white)),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}

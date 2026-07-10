import 'package:flutter/material.dart';

class LoanCalculate extends StatelessWidget {
  const LoanCalculate({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.blueGrey,
        title: Text("Loan Calculate", style: TextStyle(color: Colors.orange),),
        centerTitle: true,
        leading: Icon(Icons.calculate_rounded, color: Colors.red),
        actions: [
          Icon(Icons.notifications_active),
        ],
      ),
    );
  }

}
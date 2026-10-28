import 'package:flutter/material.dart';

class LoginScreen extends StatelessWidget {
  LoginScreen({super.key});

  TextEditingController name = TextEditingController();
  TextEditingController password = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Column(
        children: [
          Padding(
            padding: const EdgeInsets.all(8.0),
            child: SizedBox(
              width: 200,
              child: TextField(
                controller: name,
                maxLength: 10,
                keyboardType: TextInputType.number,
                style: const TextStyle(
                  color: Colors.blueAccent
                ),
                decoration: InputDecoration(
                  prefixIcon: Icon(Icons.person),
                  fillColor: Colors.transparent,
                  filled: true,
                  border: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(20)
                  ),
                  label: Text("Name")
                ),
              ),
            ),
          )
        ],
      ),
    );
  }
}
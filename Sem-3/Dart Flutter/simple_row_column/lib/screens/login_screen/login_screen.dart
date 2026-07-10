import 'package:flutter/material.dart';

class LoginScreen extends StatelessWidget{
  LoginScreen({super.key});

  TextEditingController name = TextEditingController();
  TextEditingController email = TextEditingController();
  TextEditingController number = TextEditingController();
  TextEditingController pass = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.orangeAccent,
      appBar: AppBar(
        backgroundColor: Colors.blueAccent,
        title: Text("Register", style: TextStyle(fontSize: 35),),
        leading: Icon(Icons.how_to_reg, size: 35,),
      ),
      body: Column(
        children: [
          Padding(
            padding: const EdgeInsets.all(10),
            child: SizedBox(
              height: 50,
              width: 200,
              child: TextField(
                controller: name,
                decoration: InputDecoration(
                    label: Text("Username"),
                    hintText: "Enter Username",
                    // border: OutlineInputBorder(),
                    focusedBorder: OutlineInputBorder()
                ),
              ),
            ),
          ),
          Padding(
            padding: const EdgeInsets.all(10),
            child: SizedBox(
              height: 50,
              width: 200,
              child: TextField(
                controller: email,
                decoration: InputDecoration(
                    label: Text("Email"),
                    hintText: "Enter Email",
                    // border: OutlineInputBorder(),
                    focusedBorder: OutlineInputBorder()
                ),
              ),
            ),
          ),
          Padding(
            padding: const EdgeInsets.all(10),
            child: SizedBox(
              height: 50,
              width: 200,
              child: TextField(
                controller: number,
                decoration: InputDecoration(
                    label: Text("Number"),
                    hintText: "Enter Number",
                    // border: OutlineInputBorder(),
                    focusedBorder: OutlineInputBorder()
                ),
              ),
            ),
          ),
          Padding(
            padding: const EdgeInsets.all(10),
            child: SizedBox(
              height: 50,
              width: 200,
              child: TextField(
                controller: pass,
                decoration: InputDecoration(
                    label: Text("Password"),
                    hintText: "Enter Password",
                    // border: OutlineInputBorder(),
                    focusedBorder: OutlineInputBorder(borderSide: BorderSide(color: Colors.blueAccent))
                ),
              ),
            ),
          ),
        ],
      ),
    );
  }
}
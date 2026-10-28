import 'package:flutter/material.dart';

class RegisterPage extends StatefulWidget {
  const RegisterPage({super.key});

  @override
  State<RegisterPage> createState() => _RegisterPageState();
}

class _RegisterPageState extends State<RegisterPage> {

  TextEditingController name = TextEditingController();
  TextEditingController address = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.purple,
        title: Text("Registration", style: TextStyle(fontWeight: FontWeight.bold),),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Icon(Icons.add_reaction_outlined, size: 80),
            SizedBox(height: 30,),
            SizedBox(
              width: 500,
              child: Card(
                borderOnForeground: true,

                child: Column(
                  children: [
                    TextField(
                      controller: name,
                      decoration: InputDecoration(
                        labelText: "Enter Your Name",
                        hintText: "Vishal Chudasama",
                        border: OutlineInputBorder()
                      ),
                    ),
                    SizedBox(height: 15,),
                    TextField(
                      controller: address,
                      maxLines: 3,
                      decoration: InputDecoration(
                        labelText: "Enter Your Current address",
                        hintText: "flor, building, area, city, state, pin code",
                        border: OutlineInputBorder(),
                      ),
                    ),
                    SizedBox(height: 15,),


                  ],
                ),
              ),
            )
          ],
        ),
      ),
    );
  }
}
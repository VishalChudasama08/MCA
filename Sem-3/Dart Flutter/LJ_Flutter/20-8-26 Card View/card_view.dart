
import 'package:flutter/material.dart';

class CardView extends StatelessWidget{
  const CardView({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      appBar: AppBar(
        backgroundColor: Colors.green,
        leading:
          IconButton(
              onPressed: (){},
              icon: const Icon(Icons.arrow_back),
          ),
        title: const Text("My Appointments", style: TextStyle(color: Colors.white),),
      ),
      // body: Card(
      //   child: ,
      // ),
    );
  }
}
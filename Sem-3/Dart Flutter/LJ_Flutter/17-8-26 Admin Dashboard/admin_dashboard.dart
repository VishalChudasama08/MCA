
import 'package:flutter/material.dart';

class AdminDashboard extends StatelessWidget{
  const AdminDashboard({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.blue.shade700,
        title: Text(
          "Admin Dashboard",
          style: TextStyle(
            color: Colors.white,
            fontSize: 18,
            fontWeight: FontWeight.bold,
          ),
        ),


        actions: [
          IconButton(
            onPressed: () {  },
            icon: Icon(Icons.notifications, color: Colors.white),
          ),
          IconButton(
              onPressed: (){},
              icon: Icon(Icons.exit_to_app_rounded, color: Colors.white),
          ),
        ],
      ),

      body: Column(
        children: [
          SizedBox(
            height: 50,
            child: Row(
              children: [
                
              ],
            ),
          )
        ],
      ),
    );
  }

}
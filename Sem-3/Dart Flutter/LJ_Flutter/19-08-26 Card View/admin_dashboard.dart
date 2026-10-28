
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
          const Padding(
            padding: EdgeInsets.all(8.0),
            child: Card(
              color: Colors.white,
              child: Padding(
                padding: EdgeInsets.all(8.0),
                child: Row(
                  children: [
                    CircleAvatar(),
                    Column(
                      children: [
                        Text(
                          "Supper Admin",
                          style: TextStyle(
                            fontSize: 12,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                      ],
                    ),
                  ],
                ),
              ),
            ),
          ),
          SizedBox(
            height: 50,
            child: Row(
              children: [
                Container(
                  height: 80,
                  decoration: const BoxDecoration(

                  ),
                ),
              ],
            ),
          )
        ],
      ),
    );
  }

}
import 'package:flutter/material.dart';
import 'package:simple_project/api_services/api_service.dart';
import 'package:simple_project/views/login_page.dart';
import 'package:simple_project/views/products_page.dart';
import 'package:simple_project/views/users_page.dart';

class HomePage extends StatelessWidget {
  const HomePage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        leading: Icon(Icons.pages_rounded, color: Colors.white,),
        title: Text("Dashboard", style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),),
        backgroundColor: Colors.blueAccent,

        actions: [
          TextButton(
            onPressed: (){
              Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => ProductsPage()),
              );
            },
            child: Row(
              children: [
                Icon(Icons.production_quantity_limits_rounded, color: Colors.white,),
                SizedBox(width: 5),
                Text("Product", style: TextStyle(color: Colors.white),)
              ],
            ),
          ),
          TextButton(
            onPressed: (){
              Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => UsersPage())
              );
            },
            child: Row(
              children: [
                Icon(Icons.people_rounded, color: Colors.white,),
                SizedBox(width: 5),
                Text("Users", style: TextStyle(color: Colors.white),),
              ],
            ),
          ),
          TextButton(
              onPressed: (){
                ApiService().logout();
                Navigator.pushReplacement(
                  context,
                  MaterialPageRoute(builder: (context) => LoginPage()),
                );
              },
              child: Row(
                children: [
                  Icon(Icons.login_rounded, color: Colors.white,),
                  SizedBox(width: 5),
                  Text("Logout", style: TextStyle(color: Colors.white),),
                ],
              )
          ),
        ],

      ),
      body: Column(
        children: [
        ],
      ),
    );
  }
}
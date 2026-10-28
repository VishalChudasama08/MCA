import 'package:flutter/material.dart';
import 'package:midsempractice/admin_dashboard.dart';
import 'package:midsempractice/calculator.dart';
import 'package:midsempractice/login_form.dart';

class NavigatePage extends StatelessWidget{
  const NavigatePage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Navigator", style: TextStyle(fontWeight: FontWeight.bold),),
        centerTitle: true,
        backgroundColor: Colors.blueAccent,
      ),
      body: Center(
        child: SizedBox(
          width: 200,
          child: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              ElevatedButton(
                onPressed: (){
                  Navigator.push(
                      context,
                      MaterialPageRoute(
                          builder: (context)=> AdminDashboardApp(),
                      )
                  );
                },
                child: Row(
                  children: [
                    Icon(Icons.label_important_rounded),
                    SizedBox(width: 10,),
                    Text("Admin Dashboard")
                  ],
                )
              ),
              SizedBox(height: 10),
              ElevatedButton(
                onPressed: (){
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context)=>CalculatorApp()
                    ),
                  );
                },
                child: Row(
                  children: [
                    Icon(Icons.label_important_rounded),
                    SizedBox(width: 10,),
                    Text("Calculator")
                  ],
                ),
              ),
              SizedBox(height: 10),
              ElevatedButton(
                  onPressed: (){
                    Navigator.push(context, MaterialPageRoute(
                        builder: (context)=>LoginForm(),
                    ));
                  },
                  child: Row(
                    children: [
                      Icon(Icons.label_important_rounded),
                      SizedBox(width: 10,),
                      Text("Login")
                    ],
                  )
              ),
            ],
          ),
        ),
      ),
    );
  }

}
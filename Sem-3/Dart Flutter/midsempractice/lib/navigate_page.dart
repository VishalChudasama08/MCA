import 'package:flutter/material.dart';
import 'package:midsempractice/admin_dashboard.dart';
import 'package:midsempractice/calculator.dart';
import 'package:midsempractice/counter.dart';
import 'package:midsempractice/counter_app.dart';
import 'package:midsempractice/expense_tracker.dart';
import 'package:midsempractice/grid_list_app.dart';
import 'package:midsempractice/login_form.dart';
import 'package:midsempractice/quiz_app.dart';
import 'package:midsempractice/register_page.dart';
import 'package:midsempractice/shopping_cart.dart';
import 'package:midsempractice/student_registration.dart';
import 'package:midsempractice/todo_list.dart';

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
        child: SingleChildScrollView(
          child: SizedBox(
            width: 444,
            child: Column(
              mainAxisSize: MainAxisSize.min,
              children: [
                Row(
                    children: [
                      Expanded(
                        child: ElevatedButton(
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
                          ),
                        ),
                      ),
                      SizedBox(width: 10,),
                      Expanded(
                        child: ElevatedButton(
                            onPressed: (){
                              Navigator.push(context, MaterialPageRoute(
                                builder: (context)=>RegisterPage(),
                              ));
                            },
                            child: Row(
                              children: [
                                Icon(Icons.label_important_rounded),
                                SizedBox(width: 10,),
                                Text("Register Form")
                              ],
                            )
                        ),
                      ),
                    ]
                ),
                SizedBox(height: 10,),
                Row(
                  children: [
                    Expanded(
                      child: ElevatedButton(
                        onPressed: (){
                          Navigator.push(
                              context,
                              MaterialPageRoute(builder: (context) => CalculatorApp())
                          );
                        },
                        child: Row(
                            children: [
                              Icon(Icons.label_important_rounded),
                              SizedBox(width: 10),
                              Text("Calculator")
                            ]
                        )
                      ),
                    ),
                    SizedBox(width: 10,),
                    Expanded(
                      child: ElevatedButton(
                        onPressed: (){
                          Navigator.push(context, MaterialPageRoute(
                            builder: (context)=>LoginForm(),
                          ));
                        },
                        child: Row(
                          children: [
                            Icon(Icons.label_important_rounded),
                            SizedBox(width: 10,),
                            Text("Login Form")
                          ],
                        )
                      ),
                    ),
                  ],
                ),
                SizedBox(height: 10,),
                Row(
                  children: [
                    Expanded(child: ElevatedButton(
                        onPressed: (){
                          Navigator.push(
                              context,
                              MaterialPageRoute(builder: (context) => CounterApp())
                          );
                        },
                        child: Row(
                            children: [
                              Icon(Icons.label_important_rounded),
                              SizedBox(width: 10),
                              Text("Counter")
                            ]
                        )
                    ),),
                    SizedBox(width: 10,),
                    Expanded(child: ElevatedButton(
                        onPressed: (){
                          Navigator.push(context, MaterialPageRoute(builder: (context) => ExpenseTracker()));
                        },
                        child: Row(
                          children: [
                            Icon(Icons.label_important_rounded),
                            SizedBox(width: 10),
                            Text("Expense Tracker")
                          ],
                        )
                    ),),
                  ],
                ),
                SizedBox(height: 10,),
                Row(
                  children: [
                    Expanded(child: ElevatedButton(
                        onPressed: (){
                          Navigator.push(context, MaterialPageRoute(builder: (context) => QuizApp()));
                        },
                        child: Row(
                          children: [
                            Icon(Icons.label_important_rounded),
                            SizedBox(width: 10),
                            Text("Quiz App")
                          ],
                        )
                    ),),
                    SizedBox(width: 10,),
                    Expanded(child: ElevatedButton(
                        onPressed: (){
                          Navigator.push(context, MaterialPageRoute(builder: (context) => GridListApp()));
                        },
                        child: Row(
                          children: [
                            Icon(Icons.label_important_rounded),
                            SizedBox(width: 10),
                            Text("Grid List App")
                          ],
                        )
                    ),),
                  ],
                ),
                SizedBox(height: 10,),
                Row(
                  children: [
                    Expanded(child: ElevatedButton(
                        onPressed: (){
                          Navigator.push(context, MaterialPageRoute(builder: (context) => ShoppingCart()));
                        },
                        child: Row(
                          children: [
                            Icon(Icons.label_important_rounded),
                            SizedBox(width: 10),
                            Text("Shopping Cart")
                          ],
                        )
                    ),),
                    SizedBox(width: 10,),
                    Expanded(child: ElevatedButton(
                        onPressed: (){
                          Navigator.push(context, MaterialPageRoute(builder: (context) => TodoList()));
                        },
                        child: Row(
                          children: [
                            Icon(Icons.label_important_rounded),
                            SizedBox(width: 10),
                            Text("To Do List")
                          ],
                        )
                    ),),
                  ],
                ),
                SizedBox(height: 10,),
              ],
            )
          ),
        )
      ),
    );
  }

}
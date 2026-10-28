import 'package:flutter/material.dart';

class Counter extends StatefulWidget{
  const Counter({super.key});

  @override
  State<Counter> createState() => _CounterState();
}

class _CounterState extends State<Counter> {
  int count = 0;

  List btn = [
    {Icon(Icons.looks_one_rounded)},
    {Icon(Icons.looks_two_rounded)},
    {Icon(Icons.looks_3_rounded)},
    {Icon(Icons.looks_4_rounded)},
    {Icon(Icons.looks_5_rounded)},
    {Icon(Icons.looks_6_rounded)},

  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey,
      appBar: AppBar(title: Text("Counter"), backgroundColor: Colors.blueAccent,),
      body:
      Center(
        child: Column(
          // crossAxisAlignment: CrossAxisAlignment.center,
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text("Count: $count", style: TextStyle(fontWeight: FontWeight.bold, color: Colors.purple, fontSize: 30)),

            SizedBox(height: 20),
            SizedBox(
              width: 220,
              height: 300,
              child: GridView.builder(
                  gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(crossAxisCount: 3),
                  itemCount: 9,
                  itemBuilder: (context, index){
                    return ElevatedButton(
                        onPressed: (){
                          setState(() {
                            count++;
                          });
                        },
                        child: Icon(Icons.plus_one)
                    );
                  },
              ),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                ElevatedButton(
                    onPressed: (){
                      setState(() {
                        count++;
                      });
                    },
                    child: Icon(Icons.plus_one)
                ),
                // SizedBox(width: 10,),
                ElevatedButton(
                    onPressed: (){
                      setState(() {
                        count--;
                      });
                    },
                    child: Icon(Icons.exposure_minus_1)
                ),
                ElevatedButton(
                    onPressed: (){
                      setState(() {
                        count--;
                      });
                    },
                    child: Icon(Icons.exposure)
                )
              ],
            ),


          ],
        ),
      ),
    );
  }
}
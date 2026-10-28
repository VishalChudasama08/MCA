import 'package:flutter/material.dart';

class GridViewExample extends StatelessWidget {
  GridViewExample({super.key});

  List color = [
    {"color": Colors.red, "name":"abc1"},
    {"color": Colors.green, "name":"abc2"},
    {"color": Colors.amber, "name":"abc3"},
    {"color": Colors.deepPurple, "name":"abc4"},
    {"color": Colors.purpleAccent, "name":"abc5"},
    {"color": Colors.grey, "name":"abc6"},
    {"color": Colors.yellowAccent, "name":"ab7c"},
    {"color": Colors.blue, "name":"abc8"},
    {"color": Colors.cyanAccent, "name":"abc9"},
    {"color": Colors.indigoAccent, "name":"abc10"},
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: GridView.builder(
          gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
            crossAxisCount: 4,
            // crossAxisSpacing: 10
          ),
          itemCount: color.length,
          itemBuilder: (context, index){
            return Center(
              child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: Container(
                  height: 150,
                  width: 150,
                  color: color[index]["color"],
                  child: Text("${color[index]["name"]}"),

                ),
              ),
            );
          }

              // children: [
              //   Padding(
              //     padding: const EdgeInsets.all(8.0),
              //     child: Container(
              //       height: 50,
              //       width: 50,
              //       decoration: const BoxDecoration(
              //         color: Colors.blue,
              //       ),
              //     ),
              //   ),
              //   Padding(
              //     padding: const EdgeInsets.all(8.0),
              //     child: Container(
              //       height: 50,
              //       width: 50,
              //       decoration: const BoxDecoration(
              //         color: Colors.blue,
              //       ),
              //     ),
              //   ),
              //   Padding(
              //     padding: const EdgeInsets.all(8.0),
              //     child: Container(
              //       height: 50,
              //       width: 50,
              //       decoration: const BoxDecoration(
              //         color: Colors.blue,
              //       ),
              //     ),
              //   ),
              //   Padding(
              //     padding: const EdgeInsets.all(8.0),
              //     child: Container(
              //       height: 50,
              //       width: 50,
              //       decoration: const BoxDecoration(
              //         color: Colors.blue,
              //       ),
              //     ),
              //   ),
              //   Padding(
              //     padding: const EdgeInsets.all(8.0),
              //     child: Container(
              //       height: 50,
              //       width: 50,
              //       decoration: const BoxDecoration(
              //         color: Colors.blue,
              //       ),
              //     ),
              //   ),
              //   Padding(
              //     padding: const EdgeInsets.all(8.0),
              //     child: Container(
              //       height: 50,
              //       width: 50,
              //       decoration: const BoxDecoration(
              //         color: Colors.blue,
              //       ),
              //     ),
              //   ),
              //   Padding(
              //     padding: const EdgeInsets.all(8.0),
              //     child: Container(
              //       height: 50,
              //       width: 50,
              //       decoration: const BoxDecoration(
              //         color: Colors.blue,
              //       ),
              //     ),
              //   ),
              // ],

      ),
    );
  }
  
}
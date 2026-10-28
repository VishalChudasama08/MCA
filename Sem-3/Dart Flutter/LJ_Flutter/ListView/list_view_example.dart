import 'package:flutter/material.dart';

class ListViewExample extends StatelessWidget {
  ListViewExample({super.key});

  List color = [
    Colors.red,
    Colors.green,
    Colors.amber,
    Colors.deepPurple,
    Colors.purpleAccent,
    Colors.grey,
    Colors.yellowAccent,
    Colors.blue,
    Colors.cyanAccent,
    Colors.indigoAccent
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: ListView.builder(
          itemCount: 10,
          // scrollDirection: Axis.horizontal,
          itemBuilder: (context, index){
            return Center(
              child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: Container(
                  height: 150,
                  width: 150,
                  decoration: BoxDecoration(
                    color: color[index],
                  ),
                  child: Text("$index"),
                ),
              ),
            );
          }
      ),
      // body: ListView(
      //   children: [
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: Container(
      //         height: 150,
      //         width: 150,
      //         decoration: const BoxDecoration(
      //           color: Colors.blue,
      //         ),
      //       ),
      //     ),
      //   ]
      // ),
    );
  }
}
import 'package:flutter/material.dart';

class HomeScreen extends StatelessWidget {
  const HomeScreen({super.key});

  @override
  Widget build(BuildContext context){
    return Scaffold(
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.center,
        children: [

          Row(
            children: [
              Padding(
                padding: const EdgeInsets.all(8.0),
                child: Container(
                  height: 140,
                  width: 60,
                  decoration: const BoxDecoration(
                      color: Colors.red,
                      borderRadius: BorderRadius.only()
                  ),
                ),
              ),
              Column(
                children: [
                  Row(
                    children: [
                      Padding(
                        padding: const EdgeInsets.all(8.0),
                        child: Container(
                          height: 60,
                          width: 200,
                          decoration: const BoxDecoration(
                              color: Colors.blue,
                              borderRadius: BorderRadius.only()
                          ),
                        ),
                      ),
                      Padding(
                        padding: const EdgeInsets.all(8.0),
                        child: Container(
                          height: 60,
                          width: 60,
                          decoration: BoxDecoration(
                              color: Colors.deepOrangeAccent,
                              borderRadius: BorderRadius.circular(100)
                          ),
                        ),
                      ),
                    ],
                  ),
                  Row(
                    children: [
                      Padding(
                        padding: const EdgeInsets.all(8.0),
                        child: Container(
                          height: 60,
                          width: 200,
                          decoration: const BoxDecoration(
                              color: Colors.blue,
                              borderRadius: BorderRadius.only()
                          ),
                        ),
                      ),
                      Padding(
                        padding: const EdgeInsets.all(8.0),
                        child: Container(
                          height: 60,
                          width: 60,
                          decoration: BoxDecoration(
                              color: Colors.deepOrangeAccent,
                              borderRadius: BorderRadius.circular(100)
                          ),
                        ),
                      ),
                    ],
                  ),
                ],
              ),
              Padding(
                padding: const EdgeInsets.all(8.0),
                child: Container(
                  height: 140,
                  width: 60,
                  decoration: const BoxDecoration(
                      color: Colors.green,
                      borderRadius: BorderRadius.only()
                  ),
                ),
              )
            ],
          ),
          Row(
            children: [
              Padding(
                padding: const EdgeInsets.all(8.0),
                child: Container(
                  height: 60,
                  width: 500,
                  decoration: const BoxDecoration(
                      color: Colors.purple,
                      borderRadius: BorderRadius.only()
                  ),
                ),
              )
            ],
          ),
          Row(
            children: [
              Padding(
                padding: const EdgeInsets.all(8.0),
                child: Container(
                  height: 60,
                  width: 500,
                  decoration: const BoxDecoration(
                      color: Colors.purple,
                      borderRadius: BorderRadius.only()
                  ),
                ),
              )
            ],
          ),
          Row(
            children: [
              Column(
                children: [
                  Row(
                    children: [
                      const Column(
                        children: [],
                      ),
                      Container(
                        height: 60,
                        width: 150,
                        decoration: const BoxDecoration(
                            color: Colors.grey,
                            borderRadius: BorderRadius.only()
                        ),
                      )
                    ],
                  ),

                ],
              )
            ],
          )
        ],
      ),
    );
  }
}
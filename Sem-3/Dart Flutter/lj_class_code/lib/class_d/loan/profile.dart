import 'package:flutter/material.dart';

class ProfileScreen extends StatelessWidget {
  const ProfileScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.blueAccent,
      body: Column(
        children: [
          Row(
            children: [
              Text("My Account",style: TextStyle(
                fontSize: 25
              ),),
              CircleAvatar(),
            ],
          ),
          Row(
            children: [
              Text("Show Dashboard Account Balance",style: TextStyle(
                  fontSize: 15
              ),),
              CircleAvatar(),
            ],
          ),
          Row(
            children: [
              Text("Enable Notification",style: TextStyle(
                  fontSize: 15
              ),),
              CircleAvatar(),
            ],
          ),
          Expanded(
            child: Container(
              decoration: BoxDecoration(
                color: Colors.white70,
                borderRadius: BorderRadius.only(
                  topLeft: Radius.circular(20),
                  topRight: Radius.circular(20),
                )
            ),
              child: Column(
                children: [
                  Expanded(
                    child: ListView.builder(itemBuilder: (context,index){
                      return Padding(
                        padding: const EdgeInsets.all(8.0),
                        child: Container(
                          height: 50,
                          decoration: BoxDecoration(
                              color: Colors.white,
                              borderRadius: BorderRadius.circular(20)
                          ),
                          child: Center(
                            child: ListTile(
                              leading: Icon(Icons.task),
                              title: Text("Load Apply"),
                            ),
                          ),
                        ),
                      );
                    }),
                  )
                ],
              ),

            ),
          )
        ],
      ),
    );
  }
}

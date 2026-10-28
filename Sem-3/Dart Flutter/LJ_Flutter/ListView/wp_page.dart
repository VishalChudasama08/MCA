import 'package:flutter/material.dart';

class WpPage extends StatelessWidget {
   WpPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(

        title: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          mainAxisSize: MainAxisSize.min,
          children: [
            Text("WhatsApp",style: TextStyle(color: Colors.white),),
            Text("Store you data in D: Drive not in C: Drive, your project currently in C: Drive move it and reopen Android Studio", style: TextStyle(color: Colors.black, fontSize: 12)),
          ],
        ),
        backgroundColor: Colors.green,
        actions: const[
          Icon(Icons.search,color: Colors.white),
          SizedBox(width: 10),
          Icon(Icons.more_vert,color: Colors.white),
        ],
      ),

      
      body: ListView.builder(
        itemBuilder: (context, index) {
          return ListTile(
            leading: CircleAvatar(
              backgroundColor: Colors.green,
            ),
            title: Text("Name"),
            subtitle: Text("Name"),
            trailing: Text("Name"),
          );
        },
      ),

    );
  }
}

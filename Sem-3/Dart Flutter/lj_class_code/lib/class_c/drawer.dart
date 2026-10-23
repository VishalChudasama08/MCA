import 'package:flutter/material.dart';
import 'package:get/get.dart';

class DrawerExample extends StatefulWidget {
  const DrawerExample({super.key});

  @override
  State<DrawerExample> createState() => _DrawerExampleState();
}

class _DrawerExampleState extends State<DrawerExample> {
  String? ShowDate;

  void PickDate(BuildContext context)async{
    final Date = await showDatePicker(
        context: context,
        firstDate: DateTime(1900),
        lastDate: DateTime(2100),
        initialDate: DateTime.now()
    );

    setState(() {
      ShowDate = Date.toString();
    });

  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(),
      drawer: Drawer(
        child: ListView(
          children: [
            UserAccountsDrawerHeader(

                accountName: Text("Name"),
                accountEmail: Text("Name@gmail.com"),
            ),
            InkWell(
              onTap: (){
                // Get.to();
              },
              child: ListTile(
                leading: Icon(Icons.person),
                title: Text("Friends"),
              ),
            ),
          ],
        ),
      ),
      body: Column(
        children: [
          ElevatedButton(
              onPressed: (){
                PickDate(context);
              },
              child: Text("Date Picker")
          ),

          Text(ShowDate.toString()),
        ],
      ),
    );
  }
}

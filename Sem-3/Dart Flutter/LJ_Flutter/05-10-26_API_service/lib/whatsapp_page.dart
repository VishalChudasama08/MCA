import 'package:flutter/material.dart';

class WhatsappPage extends StatelessWidget{
  WhatsappPage({super.key});

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
      appBar: AppBar(
        backgroundColor: Colors.green,
        title: const Text("Whatsapp",
          style: TextStyle(color: Colors.white),
        ),
        actions: [
          IconButton(
              onPressed: (){},
              icon: const Icon(Icons.camera_alt_outlined, color: Colors.white)
          ),
          IconButton(
              onPressed: (){},
              icon: const Icon(Icons.search, color: Colors.white)
          ),
          IconButton(
              onPressed: (){},
              icon: const Icon(Icons.menu, color: Colors.white)
          ),
        ],
      ),
      body: ListView.builder(
        itemCount: color.length,
        itemBuilder: (context, index){
          return ListTile(
            leading: CircleAvatar(
              radius: 50,
              foregroundImage: Image.network("https://images.ctfassets.net/hrltx12pl8hq/28ECAQiPJZ78hxatLTa7Ts/2f695d869736ae3b0de3e56ceaca3958/free-nature-images.jpg?fit=fill&w=1200&h=630"),
            ),

            title: const Text("Name"),
            subtitle: const Text("Message"),
          );
        },
      ),
    );
  }

}
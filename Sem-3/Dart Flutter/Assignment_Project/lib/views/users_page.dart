import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:simple_project/controllers/users_controller.dart';

class UsersPage extends StatelessWidget {
  UsersPage({super.key});

  final UsersController controller = Get.put(UsersController());

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Users', style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),),
        backgroundColor: Colors.blueAccent,
        foregroundColor: Colors.white,
      ),

      body: Obx(() {
        if (controller.isLoading.value) {
          return Center(
            child: CircularProgressIndicator(),
          );
        }

        if (controller.errorMessage.isNotEmpty) {
          return Center(
            child: Text(controller.errorMessage.value),
          );
        }

        if (controller.usersData.isEmpty) {
          return Center(
            child: Text('No users found'),
          );
        }

        return ListView.builder(
          itemCount: controller.usersData.length,
          itemBuilder: (context, index) {
            final user = controller.usersData[index];

            var name = "${user.firstName ?? ''} ${user.lastName ?? ''}";
            var email = user.email ?? 'No email';
            var phone = user.phone ?? 'No phone';

            return Card(
              margin: EdgeInsets.all(10),
              child: ListTile(
                leading: CircleAvatar(
                  backgroundImage: user.image != null ? NetworkImage(user.image!) : null,
                ),

                title: Text(name, style: TextStyle(fontWeight: FontWeight.bold),),

                subtitle: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text(email),
                    Text(phone),
                  ],
                ),
              ),
            );
          },
        );
      }),
    );
  }
}
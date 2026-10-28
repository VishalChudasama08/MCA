import 'package:demo/controller/login_controller.dart';
import 'package:demo/screen/login_page.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class HomePage extends StatelessWidget {
  const HomePage({super.key});

  @override
  Widget build(BuildContext context) {
    final LoginController controller = Get.find<LoginController>();
    final user = controller.loginData.value?.userData;

    return Scaffold(
      appBar: AppBar(
        title: const Text("Home"),
        centerTitle: true,
        actions: [
          IconButton(
            icon: const Icon(Icons.logout),
            onPressed: () {
              controller.email.clear();
              controller.password.clear();
              Get.delete<LoginController>();
              Get.offAll(() => const LoginPage());
            },
          ),
        ],
      ),
      body: Padding(
        padding: const EdgeInsets.all(20),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            const Center(
              child: Icon(Icons.account_circle, size: 90, color: Colors.blue),
            ),
            const SizedBox(height: 20),
            Text(
              "Welcome, ${user?.name ?? ''} ${user?.surName ?? ''}",
              style: Theme.of(context).textTheme.headlineSmall,
            ),
            const SizedBox(height: 20),
            _infoTile(Icons.badge, "ID", user?.id),
            _infoTile(Icons.email, "Email", user?.email),
            _infoTile(Icons.calendar_today, "Date", user?.date),
            _infoTile(Icons.access_time, "Time", user?.time),
          ],
        ),
      ),
    );
  }

  Widget _infoTile(IconData icon, String label, String? value) {
    return ListTile(
      leading: Icon(icon),
      title: Text(label),
      subtitle: Text(value ?? "-"),
    );
  }
}

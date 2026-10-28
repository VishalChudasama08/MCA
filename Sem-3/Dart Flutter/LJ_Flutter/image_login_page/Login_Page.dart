import 'package:flutter/material.dart';

class Login_Page extends StatelessWidget {
  Login_Page({super.key});

  TextEditingController name = TextEditingController();
  TextEditingController pass = TextEditingController();
  TextEditingController obscurePassword = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      // body: Column(
      //   crossAxisAlignment: CrossAxisAlignment.center,
      //   mainAxisAlignment: MainAxisAlignment.center,
      //
      //   children: [
      //     Padding(
      //         padding: EdgeInsetsGeometry.all(8),
      //         child: Text(
      //             "Login",
      //             style: TextStyle(color: Colors.cyan, fontSize: 30)
      //         ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: SizedBox(
      //         width: 200,
      //         child: TextField(
      //           controller: name,
      //           maxLength: 10,
      //           keyboardType: TextInputType.number,
      //           style: const TextStyle(
      //               color: Colors.blueAccent
      //           ),
      //           decoration: InputDecoration(
      //               prefixIcon: Icon(Icons.person),
      //               fillColor: Colors.transparent,
      //               filled: true,
      //               border: OutlineInputBorder(
      //                   borderRadius: BorderRadius.circular(20)
      //               ),
      //               label: Text("Name")
      //           ),
      //         ),
      //       ),
      //     ),
      //     Padding(
      //       padding: const EdgeInsets.all(8.0),
      //       child: SizedBox(
      //         width: 200,
      //         child: TextField(
      //           controller: pass,
      //           maxLength: 10,
      //           keyboardType: TextInputType.number,
      //           style: const TextStyle(
      //               color: Colors.blueAccent
      //           ),
      //           decoration: InputDecoration(
      //               prefixIcon: Icon(Icons.lock),
      //               fillColor: Colors.transparent,
      //               filled: true,
      //               border: OutlineInputBorder(
      //                   borderRadius: BorderRadius.circular(20)
      //               ),
      //               label: Text("Password")
      //           ),
      //         ),
      //       ),
      //     )
      //   ],
      // ),
      body: Padding(
        padding: const EdgeInsets.all(20),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const Icon(
              Icons.person,
              size: 80,
              color: Colors.blue,
            ),

            const SizedBox(height: 30),

            TextField(
              controller: name,
              decoration: const InputDecoration(
                labelText: "Email",
                border: OutlineInputBorder(),
                prefixIcon: Icon(Icons.email),
              ),
            ),

            const SizedBox(height: 20),

            TextField(
              controller: pass,
              obscureText: obscurePassword,
              decoration: InputDecoration(
                labelText: "Password",
                border: const OutlineInputBorder(),
                prefixIcon: const Icon(Icons.lock),
                suffixIcon: IconButton(
                  icon: Icon(
                    obscurePassword
                        ? Icons.visibility
                        : Icons.visibility_off,
                  ),
                  onPressed: () {
                    setState(() {
                      obscurePassword = !obscurePassword;
                    });
                  },
                ),
              ),
            ),

            const SizedBox(height: 25),

            SizedBox(
              width: double.infinity,
              child: ElevatedButton(
                onPressed: login,
                child: const Text("Login"),
              ),
            ),
          ],
        ),
      ),
    );
  }

}
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:lj/class_b/firebase/login_controller.dart';
import 'package:lj/class_b/firebase/login_controller.dart';

class LoginScreen extends StatefulWidget {
  const LoginScreen({super.key});

  @override
  State<LoginScreen> createState() => _LoginScreenState();
}

class _LoginScreenState extends State<LoginScreen> {
  final LoginController controller = Get.put(LoginController());

  void login() {
    if (!controller.formKey.currentState!.validate()) {
      return;
    }
    controller.login();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: SingleChildScrollView(
          padding: const EdgeInsets.all(24),
          child: ConstrainedBox(
            constraints: BoxConstraints(maxWidth: 400),
            child: Form(
              key: controller.formKey,
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: [
                  Icon(
                    Icons.lock_outline,
                    size: 70,
                  ),

                  SizedBox(height: 20),

                  Text(
                    'Welcome Back',
                    textAlign: TextAlign.center,
                    style: TextStyle(
                      color: Colors.black,
                      fontSize: 28,
                      fontWeight: FontWeight.bold,
                    ),
                  ),

                  SizedBox(height: 8),

                  Text(
                    'Login to your account',
                    textAlign: TextAlign.center,
                    style: TextStyle(
                      color: Colors.grey,
                    ),
                  ),

                  SizedBox(height: 40),

                  TextFormField(
                    controller: controller.emailController,
                    keyboardType: TextInputType.emailAddress,
                    decoration: const InputDecoration(
                      labelText: 'Email',
                      prefixIcon: Icon(Icons.email_outlined),
                      border: OutlineInputBorder(),
                    ),
                    validator: (value) {
                      if (value == null || value.trim().isEmpty) {
                        return 'Please enter your email';
                      }
                      if (!GetUtils.isEmail(value.trim())) {
                        return 'Please enter a valid email';
                      }
                      return null;
                    },
                  ),

                  SizedBox(height: 16),

                  TextFormField(
                    controller: controller.passwordController,
                    obscureText: controller.hidePassword.value,
                    decoration: InputDecoration(
                      labelText: 'Password',
                      prefixIcon: const Icon(Icons.lock_outline),
                      border: const OutlineInputBorder(),
                      suffixIcon: IconButton(
                        icon: Icon(
                          controller.hidePassword.value
                              ? Icons.visibility
                              : Icons.visibility_off,
                        ),
                        onPressed: () {
                          setState(() {
                            controller.hidePassword.value = !controller.hidePassword.value;
                          });
                        },
                      ),
                    ),
                    validator: (value) {
                      if (value == null || value.isEmpty) {
                        return 'Please enter your password';
                      }

                      if (value.length < 6) {
                        return 'Password must be at least 6 characters';
                      }

                      return null;
                    },
                  ),

                  SizedBox(height: 24),

                  Obx(
                   () => SizedBox(
                      height: 50,
                      child: ElevatedButton(
                        onPressed:
                        controller.isLoading.value ? null : login,
                        child: controller.isLoading.value
                            ? Center(child: const CircularProgressIndicator())
                            : const Text(
                          'LOGIN',
                          style: TextStyle(fontSize: 16),
                        ),
                      ),
                    ),
                  ),
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }
}

// import 'package:flutter/material.dart';
// import 'package:get/get.dart';
// import 'login_controller.dart';
//
// class LoginView extends StatelessWidget {
//   LoginView({super.key});
//
//   LoginController controller = Get.put(LoginController());
//
//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       body: SafeArea(
//         child: Center(
//           child: SingleChildScrollView(
//             padding: const EdgeInsets.all(24),
//             child: Column(
//               mainAxisSize: MainAxisSize.min,
//               children: [
//                 const Icon(
//                   Icons.lock_outline,
//                   size: 80,
//                   color: Colors.blue,
//                 ),
//
//                 const SizedBox(height: 20),
//
//                 const Text(
//                   'Welcome Back',
//                   style: TextStyle(
//                     fontSize: 30,
//                     fontWeight: FontWeight.bold,
//                   ),
//                 ),
//
//                 const SizedBox(height: 8),
//
//                 const Text(
//                   'Login with your email and password',
//                   style: TextStyle(
//                     color: Colors.grey,
//                   ),
//                 ),
//
//                 const SizedBox(height: 40),
//
//                 TextField(
//                   controller: controller.emailController,
//                   keyboardType: TextInputType.emailAddress,
//                   decoration: const InputDecoration(
//                     labelText: 'Email',
//                     hintText: 'Enter your email',
//                     prefixIcon: Icon(Icons.email_outlined),
//                     border: OutlineInputBorder(),
//                   ),
//                 ),
//
//                 const SizedBox(height: 16),
//
//                 Obx(
//                       () => TextField(
//                     controller: controller.passwordController,
//                     obscureText: controller.hidePassword.value,
//                     decoration: InputDecoration(
//                       labelText: 'Password',
//                       hintText: 'Enter your password',
//                       prefixIcon: const Icon(Icons.lock_outline),
//                       border: const OutlineInputBorder(),
//                       suffixIcon: IconButton(
//                         onPressed: controller.togglePasswordVisibility,
//                         icon: Icon(
//                           controller.hidePassword.value
//                               ? Icons.visibility
//                               : Icons.visibility_off,
//                         ),
//                       ),
//                     ),
//                   ),
//                 ),
//
//                 const SizedBox(height: 24),
//
//                 Obx(
//                   () => SizedBox(
//                     width: double.infinity,
//                     height: 52,
//                     child: ElevatedButton(
//                       onPressed: controller.isLoading.value
//                           ? null
//                           : controller.login,
//                       child: controller.isLoading.value
//                      ? const SizedBox(
//                         width: 24,
//                         height: 24,
//                         child: CircularProgressIndicator(
//                           strokeWidth: 2,
//                         ),
//                       )
//                      : const Text(
//                         'Login',
//                         style: TextStyle(
//                           fontSize: 16,
//                         ),
//                       ),
//                     ),
//                   ),
//                 ),
//               ],
//             ),
//           ),
//         ),
//       ),
//     );
//   }
// }

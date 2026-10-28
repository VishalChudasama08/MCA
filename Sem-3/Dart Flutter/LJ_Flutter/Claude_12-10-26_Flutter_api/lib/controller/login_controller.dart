import 'package:demo/model/login_model.dart';
import 'package:demo/screen/home_page.dart';
import 'package:demo/service/api_service.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class LoginController extends GetxController {
  final TextEditingController email = TextEditingController();
  final TextEditingController password = TextEditingController();

  final ApiServices _api = ApiServices();

  // Observable state
  final RxBool isLoading = false.obs;
  final RxBool obscurePassword = true.obs;
  final Rxn<LoginModel> loginData = Rxn<LoginModel>();

  void togglePassword() {
    obscurePassword.value = !obscurePassword.value;
  }

  Future<void> login() async {
    if (email.text.trim().isEmpty || password.text.trim().isEmpty) {
      Get.snackbar(
        "Error",
        "Please enter email and password",
        snackPosition: SnackPosition.BOTTOM,
      );
      return;
    }

    try {
      isLoading.value = true;

      final result = await _api.login(email.text.trim(), password.text.trim());
      loginData.value = result;

      if (result.status == "success" || result.userData != null) {
        Get.snackbar(
          "Success",
          result.message ?? "Login successful",
          snackPosition: SnackPosition.BOTTOM,
        );
        Get.off(() => const HomePage());
      } else {
        Get.snackbar(
          "Login failed",
          result.message ?? "Invalid email or password",
          snackPosition: SnackPosition.BOTTOM,
        );
      }
    } catch (e) {
      Get.snackbar(
        "Error",
        "Something went wrong. Please try again.",
        snackPosition: SnackPosition.BOTTOM,
      );
    } finally {
      isLoading.value = false;
    }
  }

  @override
  void onClose() {
    email.dispose();
    password.dispose();
    super.onClose();
  }
}

import 'dart:convert';

import 'package:http/http.dart' as http;

import '../model/login_model.dart';

class ApiServices {
  static const String _baseUrl = "https://www.anniecabs.com/LJ/index.php/api";

  Future<LoginModel> login(String email, String password) async {
    try {
      final response = await http.post(
        Uri.parse("$_baseUrl/login"),
        body: {
          "Email": email,
          "Password": password,
        },
      );

      if (response.statusCode == 200 || response.statusCode == 201) {
        final jsonData = jsonDecode(response.body);
        return LoginModel.fromJson(jsonData);
      } else {
        throw Exception("Server error: ${response.statusCode}");
      }
    } catch (e) {
      print("Error $e");
      throw Exception("Error: $e");
    }
  }
}

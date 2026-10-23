import 'dart:convert';

import 'package:firebase_auth/firebase_auth.dart';
import 'package:simple_project/models/users_model.dart';
import 'package:http/http.dart' as http;

import '../models/products_model.dart';


class ApiService {
  Future<void> logout() async {
    await FirebaseAuth.instance.signOut();
  }
  Future<ProductsModel> products() async {
    try {
      final response = await http.get(Uri.parse("https://dummyjson.com/products"));

      if(response.statusCode == 200) {
        final jsonData = jsonDecode(response.body);
        return ProductsModel.fromJson(jsonData);
      } else {
        int? sCode = response.statusCode;
        throw Exception("StatusCode: $sCode \nError on fetching Products");
      }
    } catch (e) {
      print(e);
      throw Exception("Error on fetching Products");
    }
  }
  
  Future<UsersModel> users() async {
    try {
      final response = await http.get(Uri.parse("https://dummyjson.com/users"));
      if(response.statusCode == 200) {
        final jsonData = jsonDecode(response.body);
        return UsersModel.fromJson(jsonData);
      } else {
        int? sCode = response.statusCode;
        throw Exception("StatusCode: $sCode \nError on fetching Users data");
      }
    } catch (e) {
      print(e);
      throw Exception("Error on fetching Users data");
    }
  }
}
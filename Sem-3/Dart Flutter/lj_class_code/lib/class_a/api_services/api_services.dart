import 'dart:convert';

import 'package:dio/dio.dart';
import 'package:http/http.dart' as http;
import 'package:lj/class_a/login/login_model.dart';
import 'package:lj/class_a/tree_plant/tree_model.dart';

class ApiServices{
  
  Dio dio = Dio();

  Future<login> Login() async{

    try {
      final respo = await http.post(
          Uri.parse("https://www.anniecabs.com/LJ/index.php/api/login"));
      print(respo);

      if (respo.statusCode == 200 || respo.statusCode == 201) {
        final Map<String, dynamic> jsonData = jsonDecode(respo.body);

        final user_value = login.fromJson(jsonData);
        return user_value;
      } else {
        throw Exception("Error!!!!");
      }
    }catch(e){
      print(e.toString());
      throw Exception("Error!!!!");
    }
  }
  
  Future<tree> Tree() async{
    try{
      final respo = await dio.get("https://www.anniecabs.com/LJ/index.php/api/get_tree_plant",
      // data: {
      //   "Email": email,
      //   "Password": password
      // }
      );

      if(respo.statusCode == 200){
        final value = tree.fromJson(respo.data);
        return value;
      }else{
        throw Exception("Error");
      }
    }catch(e){
      print(e);
      throw Exception("Error");
    }
  }

}
import 'package:get/get.dart';

import '../../class_a/api_services/api_services.dart';

class TreeController extends GetxController{

  Future<void> TreeCont()async{
    try{
      final respo = ApiServices().Tree();

      // if(){
      //
      // }else{
      //
      // }
    }catch(e){
      print(e);
     Get.snackbar("", "");
    }
  }

}
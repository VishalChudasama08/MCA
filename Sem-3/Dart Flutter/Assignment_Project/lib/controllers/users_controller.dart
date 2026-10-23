import 'package:get/get.dart';
import 'package:simple_project/api_services/api_service.dart';
import 'package:simple_project/models/users_model.dart';

class UsersController extends GetxController {
  // .obs → Makes the data observable by GetX, so Obx() can update the UI when the list changes.
  var usersData = <Users>[].obs;
  var isLoading = false.obs;
  var errorMessage = ''.obs;

  @override
  void onInit() { // onInit() is a lifecycle method provided by GetxController
    super.onInit();
    usersController();
  }

  Future<void> usersController() async {
    isLoading.value = true;
    errorMessage.value = '';

    try {
      final response = await ApiService().users();

      // set usersData value for list all users
      // response have 'users' then store it else store []
      usersData.assignAll(response.users ?? []);
    } catch (e) {
      errorMessage.value = 'Error fetching users data';
      print(e);
    } finally {
      isLoading.value = false;
    }
  }
}
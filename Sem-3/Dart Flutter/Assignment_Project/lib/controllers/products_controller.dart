import 'package:get/get.dart';
import 'package:simple_project/api_services/api_service.dart';
import 'package:simple_project/models/products_model.dart';

class ProductsController extends GetxController {
  var productsData = <Products>[].obs;
  var isLoading = false.obs;
  var errorMessage = ''.obs;

  @override
  void onInit(){
    super.onInit();
    productsController();
  }

  Future<void> productsController() async {
    isLoading.value = true;
    errorMessage.value = '';

    try {
      final response = await ApiService().products();

      productsData.assignAll(response.products ?? []);
    } catch (e) {
      errorMessage.value = '$e \nError on fetching products';
    } finally {
      isLoading.value = false;
    }
  }
}
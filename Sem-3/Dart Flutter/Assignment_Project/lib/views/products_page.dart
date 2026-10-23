import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:simple_project/controllers/products_controller.dart';

class ProductsPage extends StatelessWidget {
  ProductsPage({super.key});

  final ProductsController controller = Get.put(ProductsController());

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Products', style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),),
        backgroundColor: Colors.blueAccent,
        foregroundColor: Colors.white,
      ),
      body: Obx(() {
        if (controller.isLoading.value) {
          return Center(child: CircularProgressIndicator());
        }

        if (controller.errorMessage.isNotEmpty) {
          return Center(child: Text(controller.errorMessage.value));
        }

        if (controller.productsData.isEmpty) {
          return Center(child: Text('No products found'));
        }

        return GridView.builder(
          padding: EdgeInsets.all(8),
          gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
            crossAxisCount: 5,
            crossAxisSpacing: 8,
            mainAxisSpacing: 8,
            childAspectRatio: 0.60,
          ),

          itemCount: controller.productsData.length,
          itemBuilder: (context, index) {
            final product = controller.productsData[index];

            return Card(
              child: Column(
                children: [
                    Expanded(
                    child: SizedBox(
                      width: double.infinity,
                      child: product.thumbnail != null ? Image.network(product.thumbnail!) : Icon(Icons.image_not_supported),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(8),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text(
                          product.title ?? 'No title',
                          maxLines: 2,
                          overflow: TextOverflow.ellipsis,
                          style: const TextStyle(
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                        const SizedBox(height: 5),
                        Text('\$${product.price ?? 0}'),
                        const SizedBox(height: 5),
                        Row(
                          children: [
                            const Icon(Icons.star, color: Colors.orange, size: 18),
                            Text('${product.rating ?? 0}'),
                          ],
                        ),
                      ],
                    ),
                  ),
                ],
              ),
            );
          },
        );
      }),
    );
  }
}
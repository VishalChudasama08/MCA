import 'package:flutter/material.dart';

class GridListApp extends StatefulWidget {
  const GridListApp({super.key});

  @override
  State<GridListApp> createState() => _GridListAppState();
}

class _GridListAppState extends State<GridListApp> {
  bool isGridView = true;

  final List<Map<String, dynamic>> topics = [
    {"title": "Flutter Basics", "icon": Icons.flutter_dash, "color": Colors.blue},
    {"title": "Stateful Widget", "icon": Icons.code, "color": Colors.indigo},
    {"title": "Layouts & Rows", "icon": Icons.view_column, "color": Colors.teal},
    {"title": "ListView Builder", "icon": Icons.list_alt, "color": Colors.orange},
    {"title": "GridView Items", "icon": Icons.grid_view, "color": Colors.purple},
    {"title": "Navigation & Routes", "icon": Icons.directions, "color": Colors.red},
  ];

  void onItemTapped(String title) {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: Text("You tapped on: $title"),
        duration: const Duration(seconds: 1),
        backgroundColor: Colors.blue.shade700,
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(isGridView ? "Topics Grid View" : "Topics List View"),
        backgroundColor: Colors.blue,
        centerTitle: true,
        actions: [
          IconButton(
            tooltip: "Toggle View Mode",
            icon: Icon(isGridView ? Icons.view_list : Icons.grid_view),
            onPressed: () {
              setState(() {
                isGridView = !isGridView;
              });
            },
          ),
        ],
      ),
      body: Padding(
        padding: const EdgeInsets.all(12.0),
        child: isGridView
            ? GridView.builder(
                itemCount: topics.length,
                gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                  crossAxisCount: 2,
                  crossAxisSpacing: 12,
                  mainAxisSpacing: 12,
                ),
                itemBuilder: (context, index) {
                  final item = topics[index];
                  return Card(
                    elevation: 3,
                    shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                    child: InkWell(
                      borderRadius: BorderRadius.circular(12),
                      onTap: () => onItemTapped(item["title"]),
                      child: Center(
                        child: Column(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            CircleAvatar(
                              radius: 30,
                              backgroundColor: (item["color"] as Color).withOpacity(0.15),
                              child: Icon(item["icon"] as IconData, size: 32, color: item["color"] as Color),
                            ),
                            const SizedBox(height: 12),
                            Text(
                              item["title"],
                              textAlign: TextAlign.center,
                              style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 14),
                            ),
                          ],
                        ),
                      ),
                    ),
                  );
                },
              )
            : ListView.builder(
                itemCount: topics.length,
                itemBuilder: (context, index) {
                  final item = topics[index];
                  return Card(
                    margin: const EdgeInsets.symmetric(vertical: 6),
                    child: ListTile(
                      leading: CircleAvatar(
                        backgroundColor: (item["color"] as Color).withOpacity(0.15),
                        child: Icon(item["icon"] as IconData, color: item["color"] as Color),
                      ),
                      title: Text(
                        item["title"],
                        style: const TextStyle(fontWeight: FontWeight.bold),
                      ),
                      subtitle: const Text("Tap to view details"),
                      trailing: const Icon(Icons.arrow_forward_ios, size: 16),
                      onTap: () => onItemTapped(item["title"]),
                    ),
                  );
                },
              ),
      ),
    );
  }
}

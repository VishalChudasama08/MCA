import 'package:flutter/material.dart';

class TodoList extends StatefulWidget {
  const TodoList({super.key});

  @override
  State<TodoList> createState() => _TodoListState();
}

class _TodoListState extends State<TodoList> {
  final List<Map<String, dynamic>> tasks = [];
  final TextEditingController taskController = TextEditingController();

  void addTask() {
    String text = taskController.text.trim();
    if (text.isEmpty) return;

    setState(() {
      tasks.add({"title": text, "isDone": false});
      taskController.clear();
    });
  }

  void toggleTask(int index) {
    setState(() {
      tasks[index]["isDone"] = !tasks[index]["isDone"];
    });
  }

  void deleteTask(int index) {
    setState(() {
      tasks.removeAt(index);
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("To-Do List"),
        backgroundColor: Colors.blue,
        centerTitle: true,
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            Row(
              children: [
                Expanded(
                  child: TextField(
                    controller: taskController,
                    decoration: const InputDecoration(
                      labelText: "Enter Task Title",
                      border: OutlineInputBorder(),
                    ),
                  ),
                ),
                const SizedBox(width: 10),
                ElevatedButton(
                  onPressed: addTask,
                  style: ElevatedButton.styleFrom(backgroundColor: Colors.blue),
                  child: const Text("Add", style: TextStyle(color: Colors.white)),
                ),
              ],
            ),
            const SizedBox(height: 20),
            Expanded(
              child: tasks.isEmpty
                  ? const Center(
                      child: Text(
                        "No tasks added yet!",
                        style: TextStyle(fontSize: 16, color: Colors.grey),
                      ),
                    )
                  : ListView.builder(
                      itemCount: tasks.length,
                      itemBuilder: (context, index) {
                        final task = tasks[index];
                        return Card(
                          child: ListTile(
                            leading: IconButton(
                              icon: Icon(
                                task["isDone"]
                                    ? Icons.check_circle
                                    : Icons.circle_outlined,
                                color: task["isDone"] ? Colors.green : Colors.grey,
                              ),
                              onPressed: () => toggleTask(index),
                            ),
                            title: Text(
                              task["title"],
                              style: TextStyle(
                                decoration: task["isDone"]
                                    ? TextDecoration.lineThrough
                                    : TextDecoration.none,
                                color: task["isDone"] ? Colors.grey : Colors.black,
                              ),
                            ),
                            trailing: IconButton(
                              icon: const Icon(Icons.delete, color: Colors.red),
                              onPressed: () => deleteTask(index),
                            ),
                          ),
                        );
                      },
                    ),
            ),
          ],
        ),
      ),
    );
  }
}

import 'package:flutter/material.dart';

class StudentRegistration extends StatefulWidget {
  const StudentRegistration({super.key});

  @override
  State<StudentRegistration> createState() => _StudentRegistrationState();
}

class _StudentRegistrationState extends State<StudentRegistration> {
  final TextEditingController nameController = TextEditingController();
  final TextEditingController rollController = TextEditingController();

  String selectedCourse = "MCA";
  final List<String> courses = ["MCA", "BCA", "M.Sc. IT", "B.Tech"];

  bool isAgreed = false;

  void registerStudent() {
    String name = nameController.text.trim();
    String roll = rollController.text.trim();

    if (name.isEmpty || roll.isEmpty) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text("Error: Please enter Name and Roll Number"),
          backgroundColor: Colors.red,
        ),
      );
      return;
    }

    if (!isAgreed) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text("Error: Please accept the terms and conditions"),
          backgroundColor: Colors.red,
        ),
      );
      return;
    }

    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: Text("Student Registered: $name ($selectedCourse)"),
        backgroundColor: Colors.green,
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Student Registration"),
        backgroundColor: Colors.blue,
        centerTitle: true,
      ),
      body: Padding(
        padding: const EdgeInsets.all(20.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            TextField(
              controller: nameController,
              decoration: const InputDecoration(
                labelText: "Student Name",
                prefixIcon: Icon(Icons.person),
                border: OutlineInputBorder(),
              ),
            ),
            const SizedBox(height: 15),
            TextField(
              controller: rollController,
              decoration: const InputDecoration(
                labelText: "Roll Number",
                prefixIcon: Icon(Icons.badge),
                border: OutlineInputBorder(),
              ),
            ),
            const SizedBox(height: 15),
            const Text(
              "Select Course:",
              style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 5),
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 12),
              decoration: BoxDecoration(
                border: Border.all(color: Colors.grey),
                borderRadius: BorderRadius.circular(4),
              ),
              child: DropdownButton<String>(
                value: selectedCourse,
                isExpanded: true,
                underline: const SizedBox(),
                items: courses.map((String course) {
                  return DropdownMenuItem<String>(
                    value: course,
                    child: Text(course),
                  );
                }).toList(),
                onChanged: (String? newValue) {
                  if (newValue != null) {
                    setState(() {
                      selectedCourse = newValue;
                    });
                  }
                },
              ),
            ),
            const SizedBox(height: 15),
            InkWell(
              onTap: () {
                setState(() {
                  isAgreed = !isAgreed;
                });
              },
              child: Row(
                children: [
                  Icon(
                    isAgreed ? Icons.check_box : Icons.check_box_outline_blank,
                    color: isAgreed ? Colors.blue : Colors.grey,
                  ),
                  const SizedBox(width: 10),
                  const Text("I agree to all terms and conditions"),
                ],
              ),
            ),
            const SizedBox(height: 25),
            SizedBox(
              width: double.infinity,
              height: 45,
              child: ElevatedButton(
                onPressed: registerStudent,
                style: ElevatedButton.styleFrom(backgroundColor: Colors.blue),
                child: const Text(
                  "Register Student",
                  style: TextStyle(color: Colors.white, fontSize: 18),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

import 'package:flutter/material.dart';

class QuizApp extends StatefulWidget {
  const QuizApp({super.key});

  @override
  State<QuizApp> createState() => _QuizAppState();
}

class _QuizAppState extends State<QuizApp> {
  int currentQuestion = 0;
  int score = 0;
  bool isFinished = false;

  final List<Map<String, dynamic>> questions = [
    {
      "question": "1. What is Flutter?",
      "options": ["UI Framework", "Database", "Operating System", "Programming Language"],
      "answer": 0,
    },
    {
      "question": "2. Which language is used to build Flutter apps?",
      "options": ["Java", "Dart", "Python", "Swift"],
      "answer": 1,
    },
    {
      "question": "3. Which widget cannot change its state once built?",
      "options": ["StatefulWidget", "InheritedWidget", "StatelessWidget", "StreamBuilder"],
      "answer": 2,
    },
  ];

  void checkAnswer(int selectedIndex) {
    if (selectedIndex == questions[currentQuestion]["answer"]) {
      score++;
    }

    setState(() {
      if (currentQuestion < questions.length - 1) {
        currentQuestion++;
      } else {
        isFinished = true;
      }
    });
  }

  void restartQuiz() {
    setState(() {
      currentQuestion = 0;
      score = 0;
      isFinished = false;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Quiz Application"),
        backgroundColor: Colors.blue,
        centerTitle: true,
      ),
      body: Padding(
        padding: const EdgeInsets.all(20.0),
        child: isFinished
            ? Center(
                child: Card(
                  elevation: 4,
                  shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                  child: Padding(
                    padding: const EdgeInsets.all(24.0),
                    child: Column(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        const Icon(Icons.emoji_events, size: 70, color: Colors.amber),
                        const SizedBox(height: 15),
                        const Text(
                          "Quiz Completed!",
                          style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold),
                        ),
                        const SizedBox(height: 10),
                        Text(
                          "Your Score: $score / ${questions.length}",
                          style: const TextStyle(fontSize: 18, color: Colors.blue, fontWeight: FontWeight.bold),
                        ),
                        const SizedBox(height: 25),
                        ElevatedButton(
                          onPressed: restartQuiz,
                          style: ElevatedButton.styleFrom(backgroundColor: Colors.blue),
                          child: const Text("Restart Quiz", style: TextStyle(color: Colors.white)),
                        ),
                      ],
                    ),
                  ),
                ),
              )
            : Column(
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: [
                  Text(
                    "Question ${currentQuestion + 1} of ${questions.length}",
                    style: const TextStyle(fontSize: 16, color: Colors.grey),
                  ),
                  const SizedBox(height: 12),
                  Text(
                    questions[currentQuestion]["question"],
                    style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
                  ),
                  const SizedBox(height: 25),
                  ...List.generate(
                    (questions[currentQuestion]["options"] as List).length,
                    (index) {
                      String optionText = questions[currentQuestion]["options"][index];
                      return Padding(
                        padding: const EdgeInsets.symmetric(vertical: 6.0),
                        child: ElevatedButton(
                          style: ElevatedButton.styleFrom(
                            backgroundColor: Colors.blue.shade50,
                            foregroundColor: Colors.blue.shade900,
                            padding: const EdgeInsets.all(15),
                            alignment: Alignment.centerLeft,
                          ),
                          onPressed: () => checkAnswer(index),
                          child: Text(
                            optionText,
                            style: const TextStyle(fontSize: 16),
                          ),
                        ),
                      );
                    },
                  ),
                ],
              ),
      ),
    );
  }
}

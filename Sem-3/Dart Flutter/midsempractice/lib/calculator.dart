import 'package:flutter/material.dart';

class CalculatorApp extends StatefulWidget {
  const CalculatorApp({super.key});

  @override
  State<CalculatorApp> createState() => _CalculatorAppState();
}

class _CalculatorAppState extends State<CalculatorApp> {
  String output = "0";
  double num1 = 0;
  double num2 = 0;
  String operand = "";

  final List<String> buttons = [
    "7", "8", "9", "/",
    "4", "5", "6", "*",
    "1", "2", "3", "-",
    "C", "0", "=", "+"
  ];

  void buttonPressed(String btnText) {
    if (btnText == "C") {
      output = "0";
      num1 = 0;
      num2 = 0;
      operand = "";
    } else if (btnText == "+" || btnText == "-" || btnText == "*" || btnText == "/") {
      num1 = double.parse(output);
      operand = btnText;
      output = "0";
    } else if (btnText == "=") {
      num2 = double.parse(output);

      if (operand == "+") {
        output = (num1 + num2).toString();
      }
      if (operand == "-") {
        output = (num1 - num2).toString();
      }
      if (operand == "*") {
        output = (num1 * num2).toString();
      }
      if (operand == "/") {
        output = num2 != 0 ? (num1 / num2).toString() : "Error";
      }

      num1 = 0;
      num2 = 0;
      operand = "";
    } else {
      if (output == "0") {
        output = btnText;
      } else {
        output = output + btnText;
      }
    }

    setState(() {});
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Simple Calculator"),
        backgroundColor: Colors.blue,
        centerTitle: true,
      ),
      body: Column(
        children: [
          Container(
            alignment: Alignment.centerRight,
            padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 24),
            child: Text(
              output,
              style: const TextStyle(fontSize: 48, fontWeight: FontWeight.bold),
            ),
          ),
          const Divider(),
          Expanded(
            child: GridView.builder(
              padding: const EdgeInsets.all(8),
              itemCount: buttons.length,
              gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                crossAxisCount: 4,
                crossAxisSpacing: 8,
                mainAxisSpacing: 8,
              ),
              itemBuilder: (context, index) {
                String btn = buttons[index];
                return ElevatedButton(
                  style: ElevatedButton.styleFrom(
                    backgroundColor: (btn == "=")
                        ? Colors.green
                        : (btn == "C")
                            ? Colors.redAccent
                            : ["/", "*", "-", "+"].contains(btn)
                                ? Colors.orange
                                : Colors.grey.shade200,
                  ),
                  onPressed: () => buttonPressed(btn),
                  child: Text(
                    btn,
                    style: TextStyle(
                      fontSize: 22,
                      fontWeight: FontWeight.bold,
                      color: ["/", "*", "-", "+", "=", "C"].contains(btn)
                          ? Colors.white
                          : Colors.black,
                    ),
                  ),
                );
              },
            ),
          ),
        ],
      ),
    );
  }
}

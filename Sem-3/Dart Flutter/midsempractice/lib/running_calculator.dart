import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

/// ----------------------------------------------------------------------
/// 📱 RUNNING CALCULATOR APP
///
/// Built using ALL predefined Flutter classes, widgets, styling, and
/// controllers documented in FLUTTER_CLASSES_AND_WIDGETS.md.
/// ----------------------------------------------------------------------

/// 2. Main Calculator Screen using StatefulWidget & State
class CalculatorScreen extends StatefulWidget {
  const CalculatorScreen({super.key});

  @override
  State<CalculatorScreen> createState() => _CalculatorScreenState();
}

class _CalculatorScreenState extends State<CalculatorScreen> {
  // Display & Calculation variables
  String _expression = "";
  String _output = "0";
  double? _firstOperand;
  String? _operator;
  bool _shouldResetDisplay = false;
  bool _isProcessing = false;

  // Mode selection dropdown value
  String _selectedMode = "Standard";
  final List<String> _modes = ["Standard", "Scientific (Basic)", "Tax / GST (+18%)"];

  // Calculation history
  final List<String> _history = [];

  // Controllers
  final TextEditingController _customInputController = TextEditingController();

  // Custom Colors
  static const Color primaryDark = Color(0xFF1B3A5C);
  static const Color accentOrange = Color(0xFFF26B21);

  // Keypad button labels
  final List<String> _buttons = [
    "AC", "⌫", "%", "÷",
    "7",  "8", "9", "×",
    "4",  "5", "6", "-",
    "1",  "2", "3", "+",
    "+/-", "0", ".", "="
  ];

  @override
  void dispose() {
    _customInputController.dispose();
    super.dispose();
  }

  // Handle calculator button taps
  void _onButtonPressed(String label) {
    setState(() {
      if (label == "AC") {
        _expression = "";
        _output = "0";
        _firstOperand = null;
        _operator = null;
        _shouldResetDisplay = false;
      } else if (label == "⌫") {
        if (_output.length > 1) {
          _output = _output.substring(0, _output.length - 1);
        } else {
          _output = "0";
        }
      } else if (label == "+/-") {
        if (_output != "0") {
          if (_output.startsWith("-")) {
            _output = _output.substring(1);
          } else {
            _output = "-$_output";
          }
        }
      } else if (label == "%") {
        double val = double.tryParse(_output) ?? 0.0;
        _output = (val / 100).toString();
      } else if (label == "+" || label == "-" || label == "×" || label == "÷") {
        _firstOperand = double.tryParse(_output);
        _operator = label;
        _expression = "$_output $label";
        _shouldResetDisplay = true;
      } else if (label == "=") {
        _evaluateResult();
      } else {
        // Numeric digits & decimal
        if (_shouldResetDisplay || _output == "0") {
          _output = (label == ".") ? "0." : label;
          _shouldResetDisplay = false;
        } else {
          if (label == "." && _output.contains(".")) return;
          _output += label;
        }
      }
    });
  }

  // Calculate math operation
  void _evaluateResult() {
    if (_firstOperand == null || _operator == null) return;

    double secondOperand = double.tryParse(_output) ?? 0.0;
    double result = 0.0;

    if (_operator == "÷" && secondOperand == 0) {
      // Show SnackBar on divide by zero
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text("Error: Cannot divide by zero!"),
          backgroundColor: Colors.redAccent,
        ),
      );
      _output = "Error";
      _firstOperand = null;
      _operator = null;
      return;
    }

    switch (_operator) {
      case "+":
        result = _firstOperand! + secondOperand;
        break;
      case "-":
        result = _firstOperand! - secondOperand;
        break;
      case "×":
        result = _firstOperand! * secondOperand;
        break;
      case "÷":
        result = _firstOperand! / secondOperand;
        break;
    }

    // Apply GST if mode selected
    if (_selectedMode.contains("Tax")) {
      result = result * 1.18;
    }

    String formattedResult = result % 1 == 0 ? result.toInt().toString() : result.toStringAsFixed(2);
    String historyEntry = "$_firstOperand $_operator $secondOperand = $formattedResult";

    _history.insert(0, historyEntry);
    _expression = "$_firstOperand $_operator $secondOperand =";
    _output = formattedResult;
    _firstOperand = null;
    _operator = null;
    _shouldResetDisplay = true;
  }

  // Apply custom expression typed in the TextField
  void _applyCustomInput() {
    String text = _customInputController.text.trim();
    if (text.isEmpty) return;

    setState(() {
      _output = text;
      _customInputController.clear();
    });

    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: Text("Loaded '$text' into calculator"),
        duration: const Duration(seconds: 1),
      ),
    );
  }

  // Simulate async background calculation (demonstrating CircularProgressIndicator)
  void _simulateCalculation() async {
    setState(() {
      _isProcessing = true;
    });

    await Future.delayed(const Duration(milliseconds: 600));

    if (mounted) {
      setState(() {
        _isProcessing = false;
      });
      _onButtonPressed("=");
    }
  }

  // Navigate to calculation history screen using Navigator & MaterialPageRoute
  void _navigateToHistory() {
    Navigator.push(
      context,
      MaterialPageRoute(
        builder: (context) => HistoryScreen(
          history: _history,
          onClear: () {
            setState(() {
              _history.clear();
            });
          },
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Theme.of(context).colorScheme.surface,

      // 3. AppBar with actions and IconButton
      appBar: AppBar(
        backgroundColor: primaryDark,
        centerTitle: true,
        title: const Text(
          "Running Calculator",
          style: TextStyle(
            color: Colors.white,
            fontSize: 20,
            fontWeight: FontWeight.bold,
          ),
        ),
        actions: [
          IconButton(
            tooltip: "View History",
            icon: const Icon(Icons.history, color: Colors.white),
            onPressed: _navigateToHistory,
          ),
          IconButton(
            tooltip: "All Clear",
            icon: const Icon(Icons.refresh, color: Colors.white),
            onPressed: () => _onButtonPressed("AC"),
          ),
        ],
      ),

      // 4. FloatingActionButton
      floatingActionButton: FloatingActionButton(
        backgroundColor: accentOrange,
        tooltip: "Instant Equal",
        onPressed: _simulateCalculation,
        child: _isProcessing
            ? const SizedBox(
                height: 24,
                width: 24,
                child: CircularProgressIndicator(color: Colors.white, strokeWidth: 2),
              )
            : const Icon(Icons.check, color: Colors.white),
      ),

      // 5. SafeArea & SingleChildScrollView to prevent overflow
      body: SafeArea(
        child: SingleChildScrollView(
          physics: const BouncingScrollPhysics(),
          padding: const EdgeInsets.all(16.0),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              // 6. Mode selector with DropdownMenuItem & Row
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  const Text(
                    "Calculator Mode:",
                    style: TextStyle(fontWeight: FontWeight.w600, fontSize: 14),
                  ),
                  Container(
                    padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 4),
                    decoration: BoxDecoration(
                      color: Colors.white,
                      borderRadius: BorderRadius.circular(8),
                      border: Border.all(color: Colors.grey.shade300),
                    ),
                    child: DropdownButton<String>(
                      value: _selectedMode,
                      underline: const SizedBox(),
                      items: _modes.map((String mode) {
                        return DropdownMenuItem<String>(
                          value: mode,
                          child: Text(mode, style: const TextStyle(fontSize: 13)),
                        );
                      }).toList(),
                      onChanged: (String? newMode) {
                        if (newMode != null) {
                          setState(() {
                            _selectedMode = newMode;
                          });
                        }
                      },
                    ),
                  ),
                ],
              ),

              const SizedBox(height: 12),

              // 7. Display Screen wrapped in Card, Stack, Positioned & BoxDecoration
              Card(
                elevation: 4,
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(16),
                  side: BorderSide(color: Colors.grey.shade300, width: 1),
                ),
                child: Stack(
                  clipBehavior: Clip.none,
                  children: [
                    Container(
                      width: double.infinity,
                      padding: const EdgeInsets.all(20),
                      decoration: BoxDecoration(
                        color: Colors.white,
                        borderRadius: BorderRadius.circular(16),
                        boxShadow: const [
                          BoxShadow(
                            color: Colors.black12,
                            blurRadius: 10,
                            offset: Offset(0, 4),
                          ),
                        ],
                      ),
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.end,
                        children: [
                          // Expression text
                          Text(
                            _expression.isEmpty ? " " : _expression,
                            style: TextStyle(
                              color: Colors.grey.shade600,
                              fontSize: 18,
                              fontWeight: FontWeight.w400,
                            ),
                          ),
                          const SizedBox(height: 8),

                          // Running Main Output
                          Text(
                            _output,
                            maxLines: 1,
                            overflow: TextOverflow.ellipsis,
                            style: const TextStyle(
                              color: primaryDark,
                              fontSize: 42,
                              fontWeight: FontWeight.bold,
                              letterSpacing: 1.2,
                            ),
                          ),
                        ],
                      ),
                    ),

                    // Positioned mode badge inside Stack
                    Positioned(
                      top: 10,
                      left: 12,
                      child: Container(
                        padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 3),
                        decoration: BoxDecoration(
                          color: const Color(0x1A1B3A5C),
                          borderRadius: BorderRadius.circular(12),
                        ),
                        child: Text(
                          _selectedMode,
                          style: const TextStyle(
                            fontSize: 11,
                            color: primaryDark,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                      ),
                    ),
                  ],
                ),
              ),

              const SizedBox(height: 14),

              // 8. Custom Direct Input using TextField, TextEditingController, OutlineInputBorder
              Row(
                children: [
                  Expanded(
                    child: SizedBox(
                      height: 48,
                      child: TextField(
                        controller: _customInputController,
                        keyboardType: TextInputType.number,
                        inputFormatters: [
                          FilteringTextInputFormatter.allow(RegExp(r'[0-9\.]')),
                        ],
                        decoration: const InputDecoration(
                          hintText: "Enter direct number...",
                          prefixIcon: Icon(Icons.edit, size: 18),
                          border: OutlineInputBorder(),
                          contentPadding: EdgeInsets.symmetric(horizontal: 10, vertical: 0),
                        ),
                      ),
                    ),
                  ),
                  const SizedBox(width: 8),
                  ElevatedButton(
                    style: ElevatedButton.styleFrom(
                      backgroundColor: primaryDark,
                      foregroundColor: Colors.white,
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(8),
                      ),
                    ),
                    onPressed: _applyCustomInput,
                    child: const Text("Load"),
                  ),
                ],
              ),

              const SizedBox(height: 12),
              const Divider(thickness: 1.2),
              const SizedBox(height: 8),

              // 9. Keypad Grid built with GridView.builder, LayoutBuilder & InkWell
              LayoutBuilder(
                builder: (context, constraints) {
                  return GridView.builder(
                    shrinkWrap: true,
                    physics: const NeverScrollableScrollPhysics(),
                    itemCount: _buttons.length,
                    gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                      crossAxisCount: 4,
                      crossAxisSpacing: 10,
                      mainAxisSpacing: 10,
                      childAspectRatio: 1.2,
                    ),
                    itemBuilder: (context, index) {
                      String label = _buttons[index];
                      bool isOperator = ["÷", "×", "-", "+", "="].contains(label);
                      bool isAction = ["AC", "⌫", "%", "+/-"].contains(label);

                      Color btnBg = Colors.white;
                      Color btnText = Colors.black87;

                      if (label == "=") {
                        btnBg = accentOrange;
                        btnText = Colors.white;
                      } else if (isOperator) {
                        btnBg = primaryDark;
                        btnText = Colors.white;
                      } else if (isAction) {
                        btnBg = Colors.grey.shade300;
                        btnText = Colors.black87;
                      }

                      return InkWell(
                        borderRadius: BorderRadius.circular(12),
                        onTap: () => _onButtonPressed(label),
                        child: Container(
                          decoration: BoxDecoration(
                            color: btnBg,
                            borderRadius: BorderRadius.circular(12),
                            border: Border.all(
                              color: Colors.grey.shade300,
                              width: 1,
                            ),
                            boxShadow: const [
                              BoxShadow(
                                color: Colors.black12,
                                blurRadius: 4,
                                offset: Offset(0, 2),
                              ),
                            ],
                          ),
                          child: Center(
                            child: Text(
                              label,
                              style: TextStyle(
                                fontSize: 22,
                                fontWeight: FontWeight.bold,
                                color: btnText,
                              ),
                            ),
                          ),
                        ),
                      );
                    },
                  );
                },
              ),
            ],
          ),
        ),
      ),
    );
  }
}

/// ----------------------------------------------------------------------
/// 10. History & Info Screen using StatelessWidget, ListView.builder,
///     ListTile, CircleAvatar, Image.network, and Navigation pop
/// ----------------------------------------------------------------------
class HistoryScreen extends StatelessWidget {
  final List<String> history;
  final VoidCallback onClear;

  const HistoryScreen({
    super.key,
    required this.history,
    required this.onClear,
  });

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Calculation History"),
        backgroundColor: const Color(0xFF1B3A5C),
        foregroundColor: Colors.white,
        actions: [
          IconButton(
            tooltip: "Clear All History",
            icon: const Icon(Icons.delete_outline),
            onPressed: () {
              onClear();
              ScaffoldMessenger.of(context).showSnackBar(
                const SnackBar(content: Text("History cleared successfully!")),
              );
            },
          ),
        ],
      ),
      body: Column(
        children: [
          // Banner card with Image.network & details
          Container(
            padding: const EdgeInsets.all(16),
            color: Colors.blue.shade50,
            child: Row(
              children: [
                ClipRRect(
                  borderRadius: BorderRadius.circular(8),
                  child: Image.network(
                    "https://images.unsplash.com/photo-1594980596870-8aa52a78d8cd?w=150&fit=crop",
                    width: 60,
                    height: 60,
                    fit: BoxFit.cover,
                    errorBuilder: (context, error, stackTrace) => Container(
                      width: 60,
                      height: 60,
                      color: Colors.grey.shade300,
                      child: const Icon(Icons.calculate, color: Colors.grey),
                    ),
                  ),
                ),
                const SizedBox(width: 14),
                const Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    mainAxisSize: MainAxisSize.min,
                    children: [
                      Text(
                        "Tape & Record View",
                        style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                      ),
                      SizedBox(height: 4),
                      Text(
                        "All calculation history saved during current session.",
                        style: TextStyle(fontSize: 12, color: Colors.black54),
                      ),
                    ],
                  ),
                ),
              ],
            ),
          ),

          const Divider(height: 1),

          // ListView.builder rendering each calculation entry
          Expanded(
            child: history.isEmpty
                ? const Center(
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Icon(Icons.history_toggle_off, size: 64, color: Colors.grey),
                        SizedBox(height: 12),
                        Text(
                          "No history yet!\nPerform some calculations.",
                          textAlign: TextAlign.center,
                          style: TextStyle(color: Colors.grey, fontSize: 16),
                        ),
                      ],
                    ),
                  )
                : ListView.builder(
                    itemCount: history.length,
                    itemBuilder: (context, index) {
                      String item = history[index];
                      return ListTile(
                        leading: CircleAvatar(
                          backgroundColor: const Color(0xFF1B3A5C),
                          child: Text(
                            "${index + 1}",
                            style: const TextStyle(color: Colors.white, fontSize: 12),
                          ),
                        ),
                        title: Text(
                          item,
                          style: const TextStyle(
                            fontWeight: FontWeight.w600,
                            fontSize: 16,
                          ),
                        ),
                        subtitle: const Text("Completed calculation"),
                        trailing: const Icon(Icons.check_circle, color: Colors.green, size: 20),
                      );
                    },
                  ),
          ),
        ],
      ),
    );
  }
}

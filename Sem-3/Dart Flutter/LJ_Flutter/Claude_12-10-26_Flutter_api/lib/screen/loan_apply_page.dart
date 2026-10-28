import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

class LoanApplyPage extends StatefulWidget {
  const LoanApplyPage({super.key});

  @override
  State<LoanApplyPage> createState() => _LoanApplyPageState();
}

class _LoanApplyPageState extends State<LoanApplyPage> {
  static const Color orange = Color(0xFFF26B21);
  static const Color navy = Color(0xFF1B3A5C);
  static const int minAmount = 1000;
  static const int maxMonths = 24;

  final TextEditingController amountController = TextEditingController();
  int? selectedMonths;

  // Progress bar: first step is active
  final int totalSteps = 4;
  final int currentStep = 1;

  @override
  void dispose() {
    amountController.dispose();
    super.dispose();
  }

  void apply() {
    final amount = int.tryParse(amountController.text.trim());

    if (amount == null || amount < minAmount) {
      _showMessage("Minimum loan amount is NGN$minAmount");
      return;
    }
    if (selectedMonths == null) {
      _showMessage("Please select the loan duration");
      return;
    }

    _showMessage("Applied for NGN$amount for $selectedMonths month(s)");
  }

  void _showMessage(String text) {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(content: Text(text)),
    );
  }

  Widget _progressBar() {
    return Row(
      children: List.generate(totalSteps, (i) {
        return Expanded(
          child: Container(
            height: 3,
            margin: EdgeInsets.only(right: i == totalSteps - 1 ? 0 : 6),
            color: i < currentStep ? navy : Colors.grey.shade300,
          ),
        );
      }),
    );
  }

  Widget _label(String text) {
    return Text(
      text,
      style: const TextStyle(
        fontSize: 14,
        fontWeight: FontWeight.w500,
        color: Colors.black87,
      ),
    );
  }

  Widget _helper(String text) {
    return Padding(
      padding: const EdgeInsets.only(top: 6),
      child: Text(
        text,
        style: const TextStyle(fontSize: 10, color: orange),
      ),
    );
  }

  OutlineInputBorder _border() {
    return OutlineInputBorder(
      borderRadius: BorderRadius.circular(4),
      borderSide: BorderSide(color: Colors.grey.shade300),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: SafeArea(
        child: SingleChildScrollView(
          padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              // Header
              Row(
                children: [
                  InkWell(
                    onTap: () => Navigator.maybePop(context),
                    child: const Icon(Icons.arrow_back, color: orange, size: 20),
                  ),
                  const SizedBox(width: 20),
                  const Text(
                    "Apply for a Loan",
                    style: TextStyle(
                      color: orange,
                      fontSize: 16,
                      fontWeight: FontWeight.w600,
                    ),
                  ),
                ],
              ),

              const SizedBox(height: 16),
              _progressBar(),
              const SizedBox(height: 24),

              // Amount
              _label("How much do you want to borrow?"),
              const SizedBox(height: 8),
              TextField(
                controller: amountController,
                keyboardType: TextInputType.number,
                inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                decoration: InputDecoration(
                  contentPadding:
                      const EdgeInsets.symmetric(horizontal: 12, vertical: 24),
                  enabledBorder: _border(),
                  focusedBorder: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(4),
                    borderSide: const BorderSide(color: navy),
                  ),
                ),
              ),
              _helper("You have a minimum of NGN$minAmount"),

              const SizedBox(height: 24),

              // Duration
              _label("How long do you want the loan for?"),
              const SizedBox(height: 8),
              DropdownButtonFormField<int>(
                value: selectedMonths,
                icon: const Icon(Icons.keyboard_arrow_down, size: 28),
                decoration: InputDecoration(
                  contentPadding:
                      const EdgeInsets.symmetric(horizontal: 12, vertical: 12),
                  enabledBorder: _border(),
                  focusedBorder: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(4),
                    borderSide: const BorderSide(color: navy),
                  ),
                ),
                items: List.generate(maxMonths, (i) => i + 1)
                    .map(
                      (m) => DropdownMenuItem<int>(
                        value: m,
                        child: Text("$m ${m == 1 ? 'month' : 'months'}"),
                      ),
                    )
                    .toList(),
                onChanged: (value) => setState(() => selectedMonths = value),
              ),
              _helper("You have a maximum of $maxMonths months"),

              const SizedBox(height: 30),

              // Apply button
              SizedBox(
                width: double.infinity,
                height: 48,
                child: ElevatedButton(
                  onPressed: apply,
                  style: ElevatedButton.styleFrom(
                    backgroundColor: navy,
                    foregroundColor: Colors.white,
                    shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(4),
                    ),
                  ),
                  child: const Text(
                    "APPLY",
                    style: TextStyle(
                      fontSize: 15,
                      fontWeight: FontWeight.bold,
                      letterSpacing: 0.5,
                    ),
                  ),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();

  SystemChrome.setSystemUIOverlayStyle(
    const SystemUiOverlayStyle(
      statusBarColor: Color(0xFF062D55),
      statusBarIconBrightness: Brightness.light,
      systemNavigationBarColor: Color(0xFFFFFFFF),
      systemNavigationBarIconBrightness: Brightness.dark,
    ),
  );

  runApp(const WalletApp());
}

const Color navy = Color(0xFF062D55);
const Color orange = Color(0xFFFF7029);
const Color mutedGrey = Color(0xFFBDBDBD);

class WalletApp extends StatelessWidget {
  const WalletApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Wallet Dashboard',
      theme: ThemeData(
        useMaterial3: true,
        fontFamily: 'Roboto',
        scaffoldBackgroundColor: navy,
        colorScheme: ColorScheme.fromSeed(seedColor: navy),
      ),
      home: const WalletHomePage(),
    );
  }
}

class WalletHomePage extends StatefulWidget {
  const WalletHomePage({super.key});

  @override
  State<WalletHomePage> createState() => _WalletHomePageState();
}

class _WalletHomePageState extends State<WalletHomePage> {
  int selectedTab = 0;
  bool showBalance = true;

  final List<TransactionItem> transactions = const [
    TransactionItem(
      title: 'IPPIS deduction',
      date: '01/09/2021',
      amount: 'N20,000.34',
      subtitle: 'August repayment',
    ),
    TransactionItem(
      title: 'Refund',
      date: '01/09/2021',
      amount: 'N20,000.34',
      subtitle: 'August refund',
    ),
    TransactionItem(
      title: 'IPPIS deduction',
      date: '01/09/2021',
      amount: 'N20,000.34',
      subtitle: 'October repayment',
    ),
    TransactionItem(
      title: 'Default penalty',
      date: '01/09/2021',
      amount: 'N20,000.34',
      subtitle: 'August default',
    ),
    TransactionItem(
      title: 'Refund',
      date: '01/09/2021',
      amount: 'N20,000.34',
      subtitle: 'August refund',
    ),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: navy,
      body: SafeArea(
        bottom: false,
        child: Column(
          children: [
            // Welcome header
            Padding(
              padding: const EdgeInsets.fromLTRB(30, 20, 49, 0),
              child: Row(
                children: [
                  const Expanded(
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text(
                          'Welcome,',
                          style: TextStyle(
                            color: Colors.white,
                            fontSize: 17,
                            letterSpacing: 0.3,
                          ),
                        ),
                        SizedBox(height: 3),
                        Text(
                          'Abdulsalam',
                          style: TextStyle(
                            color: Colors.white,
                            fontSize: 23,
                            fontWeight: FontWeight.w600,
                          ),
                        ),
                      ],
                    ),
                  ),
                  const CircleAvatar(
                    radius: 22,
                    backgroundColor: Color(0xFF8096A9),
                    child: Icon(
                      Icons.person,
                      color: Colors.white,
                      size: 30,
                    ),
                  ),
                ],
              ),
            ),

            const SizedBox(height: 24),

            // Balance card
            Padding(
              padding: const EdgeInsets.symmetric(horizontal: 18),
              child: BalanceCard(
                showBalance: showBalance,
                onToggleBalance: () {
                  setState(() => showBalance = !showBalance);
                },
                onActionTap: (action) {
                  ScaffoldMessenger.of(context).showSnackBar(
                    SnackBar(content: Text('$action selected')),
                  );
                },
              ),
            ),

            const SizedBox(height: 26),

            // Transactions panel and bottom navigation
            Expanded(
              child: Container(
                width: double.infinity,
                decoration: const BoxDecoration(
                  color: Color(0xFFFAFAFA),
                  borderRadius: BorderRadius.vertical(
                    top: Radius.circular(30),
                  ),
                ),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    const Padding(
                      padding: EdgeInsets.fromLTRB(35, 32, 20, 18),
                      child: Text(
                        'Recent Transactions',
                        style: TextStyle(
                          fontSize: 18,
                          fontWeight: FontWeight.w400,
                          color: Color(0xFF383838),
                        ),
                      ),
                    ),

                    Expanded(
                      child: ListView.separated(
                        padding: const EdgeInsets.fromLTRB(32, 0, 30, 8),
                        itemCount: transactions.length,
                        separatorBuilder: (_, __) =>
                        const SizedBox(height: 15),
                        itemBuilder: (context, index) {
                          return TransactionTile(
                            transaction: transactions[index],
                          );
                        },
                      ),
                    ),

                    // Fixed bottom navigation
                    Container(
                      height: 73,
                      decoration: const BoxDecoration(
                        color: Colors.white,
                        border: Border(
                          top: BorderSide(
                            color: Color(0xFFE3E3E3),
                            width: 1,
                          ),
                        ),
                        borderRadius: BorderRadius.vertical(
                          bottom: Radius.circular(18),
                        ),
                      ),
                      child: Row(
                        children: [
                          _navItem(
                            icon: Icons.home_filled,
                            label: 'Home',
                            index: 0,
                          ),
                          _navItem(
                            icon: Icons.business_center,
                            label: 'Loans',
                            index: 1,
                          ),
                          _navItem(
                            icon: Icons.person,
                            label: 'Account',
                            index: 2,
                          ),
                        ],
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }

  Widget _navItem({
    required IconData icon,
    required String label,
    required int index,
  }) {
    final bool selected = selectedTab == index;

    return Expanded(
      child: InkWell(
        onTap: () {
          setState(() => selectedTab = index);
        },
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Icon(
              icon,
              size: 27,
              color: selected ? navy : mutedGrey,
            ),
            const SizedBox(height: 2),
            Text(
              label,
              style: TextStyle(
                fontSize: 10,
                fontWeight:
                selected ? FontWeight.w600 : FontWeight.w400,
                color: selected ? navy : mutedGrey,
              ),
            ),
          ],
        ),
      ),
    );
  }
}

// ---------------- BALANCE CARD ----------------

class BalanceCard extends StatelessWidget {
  final bool showBalance;
  final VoidCallback onToggleBalance;
  final ValueChanged<String> onActionTap;

  const BalanceCard({
    super.key,
    required this.showBalance,
    required this.onToggleBalance,
    required this.onActionTap,
  });

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 268,
      width: double.infinity,
      padding: const EdgeInsets.fromLTRB(25, 25, 25, 18),
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(25),
        gradient: const LinearGradient(
          begin: Alignment.topLeft,
          end: Alignment.bottomRight,
          colors: [
            Color(0xFF376695),
            Color(0xFF174573),
            Color(0xFF062D55),
          ],
        ),
        border: Border.all(
          color: Colors.white.withValues(alpha: 0.09),
        ),
      ),
      child: Column(
        children: [
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              const Spacer(),
              const Text(
                'Total Balance',
                style: TextStyle(
                  color: Color(0xFFE2E9F1),
                  fontSize: 13,
                ),
              ),
              const Spacer(),
              GestureDetector(
                onTap: onToggleBalance,
                child: Icon(
                  showBalance ? Icons.visibility_outlined
                      : Icons.visibility_off_outlined,
                  color: const Color(0xFF91A9C1),
                  size: 18,
                ),
              ),
            ],
          ),

          const SizedBox(height: 12),

          FittedBox(
            fit: BoxFit.scaleDown,
            child: Text(
              showBalance ? '₦200,000.98' : '₦••••••••',
              style: const TextStyle(
                color: Colors.white,
                fontSize: 36,
                fontWeight: FontWeight.w600,
                letterSpacing: 0.7,
              ),
            ),
          ),

          const SizedBox(height: 18),

          Container(
            padding: const EdgeInsets.symmetric(
              horizontal: 9,
              vertical: 4,
            ),
            decoration: BoxDecoration(
              color: const Color(0xFF496A8B),
              borderRadius: BorderRadius.circular(12),
              border: Border.all(
                color: Colors.white.withValues(alpha: 0.4),
              ),
            ),
            child: const Text(
              'NGN',
              style: TextStyle(
                color: Colors.white,
                fontSize: 12,
              ),
            ),
          ),

          const SizedBox(height: 16),

          Container(
            height: 1,
            color: Colors.white.withValues(alpha: 0.23),
          ),

          const SizedBox(height: 24),

          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              _actionItem(
                icon: Icons.receipt_long,
                label: 'Loan Apply',
                onTap: () => onActionTap('Loan Apply'),
              ),
              _actionItem(
                icon: Icons.credit_card,
                label: 'Top-up',
                onTap: () => onActionTap('Top-up'),
              ),
              _actionItem(
                icon: Icons.payments_outlined,
                label: 'Liquidation',
                onTap: () => onActionTap('Liquidation'),
              ),
              _actionItem(
                icon: Icons.apps,
                label: 'More',
                onTap: () => onActionTap('More'),
              ),
            ],
          ),
        ],
      ),
    );
  }

  Widget _actionItem({
    required IconData icon,
    required String label,
    required VoidCallback onTap,
  }) {
    return InkWell(
      onTap: onTap,
      borderRadius: BorderRadius.circular(12),
      child: SizedBox(
        width: 55,
        child: Column(
          children: [
            Container(
              height: 37,
              width: 37,
              decoration: BoxDecoration(
                color: orange,
                borderRadius: BorderRadius.circular(11),
              ),
              child: Icon(
                icon,
                color: Colors.white,
                size: 22,
              ),
            ),
            const SizedBox(height: 6),
            FittedBox(
              fit: BoxFit.scaleDown,
              child: Text(
                label,
                style: const TextStyle(
                  color: Colors.white,
                  fontSize: 10,
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

// ---------------- TRANSACTIONS ----------------

class TransactionItem {
  final String title;
  final String date;
  final String amount;
  final String subtitle;

  const TransactionItem({
    required this.title,
    required this.date,
    required this.amount,
    required this.subtitle,
  });
}

class TransactionTile extends StatelessWidget {
  final TransactionItem transaction;

  const TransactionTile({
    super.key,
    required this.transaction,
  });

  @override
  Widget build(BuildContext context) {
    return Row(
      crossAxisAlignment: CrossAxisAlignment.center,
      children: [
        Container(
          width: 34,
          height: 34,
          decoration: BoxDecoration(
            color: Colors.white,
            borderRadius: BorderRadius.circular(5),
          ),
          child: const Icon(
            Icons.check_circle_outline,
            color: Color(0xFF003C75),
            size: 23,
          ),
        ),

        const SizedBox(width: 17),

        Expanded(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text(
                transaction.title,
                maxLines: 1,
                overflow: TextOverflow.ellipsis,
                style: const TextStyle(
                  fontSize: 13,
                  fontWeight: FontWeight.w600,
                  color: Color(0xFF383838),
                ),
              ),
              const SizedBox(height: 5),
              Text(
                transaction.date,
                style: const TextStyle(
                  fontSize: 10,
                  color: Color(0xFF666666),
                ),
              ),
            ],
          ),
        ),

        const SizedBox(width: 8),

        SizedBox(
          width: 82,
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              FittedBox(
                fit: BoxFit.scaleDown,
                alignment: Alignment.centerLeft,
                child: Text(
                  transaction.amount,
                  style: const TextStyle(
                    fontSize: 14,
                    fontWeight: FontWeight.w600,
                    color: Color(0xFF383838),
                  ),
                ),
              ),
              const SizedBox(height: 5),
              Text(
                transaction.subtitle,
                maxLines: 1,
                overflow: TextOverflow.ellipsis,
                style: const TextStyle(
                  fontSize: 9,
                  color: Color(0xFF666666),
                ),
              ),
            ],
          ),
        ),
      ],
    );
  }
}
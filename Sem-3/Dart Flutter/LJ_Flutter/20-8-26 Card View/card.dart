import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return  const MaterialApp(
      debugShowCheckedModeBanner: false,
      home: AppointmentPage(),
    );
  }
}

class AppointmentPage extends StatelessWidget {
  const AppointmentPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color(0xFF17623D),
        foregroundColor: Colors.white,
        leading: const Icon(Icons.arrow_back),
        title: const Text(
          "My Appointments",
          style: TextStyle(
            fontSize: 16,
            fontWeight: FontWeight.bold,
          ),
        ),
        centerTitle: true,
      ),

      body: ListView(
        padding: const EdgeInsets.all(16),
        children: const [
          AppointmentCard(),
          AppointmentCard(),
        ],
      ),
    );
  }
}

class AppointmentCard extends StatelessWidget {
  const AppointmentCard({super.key});

  @override
  Widget build(BuildContext context) {
    return Card(
      color: const Color(0xFF17623D),
      elevation: 0,
      margin: const EdgeInsets.only(bottom: 8),
      shape: RoundedRectangleBorder(
        borderRadius: BorderRadius.circular(7),
      ),

      child: const Padding(
        padding: EdgeInsets.all(16),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [

            // Order ID
            Text(
              "Order ID",
              style: TextStyle(
                color: Color(0xFFD5A52A),
                fontSize: 10,
              ),
            ),

            SizedBox(height: 3),

            Text(
              "1234565452",
              style: TextStyle(
                color: Colors.white,
                fontSize: 11,
                fontWeight: FontWeight.bold,
              ),
            ),

            SizedBox(height: 10),

            Divider(
              color: Colors.white24,
              height: 1,
            ),

            SizedBox(height: 10),

            // Appointment Date and Time
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [

                Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text(
                      "Appointment Date",
                      style: TextStyle(
                        color: Color(0xFFD5A52A),
                        fontSize: 10,
                      ),
                    ),
                    SizedBox(height: 4),
                    Text(
                      "Saturday, March 7, 2023",
                      style: TextStyle(
                        color: Colors.white,
                        fontSize: 10,
                      ),
                    ),
                  ],
                ),

                Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text(
                      "Appointment Time",
                      style: TextStyle(
                        color: Color(0xFFD5A52A),
                        fontSize: 10,
                      ),
                    ),
                    SizedBox(height: 4),
                    Text(
                      "11:00 AM",
                      style: TextStyle(
                        color: Colors.white,
                        fontSize: 10,
                      ),
                    ),
                  ],
                ),
              ],
            ),

            SizedBox(height: 10),

            Divider(
              color: Colors.white24,
              height: 1,
            ),

            SizedBox(height: 10),

            // Service and Amount
            Row(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [

                Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        "Type of Service",
                        style: TextStyle(
                          color: Color(0xFFD5A52A),
                          fontSize: 10,
                        ),
                      ),

                      SizedBox(height: 5),

                      Text(
                        "Full Body Massage",
                        style: TextStyle(
                          color: Colors.white,
                          fontSize: 10,
                        ),
                      ),

                      Text(
                        "Back Massage",
                        style: TextStyle(
                          color: Colors.white,
                          fontSize: 10,
                        ),
                      ),

                      Text(
                        "Head Massage",
                        style: TextStyle(
                          color: Colors.white,
                          fontSize: 10,
                        ),
                      ),
                    ],
                  ),
                ),

                Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        "Total Amount",
                        style: TextStyle(
                          color: Color(0xFFD5A52A),
                          fontSize: 10,
                        ),
                      ),

                      SizedBox(height: 5),

                      Text(
                        "\$100.00",
                        style: TextStyle(
                          color: Colors.white,
                          fontSize: 11,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                    ],
                  ),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
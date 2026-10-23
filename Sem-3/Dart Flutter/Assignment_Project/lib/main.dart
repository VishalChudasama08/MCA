import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:simple_project/views/home_page.dart';
import 'package:simple_project/views/login_page.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();

  await Firebase.initializeApp(
    options: const FirebaseOptions(
        apiKey: 'AIzaSyD79xcVbV4OaCkcm4-QihgD5miiB_FPnS4',
        appId: '1:769941832372:web:b3a8f00120b6935e0b0de1',
        messagingSenderId: '769941832372',
        projectId: 'flutterdemo-2ea3e',
        authDomain: 'flutterdemo-2ea3e.firebaseapp.com',
        storageBucket: 'flutterdemo-2ea3e.firebasestorage.app',
        measurementId: 'G-XFJ6SJ17V1',
      )
  );

  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(
          seedColor: Colors.deepPurple,
        ),
      ),
      // home: const HomePage(),
      home: const LoginPage(),
    );
  }
}
# 🎓 LJ University MCA Sem-3 Flutter Workshop — Predefined Classes & Widgets Reference Guide

> **Note**: This reference guide has been generated **strictly and exclusively** from the code files present in this workshop repository (`LJ_Flutter`). It documents every built-in Flutter class, widget, controller, styling utility, and configuration found across all 36 Dart files.

---

## 📑 Table of Contents

1. [Workshop Practical Modules Overview](#1-workshop-practical-modules-overview)
2. [Core Architecture & Base Classes](#2-core-architecture--base-classes)
3. [Predefined Flutter Widgets in this Workshop](#3-predefined-flutter-widgets-in-this-workshop)
   - [3.1 Application & Shell Widgets](#31-application--shell-widgets)
   - [3.2 Single-Child Layout Widgets](#32-single-child-layout-widgets)
   - [3.3 Multi-Child Layout Widgets](#33-multi-child-layout-widgets)
   - [3.4 Scrollable & Grid Widgets](#34-scrollable--grid-widgets)
   - [3.5 Text, Typography & Display Widgets](#35-text-typography--display-widgets)
   - [3.6 Button & Interactive Widgets](#36-button--interactive-widgets)
   - [3.7 Form & Input Widgets](#37-form--input-widgets)
   - [3.8 Feedback & Notification Widgets](#38-feedback--notification-widgets)
4. [Predefined Framework Classes (Non-Widget Classes)](#4-predefined-framework-classes-non-widget-classes)
   - [4.1 Styling & Painting Classes](#41-styling--painting-classes)
   - [4.2 Alignment & Geometry Classes](#42-alignment--geometry-classes)
   - [4.3 Controllers, Inputs & Formatters](#43-controllers-inputs--formatters)
   - [4.4 Navigation & Routing Classes](#44-navigation--routing-classes)
   - [4.5 Theming & System Classes](#45-theming--system-classes)
   - [4.6 Predefined Icons Used in Workshop](#46-predefined-icons-used-in-workshop)
5. [State Management Classes in Workshop (GetX)](#5-state-management-classes-in-workshop-getx)
6. [Master Workshop Symbol Matrix](#6-master-workshop-symbol-matrix)

---

## 1. Workshop Practical Modules Overview

Here is the map of all practical folders in this repository and the core Flutter topics they cover:

| Folder / Date | Core Practical Topic | Key Widgets & Classes Used |
| :--- | :--- | :--- |
| **[`17-8-26 Admin Dashboard`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart)** | Admin Dashboard UI Layout | `Scaffold`, `AppBar`, `IconButton`, `Icons`, `Column`, `Row`, `SizedBox`, `Text`, `TextStyle`, `Colors` |
| **[`18-8-26 Stack`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart)** | Overlapping Layouts | `Stack`, `Positioned`, `Clip.none`, `Image.network`, `CircleAvatar`, `Container`, `Colors` |
| **[`19-08-26 Card View`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/19-08-26%20Card%20View/admin_dashboard.dart)** | Admin Dashboard with Cards | `Card`, `Container`, `RoundedRectangleBorder`, `BorderSide`, `Padding`, `ListTile` |
| **[`20-8-26 Card View`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/20-8-26%20Card%20View/card_view.dart)** | Card Layouts & Appointments | `Card`, `BoxDecoration`, `BorderRadius`, `Padding`, `Row`, `Column`, `Icon` |
| **[`GridView`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/GridView/gridview.dart)** | 2D Grid Layouts | `GridView.builder`, `GridView.count`, `SliverGridDelegateWithFixedCrossAxisCount`, `Center`, `Container` |
| **[`ListView`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/ListView/list_view_example.dart)** | Dynamic Lists & WhatsApp UI | `ListView.builder`, `ListTile`, `CircleAvatar`, `Divider`, `FloatingActionButton`, `Icons` |
| **[`Login_page`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart)** | Authentication UI & Validation | `TextField`, `TextEditingController`, `OutlineInputBorder`, `InputDecoration`, `ElevatedButton`, `SnackBar`, `ScaffoldMessenger`, `Navigator` |
| **[`image_login_page`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/image_login_page/Login_Page.dart)** | Login UI with Image Assets | `Image.asset`, `CircleAvatar`, `Container`, `BoxDecoration`, `TextField` |
| **[`05-10-26_API_service`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/screen/login_page.dart)** | API Auth & State Management | `GetMaterialApp`, `GetxController`, `Obx`, `CircularProgressIndicator`, `TextField`, `SnackBar` |
| **[`28-09-26_API`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/28-09-26_API/screen/login_page.dart)** | API Integration & Controller | `GetxController`, `RxBool`, `TextField`, `ElevatedButton`, `CircularProgressIndicator` |
| **[`Claude_12-10-26_Flutter_api`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart)** | Loan Application Form & API | `DropdownMenuItem`, `FilteringTextInputFormatter`, `SafeArea`, `InkWell`, `NeverScrollableScrollPhysics`, `Card` |
| **[`whatsapp_page`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/whatsapp_page/whatsapp_page.dart)** | WhatsApp Screen Clone | `Scaffold`, `AppBar`, `ListView.builder`, `ListTile`, `CircleAvatar`, `FloatingActionButton` |
| **Root Practicals** | Grid/Flex Screen Mockup | `home_screen.dart`, `home.dart.txt`, `main.dart` (Nested `Row`, `Column`, `Padding`, `Container`, `BoxDecoration`) |

---

## 2. Core Architecture & Base Classes

These base classes define the structure and rendering lifecycle of every screen in this workshop.

### 2.1 `Widget`
- **What it is**: The base class for all visual and structural elements in the Flutter framework.
- **How it's used in this workshop**: Used as return type for every screen's `build(BuildContext context)` method.
- **Workshop Files**: Present in 25 files (e.g. [`home_screen.dart:L7`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart#L7), [`admin_dashboard.dart:L8`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart#L8)).
```dart
@override
Widget build(BuildContext context) {
  return Scaffold(...);
}
```

### 2.2 `StatelessWidget`
- **What it is**: A widget whose UI configuration is immutable once built and has no local mutable state.
- **How it's used in this workshop**: Used for static dashboards, layouts, grid examples, and list demonstrations.
- **Workshop Files**: 21 files, including:
  - [`home_screen.dart:L3`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart#L3) (`class HomeScreen extends StatelessWidget`)
  - [`admin_dashboard.dart:L4`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart#L4) (`class AdminDashboard extends StatelessWidget`)
  - [`stack_example.dart:L3`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart#L3) (`class StackExample extends StatelessWidget`)
  - [`gridview.dart:L3`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/GridView/gridview.dart#L3) (`class GridViewExample extends StatelessWidget`)
  - [`list_view_example.dart:L3`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/ListView/list_view_example.dart#L3) (`class ListViewExample extends StatelessWidget`)

### 2.3 `StatefulWidget` & `State<T>`
- **What it is**: A widget that has mutable state. Delegates its UI build logic to a linked `State<T>` object.
- **How it's used in this workshop**: Used for interactive pages like login pages, loan applications, and counter screens where text inputs and toggle states change dynamically.
- **Workshop Files**: 7 files, including:
  - [`Login_page/login_page.dart:L3-L10`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart#L3-L10)
  - [`05-10-26_API_service/lib/screen/login_page.dart:L3-L10`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/screen/login_page.dart#L3-L10)
  - [`Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart:L4-L11`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart#L4-L11)
  - [`main.dart:L33-L40`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart#L33-L40)
```dart
class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  // Mutable state variables & controllers here
}
```

### 2.4 `BuildContext`
- **What it is**: An object that provides access to the widget's location within the widget tree (used for `Theme.of(context)`, `ScaffoldMessenger.of(context)`, and `Navigator.push(context, ...)`).
- **How it's used in this workshop**: Passed into every `build(BuildContext context)` and used to display snackbars or perform navigation.
- **Workshop Files**: Present in 25 files.

---

## 3. Predefined Flutter Widgets in this Workshop

### 3.1 Application & Shell Widgets

#### `MaterialApp` & `GetMaterialApp`
- **Purpose**: Top-level root widget providing Material theming, title, routing, and device navigation support.
- **Workshop Usage**:
  - `MaterialApp`: [`main.dart:L10`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart#L10), [`Login_page/main.dart:L9`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/main.dart#L9)
  - `GetMaterialApp`: Used in [`05-10-26_API_service/lib/main.dart:L9`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/main.dart#L9) to enable GetX snackbars and navigation without context.
```dart
return MaterialApp(
  title: 'Flutter Demo',
  theme: ThemeData(colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple)),
  home: const MyHomePage(title: 'Flutter Demo Home Page'),
);
```

#### `Scaffold`
- **Purpose**: Implements the basic Material Design visual layout structure.
- **Workshop Parameters Used**: `appBar`, `body`, `floatingActionButton`, `backgroundColor`.
- **Workshop Files**: 24 files (e.g. [`admin_dashboard.dart:L9`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart#L9), [`stack_example.dart:L8`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart#L8)).

#### `AppBar`
- **Purpose**: Top header toolbar with support for titles, leading icons, and action buttons.
- **Workshop Parameters Used**: `title: Text(...)`, `backgroundColor`, `actions: [IconButton(...)]`, `centerTitle: true`.
- **Workshop Files**: 16 files (e.g. [`admin_dashboard.dart:L10-L32`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart#L10-L32), [`whatsapp_page.dart:L10-L24`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/whatsapp_page/whatsapp_page.dart#L10-L24)).
```dart
appBar: AppBar(
  backgroundColor: Colors.blue.shade700,
  title: const Text("Admin Dashboard", style: TextStyle(color: Colors.white, fontSize: 18, fontWeight: FontWeight.bold)),
  actions: [
    IconButton(onPressed: () {}, icon: const Icon(Icons.notifications, color: Colors.white)),
    IconButton(onPressed: () {}, icon: const Icon(Icons.exit_to_app_rounded, color: Colors.white)),
  ],
)
```

#### `SafeArea`
- **Purpose**: Insets its child with enough padding to avoid device camera notches and status bars.
- **Workshop Files**: [`Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart:L104`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart#L104).

---

### 3.2 Single-Child Layout Widgets

#### `Container`
- **Purpose**: A multi-purpose convenience box supporting sizing, margin, padding, color, borders, and decoration.
- **Workshop Parameters Used**: `height`, `width`, `color`, `decoration: BoxDecoration(...)`, `margin`, `padding`, `child`.
- **Workshop Files**: 7 files, 43 usages (e.g. [`home_screen.dart:L17-L24`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart#L17-L24), [`gridview.dart:L32-L38`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/GridView/gridview.dart#L32-L38)).
```dart
Container(
  height: 140,
  width: 60,
  decoration: const BoxDecoration(
    color: Colors.red,
    borderRadius: BorderRadius.only(),
  ),
)
```

#### `Padding`
- **Purpose**: Insets its child widget by a specified `EdgeInsets` distance.
- **Workshop Parameters Used**: `padding: const EdgeInsets.all(8.0)`, `padding: const EdgeInsets.all(20)`, `child`.
- **Workshop Files**: 14 files, 52 usages (e.g. [`home_screen.dart:L15`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart#L15), [`Login_page/login_page.dart:L41`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart#L41)).

#### `Center`
- **Purpose**: Centers its child widget horizontally and vertically within the parent.
- **Workshop Files**: 6 files, 9 usages (e.g. [`main.dart:L56`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart#L56), [`gridview.dart:L29`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/GridView/gridview.dart#L29), [`list_view_example.dart:L26`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/ListView/list_view_example.dart#L26)).

#### `SizedBox`
- **Purpose**: Creates empty vertical or horizontal spacing or gives a fixed dimension to its child.
- **Workshop Parameters Used**: `const SizedBox(height: 20)`, `const SizedBox(height: 30)`, `const SizedBox(width: 12)`.
- **Workshop Files**: 14 files, 55 usages (e.g. [`Login_page/login_page.dart:L51,L62`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart#L51)).

#### `Card`
- **Purpose**: Material Design card surface with rounded corners and elevation shadow.
- **Workshop Parameters Used**: `shape: RoundedRectangleBorder(...)`, `child`.
- **Workshop Files**: 5 files (e.g. [`20-8-26 Card View/card.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/20-8-26%20Card%20View/card.dart), [`19-08-26 Card View/admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/19-08-26%20Card%20View/admin_dashboard.dart)).

#### `SingleChildScrollView`
- **Purpose**: A scroll box for a single child widget that prevents "A RenderFlex overflowed by xxx pixels" screen errors on smaller screens or when the keyboard opens.
- **Workshop Files**: 3 files (e.g. [`17-8-26 Admin Dashboard/admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart), [`Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart:L106`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart#L106)).

#### `LayoutBuilder`
- **Purpose**: Builds a widget tree that can depend on the parent widget's dimensions/constraints (`BoxConstraints`).
- **Workshop Files**: [`17-8-26 Admin Dashboard/admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart).

---

### 3.3 Multi-Child Layout Widgets

#### `Row`
- **Purpose**: Displays children in a horizontal array.
- **Workshop Parameters Used**: `children: [...]`, `mainAxisAlignment`, `crossAxisAlignment`.
- **Workshop Files**: 6 files, 21 usages (e.g. [`home_screen.dart:L13,L28,L54`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart#L13)).

#### `Column`
- **Purpose**: Displays children in a vertical array.
- **Workshop Parameters Used**: `children: [...]`, `mainAxisAlignment: MainAxisAlignment.center`, `crossAxisAlignment: CrossAxisAlignment.start`.
- **Workshop Files**: 20 files, 38 usages (e.g. [`home_screen.dart:L9`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart#L9), [`Login_page/login_page.dart:L42`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart#L42)).

#### `Stack` & `Positioned`
- **Purpose**: `Stack` overlays children on top of each other. `Positioned` controls the exact coordinate offsets inside the stack.
- **Workshop Parameters Used**:
  - `Stack(clipBehavior: Clip.none, children: [...])`
  - `Positioned(bottom: -40, right: 10, child: CircleAvatar(...))`
- **Workshop Files**: [`18-8-26 Stack/stack_example.dart:L11-L32`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart#L11-L32).
```dart
Stack(
  clipBehavior: Clip.none,
  children: [
    Image.network("..."),
    const Positioned(
      bottom: -40,
      right: 10,
      child: CircleAvatar(radius: 40),
    ),
    Positioned(
      bottom: -100,
      right: 5,
      child: Container(height: 100, width: 100, color: Colors.blue),
    ),
  ],
)
```

#### `Expanded`
- **Purpose**: Expands a child of a `Row` or `Column` to fill all available leftover space along the main axis.
- **Workshop Files**: [`Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart:L54`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart#L54).

---

### 3.4 Scrollable & Grid Widgets

#### `ListView` & `ListView.builder`
- **Purpose**: Linear scrollable list of widgets. `.builder` lazily creates items only as they are scrolled into view.
- **Workshop Parameters Used**: `itemCount: 10`, `itemBuilder: (context, index) { ... }`, `physics: const NeverScrollableScrollPhysics()`.
- **Workshop Files**: 6 files, including:
  - [`ListView/list_view_example.dart:L22-L40`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/ListView/list_view_example.dart#L22-L40)
  - [`ListView/wp_page.dart:L28-L47`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/ListView/wp_page.dart#L28-L47)
  - [`whatsapp_page/whatsapp_page.dart:L26-L45`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/whatsapp_page/whatsapp_page.dart#L26-L45)
```dart
ListView.builder(
  itemCount: color.length,
  itemBuilder: (context, index) {
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(8.0),
        child: Container(
          height: 150,
          width: 150,
          decoration: BoxDecoration(color: color[index]),
          child: Text("$index"),
        ),
      ),
    );
  },
)
```

#### `GridView` & `GridView.builder`
- **Purpose**: Scrollable 2-dimensional grid array of widgets.
- **Workshop Parameters Used**: `gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(crossAxisCount: 4)`, `itemCount`, `itemBuilder`.
- **Workshop Files**: [`GridView/gridview.dart:L22-L41`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/GridView/gridview.dart#L22-L41).
```dart
GridView.builder(
  gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
    crossAxisCount: 4,
  ),
  itemCount: color.length,
  itemBuilder: (context, index) {
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(8.0),
        child: Container(
          height: 150,
          width: 150,
          color: color[index]["color"],
          child: Text("${color[index]["name"]}"),
        ),
      ),
    );
  },
)
```

#### `ListTile`
- **Purpose**: Material standard list row item containing leading icons/avatars, titles, subtitles, and trailing icons.
- **Workshop Parameters Used**: `leading: CircleAvatar(...)`, `title: Text(...)`, `subtitle: Text(...)`, `trailing: Icon(...)`.
- **Workshop Files**: 7 files (e.g. [`ListView/wp_page.dart:L30-L45`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/ListView/wp_page.dart#L30-L45), [`whatsapp_page/whatsapp_page.dart:L28-L43`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/whatsapp_page/whatsapp_page.dart#L28-L43)).
```dart
ListTile(
  leading: const CircleAvatar(
    radius: 25,
    backgroundColor: Colors.grey,
  ),
  title: Text("User $index"),
  subtitle: const Text("Recent message preview..."),
  trailing: const Text("10:30 AM"),
)
```

---

### 3.5 Text, Typography & Display Widgets

#### `Text`
- **Purpose**: Displays a string of styled text.
- **Workshop Parameters Used**: `style: TextStyle(...)`, string interpolation (e.g. `Text("$index")`, `Text("${color[index]["name"]}")`).
- **Workshop Files**: 23 files, 89 usages (the most widely used display widget).

#### `Icon`
- **Purpose**: Renders an icon glyph from Material icon fonts.
- **Workshop Parameters Used**: `icon: IconData`, `size: 80`, `color: Colors.blue`.
- **Workshop Files**: 21 files, 56 usages (e.g. [`Login_page/login_page.dart:L45-L49`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart#L45-L49)).

#### `CircleAvatar`
- **Purpose**: Displays a circular avatar, often used for profile photos or WhatsApp contact pictures.
- **Workshop Parameters Used**: `radius: 40`, `backgroundColor: Colors.grey`, `backgroundImage: NetworkImage(...)`, `foregroundImage: NetworkImage(...)`.
- **Workshop Files**: 7 files (e.g. [`18-8-26 Stack/stack_example.dart:L19`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart#L19), [`ListView/wp_page.dart:L31`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/ListView/wp_page.dart#L31)).

#### `Image` (`Image.network` & `Image.asset`)
- **Purpose**: Displays images from the web via URL or bundled locally from project assets.
- **Workshop Files**:
  - `Image.network`: [`18-8-26 Stack/stack_example.dart:L14`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart#L14)
  - `Image.asset`: [`image_login_page/Login_Page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/image_login_page/Login_Page.dart)

#### `Divider`
- **Purpose**: A thin horizontal line separating list items or visual content.
- **Workshop Files**: [`Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart).

---

### 3.6 Button & Interactive Widgets

#### `ElevatedButton`
- **Purpose**: A Material elevated button used as the primary CTA (submit, login, apply).
- **Workshop Parameters Used**: `onPressed: () { ... }`, `child: const Text("Login")`.
- **Workshop Files**: 6 files (e.g. [`Login_page/login_page.dart:L84-L91`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart#L84-L91), [`05-10-26_API_service/lib/screen/login_page.dart:L78-L86`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/screen/login_page.dart#L78-L86)).

#### `IconButton`
- **Purpose**: A button containing only an icon that shows an ink splash when pressed.
- **Workshop Parameters Used**: `icon: Icon(...)`, `onPressed: () {}`, `color: Colors.white`.
- **Workshop Files**: 12 files (e.g. [`admin_dashboard.dart:L23-L30`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart#L23-L30), [`whatsapp_page/whatsapp_page.dart:L13-L22`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/whatsapp_page/whatsapp_page.dart#L13-L22)).

#### `FloatingActionButton`
- **Purpose**: Circular action button floating over screen content (e.g. counter increment, WhatsApp new chat).
- **Workshop Parameters Used**: `onPressed`, `child: const Icon(Icons.message)`, `backgroundColor: const Color(0xFF17623D)`.
- **Workshop Files**: 3 files (e.g. [`whatsapp_page/whatsapp_page.dart:L47-L51`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/whatsapp_page/whatsapp_page.dart#L47-L51), [`main.dart:L67-L71`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart#L67-L71)).

#### `InkWell`
- **Purpose**: Wraps a widget to make it clickable with a Material ripple ink splash effect.
- **Workshop Files**: [`Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart:L186`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart#L186).

---

### 3.7 Form & Input Widgets

#### `TextField`
- **Purpose**: Material single-line or multi-line text input field.
- **Workshop Parameters Used**: `controller: emailController`, `obscureText: obscurePassword`, `keyboardType: TextInputType.emailAddress`, `decoration: InputDecoration(...)`.
- **Workshop Files**: 7 files, 14 usages (e.g. [`Login_page/login_page.dart:L53-L60,L64-L78`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart#L53-L60)).
```dart
TextField(
  controller: emailController,
  decoration: const InputDecoration(
    labelText: "Email",
    border: OutlineInputBorder(),
    prefixIcon: Icon(Icons.email),
  ),
)
```

#### `DropdownMenuItem<T>`
- **Purpose**: An item choice used inside a dropdown button selector.
- **Workshop Files**: [`Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart:L177`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart#L177).

---

### 3.8 Feedback & Notification Widgets

#### `SnackBar` & `ScaffoldMessenger`
- **Purpose**: Shows temporary floating banner messages at the bottom of the screen.
- **Workshop Syntax Used**:
```dart
ScaffoldMessenger.of(context).showSnackBar(
  const SnackBar(
    content: Text("Please enter email and password"),
  ),
);
```
- **Workshop Files**: 4 files (e.g. [`Login_page/login_page.dart:L18-L30`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart#L18-L30), [`05-10-26_API_service/lib/screen/login_page.dart:L18-L30`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/screen/login_page.dart#L18-L30)).

#### `CircularProgressIndicator`
- **Purpose**: Spinning loading circle indicator used while waiting for API network responses.
- **Workshop Parameters Used**: `strokeWidth: 2`, `color: Colors.white`.
- **Workshop Files**: [`05-10-26_API_service/lib/screen/login_page.dart:L83`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/screen/login_page.dart#L83), [`Claude_12-10-26_Flutter_api/lib/screen/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/login_page.dart).

---

## 4. Predefined Framework Classes (Non-Widget Classes)

These are utility, styling, controller, and geometry classes provided by Flutter that you configure inside widgets.

### 4.1 Styling & Painting Classes

| Class | Description & Workshop Usage | Workshop Occurrences & Sample |
| :--- | :--- | :--- |
| `Colors` | Predefined Material color constants (`Colors.blue`, `Colors.red`, `Colors.grey`, `Colors.amber`, `Colors.white`). | **173 usages** across **27 files** |
| `Color` | Custom ARGB 32-bit hex color constructor (`Color(0xFF17623D)` for WhatsApp green, `Color(0xFFF26B21)`). | **10 usages** across **3 files** |
| `TextStyle` | Font styling parameters: `fontSize: 18`, `fontWeight: FontWeight.bold`, `color: Colors.white`. | **36 usages** across **13 files** |
| `FontWeight` | Font thickness levels: `FontWeight.bold`, `FontWeight.w500`, `FontWeight.w600`. | **13 usages** across **6 files** |
| `BoxDecoration` | Complete styling of a `Container`: `color`, `borderRadius`, `border`, `boxShadow`. | **40 usages** across **5 files** |
| `BorderRadius` | Corner rounding curves: `BorderRadius.circular(100)`, `BorderRadius.only()`, `BorderRadius.circular(8)`. | **26 usages** across **6 files** |
| `Border` & `BorderSide` | Box border outline and edge stroke: `BorderSide(color: Colors.grey.shade300)`. | **4 usages** across **2 files** |
| `RoundedRectangleBorder` | Rounded card border shape used in `Card(shape: RoundedRectangleBorder(...))`. | **2 usages** across **2 files** |
| `EdgeInsets` | Insets and padding dimensions: `EdgeInsets.all(8.0)`, `EdgeInsets.all(20)`, `EdgeInsets.symmetric(...)`. | **59 usages** across **16 files** |

---

### 4.2 Alignment & Geometry Classes

| Class | Description | Workshop Usage Sample |
| :--- | :--- | :--- |
| `MainAxisAlignment` | Position of children along row/column main axis. | `mainAxisAlignment: MainAxisAlignment.center` ([`login_page.dart:L43`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart#L43)) |
| `CrossAxisAlignment` | Alignment of children perpendicular to the main axis. | `crossAxisAlignment: CrossAxisAlignment.start` ([`loan_apply_page.dart:L109`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart#L109)) |
| `MainAxisSize` | Flex sizing along the main axis (`MainAxisSize.min`, `MainAxisSize.max`). | `mainAxisSize: MainAxisSize.min` |
| `Clip` | Clipping behavior configuration. | `clipBehavior: Clip.none` ([`stack_example.dart:L12`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart#L12)) |
| `NeverScrollableScrollPhysics`| Scroll physics that locks scrolling when embedding inside a parent scrollable. | `physics: const NeverScrollableScrollPhysics()` ([`loan_apply_page.dart:L155`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart#L155)) |
| `SliverGridDelegateWithFixedCrossAxisCount` | Grid layout delegate with a fixed number of tiles in the cross axis. | `crossAxisCount: 4` ([`gridview.dart:L23`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/GridView/gridview.dart#L23)) |

---

### 4.3 Controllers, Inputs & Formatters

| Class | Purpose | Workshop Code Example |
| :--- | :--- | :--- |
| `TextEditingController` | Manages reading, writing, and clearing text from a `TextField`. | `final TextEditingController emailController = TextEditingController();` ([`login_page.dart:L11`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart#L11)) |
| `InputDecoration` | Styles a `TextField` with borders, hints, labels, and prefix/suffix icons. | `decoration: const InputDecoration(labelText: "Email", border: OutlineInputBorder(), prefixIcon: Icon(Icons.email))` |
| `OutlineInputBorder` | Rectangular outline border wrapping a text input field. | `border: OutlineInputBorder()` (Used across 7 files, 17 times) |
| `TextInputType` | Sets the soft keyboard type on mobile devices. | `keyboardType: TextInputType.emailAddress`, `TextInputType.number` |
| `FilteringTextInputFormatter` | Restricts characters entered into a `TextField`. | `inputFormatters: [FilteringTextInputFormatter.digitsOnly]` ([`loan_apply_page.dart:L142`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart#L142)) |

---

### 4.4 Navigation & Routing Classes

| Class | Purpose | Workshop Usage Example |
| :--- | :--- | :--- |
| `Navigator` | Manages the stack of app screens (routes). | `Navigator.push(context, MaterialPageRoute(builder: (context) => const HomeScreen()));` ([`Login_page/login.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login.dart)) |
| `MaterialPageRoute` | A modal route that transitions with platform-native slide/fade animation. | `MaterialPageRoute(builder: (context) => const HomeScreen())` |

---

### 4.5 Theming & System Classes

| Class | Purpose | Workshop Usage Example |
| :--- | :--- | :--- |
| `ThemeData` | Central theme definition for the entire application. | `theme: ThemeData(colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple))` ([`main.dart:L12`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart#L12)) |
| `ColorScheme` | Palette of colors mapped to Material components. | `ColorScheme.fromSeed(seedColor: Colors.deepPurple)` |
| `Theme` | Accesses active theme data within the build context. | `Theme.of(context).colorScheme.inversePrimary` ([`main.dart:L46`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart#L46)) |

---

### 4.6 Predefined Icons Used in Workshop

The following constants from the predefined `Icons` class appear directly in the workshop code:

- **Authentication & User**: `Icons.email`, `Icons.lock`, `Icons.person`, `Icons.visibility`, `Icons.visibility_off`
- **Dashboard & Navigation**: `Icons.notifications`, `Icons.exit_to_app_rounded`, `Icons.home`, `Icons.arrow_back`, `Icons.arrow_forward_ios`
- **Social / WhatsApp UI**: `Icons.message`, `Icons.camera_alt`, `Icons.search`, `Icons.more_vert`, `Icons.call`, `Icons.chat`
- **Misc / Utilities**: `Icons.add`, `Icons.inventory_2_rounded`, `Icons.attach_money`, `Icons.calendar_today`

---

## 5. State Management Classes in Workshop (GetX)

In the API integration practicals ([`05-10-26_API_service`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/controller/login_controller.dart) and [`28-09-26_API`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/28-09-26_API/controller/login_controller.dart)), the workshop uses the **GetX** library for reactive state management:

| Class | Role in Workshop | Workshop Code Sample |
| :--- | :--- | :--- |
| `GetxController` | Base class for controllers separating business logic from UI. | `class LoginController extends GetxController { ... }` |
| `RxBool` | Reactive observable boolean variable. | `final RxBool isLoading = false.obs;` |
| `Obx` | Reactive widget builder that listens to observable variables (`isLoading.value`). | `Obx(() => isLoading.value ? const CircularProgressIndicator() : const Text("Login"))` |
| `SnackPosition` | Configures bottom or top placement for GetX snackbar notifications. | `snackPosition: SnackPosition.BOTTOM` |

---

## 6. Master Workshop Symbol Matrix

A complete summary table of all **70 verified predefined symbols** in this repository sorted by frequency of use:

| Symbol Name | Symbol Type | Occurrences in Workshop | Files Count | Example File Link |
| :--- | :--- | :---: | :---: | :--- |
| `Colors` | Material Class | 173 | 27 | [`admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart) |
| `Text` | Display Widget | 89 | 23 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `Icons` | Icon Class | 66 | 21 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `EdgeInsets` | Geometry Class | 59 | 16 | [`admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart) |
| `Icon` | Display Widget | 56 | 21 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `SizedBox` | Layout Widget | 55 | 14 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `Padding` | Layout Widget | 52 | 14 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `Container` | Layout Widget | 43 | 7 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `BoxDecoration` | Styling Class | 40 | 5 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `Widget` | Base Framework | 40 | 25 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `Column` | Multi-Child Layout | 38 | 20 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `TextStyle` | Styling Class | 36 | 13 | [`admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart) |
| `BuildContext` | Architecture Class | 30 | 25 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `BorderRadius` | Styling Class | 26 | 6 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `Scaffold` | Shell Widget | 24 | 24 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `StatelessWidget` | Base Class | 23 | 21 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `State` | Base Class | 23 | 7 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `Row` | Multi-Child Layout | 21 | 6 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `IconButton` | Button Widget | 20 | 12 | [`admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart) |
| `AppBar` | Shell Widget | 19 | 16 | [`admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart) |
| `OutlineInputBorder` | Input Style Class | 17 | 7 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `InputDecoration` | Input Style Class | 15 | 7 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `TextField` | Input Widget | 14 | 7 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `TextEditingController` | Controller Class | 14 | 7 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `CrossAxisAlignment` | Alignment Class | 14 | 9 | [`home_screen.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/home_screen.dart) |
| `FontWeight` | Styling Class | 13 | 6 | [`admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart) |
| `ListTile` | List Widget | 11 | 7 | [`ListView/wp_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/ListView/wp_page.dart) |
| `Color` | Styling Class | 10 | 3 | [`whatsapp_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/whatsapp_page/whatsapp_page.dart) |
| `MainAxisAlignment` | Alignment Class | 10 | 9 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `Center` | Layout Widget | 9 | 6 | [`main.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart) |
| `Card` | Layout Widget | 9 | 5 | [`20-8-26 Card View/card.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/20-8-26%20Card%20View/card.dart) |
| `CircleAvatar` | Display Widget | 8 | 7 | [`18-8-26 Stack/stack_example.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart) |
| `ListView` | Scroll Widget | 7 | 6 | [`ListView/list_view_example.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/ListView/list_view_example.dart) |
| `Theme` | Theme Widget | 7 | 4 | [`main.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart) |
| `ElevatedButton` | Button Widget | 7 | 6 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `StatefulWidget` | Base Class | 7 | 7 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `SnackBar` | Feedback Widget | 7 | 4 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `ScaffoldMessenger` | Service Class | 7 | 4 | [`Login_page/login_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login_page.dart) |
| `TextInputType` | Input Class | 5 | 4 | [`Claude_12-10-26_Flutter_api`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart) |
| `Navigator` | Routing Class | 5 | 3 | [`Login_page/login.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login.dart) |
| `MaterialApp` | Shell Widget | 4 | 4 | [`main.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart) |
| `MaterialPageRoute` | Routing Class | 4 | 2 | [`Login_page/login.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Login_page/login.dart) |
| `ThemeData` | Theming Class | 4 | 4 | [`main.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart) |
| `ColorScheme` | Theming Class | 4 | 4 | [`main.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/main.dart) |
| `SnackPosition` | GetX Class | 4 | 1 | [`05-10-26_API_service`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/controller/login_controller.dart) |
| `FloatingActionButton` | Button Widget | 3 | 3 | [`whatsapp_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/whatsapp_page/whatsapp_page.dart) |
| `SingleChildScrollView`| Layout Widget | 3 | 3 | [`admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart) |
| `Image` | Display Widget | 3 | 3 | [`18-8-26 Stack/stack_example.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart) |
| `BorderSide` | Styling Class | 3 | 1 | [`admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart) |
| `GetxController` | State Class | 3 | 3 | [`05-10-26_API_service`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/controller/login_controller.dart) |
| `Expanded` | Layout Widget | 3 | 2 | [`loan_apply_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart) |
| `GridView` | Scroll Widget | 2 | 2 | [`GridView/gridview.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/GridView/gridview.dart) |
| `Divider` | Display Widget | 2 | 1 | [`loan_apply_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart) |
| `RoundedRectangleBorder` | Styling Class | 2 | 2 | [`admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart) |
| `Positioned` | Layout Widget | 2 | 1 | [`18-8-26 Stack/stack_example.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart) |
| `RxBool` | GetX State | 2 | 1 | [`05-10-26_API_service`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/controller/login_controller.dart) |
| `Obx` | GetX Widget | 2 | 1 | [`05-10-26_API_service`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/screen/login_page.dart) |
| `SafeArea` | Layout Widget | 1 | 1 | [`loan_apply_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart) |
| `Stack` | Layout Widget | 1 | 1 | [`18-8-26 Stack/stack_example.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart) |
| `LayoutBuilder` | Layout Widget | 1 | 1 | [`admin_dashboard.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/17-8-26%20Admin%20Dashboard/admin_dashboard.dart) |
| `SliverGridDelegateWithFixedCrossAxisCount` | Grid Delegate | 1 | 1 | [`GridView/gridview.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/GridView/gridview.dart) |
| `NeverScrollableScrollPhysics` | Physics Class | 1 | 1 | [`loan_apply_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart) |
| `InkWell` | Gesture Widget | 1 | 1 | [`loan_apply_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart) |
| `DropdownMenuItem` | Form Widget | 1 | 1 | [`loan_apply_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart) |
| `CircularProgressIndicator` | Feedback Widget | 1 | 1 | [`05-10-26_API_service`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/screen/login_page.dart) |
| `MainAxisSize` | Alignment Class | 1 | 1 | [`loan_apply_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart) |
| `Clip` | Geometry Class | 1 | 1 | [`18-8-26 Stack/stack_example.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/18-8-26%20Stack/stack_example.dart) |
| `FilteringTextInputFormatter` | Formatter Class | 1 | 1 | [`loan_apply_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/Claude_12-10-26_Flutter_api/lib/screen/loan_apply_page.dart) |
| `NetworkImage` | Image Provider | 1 | 1 | [`whatsapp_page.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/whatsapp_page/whatsapp_page.dart) |
| `GetMaterialApp` | Shell Widget | 1 | 1 | [`05-10-26_API_service/lib/main.dart`](file:///d:/Happy_Coding/My_Code_In_Github/MCA/Sem-3/Dart%20Flutter/LJ_Flutter/05-10-26_API_service/lib/main.dart) |

---

*Compiled directly from the 36 Dart source files in `LJ_Flutter`.*

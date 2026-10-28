// API json response to convert dart model

class LoginModel {
  String? responseCode;
  String? message;
  String? status;
  UserData? userData;

  LoginModel({this.responseCode, this.message, this.status, this.userData});

  LoginModel.fromJson(Map<String, dynamic> json) {
    responseCode = json['response_code'];
    message = json['message'];
    status = json['status'];
    userData = json['user_data'] != null
        ? UserData.fromJson(json['user_data'])
        : null;
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{};
    data['response_code'] = responseCode;
    data['message'] = message;
    data['status'] = status;
    if (userData != null) {
      data['user_data'] = userData!.toJson();
    }
    return data;
  }
}

class UserData {
  String? id;
  String? name;
  String? surName;
  String? email;
  String? password;
  String? date;
  String? time;

  UserData(
      {this.id,
      this.name,
      this.surName,
      this.email,
      this.password,
      this.date,
      this.time});

  UserData.fromJson(Map<String, dynamic> json) {
    id = json['id'];
    name = json['Name'];
    surName = json['SurName'];
    email = json['Email'];
    password = json['Password'];
    date = json['Date'];
    time = json['Time'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{};
    data['id'] = id;
    data['Name'] = name;
    data['SurName'] = surName;
    data['Email'] = email;
    data['Password'] = password;
    data['Date'] = date;
    data['Time'] = time;
    return data;
  }
}

# -*- coding: utf-8 -*-
"""
Created on Thu Feb 26 09:39:13 2026

@author: Administrator
"""

def login():
    f = open("login.txt","r")
    for lid in f:
        unm, login = lid.split()
        if username == unm:
            return False
    return True
    f.close()

choice = 0
while choice < 3:       
    username = input("Select your userID")
    if login():
        attempt=0
        while attempt < 3:
            password = input("Enter your password")
            retype = input("Retype the password")
            if password == retype:
                f = open("login.txt","a")
                f.write("\n" + username + " " + password)
                f.close()
                attempt, choice = 3, 3
                print("Login Created Successfully...")
            else:
                print("Password must be same")
                attempt += 1
    else:
        print("This ID already exists...Please try another one")
        choice += 1
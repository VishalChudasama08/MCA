# -*- coding: utf-8 -*-
"""
Created on Wed Feb 25 14:40:54 2026

@author: Administrator
"""
def login():
    
    f = open("login.txt","r")
    for lid in f:
        unm, pwd = lid.split()
        if username == unm and password == pwd:
            return True

attempts = 0
while attempts < 3:
    username = input("Enter your user name")
    password = input("Enter your password")
    attempts += 1
    if login():
        print("login success")
        break
    else:
        print("Try again...")

        if attempts > 2:
            print("Sorry Login blocked...")
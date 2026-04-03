# -*- coding: utf-8 -*-
"""
Created on Thu Feb 26 10:09:09 2026

@author: Administrator
"""
choice = 0
f = open("words.txt","r")
while choice < 3:
    guess = input("Enter your 4 letters")
    letters = list(map(lambda ch: ch,guess))
    f.seek(0)
    for w in f:
        l = list(map(lambda c: c, w.strip()))
        if set(l) == set(letters):
            print("Guess is correct...")
            print("The word formed is ", w)
            choice = 3
            break
        
    choice += 1
f.close()

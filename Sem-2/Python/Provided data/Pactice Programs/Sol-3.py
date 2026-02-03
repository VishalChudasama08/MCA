# -*- coding: utf-8 -*-
"""
Created on Mon Feb  2 09:57:11 2026

@author: Administrator
"""

# Program to compare two sets

# Take input from user
s1 = set(map(int, input("Enter elements of Set 1 (space separated): ").split()))
s2 = set(map(int, input("Enter elements of Set 2 (space separated): ").split()))

# Compare the sets
if s1 == s2:
    print("Both sets are equal.")

elif s1.issubset(s2):
    print("Set 1 is the subset of Set 2.")

elif s2.issubset(s1):
    print("Set 2 is the subset of Set 1.")

else:
    print("Two different (unique) sets.")

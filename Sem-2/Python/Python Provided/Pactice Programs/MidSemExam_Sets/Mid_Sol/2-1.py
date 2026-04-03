# -*- coding: utf-8 -*-
"""
Created on Mon Mar 16 13:26:51 2026

@author: Administrator
"""

# Function to count digits and store in dictionary
def count_digits(nums):
    digit_dict = {}
    for n in nums:
        digit_dict[n] = len(str(abs(n)))
    return digit_dict


# Function to find palindrome numbers and return tuple
def palindrome_numbers(nums):
    pal = []
    for n in nums:
        if str(n) == str(n)[::-1]:
            pal.append(n)
    return tuple(pal)


# Function to find sum of digits of all numbers
def sum_of_digits(nums):
    total = 0
    for n in nums:
        for d in str(abs(n)):
            total += int(d)
    return total


# Function to multiply numbers by 10
def multiply_by_10(nums):
    return [n * 10 for n in nums]


# -------- Main Program --------

n = int(input("Enter number of elements: "))

numbers = []
for i in range(n):
    num = int(input("Enter number: "))
    numbers.append(num)

print("\n1) Dictionary with digit count:")
print(count_digits(numbers))

print("\n2) Palindrome numbers (tuple):")
print(palindrome_numbers(numbers))

print("\n3) Sum of all digits:")
print(sum_of_digits(numbers))

print("\n4) Numbers multiplied by 10:")
print(multiply_by_10(numbers))
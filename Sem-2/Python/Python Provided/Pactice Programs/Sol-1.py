# -*- coding: utf-8 -*-
"""
Created on Mon Feb  2 09:48:23 2026

@author: Administrator
"""

sentence = input("Enter a sentence: ")
# Split sentence into words
words = sentence.split()

# Dictionary to store word counts
word_count = {}

# Count frequency of each word
for word in words:
    word_count[word] = word_count.get(word, 0) + 1

# Display words appearing more than once
print("\nRepeated words with count:")
for word, count in word_count.items():
    if count > 1:
        print(f"{word} - {count}")
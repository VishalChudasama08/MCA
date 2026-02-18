# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
'''
f = lambda x, y: x if x > y else y
print(f(5,6))

f = lambda x,y,z: x if x>y and x>z else y if y > z else z
print(f(140,50,60))

f = lambda x: x*5 if x%2==0 else x*10
print(f(30))

l = [1,2,'a','b',3,'c',4,5,'d']
f = lambda l: [e for e in l if type(e) == int]
print(f(l))

print(list(filter(lambda e: type(e) == str ,l)))

l1 = [1,2,3]
l2 = [4,5,6]
print(list(map(lambda x,y: x+y,l1,l2)))
'''
s = 'Hello all'
l = ['a','e','i','o','u']
print((lambda x: [e for e in x if e in l])(s))
print(list(filter(lambda e: e in l, s)))

l1 = [[7,5,1],[2,6,5],[3,4,8]]
print(sorted(l1,key= lambda x: x[1]))
print(l1)
l1.sort(key = lambda x: x[0])
print(l1)


d = {1: 'Apple', 2: 'Cherry', 3: 'Banana'}
print(sorted(d.values(), key = lambda x: x[1]))

l=[88, 92, 78, 95, 86]
print(list(map(lambda x: 'A' if x>90 else 'B' if x>80 else 'C',l)))

num1 = [6, 5, 3, 9]   
num2 = [0, 1, 7, 7]

print(list(map(lambda x,y: x-y if x>y else x+y, num1, num2)))

w = ['wow', 'pet', 'cook', 'mom', 'dad', 'lol']
print(list(filter(lambda s: s==s[::-1],w)))

matrix = [[1, 2],[3,4],[5,6],[7,8]]
print(list(zip(*matrix)))

f = lambda m: [[m[i][j] for i in range(len(m))] for j in range(len(m[0]))]
print(f(matrix))
stud= [{'name': 'Amit', 'age': 25}, {'name': 'Bina', 'age': 22}, {'name': 'Dax', 'age': 25}]
print(list(sorted(stud, key=lambda x:(x['age'],x['name']),reverse = True)))

Str1 = "Hello how are you ?"
result = list(map(
    lambda word: {
        'a': word.lower().count('a'),
        'e': word.lower().count('e'),
        'i': word.lower().count('i'),
        'o': word.lower().count('o'),
        'u': word.lower().count('u'),
        'length': len(word)
    },
    Str1.split()
))
print(result)

print(list(map(lambda word: 
          {"Length": len(word), "Vowels": sum(1 for v in word if v.lower() in 'aeiou')},Str1.split())))
    
fact = lambda n: 1 if n == 0 else n * fact(n - 1)

print(fact(5))
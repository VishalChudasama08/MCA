# -*- coding: utf-8 -*-
"""
Created on Mon Mar 16 12:17:03 2026

@author: Administrator
"""
import functools

v = 'aeiouAEIOU'
s = input("Enter a string")
#print(s.split())
l = s.split()
for w in l:
    if(w[0] in v):
        print(w)
print(dict(map(lambda w:(w , w[::-1]) ,l)))

print(functools.reduce(lambda a,b: a if len(a)>len(b) else b,l))
print(min(l,key=len))

print([w for w in l if len(w) > 4])
print(list(filter(lambda w: len(w) > 4, l)))

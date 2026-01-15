# -*- coding: utf-8 -*-
"""
Created on Fri Mar 21 10:07:05 2025

@author: Administrator
"""

class negNo(Exception):
    pass
try:
    no = int(input(('Enter No')))
    if no < 0:
        raise negNo
        
    no = no / 5
    print(no)
except negNo:
    print('No is negative')
finally:
    print('End..')
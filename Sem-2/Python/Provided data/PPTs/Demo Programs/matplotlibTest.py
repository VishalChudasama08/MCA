# -*- coding: utf-8 -*-
"""
Created on Thu Feb 15 22:44:07 2024

@author: urja
"""

import matplotlib.pyplot as plt
import numpy as np

#xpoints = np.array([1, 5])
#ypoints = np.array([3, 10])
#plt.plot(xpoints, ypoints)
#
#xpoints = np.array([5, 10])
#ypoints = np.array([10, 3])
#plt.plot(xpoints, ypoints)`
#
#xpoints = np.array([3, 7])
#ypoints = np.array([6, 6])
#plt.plot(xpoints, ypoints)

xpoints = np.array([1,4,8,2])
ypoints = np.array([1,5,1,3])
plt.plot(xpoints, ypoints, color='red', linestyle='dashdot')

plt.show()

ypoints = np.array([1,5,1,5,1])
plt.plot(ypoints, marker='*')

plt.title('Letter M')
plt.xlabel('X label')
plt.ylabel('Y Label')
plt.grid(axis = 'y', linestyle='--', linewidth=1)

plt.savefig('plt1.png')
plt.show()
# -*- coding: utf-8 -*-
"""
Created on Mon Feb  2 09:51:02 2026

@author: Administrator
"""

# Electricity Bill Calculation using Dictionary

# Static dictionary for unit ranges and rates
rates = {
    (0, 100): 3.00,
    (101, 200): 4.50,
    (201, 300): 6.00,
    (301, 100000): 8.00   # upper bound kept large
}

# Accept units consumed from user
units = int(input("Enter total units consumed: "))

total_bill = 0

# Calculate bill slab-wise
for unit_range, rate in rates.items():
    lower, upper = unit_range

    if units > lower:
        consumed_units = min(units, upper) - lower
        total_bill += consumed_units * rate

# Display result
print(f"Total Electricity Bill = ₹ {total_bill}")

'''
Loop Tracing (Slab-wise Calculation)
▶️ 1st Slab: (0, 100) → ₹3.00
consumed_units = min(350, 100) - 0 = 100
amount = 100 × 3.00 = 300
total_bill = 0 + 300 = 300

▶️ 2nd Slab: (101, 200) → ₹4.50
consumed_units = min(350, 200) - 100 = 100
amount = 100 × 4.50 = 450
total_bill = 300 + 450 = 750

▶️ 3rd Slab: (201, 300) → ₹6.00
consumed_units = min(350, 300) - 200 = 100
amount = 100 × 6.00 = 600
total_bill = 750 + 600 = 1350

▶️ 4th Slab: (301, 100000) → ₹8.00
consumed_units = min(350, 100000) - 300 = 50
amount = 50 × 8.00 = 400
total_bill = 1350 + 400 = 1750
'''
# -*- coding: utf-8 -*-
"""
Created on Thu Feb 26 13:14:05 2026

@author: Administrator
"""

def validate_inputs(coverage, term, age):
    if coverage <= 0:
        return "Coverage amount must be greater than zero."
    if term <= 0:
        return "Policy term must be greater than zero."
    if term > 40:
        return "Policy term exceeds maximum allowed limit."
    if age < 18 or age > 70:
        return "Applicant not eligible for policy."
    return None


def get_base_rate(coverage):
    if coverage <= 500000:
        return 2.0
    elif coverage <= 2000000:
        return 3.5
    else:
        return 5.0


def get_age_risk_charge(coverage, age):
    if 18 <= age <= 30:
        return 0
    elif 31 <= age <= 50:
        return coverage * 0.01
    else:
        return coverage * 0.02


def calculate_premium():
    try:
        coverage = float(input("Enter Coverage Amount : "))
        term = int(input("Enter Policy Term (Years): "))
        age = int(input("Enter Applicant Age: "))
        plan_type = input("Enter Plan Type (Standard / Premium): ").strip().lower()

        error = validate_inputs(coverage, term, age)
        if error:
            print("\n", error)
            return

        base_rate = get_base_rate(coverage)
        base_premium = coverage * (base_rate / 100)

        age_risk_charge = get_age_risk_charge(coverage, age)

        plan_charge = 0
        if plan_type == "premium":
            plan_charge = 2000

        total_premium = base_premium + age_risk_charge + plan_charge

        discount = 0
        if term > 20:
            discount = total_premium * 0.05
            total_premium -= discount

        monthly_premium = total_premium / 12

        print("\n====== Premium Breakdown ======")
        print(f"Applicable Base Rate: {base_rate}%")
        print(f"Base Premium: ₹{base_premium:,.2f}")
        print(f"Age Risk Charge: ₹{age_risk_charge:,.2f}")
        print(f"Plan Charge: ₹{plan_charge:,.2f}")
        print(f"Discount Applied: ₹{discount:,.2f}")
        print("--------------------------------")
        print(f"Final Annual Premium: ₹{total_premium:,.2f}")
        print(f"Monthly Premium: ₹{monthly_premium:,.2f}")

    except ValueError:
        print("\n Invalid input. Please enter correct numeric values.")


# Run program
calculate_premium()
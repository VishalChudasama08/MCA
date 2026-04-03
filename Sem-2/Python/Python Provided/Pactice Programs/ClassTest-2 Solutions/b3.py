# -*- coding: utf-8 -*-
"""
Created on Thu Feb 26 13:17:13 2026

@author: Administrator
"""

def validate_inputs(loan_amount, years):
    if loan_amount <= 0:
        return "Loan amount must be greater than zero."
    if years <= 0:
        return "Number of years must be greater than zero."
    if years > 30:
        return "Loan tenure exceeds policy limit."
    return None


def get_interest_rate(loan_amount):
    if loan_amount <= 50000:
        return 8.0
    elif loan_amount <= 200000:
        return 10.0
    else:
        return 12.0


def calculate_loan():
    try:
        principal = float(input("Enter Loan Amount (₹): "))
        years = int(input("Enter Number of Years: "))
        customer_type = input("Enter Customer Type (Regular / Senior Citizen): ").strip().lower()

        error = validate_inputs(principal, years)
        if error:
            print("\n", error)
            return

        rate = get_interest_rate(principal)

        # Senior citizen benefit
        if customer_type == "senior citizen":
            rate -= 1

        # Compound Interest Formula
        amount = principal * (1 + rate / 100) ** years
        interest = amount - principal

        emi = amount / (years * 12)

        print("\n====== Loan Repayment Details ======")
        print(f"Applicable Interest Rate: {rate}%")
        print(f"Total Interest: ₹{interest:,.2f}")
        print(f"Total Payable Amount: ₹{amount:,.2f}")
        print(f"Monthly EMI: ₹{emi:,.2f}")

    except ValueError:
        print("\n Invalid input. Please enter correct numeric values.")


# Run program
calculate_loan()
# Unit-3 PYTHON INDICATIVE LIST.docx

"""
36	Find the factorial of a number using lambda (recursive)
"""
fact = lambda x: x if x==1 else x*fact(x-1)
print(fact(5))


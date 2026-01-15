#Recursion Function

def factorial(n):
    if n == 0:
        result = 1
    else:
        result = n * factorial(n-1)#function call itself is known as "recursion function" 
    return result

value = int(input("Enter No:  " ))
for loop in range(1,value+1):
    print("Factorial of  " ,loop , " is ",factorial(loop)) 

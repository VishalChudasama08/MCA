# Unit-3 PYTHON INDICATIVE LIST.docx

# 13	Create a lambda function that will return maximum of two numbers

max = lambda x,y: x if x>y else y
print(max(10, 20))
    
# 14	Create a lambda function that will return maximum of three numbers

max_3 = lambda x,y,z: x if x>y and x>z else(y if y>z else z)
max_3(15, 20, 10)

# 15	Write a lambda function that takes one number and if the number is even, returns that number multiplied by 5 else if the number is odd, returns that number multiplied by 10

evenodd = lambda n=int(input("Enter number:")) : n*5 if n%2==0 else n*10;
print(evenodd())

"""
16	Take a list of mixed elements and 
    a.	Write a lambda function to separate integer elements as an output list. 
    b.	Write another lambda function to separate string elements as an output list.
"""

l = [1, "hey", 2, 3, "there", 4, 1.2]

l_int = list(x for x in l if(lambda x:type(x)==int or type(x)==float)(x))
l_str = list(x for x in l if(lambda x:type(x)==str)(x))

print(l_int)
print(l_str)

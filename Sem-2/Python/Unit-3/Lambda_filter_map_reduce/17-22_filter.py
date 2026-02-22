# Unit-3 PYTHON INDICATIVE LIST.docx

# 17	Modify the above program using filter()

l = [1, "hey", 2, 3, "there", 4, 1.2]

l_int = list(filter(lambda x:type(x)==int,[x for x in l]))
l_str = list(filter(lambda x:type(x)==str,[x for x in l]))

print(l_int)
print(l_str)

# 18	Filter all vowels from the given string.

s = "hey there, i am string"
print(list(filter(lambda x:x in "aeiou",s)))

# 19	From the provided list filter, the even numbers and odd numbers as a separate output list

l = [1,2,3,4,5,6,7,8,9,10]

even = list(filter(lambda x:x%2==0, l))
odd = list(filter(lambda x:x%2==1, l))
print(odd)
print(even)

# 20	Write a lambda function that will take 2 inputs. If inputs are integers, it will return the product of 2 numbers. Else perform concatenation.

a = input("Enter first:")
b = input("Enter second:")

product = lambda a,b: int(a)*int(b) if a.isdigit() and b.isdigit() else a+b

print(product(a,b))

# 21	Sort the list elements using lambda

l = [1,8,6,4,7,3,2,9,5]

print(sorted(l, key=lambda x:x))

# 22	Find the average of all the elements passed as an argument in lambda (using variable length arguments)

avg = lambda *x : sum(x)/len(x) if x else 0
print(avg(1,2,3,4,5))


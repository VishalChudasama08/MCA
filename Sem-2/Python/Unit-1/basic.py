# find the minimum and maximum fron 2 number
"""
a = input("Enter first number: ");
b = input("Enter second number: ");

if a>b:
    print("maximum number is", a)
    print("minimum number is", b)
else:
    print("maximum number is", b)
    print("minimum number is", a)
"""

# find maximum from 3 numbers
"""
a = input("Enter first number: ");
b = input("Enter second number: ");
c = input("Enter third number: ");

if a>b:
    if c>a :
        print("maximum number is", c)
    else :
        print("maximum number is", a)
else :
    if b>c :
        print("maximum number is", b)
    else :
        print("maximum number is", c)
"""

#
"""
s = eval(input("Enter salary: "));
da=0;
hra=0;
pf=s*0.12;

if s<10000 :
    da=s*0.25;
    hra=s*0.05;
    
if s>=20000 and s<=30000:
    da=s*0.35;
    hra=s*0.10;

if s>30000 :
    da=s*0.40;
    hra=s*0.20;
    
netsal = (s+da+hra)-pf;
print("net salary=", netsal);
"""

# print 1 to 10 asending and descending order using range
"""
print("asending:")
for i in range(1,11):
    print(i)

print("\ndescending:")
for i in reversed(range(1,11)) :
    print(i)
"""

# print odd between 1 to 50
for i in range(1,50,2):
    print(i)
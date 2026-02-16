# Practice test.docx

"""
1.	Consider 2 lists, having random numbers between 1 and 50 in each list. Display the output as defined below: Create user defined functions for performing both the operations.
    a.	Display all the elements which are common in both the lists
    b.	Display only the elements which are present in list1 but not in list2
"""
import random
# l1 = [2, 5, 7, 23, 4, 9, 10, 24, 18, 8, 12, 35, 13, 26, 45, 41]
# l2 = [20, 49, 17, 23, 5, 10, 11, 25, 19, 9, 13, 36, 14, 15, 27, 46, 42]

l1 = []
l2 = []
for i in range(20):
    l1.append(random.randrange(1, 50))
    l2.append(random.randrange(1, 50))

print("list 1:",l1)
print("list 2:",l2)

def common():
    commonlist=[]
    for i in l1:
        if i in l2:
            commonlist.append(i)
    print(commonlist)            
    
def notinlist2():
    notinlist=[]
    for i in l1:
        if i not in l2:
            notinlist.append(i)
    print(notinlist)
    
common();
notinlist2();
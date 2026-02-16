# unit-2 PYTHON INDICATIVE LIST.docx

# 63.	  Take 5 names of students as an input from the user and create a dictionary with keys as their initials and value is a list as [age, degree, favorite subject] 
"""
std={}
for i in range(1,6):
    print("Enter data for student",i)
    name = input("\tname:")
    age = int(input("\tAge:"))
    fvs = input("\tFavorite subject:")
    list = [age,degree,fvs]
    std[name[0]] = list;
    
print(std)
"""

std = {'r': [20, 'MCA', 'java'], 's': [19, 'MCA', 'javasript'], 'a': [21, 'MCA', 'c'], 'k': [22, 'MCA', 'python'], 'p': [21, 'MCA', 'sql']}

# 1.	Display the youngest student from the above dictionary.
youngest = 100
k = 'v'

for i in std:
    if std[i][0]<youngest:
        youngest=std[i][0]
        k = i;

print("youngest student age is",youngest)
        

# 2.	Create a dictionary of students having rollno of the student is as key and value is a list of marks obtained by that student in 5 subjects
"""
std2={}
for i in range(1,6):
    print("Enter data for student",i)
    roll = int(input("\troll number:"))
    mark1 = int(input("\tSubject 1 Mark:"))
    mark2 = int(input("\tSubject 2 Mark:"))
    mark3 = int(input("\tSubject 3 Mark:"))
    list = [mark1,mark2,mark3]
    std2[roll] = list;
    
print(std2)
"""
std2 = {12: [60, 70, 80], 13: [70, 80, 90], 14: [90, 80, 70], 15: [88, 99, 89], 16: [80, 70, 60]}

# 3.	Create a dictionary from the above one, where key is rollno and value is (total of all subjects, percentage and grade ) a tuple of his result

std3={}
for i in std2:
    l = std2[i]
    total = 0
    for j in l:
        total += j
    per = total/3
    if per>=90:
        grade = "A"   
    elif per>=80:
        grade = "B"
    elif per>=70:
        grade = "C"
    elif per>=60:
        grade="D"
    else:
        grade="F"
    t = (total,per,grade)
    std3[i] = t;
    
print(std3)
        

# 4.	Display the rollno who has scored highest marks (total)
highest = 0;
roll = 0;
for i in std3:
    if std3[i][0]>highest:
        highest=std3[i][0]
        roll = i;
        
print(highest,"is highest marks student rollno number is",roll)


# 5.	Take 10 numbers from the user and create a list, apply bubble sort and arrange the elements in the list.
"""
l = [];
for i in range(1,11):
    print("Enter number",i,": ",end="")
    num = int(input())
    l.append(num)
""" 
l = [50, 60, 20, 100, 30, 10, 70, 40, 90, 80];
print(l)
for i in range(1,len(l)):
    for j in range(0,len(l)-1):
        if l[j] > l[j+1]:
            temp = l[j];
            l[j] = l[j+1];
            l[j+1] = temp;
print(l)



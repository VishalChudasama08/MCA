# Take user input for roll no of 5 students and their coma separated marks of 6 subjects (out of 50).
# Display the minimum and maximum marks of each subject in a separate dictionary object.
# Example:
# i/p : 	Enter RollNo : 1
# 	Enter Marks of 6 subjects: 23,33,43,29,44,35
# 	Enter RollNo : 2
# 	Enter Marks of 6 subjects: 33,32,27,25,41,30
# Enter RollNo : 3
# 	Enter Marks of 6 subjects: 43,23,43,39,44,45
# 	.
# .
# .
# .
# O/P:	{Sub1: (23,43), sub2: (23, 33), sub3: (27,43) , sub4: (25,39),……}

stud={}
'''
for i in range(5):
    rno=int(input("Enter rollno =>"))
    allmark=input("enter marks =>")
    lst=[]
    marks=allmark.split(',')
    for x in marks:
        lst.append(int(x))
    stud[rno]=lst
'''
stud={1: [23, 34, 33, 44, 43, 25],
      2: [33, 44, 42, 33, 25, 20],
      3: [34, 44, 32, 43, 22, 23],
      4: [43, 34, 23, 32, 44, 33],
      5: [44, 43, 44, 42, 41, 31]} 
print(stud)
smarks={}

values=list(stud.values())
print(values)
print(len(values))
#m=()

m = [x for x in stud.values()]
#print(m)
marks = [[m[i][j] for i in range(5)] for j in range(6)]
print(marks)

for i in range(6):
    smarks[i] = (min(marks[i]),max(marks[i]))
print(smarks)
'''
for i in range(5):
    marks=[]
    for j in range(0,len(values)):
        marks.append(values[j][i])
        print(marks)
        m+=(max(marks),min(marks))
        #print(m)
        #ind=''
        ind="sub"+str(i+1)
        
        smarks[ind]=m
        m=()
     
print(smarks)
        
'''        
    

    






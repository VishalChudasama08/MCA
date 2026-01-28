# unit-2 PYTHON INDICATIVE LIST.docx
# 45.	Display the students from L1 list, whose name contains the character ‘a’.

l1 = eval(input("Enter student list, in list format: "))
indexList = []
for i in l1:
    for j in i:
        if j == 'a':
            indexList.append(l1.index(i))
            
    
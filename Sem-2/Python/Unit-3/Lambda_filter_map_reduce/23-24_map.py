# Unit-3 PYTHON INDICATIVE LIST.docx

# 23	Find the square of each element of a list (using map())

l = [1,2,3,4,5,6,7,8,9,10]

square = list(map(lambda x:x*x, l))
print(square)

# 24	Use a lambda function to calculate grades for a list of scores (using map()) Eg scores = [88, 92, 78, 95, 86]
scores = [88, 92, 78, 95, 86]
grade = list(map(lambda x: 'A' if x>90 else ('B' if x>80 else ('C' if x>70 else ('D' if x>60 else 'F'))), scores))
print(scores)
print(grade)


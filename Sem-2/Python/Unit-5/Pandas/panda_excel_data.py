# PYTHON INDICATIVE LIST.docx UNIT-5
"""
10.	Create a dataframe from an excel sheet. (Student data: RollNo, Name, Age, Marks)
"""

import pandas as pd

std = pd.read_excel("Student.xlsx")
df = pd.DataFrame(std)

print(df)
 
# 1.	Display total number of rows and columns in the dataframe
r,c = df.shape
print("row:", r, "Column:", c)

# 2.	Display only 1st 3 rows from dataframe
print(df.head(3))

# 3.	Display only last two rows from dataframe
print(df.tail(2))

# 4.	Display 3rd to 7th row of the dsataframe
print(df[2:7])
# Unit-3 PYTHON INDICATIVE LIST.docx
"""
32	Take a list of words and print all palindrome words  using filter() [Hint: string slicing str1[::-1]]
"""

l=['vishal', 'nayan', 'ajay', 'piyush', 'pinak']
palindrome = list(filter(lambda x: x[::-1]==x,l))
print(palindrome)


"""
33	Take a list of students and filter the students whose name is less than 6 characters.
"""
l=['vishal', 'nayan', 'ajay', 'piyush', 'pinak']
less = list(filter(lambda x:len(x)<6,l))
print(less)


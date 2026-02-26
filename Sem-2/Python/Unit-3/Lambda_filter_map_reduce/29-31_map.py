# Unit-3 PYTHON INDICATIVE LIST.docx
"""
29	Take 2 lists and add the elements of it. if the 1st number is greater than the other, find the difference between them
Eg. nums1 = [6, 5, 3, 9]   nums2 = [0, 1, 7, 7]
O/P [6, 4, 10, 2]

"""
nums1 = [6, 5, 3, 9]   
nums2 = [0, 1, 7, 7]
a = list(map(lambda x,y:(x-y) if x>y else x+y, nums1, nums2))
print(a)

"""
30	Take a list of person names and display them all in upper case using map()
"""
name = ["person", "names", "and", "display"]
a=list(map(lambda x:x.upper(), name))
print(a)

"""
31	Take a list of floating-point numbers and display list of all round numbers. Also round them with just 2 decimal points. Using map()
Eg. [6.56773, 9.57668, 4.00914, 56.24241, 9.01344]
o/p [7, 10, 4, 56, 9] and [6.57, 9.58, 4.01, 56.24, 9.01]

"""

l = [6.56773, 9.57668, 4.00914, 56.24241, 9.01344]
a=list(map(lambda x:round(x), l))
b=list(map(lambda x:round(x,2), l))
print(a)
print(b)


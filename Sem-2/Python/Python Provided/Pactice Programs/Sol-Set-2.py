#Prog-1
'''
s = "welcome"
s1 = s[-1::-1]
if s == s1:
    print("palindrom")
else:
    print("NOT")
    
l1 =list(s)
#l2 = l1[:]
l2 = list(s)
print(l2)
l1.reverse()
print(l1)
if l2 == l1:
    print("palindrom")
else:
    print("Not")
    
'''
s1 = "listen"
s2 = "silent"
s1 = "Good"
s2 = "Days"

set1 = set(list(s1))
set2 = set(list(s2))

if len(set1) == len(set2):
    if set1 == set2:
        print("Anagram")
    else:
        print("Not")
else:
    print("Different Strings")
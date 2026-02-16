# Practice test.docx
"""
2.	Create a list of 10 strings by taking user input. Separate the elements based on the length of the string.
"""

l = ["Create","strings","taking","Separate","elements","length"];
ans = {}

for i in l:
    n = len(i)
    if n not in ans:
        ans[n]=[i]
    else:
        ans[n].append(i)
        
print(ans)

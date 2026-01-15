# day-3
# 4.	Print only the second line of the given string

text = "I like “Python Programming” very much\nIt is my favorite subject";

ans = text.split("\n"); # split return array
index = len(ans)-1;

print(ans[index]);

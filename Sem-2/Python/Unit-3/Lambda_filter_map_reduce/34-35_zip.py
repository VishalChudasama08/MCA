# Unit-3 PYTHON INDICATIVE LIST.docx

"""
34	Take a string as an input and display the output to analysis the string based on separate words. Using map()
    a.	Display the words in upper case along with the length of each word  
    b.	Display total number of each vowel in each word
Eg. Str1 = ‘Hello how are you?’
o/p: [{'a': 0, 'e': 1, 'length': 5}, {'a': 0, 'e': 0, 'length': 3}, {'a': 1, 'e': 1, 'length': 3}, {'a': 0, 'e': 0, 'length': 4}]

"""

s = input("Enter string: ")
l=s.split(' ');

l1 = list(map(lambda x:x.upper(), l)) 
l2 = list(map(lambda x:len(x), l))

a = list(zip(l1, l2))
print(a)

b = list(map(lambda w:{'a':w.count('a'), 'e':w.count('e'), 'i':w.count('i'), 'o':w.count('o'), 'u':w.count('u'), 'leagth':len(w)}, l))
print(b)

"""
35	Take a matrix as input and transpose its elements using lambda
Eg. matrix = [[1, 2],[3,4],[5,6],[7,8]]
      o/p: [[1, 3, 5, 7], [2, 4, 6, 8]]

"""

matrix = [[1, 2],[3,4],[5,6],[7,8]]
print(list(zip(*matrix)))



#map function
##The map() function is similar to filter() function
##but it
##acts on each element of the
##sequence and perhaps changes the elements.
def squares(no):
    return no*no
lst = [2,4,6]
#sqr = list(map(squares,lst))
sqr = map(squares,lst)
print(type(sqr))
print("List: ", lst)
print("Squares: " ,sqr)
for each in sqr:
    print(each)
print("Using Lambda")
sqr = map(lambda x:x*x,lst)
for each in sqr:
    print(each)
#passing more than one list
lst1 = [2,3,4]
lst2 = [6,7,8,7]
list3=[1,2]# nothing happen with extra element of lst2 and lst1
add =list( map(lambda x,y,z:x + y+z,lst1,lst2,list3))
print(add)

# Day-4

"""
1.	Create a menu driven program for string manipulation
    a.	Find the length of a string
    b.	Print the string in upper case
    c.	Print the string in lower case
    d.	Print the string with initial capital
    e.	Split the string

"""
text = "i like Python Programming";
print("originl String is \"", text, "\"");

print("a.	Find the length of a string\nb.	Print the string in upper case\nc.	Print the string in lower case\nd.	Print the string with initial capital\ne.	Split the string")

ch = input("Enter Your choice: ");

match ch:
    case "a" : print("String length is" , len(text));
    case "b" : print("String upper case", text.upper());
    case "c" : print("String lower case", text.lower());
    case "d" : print("String initial capital", text.capitalize());
    case "e" : print(text.split(" "))
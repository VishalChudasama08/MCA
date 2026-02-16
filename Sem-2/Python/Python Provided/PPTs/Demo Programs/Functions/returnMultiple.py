def sum_sub(no1,no2):
    add = no1 + no2
    sub = no1 - no2
    return add,sub
def main():
    no1 = int(input("Enter value of no1: "))
    no2 = int(input("Enter value of no2: "))
##    a,s = sum_sub(no1,no2)
##    print("Addition: ",type(a),"\nSubtraction: ",type(s))
    ans = sum_sub(no1,no2)
    print("Type: ",type(ans),"\nAddition: ",ans[0],"\nSubtraction: ",ans[1])
main()

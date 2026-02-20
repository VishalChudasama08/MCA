# Unit-3 PYTHON INDICATIVE LIST.docx

# 11 Create a function to generate prime numbers. Ask total numbers form the user and pass in the function which will return a list of prime numbers.
# 12 Eg. GeneratePrime(10) function will return 1st 10 prime numbers starting from 2 like  2,3,5,7,11,13,15,1719,23

def isprime(n):
    ans = True
    for i in range(1, int(n/2)):
        if n%2 == 0:
            ans = False
            break
    return ans

def generatePrime(n):
    l = []
    p = 2
    i = 0
    while True:
        if isprime(p):
            l.append(p)
            i=i+1
        
        p=p+1
        if i>=n:
            break
    return l
            
print(generatePrime(int(input("How many prime number generate: "))))

generatePrime(10);

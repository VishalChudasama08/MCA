

def calculateMaxMin(lstNum):
    if(len(lstNum) >= 0):
        maxNum = lstNum[0]
        minNum = lstNum[0]
        for num in lstNum:
            if(maxNum < num):
                maxNum = num
            elif minNum > num:
                minNum = num
        return minNum,maxNum
    else:
        return 0,0
lstNum=[int(x) for x in input().split()]

minNum,maxNum = calculateMaxMin(lstNum)
print("Min = %d Max = %d" %(minNum,maxNum))

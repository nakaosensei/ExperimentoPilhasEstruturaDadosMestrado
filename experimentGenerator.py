from random import randrange

def generateInput(qtdeOperators):
    out = ''
    startOperators=['(','[','{']
    endOperators=[')',']','}']
    mathOperations=['+','-','*','/']
    numbers=['0','1','2','3','4','5','6','7','8','9']
    randomOperatorIndex=None
    
    for i in range(0,qtdeOperators):
        randomOperatorIndex=randrange(3)
        out+=startOperators[randomOperatorIndex]
        out+=numbers[randrange(10)]
        out+=mathOperations[randrange(4)]
        out+=numbers[randrange(10)]
        out+=endOperators[randomOperatorIndex]
        if i!=qtdeOperators-1:
            out+=mathOperations[randrange(2)]
    return out

if __name__ == '__main__':
    startPoint=100000
    for i in range(0,5):
        out=generateInput(startPoint)
        f = open('./inputs/'+str(startPoint)+'.txt','w')
        f.write(out)
        f.close()
        startPoint*=2
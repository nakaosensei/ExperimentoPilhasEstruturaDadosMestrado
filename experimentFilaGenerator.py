from random import randrange

if __name__ == '__main__':
    startPoint=100
    
    while startPoint<= 100000000:
        for i in range(1,41):
            f = open('./inputsFila/teste'+str(i)+'-'+str(startPoint)+'.txt','w')
            number = randrange(startPoint, startPoint*10)
            f.write('char expressao=["'+str(number)+'"];')
            f.close()        
        startPoint = startPoint*10
    

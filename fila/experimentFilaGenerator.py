from random import randrange

if __name__ == '__main__':
    finalPoint = 100    

    while finalPoint < 100000000:
        i = 0
        f = open('./inputs/teste1'+'-'+str(finalPoint)+'.h','w')
        vetor = 'int vetor[ ] = {'
        while i < finalPoint:
            number = randrange(0, 10000)
            vetor += str(number)
            if i != finalPoint -1:
                vetor += ', '
            i+=1
        vetor += '};'
        f.write(vetor)
        f.close()
        finalPoint *= 10
    

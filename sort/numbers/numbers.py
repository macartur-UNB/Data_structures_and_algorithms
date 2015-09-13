from random import randrange as random_number

for x in range(100,10**6-1,100):
    _file = open(str(x)+".txt","w")
    for l in range(0,x):
        _file.write(str(random_number(0,10**8))+" ")
    _file.close()

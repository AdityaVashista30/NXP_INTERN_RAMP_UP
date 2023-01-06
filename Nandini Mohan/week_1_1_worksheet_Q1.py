import string
import random

rand_str = ''.join(random.choices(string.ascii_uppercase + string.digits, k=20))
rand_int = random.randint(1, 100000000) 

f1 = open("file1","w")
for i in range(5000): 
    if random.random()>0.48: 
        f1.write(str(rand_int)+'\n')
    else:
        f1.write(str(rand_str)+'\n')
f1.close

f2 = open("f2","w")
f1 = open("f1","r")
lines = f1.readlines()
for l in lines:
    if l.isnumeric():
        wstr = hex(int(l))
        f2.write(wstr+'\n')
    else:
        f2.write(str(l[::-1])+'\n') 
import string
import random


# generating random strings
rand_str = ''.join(random.choices(string.ascii_uppercase +
							string.digits, k=20))
rand_int = random.randint(1, 100000000) #random int

file1 = open("file1","w")
for i in range(5000): #5k lines of file
    if random.random()>0.48: #choose no > 0.45
        file1.write(str(rand_int)+'\n')
    else:
        file1.write(str(rand_str)+'\n')
file1.close

#wrtie to file 2
file2 = open("file2","w")
file1 = open("file1","r")
lines = file1.readlines()
for l in lines:
    if l.isnumeric():
        wstr = hex(int(l))#hex of int
        file2.write(wstr+'\n')
    else:
        file2.write(str(l[::-1])+'\n') #rev string


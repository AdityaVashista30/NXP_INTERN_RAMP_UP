from pickle import TRUE
import string
import random


# def genRandString():
#     return str(''.join([str(item) for item in random.choices(string.ascii_letters,k=15)]))
#
# def genRandInt():
#     return str(int(random.random()*1_000_000_000_000_000))
#
# def createFile1():
#     file1=open("file1","w")
#     for i in range(5000):
#           if random.random()>0.5:
#               file1.write(genRandInt()+'\n')
#           else:
#               file1.write(genRandString()+'\n')
#     file1.close()
#
# createFile1()

f1=open("file1.txt", "w")

word=""
l=0

print("on it")

while l<=5000:

    line=""
    count=0

    if random.random()>0.5:

        while count<=15:

            word=random.choice(string.ascii_letters)
            line=line+word

            count+=1
    else:

        while count<=15:

            word=random.choice(string.digits)
            line=line+word

            count+=1


    f1.write(line+'\n')
    l+=1

f1.close()

f2=open("file2.txt","w")
f1=open("file1.txt","r")
list=f1.readlines()
for line in list:
    string=line[0:-1]
    if string.isnumeric():
        string=int(string)
        string=hex(string)
        f2.write(str(string)+'\n')
    else:
        string=string[::-1]
        f2.write(str(string)+'\n')

f1.close()
f2.close()

print("done")

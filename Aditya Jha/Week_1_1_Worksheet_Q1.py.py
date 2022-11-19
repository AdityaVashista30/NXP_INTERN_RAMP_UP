import random
import string


def genRandString():
    return str(''.join([str(item) for item in random.choices(string.ascii_letters,k=15)]))

def genRandInt():
    return str(int(random.random()*1_000_000_000_000_000))

def createFile1():
    file1=open("file1","w")
    for i in range(5000):
          if random.random()>0.5:
              file1.write(genRandInt()+'\n')
          else:
              file1.write(genRandString()+'\n')
    file1.close()

def createFile2():
    file2=open("file2","w")
    file1=open("file1","r")
    list=file1.readlines()
    for line in list:
        string=line[0:-1]
        if string.isnumeric():
            string=int(string)
            string=hex(string)
            file2.write(str(string)+'\n')
        else:
            string=string[::-1]
            file2.write(str(string)+'\n')

createFile1()
createFile2()
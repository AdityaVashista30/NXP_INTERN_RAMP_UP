import string
import random



def rand_String():
    return str(''.join(random.choices(string.ascii_letters,k=20)))

def rand_Int():
    return str(random.randint((10**19),(10**20)-1))

def writeFile1():
    f = open("file1","w")
    for i in range(5000):
        if random.random() > 0.5:
            f.write(rand_String()+"\n")
        else:
            f.write(rand_Int()+"\n")
    f.close()


def writeFile2():
    f = open("file1","r")
    nf = open("file2","w")
    data = f.readlines()
    for line in data:
        d = line[0:-1]
        # print(d.isnumeric())
        if d.isnumeric():
            hexdata = hex(int(d))
            # print(hexdata)
            nf.write(str(hexdata)+"\n")
        else:
            newString = d[::-1]
            nf.write(str(newString)+"\n")





writeFile1()
writeFile2()

import os
import random
import string



#open a sample file in write mode
with open ("infile.txt","w") as f:
    choice = [0,1]              #0 stands for integers, 1 stands for strings

    for i in (random.choices(choice,k=5000)):       #create 5000 sequences with uniform probability from sequence of choices
        lgth = random.randint(15,20)                #creates sentence with given length
        s= ""
        if i==0:
            for j in range(lgth):
                s+= "".join(random.choices([random.choice(string.digits)," "],weights=[2,1]))          #generates sentences

        else:
            for j in range(lgth):
                s+= "".join(random.choices([random.choice(string.ascii_letters)," "],weights=[2,1]))   #generates sentences
        f.write(s+"\n")


#creates outfile with the desired specifications

with open ("infile.txt","r") as infile,open("outfile.txt","w") as outfile:
    lines = infile.readlines()

    for line in lines:
        s = ""
        for i in line.split():
            if i.isdigit():
                s+=(str(hex(int(i)))+" ")
            else:
                s+= i[::-1]+" "
        outfile.write(s+'\n')

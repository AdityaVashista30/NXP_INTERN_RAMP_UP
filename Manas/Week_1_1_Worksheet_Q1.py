# 1. Create a text file (file 1) and fill it contents with random integers and strings (5000 lines to be filled).
#   Populate strings and integers randomly in different lines, but make sure each type of line consist of minimum 45% of the file . Lngth of each line should be between 15-20 characters
#   Create another file (file 2). In file 2 read data from file 1; Convert integers to hex numbers in 0x format (i.e. 0x1A,0x10 etc); 
#   Reverse the strings (i.e. ABC is a boy. -> yob a si CBA. ). 

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




# for i in range(5000):
#     lth=random.randint(15,20)
    

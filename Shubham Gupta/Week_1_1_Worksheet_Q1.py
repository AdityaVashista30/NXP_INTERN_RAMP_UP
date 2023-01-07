# Create a text file (file 1) and fill it contents with random integers and strings (5000 lines to be filled).
#   Populate strings and integers randomly, but make sure each type consist of minimum 45% of the file . Lngth of each line should be between 15-20 characters
#   Create another file (file 2). In file 2 read data from file 1; Convert integers to hex numbers in 0x format (i.e. 0x1A,0x10 etc); 
#   Reverse the strings (i.e. ABC is a boy. -> yob a si CBA. ).
import string
import random
f1=open('file1.txt','w')
for i in range(5000):
    if random.random()>0.48:
        num=random.randint(100000000000000,10000000000000000000)
        f1.write(str(num)+'\n')
    else:
        strng = ''.join(random.choices(string.ascii_letters, k=random.randint(15,20)))
        f1.write(strng+'\n')
f1.close()
f1=open('file1.txt','r');
f2=open('file2.txt','w')
lines=f1.readlines()
for line in lines:
    word=line[0:-1]
    if word.isnumeric():
        word=int(word)
        word=hex(word)
        f2.write(str(word)+'\n')
    else:
        word=word[::-1]
        f2.write(str(word)+'\n')
f1.close()
f2.close()
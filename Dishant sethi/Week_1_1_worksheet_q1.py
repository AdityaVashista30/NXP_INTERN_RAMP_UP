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
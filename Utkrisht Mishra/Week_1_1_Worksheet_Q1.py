import random   
import string  


txt_fl1=open("file_1.txt", "w")

for i in range(5000):
    if random.random()>0.5:
        utm_str = ''.join(random.choices(string.ascii_letters, k=random.randint(15,20)))
        txt_fl1.write(str(utm_str) + '\n')
    else:
        utm_digi = ''.join(random.choices(string.digits, k=random.randint(15,20)))
        txt_fl1.write(str(utm_digi) + '\n')

txt_fl1.close()

txt_fl2=open("file_2.txt","w")
txt_fl1=open("file_1.txt", "r")

cust_list=txt_fl1.readlines()
for line in cust_list:
    string=line[0:-1]
    if string.isnumeric():
        string=int(string)
        string=hex(string)
        txt_fl2.write(str(string)+'\n')
    else:
        string=string[::-1]
        txt_fl2.write(str(string)+'\n')

txt_fl1.close()
txt_fl2.close()

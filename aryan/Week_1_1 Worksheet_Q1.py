import string
import random

line_count = 5000

total_count = 0
letter_count = 0
line = ""
para = ""
f1 = open("Week_1_1 Worksheet_Q1_1.txt" ,"w")

while True:
    letter_count = 0
    total_count = 0
    para = ""
    count = 0;
    while count < line_count:
        line = ""
        lastchar = random.choice(string.ascii_letters+string.digits+'\n')
        while lastchar != '\n':
            line = line + lastchar
            total_count += 1
            if lastchar.isalpha():
                letter_count += 1
            lastchar = random.choice(string.digits+string.digits+string.digits+string.digits+string.digits+string.ascii_letters+string.digits+'\n')
        count += 1
        if count <= line_count:
            para += line + "\n"
    # redo the operation if 45% criteria is not met
    if (letter_count*100)/total_count>45 and (letter_count*100)/total_count<55:
        break


f1.write(para)
#print(letter_count*100/total_count)

f1.close();
f1 = open("Week_1_1 Worksheet_Q1_1.txt", "r")
f2 = open("Week_1_1 Worksheet_Q1_2.txt", "w")

wasdigit = False
digit = ""

for line in f1.readlines():
    newline = ""
    for lett in line:
        if lett.isdigit():
            wasdigit = True
            digit += lett
            continue
        elif wasdigit == True:
            newline = hex(int(digit)) + newline
            wasdigit = False
            digit = ""
        if lett != "\n":
            newline = lett + newline
    f2.write(newline+"\n")

f2.close()

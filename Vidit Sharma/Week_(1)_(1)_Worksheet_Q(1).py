# -*- coding: utf-8 -*-
"""
Created on Thu Nov 17 12:29:01 2022

@author: Vidit Sharma
"""
import re
import random   
import string  
import secrets
final_ans=[]
final_list=[]
def generatetxt(letter_c,digit_c):
    for i in range(5000):
        res = ''.join((random.choice(string.ascii_letters) for x in range(letter_c)))  
        res += ''.join((random.choice(string.digits) for x in range(digit_c)))  
        str_list = list(res)
        random.shuffle(str_list)   
        ans = ''.join(str_list)
        final_ans.append(ans)
        my_list = list(filter(None, re.split(r'(\d+)', ans)))
        final_list.append(my_list)
    return final_ans  
ans=generatetxt(10,10)
# 20 characters in each line with 50% digits and 50%characters
separated_numlist=[]
separated_wordlist=[]
for i in final_list:
    for j in i:
        if(j[0].isnumeric()):
            separated_numlist.append(hex((int)(j)))
        else:
            separated_wordlist.append(j[::-1])

print("numbers in hex "+ str(separated_numlist))
print("words in reverse "+ str(separated_wordlist))
            
            
        
          
        

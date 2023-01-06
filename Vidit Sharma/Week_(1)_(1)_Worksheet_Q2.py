# -*- coding: utf-8 -*-
"""
Created on Fri Nov 18 02:05:46 2022

@author: Vidit Sharma
"""

import shutil
import os

file_path = input('Enter a file path: ')
dir1=os.path.basename(file_path)
dir1_name,ext=dir1.split('.')
dir2_name='Copy_'+dir1_name+'_2.'+ext
if os.path.exists(file_path):
    parent_dir = "C:/NXP_intern/"
    path = os.path.join(parent_dir, dir2_name)
    shutil.copy2(file_path, path)
    with open(path, 'r', encoding='utf-8-sig') as f:
        lines = f.readlines()
        print(lines)
else:
    print('The specified file does not exist')

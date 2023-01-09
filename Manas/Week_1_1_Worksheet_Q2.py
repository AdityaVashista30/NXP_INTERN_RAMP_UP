# Q2. Create a program which takes 2 directory paths as input (via CMD). 
# Copy the contents of directory 1 to directory 2.
# Also, change the name of all files/folders by adding preffix 'Copy_' and suffix  "__2". 
# Eg: if a file is ABC.txt then copied file should be named Copy_ABC_2.txt

import os
import shutil
import sys
import os 

src = 'src'
dest = 'dest'

shutil.copytree(src,dest)

def rename(dest):
    for file in os.listdir(dest):
        
        path = os.path.join(dest,file)
        if os.path.isfile(path):
            
            name,ext = os.path.splitext(file)
            new_name = 'Copy_'+name+'_2'+ext
            new_des=(os.path.join(dest,new_name))
            os.rename(path,new_des)
        else:
            new_name = 'Copy_'+file+'_2'
            curr = os.path.join(dest,file)
            new_des=(os.path.join(dest,new_name))
            os.rename(curr,new_des)
            rename(new_des)
rename(dest)

# Q2. Create a program which takes 2 directory paths as input (via CMD). 
# Copy the contents of directory 1 to directory 2.
# Also, change the name of all files/folders by adding preffix 'Copy_' and suffix  "__2". 
# Eg: if a file is ABC.txt then copied file should be named Copy_ABC_2.txt

import os, shutil

source_dir = input("Enter path to directory 1: ")
destination_dir = input("Enter patht to directory 2: ")

shutil.copy2(source_dir, destination_dir)

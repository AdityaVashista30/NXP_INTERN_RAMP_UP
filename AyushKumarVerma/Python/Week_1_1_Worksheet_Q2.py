# Q2. Create a program which takes 2 directory paths as input (via CMD). 
# Copy the contents of directory 1 to directory 2.
# Also, change the name of all files/folders by adding preffix 'Copy_' and suffix  "__2". 
# Eg: if a file is ABC.txt then copied file should be named Copy_ABC_2.txt

import os

source_dir = input("Enter path to source directory : ")
dest_dir = input("Enter path to destination directory : ")

for file_name in os.listdir(source_dir):
    source = os.path.join(source_dir, file_name)
    name, ext = os.path.splitext(file_name)
    updated_name = "Copy_" + name + "_2" + ext
    destination = os.path.join(dest_dir, updated_name)
    
    if os.path.isfile(source):
        print("Found File:", source)
        print("Copyting to:", destination)
        source_file = open(source, "rb")
        source_data = source_file.read()
        source_file.close()

        destination_file = open(destination, "wb")
        destination_file.write(source_data)
        destination_file.close()

import os
import shutil

src_path = input("Enter source path: ")
dest_path = input("Enter Destination path: ")

files_src = os.listdir(src_path)

shutil.copytree(src_path, dest_path)

files_dest = os.listdir(dest_path)

for file_name in files_dest:
    stp1=os.path.join(dest_path,file_name)
    src_name,ext=file_name.split('.')
    stp2=os.path.join(dest_path,"Copy_"+str(src_name)+"__2."+ext)
    os.rename(stp1,stp2)

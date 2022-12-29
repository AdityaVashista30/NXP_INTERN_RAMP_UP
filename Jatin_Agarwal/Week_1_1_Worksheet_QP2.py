

import shutil
import os
 
#taking input 
path1 = input("Enter directory1 path")
path2 = input("Enter directory2 path")
 
 #list path1 files
files=os.listdir(path1)
 
# iterating over all the files in path1 dir
for fname in files:
    shutil.copy2(os.path.join(path1,fname), path2)

#renaming files
for filename in os.listdir(path2):
		newfile ="Copy_" +filename + "__2"
		oldfile =path2 +"/"+ filename
		newfile =path2 +"/"+ newfile
		# rename() function will
		# rename all the files
		os.rename(oldfile, newfile)
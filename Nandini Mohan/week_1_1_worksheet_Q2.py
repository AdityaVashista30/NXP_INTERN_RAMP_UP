import os
import shutil
from pathlib import Path

src = input('Enter a source file path: ')
dest = input('Enter a destination file path: ')

f1=os.listdir(src)

for filename in f1:
    shutil.copy2(os.path.join(src,filename), dest)

f2=os.listdir(dest)

for filename in f2:
    n1=os.path.join(dest,filename)
    name,ext=filename.split('.')
    n2=os.path.join(dest,"Copy_"+str(name)+"__2."+ext)
    os.rename(n1,n2)
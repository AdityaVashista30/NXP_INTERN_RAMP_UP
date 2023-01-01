import os
import shutil
from pathlib import Path

src = input('Enter a source file path: ')
dest = input('Enter a destination file path: ')

files1=os.listdir(src)

for fname in files1:
    shutil.copy2(os.path.join(src,fname), dest)

files2=os.listdir(dest)

for fname in files2:
    n1=os.path.join(dest,fname)
    name,ext=fname.split('.')
    n2=os.path.join(dest,"Copy_"+str(name)+"__2."+ext)
    os.rename(n1,n2)

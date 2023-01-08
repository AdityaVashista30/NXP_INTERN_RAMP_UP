import os
 import sys
 import shutil
 dir1=sys.argv[1]
 dir2=sys.argv[2]
 files = os.listdir(dir1)
 shutil.copytree(dir1, dir2)
 i = 0
 for filename in os.listdir(dir2):
     my_source =dir2 + filename
     my_dest='Copy_'+filename+'_2'
     my_dest =dir2 + my_dest
     os.rename(my_source, my_dest)
     i += 1
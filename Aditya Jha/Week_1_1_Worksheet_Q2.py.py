import argparse
import sys
import shutil
import os

"""root="E:\Coding"
src="testdir1"
des="testdir2"""
def copyPaste(src,des):
    sys.stdout.write("\n"+str(os.listdir(src))+"\n")
    for filename in os.listdir(src):
        src_path=os.path.join(src,filename)
        des_path=des
        shutil.copy(src_path,des_path)
def rename(des):
    sys.stdout.write(str(os.listdir(des))+"\n")
    for filename in os.listdir(des):
        source=os.path.join(des,filename)
        destination=os.path.join(des,"Copy_"+str(filename)[0:-4]+"__2"+".txt")
        os.rename(source,destination)
def copyPasteAndRename(args):
    copyPaste(args.src,args.des)
    rename(args.des)
if __name__ == '__main__':
    parser=argparse.ArgumentParser(
        prog='CopyPasteRename',
        description='Copy all files from src directory and paste in des with renaming the file'
    )
    parser.add_argument('--src',help='Source Directory Address: ',required=TRUE)
    parser.add_argument('--des',help='Destination Directory Address: ',required=FALSE)
    args=parser.parse_args()
    copyPasteAndRename(args)
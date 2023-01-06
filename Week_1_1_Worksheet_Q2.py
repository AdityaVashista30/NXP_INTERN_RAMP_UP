import shutil
import os


def copy_files(source:str,dest:str):
    for file in os.listdir(source):
        # print(file)
        original=os.path.join(source,file)
        copy=os.path.join(dest,"Copy_"+file)
        if os.path.isdir(original):
            os.makedirs(copy)
            copy_files(original,copy)
        else:
            shutil.copy2(original,copy)
            # print(file)

if __name__=="__main__":
    # dir1="../../../competetive_programming"
    # dir2="../../../temp"
    source=input()
    dest=input()
    if os.path.isdir(source) and os.path.isdir(dest):
        copy_files(source,dest)
        print("done")
    else:
        raise NameError("Directory does not exist")
    

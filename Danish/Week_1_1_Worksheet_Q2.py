import sys
import shutil
from glob import glob
import os

if len(sys.argv) != 3:
    print("Provide Source and destination location to copy")
    print("Use two space seperated arguments as source and destination path")
else:
    # take source and destination arguments as directory1 and directory2
    source = sys.argv[1]
    dest = sys.argv[2]
    # Find urls for all the files in source directory
    urls = glob(os.path.join(source, '**'), recursive=True)
    # for each file in source directory
    for url in urls:
        # if it is valid file
        if os.path.isfile(url):
            # rename all folders
            new_dest = os.path.join(*[f'Copy_{folder}_2' for folder in os.path.dirname(url).split(os.path.sep)])
            # Create new destination directory
            new_dest = os.path.join(dest, new_dest)
            os.makedirs(new_dest, exist_ok=True)
            # find filename and its extension
            name, mime = os.path.splitext(os.path.basename(url))
            filename = f"Copy_{name}_2{mime}"
            # copy to destination directory
            shutil.copy(url, os.path.join(new_dest, filename))

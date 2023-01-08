import os
import shutil
import sys

# Get the source and destination directories from the command line arguments
src_dir = sys.argv[1]
dst_dir = sys.argv[2]

# Create the destination directory if it doesn't exist
if not os.path.exists(dst_dir):
  os.makedirs(dst_dir)

# Walk through the source directory
for root, dirs, files in os.walk(src_dir):
  # Create the corresponding subdirectory in the destination directory
  dst_subdir = root.replace(src_dir, dst_dir)
  if not os.path.exists(dst_subdir):
    os.makedirs(dst_subdir)
  
  # Copy the files from the source directory to the destination directory
  for file in files:
    src_file = os.path.join(root, file)
    dst_file = os.path.join(dst_subdir, 'Copy_' + file + '_2')
    shutil.copy(src_file, dst_file)

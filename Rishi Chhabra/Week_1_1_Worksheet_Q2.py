import sys
import argparse
import os



filename = sys.argv[1]
destfile = sys.argv[2]


shortfilename,filetype = filename.split(".")
print(shortfilename,filetype)

f = open(sys.argv[1],"r")
nf = open(destfile,"w")
data = f.readlines()
for line in data:
    d = line[0:-1]
    nf.write(str(d)+"\n")

os.rename(destfile,f"Copy_{shortfilename}_2.{filetype}")
nf.close()
f.close()

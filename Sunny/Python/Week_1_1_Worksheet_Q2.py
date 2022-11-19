import os

print("Enter Directory 1")
path1 = input()
print("Entered Path is :",path1)
print("Enter Directory 2")
path2 = input()
print("Entered Path is :",path2)

for file_name in os.listdir(path1):
    source = os.path.join(path1,file_name)
    name,ext = os.path.splitext(file_name)
    new_name = "Copy_"+name+"_2"+ext
    destination = os.path.join(path2,new_name)
    if os.path.isfile(source):
        print("Found File:",source)
        print("Copyting to:",destination)
        source_file = open(source, "rb")
        source_data = source_file.read()
        source_file.close()

        destination_file = open(destination,"wb")
        destination_file.write(source_data)
        destination_file.close()

       


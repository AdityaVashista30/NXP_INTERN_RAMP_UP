import random
import string

# Set the number of lines in file 1
num_lines = 5000

# Set the minimum percentage of lines that should be integers or strings
min_percentage = 45

# Set the length of each line
line_length = random.randint(15, 20)

# Create an empty list to store the lines
lines = []

# Populate the list with integers and strings
for i in range(num_lines):
  # Randomly decide whether to use an integer or a string
  if random.randint(0, 100) < min_percentage:
    # Use an integer
    lines.append(str(random.randint(0, 100)))
  else:
    # Use a string
    lines.append(''.join(random.choices(string.ascii_letters, k=line_length)))

# Write the lines to file 1
with open('file1.txt', 'w') as f:
  for line in lines:
    f.write(line + '\n')

# Read the lines from file 1
with open('file1.txt', 'r') as f:
  lines = f.readlines()

# Convert integers to hex numbers and reverse the strings
converted_lines = []
cnt=0
for line in lines:
  line=line[:-1]    
  if line.isdigit():
    cnt+=1
    converted_lines.append('0x' + hex(int(line))[2:])
  else:
    converted_lines.append(line[::-1])
print(cnt)
# Write the converted lines to file 2
with open('file2.txt', 'w') as f:
  for line in converted_lines:
    f.write(line+'\n')
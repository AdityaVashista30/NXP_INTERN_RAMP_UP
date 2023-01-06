# A, E, I, has 25 students each
# 20 students after vowel [ B, F, J]
# 30 students before vowel [D, H]
# Rest has 22 students [C,G]
import random


class Student:
    def __init__(self, section, roll, marks):
        self.section = section
        self.roll = roll
        self.marks = marks

    def __str__(self):
        return "Section: " + str(self.section) + " Roll: " + str(self.roll) + " Marks: " + str(self.marks)


# generate
db = {k: [] for k in "ABCDEFGHIJ"}
for char in db.keys():
    if char in "AEI":
        students = 25
    elif char in "BFH":
        students = 20
    elif char in "DH":
        students = 30
    else:
        students = 22
    # create database
    for i in range(1, students+1):
        db[char].append(Student(char, i, random.sample(range(1, 100), 5)))


for key, value in db.items():
    print(key)
    for s in value:
        print(s)
    print()

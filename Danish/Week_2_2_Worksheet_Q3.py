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

    def percentage(self):
        return f"{sum(self.marks)/5}%"


class NewStudent(Student):
    def __init__(self, section, roll, marks, newsection=None, newroll=None):
        Student.__init__(self, section, roll, marks)
        self.newroll = newroll
        self.newsection = newsection

    def __str__(self):
        return "Section: " + str(self.section) + " Roll: " + str(self.roll) + " Marks: " + str(self.marks) + " New Roll: " + str(self.newroll) + " New Section: " + str(self.newsection)


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
        db[char].append(NewStudent(char, i, random.sample(range(1, 100), 5)))

# sort by percentage
students = []
for k, v in db.items():
    students += v
sorted_students = sorted(students, key=lambda x: sum(x.marks), reverse=True)


db = {k: [] for k in "ABCDEFGHIJ"}
current_student = 0
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
        sorted_students[current_student + i - 1].newsection = char
        sorted_students[current_student + i - 1].newroll = i
        db[char].append(sorted_students[current_student + i - 1])
    current_student += students


# print database
for key, value in db.items():
    print(key)
    for s in value:
        print(s, s.percentage())
    print()

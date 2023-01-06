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


# Q2.a:
# Top 5 students from each section
print("Q.a")
for section in db.keys():
    print(section)
    top5_ = sorted(db[section], key=lambda x: sum(x.marks), reverse=True)[:5]
    for s in top5_:
        print(s, s.percentage())

# top 10; Q2.b
print("Q2.b")
students = []
for k, v in db.items():
    students += v

top10_ = sorted(students, key=lambda x: sum(x.marks), reverse=True)[:10]
for t in top10_:
    print(t, t.percentage())

print("Q2.c")

for i in range(5):
    top20 = sorted(students, key=lambda x: x.marks[i], reverse=True)[:20]
    print("Subject", i)
    for t in top20:
        print(t, t.percentage())

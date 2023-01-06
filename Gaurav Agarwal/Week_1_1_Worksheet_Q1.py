from itertools import permutations
a = ["This", "is", "a", "string"]
b1 = [''.join(p) for p in permutations(a[0])]
b2 = [''.join(p) for p in permutations(a[1])]
b3 = [''.join(p) for p in permutations(a[2])]
b4 = [''.join(p) for p in permutations(a[3])]
li = []
for i in b1:
    for j in b2:
        for k in b3:
            for l in b4:
                if(len(li) >= 2500):
                    break
                else:
                    li.append(i+" "+j+" "+k+" "+l+".")
f1 = open("Gaurav1.txt", 'w')
for i in range(2500):
    f1.write(li[i]+"\n")
for i in range(2500):
    f1.write("%d\n" % (i+1111111111111111))
f1 = open("Gaurav1.txt", 'r')
a = f1.readlines()
for i in a:
    print(len(i))
f1.close()
with open('Gaurav1.txt', 'r') as f1, open('Gaurav2.txt', 'w') as f2:
    for l in f1:
        f2.write(l)
f1.close()
f2.close()
f2 = open("Gaurav2.txt", 'r')
a = f2.readlines()
f2.close()
for i in range(2500):
    a[i] = a[i].split(".")[0][::-1]+"."
with open('Gaurav3.txt', 'w') as f3:
    for i in range(2500):
        f3.write(a[i]+"\n")
f3.close()
for i in range(2500):
    a[2500+i] = hex(int(a[2500+i].split("\n")[0]))
with open('Gaurav3.txt', 'a') as f3:
    for i in range(2500):
        f3.write(a[2500+i]+"\n")
f3.close()

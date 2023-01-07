class student:
    def __init__(self,osec,nsec,name,oroll,nroll,m1,m2,m3,m4,m5):
        self.osec=osec
        self.nsec=nsec
        self.name=name
        self.oroll=oroll
        self.nroll=nroll
        self.m1=m1
        self.m2=m2
        self.m3=m3
        self.m4=m4
        self.m5=m5
    def enterDetails(self,sec,name,roll,m1,m2,m3,m4,m5):
        stu=student(sec,sec,name,roll,roll,m1,m2,m3,m4,m5)
        ls.append(stu)
    def dispDetails(self,stu):
        print("Name:",stu.name)
        print("\nOld Section:",stu.osec)
        print("\nNew Section:",stu.nsec)
        print("\nOld Roll no:",stu.oroll)
        print("\nNew Roll no:",stu.nroll)
        print("\nMarks-1:",stu.m1)
        print("\nMarks-2:",stu.m2)
        print("\nMarks-3:",stu.m3)
        print("\nMarks-4:",stu.m4)
        print("\nMarks-5:",stu.m5)
    def search(self,sec,rno):
        for i in range(ls.__len__()):
            if ls[i].nroll==rno and ls[i].nsec==sec:
                return i
        return -1
    def delete(self,i):
        del ls[i]
clas={'A':[0,25],'B':[0,20],'C':[0,22],'D':[0,30],'E':[0,25],'F':[0,20],'G':[0,22],'H':[0,30],'I':[0,25],'J':[0,20]}
nclas=clas
obj=student('','','',0,0,0,0,0,0,0)
ls=[]

while(1):
    print("\n1.Enter Student details\n2.Display Student Details\n3.Delete Details of Student\n4.To shuffle students according to merit\n5.To exit\n")
    i=int(input("Enter the id of the operation to be performed:"))
    if i==1:
        sec=input("\nEnter the section of the student:")
        if clas[sec][0]>=clas[sec][1]:
            print("The section is full!!\n")
        else:
            name=input("Enter the name of student:")
            roll,m1,m2,m3,m4,m5=[int(x) for x in input("Enter roll number and the marks in subjects respectively:").split()]
            val=obj.search(sec,roll)
            if val==-1:
                clas[sec][0]=clas[sec][0]+1
                obj.enterDetails(sec,name,roll,m1,m2,m3,m4,m5)
            else:
                a=int(input("Details for the entered roll number already present in database. Enter 1 to update and 2 to discard changes."))
                if a==1:
                    obj.enterDetails(sec,name,roll,m1,m2,m3,m4,m5)                
    elif i==2:
        sec=input("Enter the section of student:")
        rno=int(input("Enter the roll number of the students:"))
        j=obj.search(sec,rno)
        if j==-1:
            print("Details are not present for the entered roll number.\n")
        else:
            obj.dispDetails(ls[j])
    elif i==3:
        sec=input("Enter the section of student:")
        rno=int(input("Enter the roll number of the student:"))
        val=obj.search(sec,rno)
        if val==-1:
            print("No data present for the entered roll number.\n")
        else:
            obj.delete(val)
            clas[sec][0]=clas[sec][0]-1
            print("Data deleted successfully.\n")
    elif i==4:
        ls.sort(key=lambda x: -(x.m1+x.m2+x.m3+x.m4+x.m5)/5)
        Y=0
        clas=nclas
        for sec in clas.keys():
            n=0
            for n in range(clas[sec][1]):
                if Y>=ls.__len__():
                    break
                ls[Y].nroll=n+1
                ls[Y].nsec=sec
                Y=Y+1
            clas[sec][0]=n+1
        print("Database Updated.\n")
    else:
        print("Exiting program...\n")
        exit(0)
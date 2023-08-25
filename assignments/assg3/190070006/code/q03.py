
#Minor
#Akshay Iyer
#190070006
#h190070006 on hackerrank
#Email id on hackerrank- 190070006@iitb.ac.in

#I pledge on my honor that I have not given or received any unauthorized #assistance on this assignment or any previous task.


stack=[]
a=[]
#b=[1,3,4,2,5]
inp= input()
b = [int(item) for item in input().split()]
for i in range(len(b)):
    k = 0
    while len(stack)>0: 
        if (b[i] >= b[int(stack[-1])]): 
            stack.pop(-1);
        else: 
            break;
    if len(stack)==0:
        k=-1
    else:
        k=stack[-1]
    
    a.append(i - k)
    stack.append(i)

for i in range(len(a)):
    print(a[i])



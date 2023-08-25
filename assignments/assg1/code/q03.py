

#Minor
#Akshay Iyer
#190070006
#h190070006 on hackerrank
#Email id on hackerrank- 190070006@iitb.ac.in

#I pledge on my honor that I have not given or received any unauthorized #assistance on this assignment or any previous task.


n=input()
n=int(n)
a=list(range(1, n+1))
a.append(1000)
a.reverse()
b=[1000]
c=[1000]

k1=0
while (len(b)!=n+1 and len(c)!=n+1):
  
  if n%2==1:
    k1=k1+1
    if k1%2==0:
      if a[-1]==1:
        a.pop()
        b.append(1)
        print("A B 1")

      elif b[-1]==1:
        b.pop()
        c.append(1)
        print("B C 1")

      else:
        c[-1]==1
        c.pop()
        a.append(1)
        print("C A 1")
        
    else:

      if a[-1]==1:
        
        if b[-1]>c[-1]:
          b.append(c[-1])
          print("C B",c[-1])
          c.pop()
        elif b[-1]<c[-1]:
          c.append(b[-1])
          print("B C",b[-1])
          b.pop()
      
      elif b[-1]==1:

        if a[-1]>c[-1]:
          a.append(c[-1])
          print("C A",c[-1])
          c.pop()
        elif a[-1]<c[-1]:
          c.append(a[-1])
          print("A C",a[-1])
          a.pop()

      else :
        if a[-1]>b[-1]:
          a.append(b[-1])
          print("B A",b[-1])
          b.pop()
        elif a[-1]<b[-1]:
          b.append(a[-1])
          print("A B",a[-1])
          a.pop()

          
  else:
    k1=k1+1
    if k1%2==0:
      if a[-1]==1:
        a.pop()
        c.append(1)
        print("A C 1")
      elif b[-1]==1:
        b.pop()
        a.append(1)
        print("B A 1")
      else:
        c[-1]==1
        c.pop()
        b.append(1)
        print("C B 1")
        
    else:

      if a[-1]==1:
        
        if b[-1]>c[-1]:
          b.append(c[-1])
          print("C B",c[-1])
          c.pop()
        elif b[-1]<c[-1]:
          c.append(b[-1])
          print("B C",b[-1])
          b.pop()
      
      elif b[-1]==1:

        if a[-1]>c[-1]:
          a.append(c[-1])
          print("C A",c[-1])
          c.pop()
        elif a[-1]<c[-1]:
          c.append(a[-1])
          print("A C",a[-1])
          a.pop()

      else :
        if a[-1]>b[-1]:
          a.append(b[-1])
          print("B A",b[-1])
          b.pop()
        elif a[-1]<b[-1]:
          b.append(a[-1])
          print("A B",a[-1])
          a.pop()
      
      

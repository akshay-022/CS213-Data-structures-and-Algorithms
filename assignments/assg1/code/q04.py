
#Minor
#Akshay Iyer
#190070006
#h190070006 on hackerrank
#Email id on hackerrank- 190070006@iitb.ac.in

#I pledge on my honor that I have not given or received any unauthorized #assistance on this assignment or any previous task.



def maxim(c, l, h, n,b):
    mid =l+((h - l)//2)
    if((mid==0 or c[mid-1]^b <= c[mid]^b) and (mid==n-1 or c[mid]^b >= c[mid+1]^b)): 
        return(mid) 
    elif(mid>0 and c[mid+1]^b >= c[mid]^b): 
        return(maxim(c,mid+1,h,n,b)) 
    else:
        return(maxim(c,l,mid-1,n,b)) 
      
n,q= [int(item) for item in input().split()]
n=int(n)
q=int(q)
#n=4
#q=3
#b=[2,4,5]
a=[]
b=[]
a = [int(item) for item in input().split()]
#a=[6,2,10,7]
xor1=0
for i in range(0, q): 
    k = int(input()) 
    xor1=xor1^k
    z=maxim(a,0,n-1,n,xor1)
    print(z+1,"\n")




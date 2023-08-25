
#Minor
#Akshay Iyer
#190070006
#h190070006 on hackerrank
#Email id on hackerrank- 190070006@iitb.ac.in

#I pledge on my honor that I have not given or received any unauthorized #assistance on this assignment or any previous task.


a=[1,1,2,5]

def ways(n):
    if n<len(a):
        return(a[n])
     
    else:
        k=0
        if n%2==0:
            for i in range(0,(n-1)//2+1):
                k=k+ways(i)*ways(n-i-1)
            k=(2*k)%1000000007
            a.append(k)
            return(k)
        else:
            for i in range(0,((n-1)//2)):
                k=k+ways(i)*ways(n-i-1)
            k=((2*k)+(ways((n-1)//2))**2)%1000000007
            a.append(k)
            return(k)
#I didn't really ned to do the odd even case, i thought it would reduce the stack space but it didn't
    
inp=input()
print(ways(int(inp))%1000000007)

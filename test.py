lst=eval(input())
s=lst[0]+lst[1]+lst[2]
t=0
for i in range(3,len(lst)):
    t=lst[i]+lst[i-1]+lst[i-2]
    if (t>s):
        ans=i-2
        s=t
print(lst[ans:ans+3])
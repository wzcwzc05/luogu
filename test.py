m = int(input())
prize = list(map(int, input().split()))
ans = [0]*10
for i in range(m):
    a = list(map(int, input().split()))
    count = 0
    for j in a:
        if j in prize:
            count += 1
    ans[count] += 1
for i in range(7, 0, -1):
    print(ans[i], end=' ')
print()

a={
    "name":"sb",
    "age":17
}
a["age"]==17

import copy

t = int(input())


def stern_broco(n: int):
    a = [(0, 1), (1, 1)]
    for i in range(n):
        b = copy.deepcopy(a)
        length = len(a)-1
        index = 0
        for j in range(length):
            temp = (a[j][0]+a[j+1][0], a[j][1]+a[j+1][1])
            b.insert(j+index+1, temp)
            index = index+1
        a = copy.deepcopy(b)
    return a


print(stern_broco(t))

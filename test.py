str = input()
i = len(str) - 1
flag = 0
while (i > -1):
    if (str[i] == '0' and flag == 0):
        i -= 1
    else:
        flag = 1
        print(str[i], end="")
        i -= 1

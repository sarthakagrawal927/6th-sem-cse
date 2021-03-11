

n = 1
while n != -1:
    n = int(input("Enter 1 for +, 2 for -, 3 for *. 4 for /, -1 to exit \n"))
    if n == -1:
        exit(0)
    a = int(input("Enter first no.\n"))
    b = int(input("Enter second no.\n"))

    if n == 1:
        print(a+b)
    elif n == 2:
        print(a-b)
    elif n == 3:
        print(a*b)
    elif n==4:
        try:          
            c = a/b
        except ZeroDivisionError:  
            c = 0
        print(c)
    
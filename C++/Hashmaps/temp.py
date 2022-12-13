a = int(input("Enter the first number\n"))
b = int(input("Enter the Second number\n"))
c = int(input("Enter the third number\n"))
if(a>b):
    if(a>c):
        print("First number is the largest\n")
    else:
        if(c>b):
            print("Third is the largest number\n")
        else:
            print("Second is the largest number\n")

else:
    if(c>a):
        print("Third number is the largest number")
    else:
        if(a>b):
            print("First is the largest number")
        else:
            print("Second is the largest number")
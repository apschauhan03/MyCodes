a = int(input("Enter the first number\n"))
b = int(input("Enter the second number\n"))
c = int(input("Enter the third number\n"))
d = int(input("Enter the fourth number\n"))

g1 = -1111111111
if(a>b):
    g1 = a
else:
    g1 = b

g2 = -1111111111
if(c>d):
    g2 = c
else:
    g2 = d

if(g1>g2):
    print(g1)
else:
    print(g2)
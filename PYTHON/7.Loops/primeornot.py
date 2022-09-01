from operator import truediv


a = int(input("Enter the number\n"))


i = 1

while(i<10):
    if(a%i==0):
        f = False
        break
    
    else:
        f = True
    i = i + 1

print(f)
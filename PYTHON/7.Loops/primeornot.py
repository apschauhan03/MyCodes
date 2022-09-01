from operator import truediv


a = int(input("Enter the number\n"))


i = 1

while(i<pow(a,.5)):
    if(a%i==0):
        f = False
        break
    
    else:
        f = True
    i = i + 1

print(f)
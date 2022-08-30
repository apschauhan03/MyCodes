username = input("Enter your usernam\n")
count = username.__len__()
if(count<10):
    print("less than 10 characters")
else:
    print("more than 10 characters")
comment = input("Enter the comment\n")
ans = ("make a lot of money" in comment or"buy now" in comment or"subscibe this" in comment or"click this" in comment)
if(ans):
    print("Spam Detect")
else:
    print("Spam NOT Detected")
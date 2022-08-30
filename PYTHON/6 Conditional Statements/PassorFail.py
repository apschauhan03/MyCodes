marks1 = int(input("Enter the marks in Science\n"))
marks2 = int(input("Enter the marks in Social Science\n"))
marks3 = int(input("Enter the marks in Maths\n"))

Total_percentage = (marks1+marks2+marks3)/3
if(Total_percentage>=40 and marks1>=33 and marks2>=33 and marks3>=33):
    print("Pass")
else:
    print("Fail")
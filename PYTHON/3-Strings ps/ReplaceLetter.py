from dataclasses import replace


letter = '''Hello <|NAME|>,
You are Selected.
Date: <|DATE|>'''
name = input("Enter your Name\n")
date = input("Enter the date\n")
letter = letter.replace("NAME",name)
letter = letter.replace("DATE",date)
print(letter)
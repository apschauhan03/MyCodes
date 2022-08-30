sample = '''there are double spaces in  this  string'''
ans = sample.find("  ")
sample = sample.replace("  "," ")
print(sample)
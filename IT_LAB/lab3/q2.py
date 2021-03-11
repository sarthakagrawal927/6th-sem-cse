import sys

inp  = open("q1.py",'r')
out = open("q1rev.txt",'w')

# for line in inp:
#     print(line)

text = inp.read()
# print(text)

out.write(text[::-1])

inp.close()
out.close()
import numpy as np
import random as rd

A = np.array([2,5,10])
print(A.dtype) 

B = np.array ([2.4,10.6,5.2])
print(B.dtype)

A=np.array([(3,4,5),(12,6,1)])

print(np.ones((3,3)))
print(A)

print(np.linspace(0,2,9))

print(rd.choice([1,2,3,4,5]))
print(rd.choice('dsada'))
print(rd.randrange(25,80))
print(rd.randrange(25,80,2))
print(rd.random())
print(rd.uniform(5,10))
print(rd.shuffle([1,2,3,4,5,7]))

for i in range(5):
    rd.seed(10)
    print(rd.randint(1, 1000))   
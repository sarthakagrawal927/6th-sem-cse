import numpy as np


aList = [23.4,21.2,54.5]
arr = np.array(aList)
print(arr)

aTuple = (34,234,23,5)
arr2 = np.array(aTuple)
print(arr2)

arr3 = np.zeros((3,4))
print(arr3)

arr4 = np.arange(0,20,5)
print(arr4)

arr5 = arr3.reshape((2,2,3))
print(arr5)

arr = np.array([[1,2,4], [ 3,5,21], [2,53,5]])

print(arr.max(axis=1))
print(arr.max(axis=0))
print(arr.sum(axis=1))
print(arr.sum(axis=0))
print(arr.min(axis=1))
print(arr.min(axis=0))
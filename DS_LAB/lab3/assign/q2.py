import numpy as np
arr = np.array([[1,2,4], [ 3,5,21], [2,53,5]])
print(arr.shape)

print('rows:')
print(arr.sum(axis =  1))
print('Columns:')
print(arr.sum(axis =  0))

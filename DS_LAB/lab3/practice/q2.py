import numpy as np

#Dimensional Array (Matrix)
a=np.arange(15).reshape(3,5)
print(a)
print(a.shape)
print(a.size)
print(a.T) #transpose

print("-------------------------------")

#Dimensional Array
c=np.arange(24).reshape(2,3,4)
print(c)
print(c.shape)
print(c[1,:,:])
print(c[:,:,2])

print("-------------------------------")

#Array operations
a = np.array( [20,30,40,50] )
print(a)
b = np.arange( 4 )
print(b)
c = a-b
print(c)
print(b**2)
print(10*np.sin(a))
print(a<35)

print("-------------------------------")

#Matrix operations
A = np.array( [[1,1],[0,1]] )
B = np.array( [[2,0],[3,4]] )
print(A*B)
print(A.dot(B))
print(np.dot(A, B))
C = np.arange(12).reshape(3,4)
print(C)
print(C.sum(axis=0))
print(C.sum(axis=1))

print("-------------------------------")

#Indexing, Slicing & Iterating Array
x = np.arange(10)**3
print(x)
print("**********")
print(x[2:5])
print("**********")
print(x[0:6:2])
print("**********")
y=np.array([[ 0, 1, 2, 3],[10, 11, 12, 13],[20, 21, 22, 23],[30, 31, 32, 33],[40, 41, 42, 43]])
print(y[2,3])
print("**********")
print(y[:5,1])
print("**********")
print(y[-1,:])
print("**********")
print(y[:,-1])
print("**********")
for row in y:
	print(row)
print("**********")	
for element in y.flat:
	print(element)
print("-------------------------------")
#Changing the shape of a matrix
print(y.ravel())
B1=y.reshape(4,5)
print(B1)  

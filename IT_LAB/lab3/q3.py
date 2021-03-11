arr = [1,2,3,5,6,7,8,9]
l = 0
u = len(arr)

def binary(l,u,toFind):
    m = ( l+u)//2
    if(l > u ):
        print('noFound  ' )
    elif arr[m] == toFind:
        print('Found at ' + str(m))
    elif arr[m] < toFind:
        binary(m+1,u,toFind)
    else:
        binary(l,m-1,toFind)

binary(l,u,7)
binary(l,u,4)

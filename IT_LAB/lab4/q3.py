class Solution:
    def findPow(self, x, n):
        num = x
        for _ in range(1, n):
            num = num * x

        return num


x = int(input("Enter x : "))
n = int(input("enter n : "))
print(Solution().findPow(x, n))

class Solution:
    def findPair(self, l, target):
        lookup = {}
        for i in range(len(l)):
            if target - l[i] in lookup:
                return {lookup[target-l[i]]+1, i+1}
            lookup[l[i]] = i


print(Solution().findPair([4, 3, 5, 8, 7, 9, 1], 6))

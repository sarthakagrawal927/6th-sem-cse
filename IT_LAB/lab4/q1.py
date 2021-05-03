class Solution:
    def generateSets(self, l):
        print("Printing Sets for {list}".format(list=l))
        ans = []
        for counter in range(0, 2**len(l)):
            ans1 = []
            for j in range(0, len(l)):
                if((counter & (1 << j)) > 0):
                    ans1.append(l[j])
            ans.append(ans1)
        return ans


print(Solution().generateSets([4, 3, 5]))

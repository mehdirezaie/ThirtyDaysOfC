'''

input:
[2,7,11,15]
9

output:
[0,1]

'''
class Solution:
     def twoSum(self, nums, target):
         n = len(nums)
         for i in range(n):
             for j in range(i+1, n):
                 sum_ij = nums[i]+nums[j]
                 if sum_ij == target:
                     return [i, j]
         return []

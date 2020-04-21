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
            remain = target - nums[i]
            
            for j in range(i+1, n):     
                if nums[j] == remain:
                    return [i, j]
        return []



def extract(input_list):
	numbers = [int(num) for num in input_list[1:-1].split(',')]
	return numbers

#--- read
nums = extract(input())
target = int(input())


solver = Solution()
print(solver.twoSum(nums, target))



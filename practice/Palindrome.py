'''

Determine whether an integer is a palindrome. 
An integer is a palindrome when it reads the same backward as forward.

'''



class Solution:
    def isPalindrome(self, x: int):
        y = 0
        while (x != 0):
            y = 10*y + (x%10)
            x = x // 10

        if y == x:
            return 'true'
        else:
            return 'false'


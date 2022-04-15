class Solution:
    def isPalindrome(self, x: int) -> bool:
        temp = str(x)[::-1]
        if temp == str(x):
            return True
        else:
            return False
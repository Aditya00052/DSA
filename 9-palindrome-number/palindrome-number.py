class Solution:
    def isPalindrome(self, x: int) -> bool:
        str_x = str(x)
        n = len(str_x)

        if n == 0 or n == 1:
            return True
        if x < 0:
            return False

        i = 0
        j = n - 1

        while i < j:
            if str_x[i] == str_x[j]:
                i += 1
                j -= 1
            else:
                return False
        
        return True
        
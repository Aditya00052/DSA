class Solution:
    def isPalindrome(self, s: str) -> bool:
        if s == '' or s == ' ':
            return True
        
        str_pal = ''.join(char.lower() for char in s if char.isalnum())

        i = 0
        j = len(str_pal) - 1

        while i < j:
            if str_pal[i] == str_pal[j]:
                i += 1
                j -= 1
            else:
                return False
        return True

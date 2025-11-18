# Time complexity = O(n)
# Space Cmplexity = O(1)

class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        res = 0

        while i < len(chars):
            count = 1
            j = i + 1
            
            while j < len(chars) and chars[j] == chars[i]:
                count += 1
                j += 1
            
            chars[res] = chars[i]
            res += 1

            if count > 1:
                str_rep = str(count)
                chars[res: res+len(str_rep)] = list(str_rep)
                res += len(str_rep)
            
            i = j
        
        return res
        
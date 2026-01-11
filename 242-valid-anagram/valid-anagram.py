class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        dict_s = {}
        dict_t = {}

        for i in range(len(s)):
            if s[i] not in dict_s:
                dict_s[s[i]] = 1
            else:
                dict_s[s[i]] += 1
        
        for i in range(len(t)):
            if t[i] not in dict_t:
                dict_t[t[i]] = 1
            else:
                dict_t[t[i]] += 1
        
        for key, value in dict_s.items():
            if key not in dict_t or dict_s[key] != dict_t[key]:
                return False
        return True
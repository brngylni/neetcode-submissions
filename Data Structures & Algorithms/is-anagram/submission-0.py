class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        s_table = {}
        t_table = {}

        for char, char_t in zip(s, t):
            ch = s_table.get(char, False)
            ch_t = t_table.get(char_t, False)
            if ch:
                s_table[char] += 1
            else:
                s_table[char] = 1
            
            if ch_t:
                t_table[char_t] += 1
            else:
                t_table[char_t] = 1

        if all(x in t_table.keys() for x in s_table.keys()):
            return all(s_table[x] == t_table[x] for x in s_table.keys())
        return False
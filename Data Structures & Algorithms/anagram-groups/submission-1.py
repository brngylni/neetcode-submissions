class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = []
        for i in range(len(strs)):
            temp = []
            if not any(strs[i] in x for x in anagrams):
                temp.append(strs[i])
            for j in range(i + 1, len(strs)):
                if any(strs[j] in x for x in anagrams):
                    continue
                if self.is_anagram(strs[i], strs[j]):
                    temp.append(strs[j])
            if len(temp) > 0:
                anagrams.append(temp)

        return anagrams

            
        

    def is_anagram(self, s1, s2):
        if len(s1) != len(s2):
            return False
        freq_s1 = {}
        freq_s2 = {}
        for ch_s1, ch_s2 in zip(s1, s2):
            if ch_s1 in freq_s1.keys():
                freq_s1[ch_s1] += 1
            else:
                freq_s1[ch_s1] = 1
            if ch_s2 in freq_s2.keys():
                freq_s2[ch_s2] += 1
            else:
                freq_s2[ch_s2] = 1
        if all(x in freq_s2.keys() for x in freq_s1.keys()):
            return all(freq_s1[key] == freq_s2[key] for key in freq_s1.keys())
        return False

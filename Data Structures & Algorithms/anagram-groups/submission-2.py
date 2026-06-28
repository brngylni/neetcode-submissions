class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) == 1:
            if isinstance(strs[0], str):
                return [[strs[0]]]
        


        freq = [[0] * 26 for _ in range(len(strs))]
        anagrams = {}
        for index, word in enumerate(strs):
            for ch in word:
                order = self.alphabetical_order(ch)
                freq[index][order] += 1
        for index, fr in enumerate(freq):
            key = tuple(fr)
            if anagrams.get(key, None) is None:
                anagrams[key] = [strs[index]]
                
            else:
                anagrams[key].append(strs[index])
        return list(anagrams.values())
       
    def alphabetical_order(self, char):
        return ord(char) - ord('a')

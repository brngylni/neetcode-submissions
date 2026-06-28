class Solution:

    def encode(self, strs: List[str]) -> str:
        st = ""
        for s in strs:
            st += f"{len(s)}#{s}"
        print(st)
        return st

    def decode(self, s: str) -> List[str]:
        strings = []
        length_string = ""
        i = 0
        while i < len(s):
            print(length_string)
            if s[i] != "#":
                length_string += s[i]
                i += 1
                continue
            if s[i] == "#":
                strings.append(s[i+1: i+int(length_string)+1])
                i += int(length_string) + 1
                length_string = ""
        return strings
            
            

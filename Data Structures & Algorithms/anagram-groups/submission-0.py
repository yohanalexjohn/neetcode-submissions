from typing import DefaultDict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        ans = DefaultDict(list)
        for word in strs:
            sorted_word = "".join(sorted(word))
            ans[sorted_word].append(word)
    
        # print(list(ans.values()))
        return list(ans.values())


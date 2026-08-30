class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        output = 0

        # Brute force
        # for i in range(len(s)):
        #     charSet = set()
            
        #     for j in range(i, len(s)):
        #         if s[j] in charSet:
        #             break
        #         charSet.add(s[j])

        #     output = max(output, len(charSet))

        # sliding window
        mp = {}
        left = 0

        for right in range(len(s)):
            if s[right] in mp:
                left = max(mp[s[right]] + 1, left)
            
            mp[s[right]] = right

            output = max(output, right - left + 1)

        return output

        
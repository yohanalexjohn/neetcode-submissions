class Solution:
    def isValid(self, s: str) -> bool:
        bracket_map = {"}": "{", ")": "(", "]": "["}

        stack = []

        for bracket in s:
            if bracket in bracket_map:
                top_element = stack.pop() if stack else "#"

                if bracket_map[bracket] != top_element:
                    return False

            else:
                stack.append(bracket)

        return not stack

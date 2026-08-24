class Solution:
    def lengthOfLongestSubstring(self, input: str) -> int:
        length_of_string = len(input)

        start_of_index = 0
        count = 0
        seen = {}
        for window_length in range(length_of_string):

            # If character is in the unique list
            # Update the start index count
            if input[window_length] in seen:
                # seen["get_char_for_fast_pointer_index"]
                start_of_index = max(
                start_of_index, seen[input[window_length]] + 1)

            # Update the unique element found with the index it was found 
            # from the original input 
            seen[input[window_length]] = window_length

            # Unique element found is the buffer size difference 
            count = max(count, window_length - start_of_index + 1)

        return count
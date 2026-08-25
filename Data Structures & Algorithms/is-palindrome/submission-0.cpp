class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right= s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }

            // Skip non-alphanumeric characters from the right
            while (left < right && !std::isalnum(s[right])) {
                right--;
            }

            // Compare characters after converting both to lowercase
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        return true;
    }
};



class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.size(); ++end) {
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
                // Move start to the right of the previous occurrence of s[end]
                start = std::max(start, charIndexMap[s[end]] + 1);
            }
            // Update the latest index of the character s[end]
            charIndexMap[s[end]] = end;
            // Calculate the length of the current substring
            maxLength = std::max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

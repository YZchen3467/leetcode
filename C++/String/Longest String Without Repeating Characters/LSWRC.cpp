#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        int start = 0;
        unordered_map<char, int> charIndexMap;

        for (int end = 0; end < n; ++end) {
            // If the character is not already in the map, or if it is not repeating
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
                start = max(start, charIndexMap[s[end]] + 1);
            }

            // If find a repeating character, move the start pointer
            charIndexMap[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    cout << "Input: 'abcabcbb'\tOutput: " << sol.lengthOfLongestSubstring(s1) << endl;
    cout << "Input: 'bbbbb'\tOutput: " << sol.lengthOfLongestSubstring(s2) << endl;
    cout << "Input: 'pwwkew'\tOutput: " << sol.lengthOfLongestSubstring(s3) << endl;
    return 0;
}
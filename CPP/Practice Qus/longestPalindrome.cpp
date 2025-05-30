#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 1) return "";

        int start = 0, maxLength = 1;

        for (int i = 0; i < n; i++) {
            // Check for odd-length palindromes
            int len1 = expandAroundCenter(s, i, i);
            // Check for even-length palindromes
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);

            if (len > maxLength) {
                maxLength = len;
                start = i - (maxLength - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // Length of the palindrome
    }
};

int main() {
    Solution solution;
    string input;

    cout << "Enter a string: ";
    cin >> input;

    string longestPalin = solution.longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << longestPalin << endl;

    return 0;
}

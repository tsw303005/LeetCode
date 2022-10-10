#include <string>

using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int left = 0, right = palindrome.length()-1;
        
        while (left < right) {
            palindrome[left] = 'a';
            if (palindrome[left] != palindrome[right]) return palindrome;
            else left++, right--;
        }
        
        left = 0, right = palindrome.length()-1;
        
        while (left < right) {
            palindrome[right] = 'b';
            if (palindrome[left] != palindrome[right]) return palindrome;
            else left++, right--;
        }
        
        return "";
    }
};

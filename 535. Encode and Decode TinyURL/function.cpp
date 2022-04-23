#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, string> longStore;
    int count;
    int remainder;
    
    Solution() {
        longStore.clear();
        count = 1;
        remainder = 64;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortenUrl = "https://";
        int tmp = count++;
        int value = 0;
        
        while (tmp > 0) {
            value = tmp % remainder;
            tmp /= remainder;
            if (value <= 25) shortenUrl += 'a' + value;
            else if (value <= 51) value -= 26, shortenUrl += 'A' + value;
            else value -= 52, shortenUrl += '0' + value;
        }
        longStore[value] = longUrl;
        
        return shortenUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int value = 0;
        
        for (int i = 8; i < shortUrl.length(); i++) {
            if ('a' <= shortUrl[i] && shortUrl[i] <= 'z')
                value = value * 62 + shortUrl[i] - 'a';
            if ('A' <= shortUrl[i] && shortUrl[i] <= 'Z')
              value = value * 62 + shortUrl[i] - 'A' + 26;
            if ('0' <= shortUrl[i] && shortUrl[i] <= '9')
              value = value * 62 + shortUrl[i] - '0' + 52;
        }
        
        return longStore[value];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

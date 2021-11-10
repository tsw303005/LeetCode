#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
        int len = wordList.size();
        int str_len = wordList[0].length();
        
        queue<string> start_q, end_q;
        map<string, int> start_m;
        map<string, int> end_m;
        start_m[beginWord] = 0;
        end_m[endWord] = 0;
        
        string letters = "abcdefghijklmnopqrstuvwxyz";
            
        unordered_set <string> WordList;
        for (auto p : wordList) WordList.insert(p);
        
        start_q.push(beginWord);
        end_q.push(endWord);
        while (!start_q.empty() || !end_q.empty()) {
            queue<string>& used_q = (start_q.size() <= end_q.size() && start_q.size() != 0) ? start_q : end_q;
            map<string, int>& used_m = (start_q.size() <= end_q.size() && start_q.size() != 0) ? start_m : end_m;
            map<string, int>& another_m = (start_q.size() <= end_q.size() && start_q.size() != 0) ? end_m : start_m;
            auto p = used_q.front();
            used_q.pop();
            if (another_m.find(p) != another_m.end()) return start_m[p] + end_m[p] + 1;
            else {
                for (int i = 0; i < str_len; i++) {
                    for (int j = 0; j < 26; j++) {
                        if (p[i] != letters[j]) {
                            string tmp = p;
                            tmp[i] = letters[j];
                            if (WordList.find(tmp) != WordList.end() && used_m.find(tmp) == used_m.end()) {
                                used_q.push(tmp);
                                used_m[tmp] = used_m[p] + 1;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};
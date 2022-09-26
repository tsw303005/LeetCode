
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) arr[i] = i;
        
        for (auto &e : equations) {
            if (e[1] == '=') arr[unionFind(e[0]-'a')] = unionFind(e[3]-'a');
        }
        
        for (auto &e : equations) {
            if (e[1] == '!' and unionFind(e[0]-'a') == unionFind(e[3]-'a')) return false;
        }
        
        return true;
    }
private:
    int arr[26];
    
    int unionFind(int a) {
       return (arr[a] == a) ? a : (arr[a] = unionFind(arr[a])); 
    }
};

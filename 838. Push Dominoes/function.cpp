using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int right = -1;
        int left = 0;
        
        for (int i = 0; i < dominoes.length(); i++) {
            if (dominoes[i] == 'L' and right == -1) {
                for (int j = i - 1; j >= 0 and dominoes[j] == '.'; j--) dominoes[j] = 'L';
            } else if (dominoes[i] == 'L' and right != -1) {
                left = i;
                while (left > right) {
                    dominoes[left--] = 'L';
                    dominoes[right++] = 'R';
                }
                right = -1;
            } else if (dominoes[i] == 'R' and right == -1) right = i;
            else if (dominoes[i] == 'R' and right != -1) {
                for (; right < i; right++) dominoes[right] = 'R';
            }
        }
        if (right != -1)
            for (; right < dominoes.length(); right++) dominoes[right] = 'R';
        
        return dominoes;
    }
};

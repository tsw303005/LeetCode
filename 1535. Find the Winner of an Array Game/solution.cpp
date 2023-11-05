class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int num = arr[0];
        int turn = 0;
        
        for (int i = 1; i < arr.size(); i++) {
            if (num > arr[i]) turn += 1;
            else {
                turn = 1;
                num = arr[i];
            }
            
            if (turn == k) break;
        }
        
        return num;
    }
};

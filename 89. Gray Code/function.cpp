#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int total = pow(2, n);
        vector<int> result(total, 0);
 
        for (int i = 0; i < total; i++) {
            result[i] = i ^ (i >> 1);
        }
        
        return result;
    }
};
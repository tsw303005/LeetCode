#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len_1 = nums1.size();
        int len_2 = nums2.size();
        int len = len_1 + len_2;
        if (len_1 > len_2) {
            return findMedianSortedArrays(nums2, nums1);
        } else if (len_1 == 0) {
            return ((double)nums2[(len_2-1)/2] + (double)nums2[len_2/2]) / 2;
        } else {
            int start = 0;
            int end = len_1;
            int cut_1, cut_2;
            double L1, L2, R1, R2;
            while (start <= end) {
                cut_1 = (start + end) / 2;
                cut_2 = (len + 1) / 2 - cut_1;
                L1 = (cut_1 == 0) ? INT_MIN : nums1[cut_1-1];
                L2 = (cut_2 == 0) ? INT_MIN : nums2[cut_2-1];
                R1 = (cut_1 == len_1) ? INT_MAX : nums1[cut_1];
                R2 = (cut_2 == len_2) ? INT_MAX : nums2[cut_2];
                if (L1 > R2) {
                    end = cut_1 - 1;
                } else if (L2 > R1) {
                    start = cut_1 + 1;
                } else {
                    if (len % 2 == 0) {
                        return (max(L1, L2) + min(R1, R2)) / 2;
                    } else {
                        return max(L1, L2);
                    }
                }
            }
        }
        return -1;
    }
};
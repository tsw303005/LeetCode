class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size();
        int nums1_last = nums1[size-1];
        int nums2_last = nums2[size-1];
        int not_change_count = 0;
        int change_count = 1;
        
        for (int i = 0; i < size - 1; i++) {
            if (nums2_last >= nums1_last) {
                if (nums2_last < nums1[i] || nums2_last < nums2[i]) return -1;
                else if (nums1_last < nums1[i] and nums1_last < nums2[i]) return -1;
                else if (nums1[i] > nums1_last) not_change_count++;
                else if (nums2[i] > nums1_last) change_count++;
            } else {
                if (nums1_last < nums1[i] || nums1_last < nums2[i]) return -1;
                else if (nums2_last < nums1[i] and nums2_last < nums2[i]) return -1;
                else if (nums2[i] > nums2_last) not_change_count++;
                else if (nums1[i] > nums2_last) change_count++;
            }
        }
        
        return min(change_count, not_change_count);
    }
};

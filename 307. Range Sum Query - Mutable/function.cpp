#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> V;
    vector<int> record;
    void build(int left, int right, int place, vector<int>& nums) {
        if (left == right) {
            record[left] = place;
            V[place] = nums[left];
        }
        else {
            int mid = (left + right) / 2;
            build(left, mid, place*2, nums);
            build(mid+1, right, place*2+1, nums);
            V[place] = V[place*2] + V[place*2+1];
        }
    }
    
    NumArray(vector<int>& nums) {
        V.resize(4*nums.size());
        record.resize(nums.size());
        build(0, nums.size()-1, 1, nums);
    }
    
    void update_tree(int index) {
        if (!index) return;
        index /= 2;
        V[index] = V[index*2] + V[index*2+1];
        update_tree(index);
    }
    
    void update(int index, int val) {
        int place = record[index];
        if (V[place] == val) return ;
        V[place] = val;
        update_tree(place);
    }
    
    int find_sum(int left, int right, int left_range, int right_range, int place) {
        if (left_range >= left && right_range <= right) return V[place];
        else {
            int left_sum, right_sum;
            left_sum = right_sum = 0;
            int mid = (left_range + right_range) / 2;
            if (mid >= left) left_sum = find_sum(left, right, left_range, mid, place*2);
            if (right > mid) right_sum = find_sum(left, right, mid+1, right_range, place*2+1);
            return left_sum + right_sum;
        }
    }
    
    int sumRange(int left, int right) {
        return find_sum(left, right, 0, record.size()-1, 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int count = 0;
        for (int i = 0; i < len; i++) {
            if(nums[i] != val) {
                nums.push_back(nums[i]);
                count++;
            }
        }
        for (int i = 0; i < count; i++) {
            nums[i] = nums[i+len];
        }
        return count;
    }
};

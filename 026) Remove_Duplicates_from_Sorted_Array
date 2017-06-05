class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int len = nums.size();
        int pre = nums[0];
        int count = 1;
        nums.push_back(nums[0]);
        for(int i = 1; i < len; i++) {
            if (nums[i] != pre) {
                pre = nums[i];
                nums.push_back(nums[i]);
                count++;
            }
        }
        int newlen = nums.size();
        for(int j = 0; j < count; j++) {
            nums[j] = nums[newlen - count + j];
        }
        return count;
    }
};

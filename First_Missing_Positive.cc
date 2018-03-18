class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		int i = 0;
		if (len == 0) {
			return 1;
		}
		while (i < len) {
			if (nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i] - 1]) {
				int temp = nums[i];
				nums[i] = nums[temp - 1];
				nums[temp - 1] = temp;
			}
			else {
				i++;
			}
		}
		if (nums[0] != 1) {
			return 1;
		}

		for (int i = 0; i < len; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
			if (i == len - 1) {
				return nums[i] + 1;
			}

		}
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::map<int, int> helper;
		std::map<int, int>::iterator it;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			it = helper.find(nums[i]);
			if (it != helper.end()) {
				if (it->second != i) {
					result.push_back(i);
					result.push_back(it->second);
					return result;
				}
			}
			else {
				helper[target - nums[i]] = i;
			}
		}
		return result;
	}
};

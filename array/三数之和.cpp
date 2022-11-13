#include "array.h"

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    if (nums.size() < 3)
        return res;
    int n = nums.size();
    for (int i=0; i<n-2; i++) {
        if (nums[i] > 0)
            continue;
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        int target = -nums[i];
        int left = i+1, right = n-1;
        while (left < right) {
            int cur = nums[left] + nums[right];
            if (cur < target)
                left++;
            else if (cur > target) {
                right--;
            } else {
                res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                while (left < right && nums[right-1] == nums[right])
                    right--;
                right--;
                while (left < right && nums[left] == nums[left+1])
                    left++;
                left++;
            }
        }
    }
    return res;
}

int main() {
	vector<int> nums{1, 2, 3};
	auto res = threeSum(nums);
	for (auto& vec : res) {
		for (int num : vec) {
			cout << num << endl;
		}
	}
	return 0;
}

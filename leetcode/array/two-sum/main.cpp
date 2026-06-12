#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int target = nums[i] * -1;
      int l = i + 1, r = n - 1;

      while (l < r) {
        int sum = nums[l] + nums[r];

        if (sum == target) {
          result.push_back({nums[i], nums[l], nums[r]});
          l++;
          r--;

          while (l < r && nums[l] == nums[l - 1]) {
            l++;
          }
        } else if (sum > target) {
          r--;
        } else {
          l++;
        }
      }
    }
    return result;
  };
};

int main() {
  Solution sol;

  sol.threeSum({-1, 0, 1, 2, -1, -4});
  return 0;
}

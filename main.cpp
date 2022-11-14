#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // Naive
  vector<int> twoSum_X(vector<int>& nums, int target) {
    size_t len = nums.size();
    auto start = nums.data();
    auto end = start + len;
    int diff = 0;
    for (auto p1 = start; p1 < end-1; p1++) {
      diff = target - *p1;
      for (auto p2 = p1 + 1; p2 < end; p2++) {

        if (*p2 == diff /* *p1 + *p2 == target*/) {
          return {int(p1-start), int(p2-start)};
        }
      }
    }

    return {0,1};
  }

  // Use hashmap to make it O(nlog(n))
  vector<int> twoSum(vector<int>& nums, int target) {
    size_t len = nums.size();

    unordered_map<int, int> hash_map;

    auto start = nums.data();
    auto end = start + len;

    auto p1 = start;
    for (int i = 0; p1 < end; p1++, i++) {
      auto it = hash_map.find(target - *p1);
      if (it != hash_map.end()) {
        return {i, it->second};
      }

      hash_map.insert(make_pair(*p1, i));
    }

    return {0,1};
  }
};

bool same(vector<int> const & a, vector<int> const & b)
{
  return a == b || (a[0] == b[1] && a[1] == b[0]);
}

int main() {
  Solution solution;
  vector<int> nums;
  int target = 0;
  vector<int> expected;
  vector<int> result;

  // ------------------------------------------------------------------------------------------------------------------
  nums = vector<int>{3,2,4};
  target = 6;
  expected = vector<int>{1,2};

  result = solution.twoSum(nums, target);
  assert(same(result, expected));

  // ------------------------------------------------------------------------------------------------------------------
  nums = vector<int>{51, 32, 94, 1, 92, 20, 8, 35, 50, 77, 81, 7, 39, 35, 80, 29, 76, 61, 40, 15, 21, 92, 33, 13, 12, 34, 87, 1, 44, 51, 72, 22, 13, 93, 77, 77, 28, 78, 59, 98, 85, 57, 75, 71, 99, 28, 7, 57, 61, 29, 43, 11, 42, 100, 65, 23, 62, 44, 92, 76, 40, 30, 59, 69, 44, 33, 78, 87, 1, 83, 54, 52, 71, 19, 88, 3, 97, 90, 96, 40, 4, 92, 55, 20, 40, 20, 17, 81, 39, 72, 40, 74, 31, 17, 60, 37, 84, 29, 95, 82, 42, 18, 49, 39, 37, 27, 97, 50, 38, 98, 63, 49, 93, 39, 96, 95, 66, 94, 42, 99, 72, 46, 75, 28, 93, 98, 3, 25, 75, 21, 74, 46, 96, 49, 29, 79, 75, 69, 45, 24, 74, 38, 84, 76, 47, 22, 62, 19, 57, 39, 82, 78, 16, 18, 81, 1, 17, 60, 41, 82, 47, 6, 26, 100, 82, 47, 61, 83, 4, 29, 88, 10, 68, 3, 88, 30, 87, 18, 86, 80, 57, 15, 67, 1, 60, 32, 47, 94, 8, 70, 12, 10, 37, 2, 71, 63, 10, 91, 69, 7, 13, 99, 39, 78, 52, 63, 66, 19, 66, 81, 90, 66, 62, 29, 59, 31, 12, 90, 71, 42, 8, 74, -3,4,3,90};
  target = 0;
  expected = vector<int>{75,222};

  result = solution.twoSum(nums, target);
  assert(same(result, expected));

  // ------------------------------------------------------------------------------------------------------------------
  nums = vector<int>{-3,4,3,90};
  target = 0;
  expected = vector<int>{0,2};

  result = solution.twoSum(nums, target);
  assert(same(result, expected));

  // ------------------------------------------------------------------------------------------------------------------
  nums = vector<int>{2,7,11,15};
  target = 9;
  expected = vector<int>{0,1};

  result = solution.twoSum(nums, target);
  assert(same(result, expected));

  // ------------------------------------------------------------------------------------------------------------------
  nums = vector<int>{3,3};
  target = 6;
  expected = vector<int>{0,1};

  result = solution.twoSum(nums, target);
//  assert(result == expected);
  assert(same(result, expected));


  return 0;
}

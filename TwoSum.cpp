/**
*   Given an array of integers, return indices of the two numbers such that they add up to a specific target.
*
*   Example:
*
*   Given nums = [2, 7, 11, 15], target = 9,
*
*   Because nums[0] + nums[1] = 2 + 7 = 9,
*   return [0, 1].
*/

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int>::iterator begin;
  vector<int>::iterator begin_2 = nums.begin();
  vector<int>::iterator end = nums.end();
  vector<int> ans;
  int ans1 = 0;
  int ans2 = 0;
  while (begin_2 != end)
  {
    begin = begin_2;
    while (begin != end)
    {
      if ((*begin_2 + *begin == target) && (begin_2 != begin))
      {
        ans.push_back(distance(nums.begin(), begin_2));
        ans.push_back(distance(nums.begin(), begin));
        return ans;
      }
      begin++;
    }
    begin_2++;
  }
  return ans;
}

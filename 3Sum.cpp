
/**
*     Given an array nums of n integers, are there elements a, b, c
*     in nums such that a + b + c = 0?
*     Find all unique triplets in the array which gives the sum of zero.
*
*			Example:
*
*			Given array nums = [-1, 0, 1, 2, -1, -4],
*
*			A solution set is:
*			[
*			  [-1, 0, 1],
*			  [-1, -1, 2]
*			]
*
*/

vector<vector<int>>  threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<int>::iterator b1, b2;
	vector<vector<int>> ans;
	vector<int> loc;
	b1 = nums.begin();
	b2 = nums.begin();
	b2++;
	int target;
	if (nums.size() == 0)
	{
		return ans;
	}

	while (b1 != nums.end() - 1)
	{
        if ((*b1 == 0) && (*b2 == 0))
		{
			if ((binary_search(b1 + 1, b2, 0)) || (binary_search(b2 + 1, nums.end(), 0)))
			{
				loc.push_back(0);
				loc.push_back(0);
				loc.push_back(0);
				ans.push_back(loc);
			}
			break;
		}
		while (b2 != nums.end())
		{
			target = -*b1 - *b2;
			if ((binary_search(b1 + 1, b2, target)) || (binary_search(b2 + 1, nums.end(), target)))
			{
				loc.push_back(*b1);
				loc.push_back(*b2);
				loc.push_back(target);
				sort(loc.begin(), loc.end());
				if (!(binary_search(ans.begin(), ans.end(), loc)))
					ans.push_back(loc);
				loc.clear();
			}
			b2++;
		}
		b1++;
		b2 = b1 + 1;
	}
	return ans;
}

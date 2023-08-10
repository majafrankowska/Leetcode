class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(), nums.end());

    int l = 0;
    int r = nums.back() - nums.front();

    while (l < r) {
      const int m = (l + r) / 2;
      if (numPairs(nums, m) >= p)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
    
    int numPairs(const vector<int>& nums, int maxDiff) {
    int pairs = 0;
    for (int i = 1; i < nums.size(); ++i)
      // Greedily pair nums[i] with nums[i - 1].
      if (nums[i] - nums[i - 1] <= maxDiff) {
        ++pairs;
        ++i;
      }
    return pairs;


    }
};

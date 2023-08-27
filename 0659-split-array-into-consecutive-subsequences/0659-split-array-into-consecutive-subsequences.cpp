class Solution {
public:
    bool isPossible(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> freq, need;
    for (auto num : nums)
    {
        freq[num]++;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (freq[nums[i]] == 0)
        {
            continue;
        }
        if (need[nums[i]] > 0)
        {
            freq[nums[i]]--;
            need[nums[i]]--;
            need[nums[i] + 1]++;
        }
        else if ((freq[nums[i]] > 0) && (freq[nums[i] + 1] > 0) && (freq[nums[i] + 2] > 0))
        {
            need[nums[i] + 3]++;
            freq[nums[i]]--;
            freq[nums[i] + 1]--;
            freq[nums[i] + 2]--;
        }
        else
            return false;
    }
    return true;
}
};
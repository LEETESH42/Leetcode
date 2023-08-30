class Solution {
public:
    static bool comp(string &x, string &y){
        if(x.size()<y.size()){
            return true;
        }
        else if(x.size()==y.size()){
            return x<y;
        }
        else{
            return false;
        }
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comp);
        return nums[nums.size()-k];
    }
};
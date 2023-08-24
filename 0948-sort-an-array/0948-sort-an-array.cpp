class Solution {
public:
    vector<int> merge(vector<int>& left, vector<int>& right){
        int leftsize=left.size(), rightsize=right.size();

        vector<int> spare(leftsize+rightsize);

        int ind=0,leftind=0, rightind=0;

        while(leftind<leftsize && rightind<rightsize){
            if(left[leftind]<=right[rightind]){
                spare[ind++]=left[leftind++];
            }
            else{
                spare[ind++]=right[rightind++];
            }
        }
        while(leftind<leftsize){
            spare[ind++]=left[leftind++];
        }
        while(rightind<rightsize){
            spare[ind++]=right[rightind++];
        }
        return spare;
    }

    vector<int> mergeSort(vector<int>& nums){
        if(nums.size()<=1){
            return nums;
        }
        int mid=nums.size()/2;

        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid, nums.end());

        left=mergeSort(left);
        right=mergeSort(right);

        return merge(left,right);
    }

    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums);
    }
};
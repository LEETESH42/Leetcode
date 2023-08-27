class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(),nums.end(),0.0);
        int count =0;
        double original_sum = sum;
        priority_queue<double> pq(nums.begin(),nums.end());


        while(sum*2 > original_sum){
            double temp = pq.top();
            pq.pop();
            sum -= (temp/2);
            pq.push(temp/2);
            count++;
        }
        return count;

    }
};

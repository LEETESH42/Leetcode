class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=0;
        int df=0;
        int bl=0;

        for(int i=0;i<gas.size();i++){
            bl=bl+gas[i]-cost[i];
            if(bl<0){
                st=i+1;
                df+=bl;
                bl=0;
            }
        }
        if(bl+df>=0){
            return st;
        }
        return -1;

    }
};
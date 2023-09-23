class Solution {
public:
    string originalDigits(string s) {

        unordered_map<char, int> mpp;
        for(auto i : s)
            mpp[i]++;

        vector<int> v(10); 

        int count = mpp['z'];
        v[0] = count;
        for(auto i : "zero")
            mpp[i] -= count;

        count = mpp['w'];
        v[2] = count;
        for(auto i : "two")
            mpp[i] -= count;

        count = mpp['u'];
        v[4] = count;
        for(auto i : "four")
            mpp[i] -= count;
        
        count = mpp['f'];
        v[5] = count;
        for(auto i : "five")
            mpp[i] -= count;
        
        count = mpp['x'];
        v[6] = count;
        for(auto i : "six")
            mpp[i] -= count;
        
        count = mpp['v'];
        v[7] = count;
        for(auto i : "seven")
            mpp[i] -= count;
        
        count = mpp['g'];
        v[8] = count;
        for(auto i : "eight")
            mpp[i] -= count;
        
        count = mpp['i'];
        v[9] = count;
        for(auto i : "nine")
            mpp[i] -= count;
        
        count = mpp['o'];
        v[1] = count;
        for(auto i : "one")
            mpp[i] -= count;
        
        count = mpp['h'];
        v[3] = count;
        for(auto i : "three")
            mpp[i] -= count;
        
        s = "";
        for(int i = 0; i < 10; i++) {
            while(v[i]--)
                s.push_back(48 + i);
        }
        return s;
    }
};
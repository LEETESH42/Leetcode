class Solution {
public:
    vector<int> solve(vector<int> arr){
        int n=arr.size();
        vector<int> res(n);

        stack<int> st;

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]=n;
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    res[i]=st.top();
                }
                else{
                    res[i]=n;
                }
            }
            st.push(i);
        }
        return res;
    }

    vector<int> get(vector<int> arr){
        int n=arr.size();
        vector<int> res(n);

        stack<int> st;

        for(int i=0;i<n;i++){
            if(st.empty()){
                res[i]=-1;
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    res[i]=st.top();
                }
                else{
                    res[i]=-1;
                }
            }
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=solve(arr);
        vector<int> pse=get(arr);

        int n=arr.size();

        long long sum=0;
        int m=1e9+7;

        for(int i=0;i<n;i++){
            long long ps=i-pse[i];
            long long ns=nse[i]-i;

            long long total=ps*ns;

            long long tot=arr[i]*total;

            sum=(sum+tot)%m;
        }
        return sum;
    }
};
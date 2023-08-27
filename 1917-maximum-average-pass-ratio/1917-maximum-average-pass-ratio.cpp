class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> maxheap;
        int n=classes.size();

        for(int i=0;i<n;i++){
            int pass=classes[i][0];
            int total=classes[i][1];

            double passRatio=double(pass)/total;

            int newPass=pass+1;
            int newTotal=total+1;

            double newPassRatio=double(newPass)/newTotal;
            maxheap.push({newPassRatio-passRatio,i});
        }

        while(extraStudents){
            auto p=maxheap.top();
            maxheap.pop();

            int i=p.second;
            classes[i][0]+=1;
            classes[i][1]+=1;

            double passRatio=double(classes[i][0])/classes[i][1];

            int newpass=classes[i][0]+1;
            int newtotal=classes[i][1]+1;

            double newPassRatio=double(newpass)/newtotal;
            maxheap.push({newPassRatio-passRatio,i});

            extraStudents--;
        }

        double sum=0;
        for(int i=0;i<classes.size();i++){
            sum+=(double)classes[i][0]/(double)classes[i][1];
        }
        return sum/(double)classes.size();

    }
};
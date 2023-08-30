class SmallestInfiniteSet {
public:
    priority_queue<int> pq;
    vector<int> v=vector<int>(1010,0);

    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++){
            pq.push(i*-1);
        }
    }
    
    int popSmallest() {
        int temp=pq.top()*-1;
        if(v[pq.top()*-1]==0){
            v[pq.top()*-1]=1;
        }
        pq.pop();
        return temp;
    }
    
    void addBack(int num) {
        if(v[num]==1){
            pq.push(num*-1);
            v[num]=0;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
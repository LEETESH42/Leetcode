class NumberContainers {
public:
    unordered_map<int,set<int>> mp1;
    unordered_map<int,int> mp2;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp2.find(index)==mp2.end()){
            mp2[index]=number;
            mp1[number].insert(index);
        }
        else{
            int curr=mp2[index];
            mp1[curr].erase(index);
            if(mp1[curr].size()==0){
                mp1.erase(curr);
            }
            mp1[number].insert(index);
            mp2[index]=number;
        }
    }
    
    int find(int number) {
        if(mp1.find(number)==mp1.end()){
            return -1;
        }
        return *mp1[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
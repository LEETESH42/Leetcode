class StockPrice {
public:
    map<int,int> value; // price,count
    map<int,int> timestock; // timestamp,price

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        auto it=timestock.find(timestamp);
        if(it!=timestock.end()){
            int price=it->second;
            value[price]--;
            if(value[price]==0){
                value.erase(price);
            }
        }
        timestock[timestamp]=price;
        value[price]++;
    }
    
    int current() {
        auto it=timestock.end();
        it--;
        return it->second;
    }
    
    int maximum() {
        auto it=value.end();
        it--;
        return it->first;

    }
    
    int minimum() {
        auto it=value.begin();
        return it->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
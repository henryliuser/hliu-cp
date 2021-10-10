class StockPrice {
public:
    map<int, int> mp;
    multiset<int> prices;
    StockPrice() {}

    void update(int timestamp, int price) {
        if (mp.count(timestamp))  // correction
            prices.erase( prices.find(mp[timestamp]) );

        mp[timestamp] = price;
        prices.insert(price);
    }

    int current() {
        return ( *mp.rbegin() ).second;
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
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

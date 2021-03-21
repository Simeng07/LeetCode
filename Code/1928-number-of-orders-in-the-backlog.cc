class Solution {
    // orders = [[10,5,0],[15,2,1],[25,1,1],[30,4,0]]
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        map<long long, long long> toSell;
        map<long long, long long, greater<long long>> toBuy;
        for (auto &order : orders) {
            int price = order[0], count = order[1], type = order[2];
            if (type == 0) {
                // buy
                while (!toSell.empty() && count > 0) {
                    auto it = toSell.begin();
                    if (it->first <= price) {
                        if (it->second > count) {
                            it->second -= count;
                            count = 0;
                        } else {
                            count -= it->second;
                            toSell.erase(it);
                        }
                    } else {
                        break;
                    }
                }
                if (count != 0) {
                    toBuy[price] += count;
                }
            } else {
                // sell
                while (!toBuy.empty() && count > 0) {
                    auto it = toBuy.begin();
                    if (it->first >= price) {
                        if (it->second > count) {
                            it->second -=count;
                            count = 0;
                        } else {
                            count -= it->second;
                            toBuy.erase(it);
                        }
                    } else {
                        break;
                    }
                }
                if (count != 0) {
                    toSell[price] += count;
                }
            }
        }
        long long result = 0;
        for (auto it = toSell.begin(); it != toSell.end(); ++it) {
            result += it->second;
        }
        for (auto it = toBuy.begin(); it != toBuy.end(); ++it) {
            result += it->second;
        }
        return result % 1000000007;
    }
};
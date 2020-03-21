class Cashier {
    int n;
    double discount;
    int products[201];
    int currentCount = 0;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices):n(n) {
        this->discount = 1 - discount / 100.0;
        for (int i = 0; i < products.size(); i++) {
            this->products[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        currentCount++;
        double origin = 0;
        for (int i = 0; i < product.size(); i++) {
            origin += products[product[i]] * amount[i];
        }
        if (currentCount == n) {
            currentCount = 0;
            return origin * discount;
        }
        return origin;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
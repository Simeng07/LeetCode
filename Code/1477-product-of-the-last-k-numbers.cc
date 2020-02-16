class ProductOfNumbers {
    vector<int> products;
    int numCount;
    int lastZero;
public:
    ProductOfNumbers() {
        lastZero = -1;
        numCount = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            lastZero = numCount;
        }
        if (numCount == 0) {
            products.push_back(num);
        } else {
            int last = products.back();
            if (last == 0) {
                products.push_back(num);
            } else {
                products.push_back(last * num);
            }
        }
        numCount++;
    }
    
    int getProduct(int k) {
        if (numCount - 1 - k > lastZero) {
            return (products[numCount - 1] / products[numCount - 1 - k]);
        } else if (numCount - 1 - k == lastZero) {
            return products[numCount - 1];
        } else {
            return 0;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
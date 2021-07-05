class Cashier {
public:
    unordered_map<int, int> product_to_price;
    int N, count, d;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        N = n;
        d = discount;
        count = 0;
        for(int i = 0; i < products.size(); i++)
            product_to_price[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double money = 0;
        for(int i = 0; i < product.size(); i++)
            money += product_to_price[product[i]]*amount[i];
        return count % N ? money : (money-(money*d)/100);
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */

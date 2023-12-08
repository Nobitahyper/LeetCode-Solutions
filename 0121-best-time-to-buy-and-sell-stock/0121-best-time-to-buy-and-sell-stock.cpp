class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;

        for (int price : prices) {
            if (price < minPrice){
                minPrice = price;
            }
            else if ( price - minPrice > maxProfit)
            {
                maxProfit = price - minPrice;
            }
        
        }

        return maxProfit;
    }
};
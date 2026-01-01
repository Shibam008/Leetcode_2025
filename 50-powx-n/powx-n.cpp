class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1.00) {
            return x;
        }
        return x * pow(x, n-1.00);
    }
};
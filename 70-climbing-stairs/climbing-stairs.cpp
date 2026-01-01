class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        int prev1 = 1, prev2 = 2, curr = 0;
        for(int i = 3; i <= n; i++) {
            curr = prev1 + prev2; // f(n) = f(n-1) + f(n-2)
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};

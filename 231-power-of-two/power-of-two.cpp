class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num = n, cnt = 0;
        while (n >= 1) {
            n = n / 2;
            cnt++;
        }
        return num == pow(2, cnt-1);
    }
};
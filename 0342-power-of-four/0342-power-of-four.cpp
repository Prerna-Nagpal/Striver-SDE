class Solution {
public:
    bool isPowerOfFour(int n) {
        long a = 1;
        int c = 0;
        while(a <= n)
        {
            if(a==n) return true;
            else
            {
                c ++;
                a = pow(4, c);
            }
        }
        return false;
    }
};
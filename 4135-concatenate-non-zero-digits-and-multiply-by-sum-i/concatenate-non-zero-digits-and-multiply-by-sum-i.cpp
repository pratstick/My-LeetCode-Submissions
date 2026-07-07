class Solution {
public:
    long long sumAndMultiply(int n) {
        string num = "";
        long long sum = 0;
        if(n==0) return 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit > 0) {
                num += (to_string(digit));
                sum += digit;
            }
            n /= 10;
        }
        reverse(num.begin(),num.end());
        return stoi(num) * sum;
    }
};
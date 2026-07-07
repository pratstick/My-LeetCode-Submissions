class Solution {
public:
    long long sumAndMultiply(int n) {
        // Safely handle 0 and negative numbers
        if (n <= 0) return 0; 
        
        long long sum = 0;
        long long reconstructedNum = 0;
        long long placeValue = 1;
        
        while (n > 0) {
            int digit = n % 10;
            
            if (digit > 0) {
                sum += digit;
                reconstructedNum += digit * placeValue;
                placeValue *= 10; // Shift to the next decimal place (tens, hundreds, etc.)
            }
            n /= 10;
        }
        
        return reconstructedNum * sum;
    }
};
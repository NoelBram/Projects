#include "brambila.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n > 0){
            ans += (n & 1);     // same as n % 2, produces 1 or 0, depending on the least significant bit of x: if the last bit is 1, the result of x & 1 is 1; otherwise, it is 0
            n >>= 1;            // same as n / 2, set x to itself shifted by one bit to the right 
        }
        return ans;
    }
};
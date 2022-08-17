#include "brambila.h"

class Solution {
public:
    int reverse(int x) {
        bool sign = (x >= 0);
        unsigned long _a = abs(x), _b = 0;
        while(_a > 0) {
            _b *= 10;
            _b += _a % 10;
            _a /= 10; 
        }
        int r = (int)(_b); 
        if (_b != (unsigned long)r){
            return 0;
        } 
        if (!sign) {
            r = 0 - _b;
        } if ((unsigned long)abs(r) != _b) {
            return 0;
        }
        return r;
    }
};


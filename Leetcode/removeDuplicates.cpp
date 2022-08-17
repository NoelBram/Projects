#include "brambila.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            int a = nums[i-1], b = nums[i];
            if(a == b){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};
/*  Created: 07/01/20
    Modified: 07/01/20
    Completed: 
Description:
    Determine whether an integer is a palindrome. 
    An integer is a palindrome when it reads the same backward as forward.
   
*/
#include "brambila.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 ){
            return false;
        }
        double checker, ceiling;             // the two index's that I  will use to commpare if the int is a palindrome. 
        string str = to_string(x);  // The int is converted into an int so that I can read it. 
        ceiling = str.size()/2;
        ceiling = floor(ceiling);
        for(int i = 0; i < ceiling; i++){
            checker = ((str.size() - i) - 1);
            if(str[i] == str[checker]){
                continue; 
            }
            return false;
        }
        return true; 
    }
};

int main(){
    Solution Test;
    cout << " Enter an integer to check if it is a Potential Palindrome " << endl; 
    int x;
    cin >> x;
    cout << boolalpha << Test.isPalindrome(x) << endl;
}
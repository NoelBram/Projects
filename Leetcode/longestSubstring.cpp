/*  Created: 07/03/20
    Modified: 11/06/20
    Completed: 07/28/20

Description:
    Given a string, find the length of the longest substring without repeating characters.

*/

#include "brambila.h"

class longestSubstring {
public:
    int lengthOfLongestSubstring(string s);                 // Runtime is Higher 
    bool allUnique(string str, int start, int end);         
    int lengthOfLongestSubstringOptionTwo(string s);        // Runtime is Better
};

int longestSubstring::lengthOfLongestSubstring(string s){
    int stringLength = s.length();
    int longestString = 0;
    for (int i = 0; i < stringLength; i++){
        for (int j = i + 1; j <= stringLength; j++){
            if (allUnique(s, i, j)){ 
                longestString = max(longestString, j - i);
            }
        }
    }
    return longestString;
}


bool longestSubstring::allUnique(string str, int start, int end) {
    //unordered_set <char> mySet;
    vector<char> mySet; 
    for (int i = start; i < end; i++) {
        char Character = str[i];
        for(int j = 0; j < mySet.size(); j++){
            if (Character == mySet[j]){          // Element was found 
                return false;
            } 
        }
        mySet.push_back(Character);
    }
    return true;                                            // else return True, no matches 
}     

int longestSubstring::lengthOfLongestSubstringOptionTwo(string s) {
        int stringLength = s.size();
        unordered_set<char> mySet;
        int longestString = 0, i = 0, j = 0;

        while (i < stringLength && j < stringLength) {          // try to extend the range [i, j]
            if (mySet.find(s.at(j)) == mySet.end()){
                mySet.insert(s.at(j++));                         // adding the first element 
                longestString = max(longestString, j - i); // if (longestString < (j - l)) then longestString = j - l. 
            }
            else {
                mySet.erase(s.at(i++));                      // removing a match 
            }
        }
        return longestString;
}



int main() {
    longestSubstring test; 
    int ans = test.lengthOfLongestSubstringOptionTwo("abcdaefghij");
    cout << ans << endl; 
    return 0; 
}
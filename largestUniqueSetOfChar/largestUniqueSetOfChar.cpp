/*  write a program that outputs the largest unique set of characters 
    that can be removed from this paragraph without letting its length 
    drop below 50. For example: [‘H’, ‘i’, ‘!’, ‘ ’] 
    Created: 07/03/20
    Modified: 07/01/20
    Completed: 
*/
#include "brambila.h"

bool checkVector(char cha, vector<char> vec){
    for(int j = 0; j < vec.size(); j++){
        if(cha == vec[j]){
            return false;                           // There is a already a character like this one
        }
    }
    return true;                                   // It is a unique character
}
void getSet(string s){
    vector<char> v;     
    string newString = s;                       // Creating a string that will be reduced to maximum size of 50

    while (newString.size() > 50){              // Reducing
        for(int i = (newString.size() - 1); i > 0; i--){
            char c = newString[i];
            int before, after; 
            if(checkVector(c, v)){
                v.push_back(newString[i]);
                before = ++i; 
                after = --i;
                newString.erase(before, after);
            }
        }
    }    
    cout << " The string is at size 50: " << endl 
        << newString << endl
        << " The vector of unique characters are: " << endl;
    
    for(int k = 0; k < v.size(); k++){
        cout << v[k] << endl;
    }
}

int main() {
    // Getting the set of unuique charaters in this string...
    string string1 = "If you want to jumpstart the process of talking to us about this role,heres a little challenge: write a program that outputs the largest unique set of characters that can be removed from this paragraph without letting its length drop below 50.";
    getSet(string1);

    return 0; 
}
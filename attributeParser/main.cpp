#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <stdio.h>
using namespace std;

map <string, string> tagMap;            // global variable to set the tags 

void createMap(int &N, string pretag) {
    if(!N) {
        return;
    }
    
    string line, tag, attribute, value;
    getline(cin, line);
    
    int count = 1;
    if(line[count]=='/') {              // Found closing tag 
        while(line[count] != '>') {     // Getting the length of the closing tag name
            count++;
        }
        if(pretag.size() > (count - 2))        
            tag = pretag.substr(0, pretag.size() - count + 1);  // update tag(string) to the closing tag name
        else
            tag = "";
    }
    else {                              // found opening tag
        while(line[count] != ' ' && line[count] != '>') {
            count++;
        }
        tag = line.substr(1, count - 1);    // update tag
        if(pretag != "") {
            tag = pretag + "." + tag;
        }
        
        int j;
        while(line[count] != '>') {     // go through attributes
            j = ++count;
            while(line[count]!=' ') count++;
            attribute = line.substr(j, count - j);  // attribute name
            
            while(line[count]!='\"') {
                count++;
            }
            j = ++count;
            while(line[count]!='\"') {
                count++;
            }
            value = line.substr(j, count - j);      // attribute value
            count += 1;
            
            tagMap[tag + "~" + attribute] = value;
        }
    }
    createMap(--N, tag);
}

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();
    createMap(n, "");
    
    string attr, value;
    while(q--) {
        getline(cin,attr);
        value = tagMap[attr];
        if(value=="") {
            value = "Not Found!";
        }
        cout << value << endl;
    }
    return 0;
}
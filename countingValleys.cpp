#include "brambila.h"

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
    if((steps < 2) || (steps > pow(10, 6))){
        cout << " Error: steps must be >= 2 and <= 10^6 /n"; 
        return 0;
    }
    int count = 0, level = 0; 
    bool valley = false;

    for(int i = 0; i < path.size(); i++){
        char c = path[i];
        switch(c){
            case 'U': 
                ++level;
                break;
            case 'D': 
                --level;
                break;  
            default:
                cout << " Error: path[i] must be U of D "; 
                return 0; 
        }
        if (level < 0){
            valley = true; 
        }else{
            if(valley){
                count++;
                valley = false;
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

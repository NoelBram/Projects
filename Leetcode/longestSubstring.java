/**     Created: 07/07/20
 *      Modified: 11/06/20
 *      Completed: 07/07/20
 * 
 * Description:
 *      Given a string, find the length of the longest substring without repeating characters.
 * 
 *      @author Noel Brambila Jr
 * */  

import java.io.*; 
import java.util.*; 

public class longestSubstring {
    public int lengthOfLongestSubstring(String s) {
        int stringLength = s.length();
        int longestString = 0;
        for (int i = 0; i < stringLength; i++){
            for (int j = i + 1; j <= stringLength; j++){
                if (allUnique(s, i, j)){ 
                    longestString = Math.max(longestString, j - i);
                }
            }
        }
        return longestString;
    }

    public boolean allUnique(String str, int start, int end) {
        Set<Character> set = new HashSet<>();
        for (int i = start; i < end; i++) {
            Character char = str.charAt(i);
            if (set.contains(char)){
                return false;
            } 
            set.add(char);
        }
        return true;
    }

    public int lengthOfLongestSubstringOptionTwo(String s) {
        int stringLength = s.length();
        Set<Character> set = new HashSet<>();
        int longestString = 0, i = 0, j = 0;

        while (i < stringLength && j < stringLength) {          // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))){
                set.add(s.charAt(j++));                         // adding the first element 
                longestString = Math.max(longestString, j - i); // if (longestString < (j - l)) then longestString = j - l. 
            }
            else {
                set.remove(s.charAt(i++));                      // removing a match 
            }
        }
        return longestString;
    }
}
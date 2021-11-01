Implement regular expression matching with the following special characters:

    . (period) which matches any single character
    * (asterisk) which matches zero or more of the preceding element

That is, implement a function that takes in a valid regular expression pattern and a string s and returns whether or not the string matches the regular expression.

Note: The input pattern is guaranteed not to have consecutive asterisks.

Constraints

    n ≤ 100 where n is the length of pattern
    m ≤ 1,000 where m is the length of s

Example 1
Input

pattern = "ra."

s = "ray"

Output

true

Explanation

We have ra and then a single character
Example 2
Input

pattern = "a"

s = "aa"

Output

false

Example 3
Input

pattern = "a*"

s = "aa"

Output

true

Explanation

We have 0 or more as.
Example 4
Input

pattern = ".*"

s = "abc"

Output

true

Explanation

We have 0 or more of any character


//code
bool isMatch(string s, string p) {
        //base case 
        //s:[] p:[] we can always match them , so return true
        //s:[avsjas] p:[] if s has something but p is empty it is always going to be false
        if(p.size()==0){
            return s.size()==0; //depends on the size of the source string
        }
        //first case : where the second character of the string is an *
        if(p.size()>1 && p[1]=='*'){
            //for a case like 
            //s:aab p:c*a*b //so checking if the pattern from a*b matches or not
            if(isMatch(s,p.substr(2))){
                return true;
            }
            //if the first character of the string matches, we can check the match from the next index
            //or if the current characters is a '.', it will always match all the characters.
            if((s[0]==p[0] || p[0]=='.') && s.size()>0){
                return isMatch(s.substr(1),p);
            }else{
                return false;
            }
       }
       //for a case like s:dfe p:dfk
       //since the first character of both the strings matches we can move to the next index
       else{
           if((s[0]==p[0] || p[0]=='.') && s.size()>0){
               return isMatch(s.substr(1),p.substr(1));
           }
           return false;
       }
    }


bool solve(string pattern, string s) {
return isMatch(s,pattern);
}
//pattern = "ac***b"
//s = "accb"

// class Solution {
// public:
// //sol1: brute: O(n^3)
//     int numberOfSubstrings(string s) {
//         int n=s.size();
//         int count=0;

//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){

//                 bool a=false, b=false, c=false;

//                 for(int k=i; k<=j; k++){
//                     if(s[k]=='a') a=true;
//                     else if(s[k]=='b') b=true;
//                     else if(s[k]=='c') c=true;
//                 }

//                 if(a && b && c) count++;
//             }
//         }

//         return count;
//     }
// };
/* class Solution {
public:
//O(N^2)
//sol1: better, optimal and explanation already submitted earlier
    int numberOfSubstrings(string s) {
        int n=s.size();
        int count=0;

        for(int i=0; i<n; i++){

            int freq[3]={0};

            for(int j=i; j<n; j++){
                freq[s[j]-'a']++;

                if(freq[0] && freq[1] && freq[2])count++;
            }
        }

        return count;
    }
}; */
class Solution {
public:
//sol 3: optimal
    int numberOfSubstrings(string s) {
        int n=s.size();

        int count=0;
        int la=-1, lb=-1, lc=-1;

        for(int i=0; i<n; i++){

            if(s[i]=='a') la=i;
            else if(s[i]=='b') lb=i;
            else lc=i;

            int mn=min({la,lb,lc});

            if(mn!=-1)
                count+=mn+1;
        }

        return count;
    }
};
/*
------------------------------------------------------------
Brute Force
Generate every possible substring.
Check whether it contains at least one 'a', one 'b' and one 'c'.
If yes, increase the answer.

Time Complexity
Generate all substrings : O(n²)
Checking every substring : O(n)
Total = O(n³)
------------------------------------------------------------
Better Brute Force
Fix the starting index.
Extend the ending index one by one.
Maintain the frequency of a, b and c.
As soon as all three characters are present, the current substring is valid.

Time Complexity = O(n²)

------------------------------------------------------------
Optimal Idea
Maintain the last occurrence of a, b and c.
Initially
la = lb = lc = -1
We iterate i from 0 to n-1.
Think of it like this:
At every index i, we ask,
"How many valid substrings can I make from i?"
Since i is fixed, we only need to decide how far left we must go.
------------------------------------------------------------
Example
s = "abcabac"

Index
0 1 2 3 4 5 6
a b c a b a c

At i = 1
la = 0
lb = 1
lc = -1
minimum = -1

Since one character hasn't appeared yet, there exists no substring from i containing all three characters.

Therefore, count remains unchanged.
------------------------------------------------------------
Now consider

i = 6
la = 5
lb = 4
lc = 6
minimum = 4

What does this minimum represent?
Among the latest occurrences of a, b and c, index 4 is the farthest from i.
Here, b last appeared at index 4, and there is no b after that.
Therefore, to obtain a valid substring from i, we must at least include index 4.

The smallest valid substring is
i -> 4
After that, every larger substring is also valid.

i -> 4
i -> 3
i -> 2
...
i -> 0

Therefore, if minimum = j,
Number of valid substrings = j + 1
Hence, count += minimum + 1

------------------------------------------------------------
Note:
For intuition, we're imagining the substrings as i -> j because i is fixed and we're deciding how far left to extend.
Technically, substrings are written left to right, so they are j -> i (for example, [4...6] instead of 6->4).
This is only a visualization to build intuition; the counting remains exactly the same.

------------------------------------------------------------
Time Complexity
Single traversal = n iterations.
Every operation inside the loop is O(1).
Total work ≈ 4n
Time Complexity = O(n)

------------------------------------------------------------
Space Complexity
Only three variables:
la, lb and lc
Space Complexity = O(1)
------------------------------------------------------------
*/
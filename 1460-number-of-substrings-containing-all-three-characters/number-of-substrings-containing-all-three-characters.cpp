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

            if(mn!=-1)count+=mn+1;
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

//================================================================================
/* Something good about tc and sc
😂 I know exactly what you mean. Interviewers do appreciate when you can justify *why* something is O(n), but you also don't want to sound like you're making up constants.

Here's the rule I follow:

### ✅ Case 1: Multiple independent loops

Then it's perfectly fine to add them.

```cpp
for(...)   // n
for(...)   // n
for(...)   // n
```

Total work

```text
n + n + n = 3n
```

Like in **Longest Consecutive Sequence**:

* Build set → n
* Traverse set → n
* Total iterations of while loops → ≤ n

Total

```text
n + n + n = 3n
```

This is a meaningful analysis because each `n` comes from a separate phase of the algorithm.

---

### ✅ Case 2: Nested loops where total iterations can be counted

Like the while loop in Longest Consecutive Sequence.

Instead of saying

```text
Outer = n
Inner = n

=> n²
```

(which is wrong),

you prove

```text
Outer = n
Total iterations of all inner loops = n

Total = 2n
```

or

```text
n + n + n = 3n
```

This actually impresses interviewers because you're using **amortized analysis**.

---

### ⚠️ Case 3: One loop with constant work

```cpp
for(int i=0;i<n;i++){
    ...
}
```

Now saying

```text
≈ 4n
```

is a little arbitrary.

Someone could count

* comparisons
* assignments
* increments
* function calls

and get

```text
7n
```

instead.

So it's safer to say

```text
Each iteration performs O(1) work.

Total = n × O(1) = O(n)
```

---

## If you still want to impress interviewers 😏

I'd say something like this:

> **"The algorithm performs a single traversal of the string. In each iteration, we update one last occurrence, compute the minimum of three values, perform one comparison, and possibly update the answer. Since all of these are constant-time operations, the total work is proportional to `c·n` for some constant `c`, hence the time complexity is O(n)."**

This is the mathematically correct way of saying "≈4n".

Notice I never committed to **4**.

I just said **c**.

Interviewers love this because it shows you know that:

[
T(n) = c \cdot n
]

for some constant (c), and asymptotically,

[
O(cn) = O(n).
]

---

### My suggestion for your notes

Whenever possible, use **actual counts**:

```text
n + n = 2n
n + n + n = 3n
n + 2m = O(n)
```

because they're derived from the algorithm.

Otherwise, just write

```text
Single traversal = n iterations.
Each iteration performs constant-time work.

Time Complexity = O(n)
```

It's cleaner, mathematically precise, and still gives interviewers the justification they're looking for. I think that's the sweet spot between rigor and readability.


 */

 /* 
 
 This is actually a very important distinction, and understanding it will make your time complexity analyses much stronger.

By **actual counts**, I mean **counting iterations of loops or phases of the algorithm**, **not** counting individual statements like assignments or comparisons.

Let's compare the two.

---

## ❌ Method 1: Counting statements (avoid this)

Take this code:

```cpp
for(int i=0; i<n; i++){
    if(s[i]=='a') la=i;
    else if(s[i]=='b') lb=i;
    else lc=i;

    int mn=min({la,lb,lc});

    if(mn!=-1)
        count+=mn+1;
}
```

Someone could say

```text
Update last occurrence      -> 1 operation
min()                       -> 1 operation
if()                        -> 1 operation
count+=                     -> 1 operation

Total = 4n
```

But another interviewer could argue

```text
if-else comparisons -> 2 or 3
assignment -> 1
min() -> 2 comparisons
if() -> 1
count+= -> 2 operations

Total = 8n
```

Who's correct?

**Both.**

Because there is **no standard definition of an "operation."**

That's why we don't count statements.

---

## ✅ Method 2: Count algorithmic phases

Now consider Longest Consecutive Sequence.

```cpp
unordered_set<int> st;

for(...) st.insert(...);

for(...){

    while(...){

    }
}
```

Here we can actually count.

### Phase 1

Build hash set.

```cpp
for(...)
```

runs

```text
n times
```

---

### Phase 2

Outer loop.

```cpp
for(...)
```

runs

```text
n times
```

---

### Phase 3

Inner while.

At first glance,

```text
n × n
```

looks possible.

But we prove

> Every element is visited by the while loop at most once.

So total while iterations

```text
≤ n
```

Now we can confidently say

```text
n + n + n = 3n
```

This isn't a guess.

It's derived from the structure of the algorithm.

---

## Another example

```cpp
for(int i=0;i<n;i++)
    sum+=a[i];

for(int i=0;i<n;i++)
    sum2+=b[i];
```

Two independent loops.

First loop

```text
n iterations
```

Second loop

```text
n iterations
```

Total

```text
n+n=2n
```

Much better than saying

```text
Each loop has 3 operations.

6n.
```

---

## Another example

```cpp
sort(v.begin(),v.end());

for(int i=0;i<n;i++)
    cout<<v[i];
```

Now

Sorting

```text
nlogn
```

Printing

```text
n
```

Total

```text
nlogn+n
```

Since

```text
nlogn > n
```

Final answer

```text
O(nlogn)
```

Notice again.

We're counting **algorithmic phases**.

Not

```text
sort has 15 operations

cout has 2 operations
```

---

## Another example (Two Sum)

```cpp
unordered_map<int,int> mp;

for(...)
    mp[nums[i]]=i;

for(...)
{
    if(mp.find(...))
        ...
}
```

Phase 1

```text
Build map

n
```

Phase 2

```text
Search

n
```

Total

```text
2n
```

---

## Another example (Merge Two Sorted Arrays)

```cpp
while(i<n && j<m)

while(i<n)

while(j<m)
```

The first while doesn't always do `n*m`.

It performs

```text
at most n+m iterations
```

Remaining loops

```text
≤ n+m
```

Total

```text
(n+m)+(n+m)

=2(n+m)
```

or simply

```text
O(n+m)
```

Again,

we counted iterations.

Not statements.

---

# So here's the rule I personally follow

### ✅ Count this

```text
Loop 1 → n

Loop 2 → n

Loop 3 → n

Total

3n
```

or

```text
DFS

V

Processing edges

E

Total

V+E
```

or

```text
Building set

n

Traversing

n

Total while iterations

n

Total

3n
```

---

### ❌ Don't count this

```text
assignment

comparison

increment

addition

function call

...
```

because someone else can count them differently.

---

## A nice interview tip

If you want to impress the interviewer, use this style:

```text
Building the hash set      : n insertions

Traversing the set         : n iterations

Total iterations of all
while loops                : ≤ n

Therefore,

Total work

= n+n+n

=3n

Time Complexity = O(n)
```

See why this is stronger?

You're **proving** where every `n` comes from instead of inventing a constant like `4n`.

This is the kind of analysis interviewers appreciate because it's tied directly to the algorithm's structure rather than to an arbitrary count of low-level operations.

  */
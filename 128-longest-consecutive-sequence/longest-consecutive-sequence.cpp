class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        // Store all elements
        for (int x : nums)
            st.insert(x);

        int longest = 0;

        // Traverse through every unique element
        for (int num : st) {

            // If previous element exists,
            // this cannot be the beginning of a sequence.
            if (st.find(num - 1) != st.end())
                continue;

            // Start counting the sequence.
            int current = num;
            int length = 1;

            while (st.find(current + 1) != st.end()) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};

/*
        LOGIC:
        ------------------------------------------------------------
        1. Insert every element into an unordered_set.
           This allows O(1) average lookup.

        2. Iterate through every element in the set.

        3. For every element x:
              - If (x - 1) exists in the set,
                then x is NOT the start of a sequence.
                Skip it.

              - Otherwise,
                x is the beginning of a consecutive sequence.
                Keep checking x+1, x+2, x+3... until the sequence ends.

        4. Update the maximum length found.

        ------------------------------------------------------------
        Example:

        nums = [100,4,200,1,3,2]

        Set = {100,4,200,1,3,2}

        Iterate:

        num = 100
        99 not present
        Sequence:
        100
        length = 1

        num = 4
        3 present
        -> Skip
        (because sequence already starts from 1)

        num = 200
        199 not present
        Sequence:
        200
        length = 1

        num = 1
        0 not present
        Sequence:
        1 -> 2 -> 3 -> 4
        length = 4

        Answer = 4

        ------------------------------------------------------------
        Time Complexity Analysis:

Let n = number of elements.

1. Building the unordered_set:
   - We insert every element once.
   = n insertions
   = O(n)

2. Outer loop:
   - We iterate over every unique element once.
   = n iterations
   = O(n)

3. Inner while loop:
   At first glance it looks nested, but it is NOT O(n²).

   The while loop runs only for numbers that are the
   beginning of a sequence (i.e. whose previous element
   does not exist).

   Consider:
       1 2 3 4 5

   The while loop starts only from 1.
   It will never start from 2,3,4,5 because they all
   have a previous element.

   Across the entire algorithm, every element is advanced
   through at most once.

   Therefore,

       Total while loop iterations
       ≤ n - number_of_sequences
       ≤ n

   So the total work is approximately

       n (building set)
     + n (outer loop)
     + n (all while loops combined)

     = 3n operations

Hence,

Time Complexity = O(3n) = O(n)

------------------------------------------------------------
Space Complexity:

The unordered_set stores every unique element.

Worst case:
All elements are unique.

Extra Space = n

Space Complexity = O(n)
------------------------------------------------------------
Even more accurate (what interviewers love)

Technically, because the input can contain duplicates, you can define:

n = size of input array.
m = number of unique elements (m ≤ n).

Then the analysis becomes:

Build set → O(n) (n insertions)
Iterate over set → O(m)
Total while loop iterations → O(m)

So,

T(n)=O(n+m+m)=O(n+2m)

Since m≤n,

O(n+2m)≤O(3n)=O(n)
        */
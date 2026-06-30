class Solution {
public:
//sol 3 of 3
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int pos = 0;
        int neg = 1;

        for(int x:nums){

            if(x>0){
                ans[pos] = x;
                pos += 2;
            }
            else{
                ans[neg] = x;
                neg += 2;
            }
        }

        return ans;
    }
};


        /*
        ------------------------------------------------------------
        Idea

        Since the problem guarantees

        • Equal positives and negatives.
        • Answer starts with positive.

        We already know where every number belongs.

        Positive indices

        0 2 4 6 ...

        Negative indices

        1 3 5 7 ...

        Maintain

        pos = 0

        neg = 1

        Traverse the array once.

        Positive?

        ans[pos] = value

        pos += 2

        Negative?

        ans[neg] = value

        neg += 2

        ------------------------------------------------------------
        Example

        nums

        [3,1,-2,-5,2,-4]

        ans

        _ _ _ _ _ _

        3

        3 _ _ _ _ _

        1

        3 _ 1 _ _ _

        -2

        3 -2 1 _ _ _

        -5

        3 -2 1 -5 _ _

        2

        3 -2 1 -5 2 _

        -4

        3 -2 1 -5 2 -4

        ------------------------------------------------------------
        Time Complexity

        Single traversal

        = n operations

        Time Complexity = O(n)

        ------------------------------------------------------------
        Space Complexity

        Answer array

        = n

        Space Complexity = O(n)

        ------------------------------------------------------------
        This is the optimal solution because
        the problem guarantees equal positives
        and negatives.

        ------------------------------------------------------------
        */
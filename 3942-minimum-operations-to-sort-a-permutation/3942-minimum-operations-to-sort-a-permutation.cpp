class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return 0;
        }

        // index of 0th ele (since 0 to n-1)
        const int start = find(nums.begin(), nums.end(), 0) - nums.begin();
        bool asc = true;
        bool desc = true;

        for (int i = 1; i < n; i++) {
            // cycle index -- since 0th index is at start from 1
            const int value = nums[(start + i) % n];

            if (value != i) {
                // check if it keeps on increasing
                asc = false;
            }
            if (value != n - i) {
                // check if it keeps on decreasing
                desc = false;
            }

            if (!asc && !desc) {
                // at any point both are false -- it doesn't have strictly increasing/decreasing value so we can't 
                return -1;
            }
        }

        // either will be ascending or descending
        if (asc) {
            /*ascending -- min (left shift , or rightShift)
            left shift = startIndex-0 = startIndex
            reverse+leftshift+reverse = right shift (3 min operations)

            eg 1,2,3,4,0 - we can left shift 4 times to make 0,1,2,3,4
            or -- right shift once to 0,1,2,3,4 (but right shift is not allowd)
            but reverse+leftshift+reverse = right shift
            Reverse → [0, 4, 3, 2, 1]
            Rotate left → [4, 3, 2, 1, 0]
            Reverse → [0, 1, 2, 3, 4]
            so 3 operations 
            so min(4,3) = 3
            */
            
            return min(start, n - start + 2);
        }


        /*descending -- reverse the array and move left
        like in ascending we can left shift start - here must left shift start to n-1
        i.e (n-1)-start +1(for reverse) so = n-start
        eg -- 2,1,0,5,4,3
        then - 3,4,5,0,1,2 (reverse +1)
        - 4,5,0,1,2,3 (+1 left shift)
        - 5,0,1,2,3,4 (+1 left shift)
        - 0,1,2,3,4,5 (+1 left shift) so total = 4

        or 
        start+2 (here left rotate till start become at 0th index - which we need start, as seen in ascending the +1 to make it at n-1th position, then finally reverse it to make it ascending)   = so start+1(to make start at n-1th pos by left shift) + 1(reverse)
        eg -- 2,1,0,5,4,3
        rotate left → 1,0,5,4,3,2 (+1 left shift)
        rotate left → 0,5,4,3,2,1 (+1 left shift)
        rotate left → 5,4,3,2,1,0   (+1 left shift) (start+1 = 3 rotations)
        reverse     → 0,1,2,3,4,5   (+1 reverse) → total 4 = start+2

        */
        return min(n - start, start + 2);
    }
};
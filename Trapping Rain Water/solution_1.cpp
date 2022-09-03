class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), finalSum = 0;
        vector<int> leftMax(n),rightMax(n);
        leftMax[0] = height[0];
        // leftMax contains maxm element from index 0 till index i.
        // leftMax[i] -> maxm from starting to index i.
        for(int i=1;i<n;i++)
            leftMax[i] = max(leftMax[i-1], height[i]);
        rightMax[n-1] = height[n-1];
        // rightMax contains maxm element from index i till index n-1.
        // rightMax[i] -> maxm form index i to last.
        for(int i=n-2;i>=0;i--)
            rightMax[i] = max(rightMax[i+1], height[i]);
        for(int i=0;i<n;i++){
            finalSum += min(rightMax[i],leftMax[i]) - height[i];
        }
        return finalSum;
    }
};



Discussion Links
-----------------

https://leetcode.com/problems/trapping-rain-water/discuss/2102066/C%2B%2B-oror-Simplest-way-to-solve-with-proper-Explanation-100

https://leetcode.com/problems/trapping-rain-water/discuss/1373785/Trapping-Rain-Water-oror-Basic-Implementation-w-Explanation

2 pointer approach
-------------------
https://leetcode.com/problems/trapping-rain-water/discuss/2013463/7-lines-C%2B%2B-Solution-oror-Two-Pointer-oror-Easy-to-Understand

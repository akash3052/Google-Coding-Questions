// Striver's Solution. For better understanding see solution 1

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> leftSmaller(n,0);
        vector<int> rightSmaller(n,n-1);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if(s.empty())
                leftSmaller[i] = 0;
            else
                // No need to add +1 to top. see solution 1
                leftSmaller[i] = s.top()+1;
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if(s.empty())
                rightSmaller[i] = n-1;
            else
                rightSmaller[i] = s.top()-1;
            s.push(i);
        }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea, (rightSmaller[i]-leftSmaller[i]+1) * heights[i]);
        }
        return maxArea;
    }
};

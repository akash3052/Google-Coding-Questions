class Solution {
public:
    vector<int> prevSmaller(vector<int> &heights, int n){
        vector<int> prevsmaller(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty())
                prevsmaller[i] = -1;
            else
                prevsmaller[i] = s.top();
            s.push(i);
        }
        return prevsmaller;
    }
    
    vector<int> nextSmaller(vector<int> &heights, int n){
        vector<int> nextsmaller(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            // pop out all the elements which are greater than current element because that will not be boundary. 
            // Boundary condition occurs when top element is less than current element because we can't extend our rectangle after that element. So, it will be become next smaller.
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            // If stack becomes empty, it means there is no element which will restrict our rectangle. Hence we can go till extreme right which is last index.
            if(s.empty())
                nextsmaller[i] = n;
            else
                nextsmaller[i] = s.top();
            s.push(i);
        }
        return nextsmaller;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> leftSmaller = prevSmaller(heights,n);
        vector<int> rightSmaller = nextSmaller(heights,n);
        int maxArea = 0;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea, (rightSmaller[i]-leftSmaller[i]-1) * heights[i]);
        }
        return maxArea;
    }
};

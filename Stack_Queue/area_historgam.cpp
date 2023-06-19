#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);  //stack storing indexes now
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {  //ulta chale
            int curr = arr[i];  //curr store kara, as last abhi
            while(s.top() != -1 && arr[s.top()] >= curr)  //pop karo till we get minimum element of height
            {
                s.pop();  //pop the element till we get the minimum element
            }
            //ans is stack ka top
            ans[i] = s.top();  //push the index of the minimum element in ans array
            s.push(i);   //push the index of the current element for other elements
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {  //just in case height of all elements are equal,it will return -1 na
                next[i] = n;  //so we store n
            }
             int b = next[i] - prev[i] - 1;  //we calc the area using diff of indexes
            int newArea = l*b;
            area = max(area, newArea);  //store only the max area
        }
        return area;
    }
};
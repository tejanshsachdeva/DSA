#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Node {
  int data;
  struct node * left, * right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0});  //inserting root node with line number 0
           
        while(!q.empty()) {
            auto it = q.front();   //it.first is node and it.second is line number
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 

            if(mpp.find(line) == mpp.end())   //if line number is not present in map  
                    mpp[line] = node->data;   //only those are inserted, which were never there, so basically first node of every line is inserted
            
            if(node->left != NULL) {  //if left child is present, push it in queue with line number - 1
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        string s ="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
           TreeNode* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->val)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
   TreeNode* deserialize(string data) {
    if (data.empty()) {
        return nullptr;
    }
    
    stringstream ss(data);
    string str;
    getline(ss, str, ',');
    
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (!getline(ss, str, ',')) {
            break;
        }
        if (str != "#") {
            node->left = new TreeNode(stoi(str));
            q.push(node->left);
        }
        
        if (!getline(ss, str, ',')) {
            break;
        }
        if (str != "#") {
            node->right = new TreeNode(stoi(str));
            q.push(node->right);
        }
    }
    
    return root;
}
};
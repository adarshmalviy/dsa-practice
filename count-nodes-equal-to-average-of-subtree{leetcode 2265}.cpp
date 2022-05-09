class Solution {
public:



    pair<int,int> sumofnode(TreeNode* root,int node,int sum)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                root=q.front();
                q.pop();
                sum+=root->val;
                node++;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        return {sum,node};
    }

    int averageOfSubtree(TreeNode* root) {
        
        int cnt=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                root=q.front();
                q.pop();
                pair<int,int> temp=sumofnode(root,0,0);
                if((temp.first/temp.second)==root->val)
                    cnt++;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        return cnt;   
    }    
};
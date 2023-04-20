#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long int>> que;
        que.push({root,1});

        unsigned long long int maxWidth = 0;

        while(!que.empty())
        {
            unsigned long long int size = que.size();
            unsigned long long int  minE = -1;
            unsigned long long int  maxE = -1;
            while(size--)
            {
                TreeNode* node = que.front().first;
                unsigned long long int ind = que.front().second;
                que.pop();

                if(minE==-1)
                    minE = ind;
                maxE = ind;

                if(node->left!=NULL)
                    que.push({node->left,ind*2});
                
                if(node->right!=NULL)
                    que.push({node->right,(ind*2)+1});
            }
            maxWidth = max(maxWidth,(maxE-minE)+1);
        }
        return maxWidth;
    }
};
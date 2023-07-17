#include <iostream>
struct Node
{
    int val;
    Node* left;
    Node* right;
};

/*
!!!!!!!!!!!!!!!!!!!!!
*determine if a binary tree is valid (root is greater than left child but smaller than right child)
*
* Key Ideas:
* needs to realize that we cannot only check immediate left and right, each recursion has to setup a range
* if we go left, upper bound became root->val
* if we go right, lower bound became root->val
*/
bool isValidTree(Node* root)
{
    return isValidTreeHelp(root, INT_MIN, INT_MAX);
} 

bool isValidTreeHelp(Node* root, int min, int max)
{
    if(!root)
    {
        return true;
    }
    return isValidTreeHelp(root->left, min, root->val) && isValidTreeHelp(root->right, root->val, max);
}


/* 
!!!!!!!!!!!!!!!!!!!!!
* deleting all elements smaller than a given value
*
*
* KEY IDEAS:
* understand BST property. If root is less than a val, root->right might still be ok
* in this case, root->right will take root's position
*/
Node* deleteSmaller(Node* root, int thresh)
{
    if(!root)
    {
        return nullptr;
    }
    root->left = deleteSmaller(root->left, thresh);
    root->right = deleteSmaller(root->right, thresh);
    if(root->val < thresh)
    {
        Node* rtn = root->right;
        delete root;
        return rtn;
    }
    return root;
}

/*
* Finding the height of a BST
*
*/
int findHeight(Node* root)
{
    if(!root)
    {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    int maxHeight = std::max(leftHeight, rightHeight);
    return maxHeight + 1;
}

/*
* given a root node and a int representing the depth, delete all nodes that are at or deeper than the depth
*
*/
Node* deleteDepth(Node* root, int depth)
{
    if(!root)
    {
        return nullptr;
    }
    root->left = deleteDepth(root->left, depth - 1);
    root->right = deleteDepth(root->right, depth - 1);
    if(depth <= 0)
    {
        delete root;
        return nullptr;
    }
    return root;

}

/*
* find the deepest common ancestor of two keys
*/
Node* commonAncestor(Node* root, int k1, int k2)
{
    if(!root)
    {
        return nullptr;
    }
    if(root->val == k1)
    {
        return root;
    }
    if(root->val == k2)
    {
        return root;
    }
    if(root->val < k1 && root->val < k2)
    {
        return commonAncestor(root->right, k1, k2);
    }
    if(root->val > k1 && root->val > k2)
    {
        return commonAncestor(root->left, k1, k2);
    }
    return root;
}

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!
* return the sum of all values in the tree and update the value in each node with the sum of the all the values in the original tree
* greater than and including its own value
*
*
*/
int sumLargeToSmall(Node* root)
{
    return sumLargeToSmallHelp(root, 0);
}

int sumLargeToSmallHelp(Node* root, int csum)
{
    if(!root)
    {
        return csum;
    }
    csum = sumLargeToSmallHelp(root->right, csum);
    root->val += csum;
    csum = root->val;
    return sumLargeToSmallHelp(root->left, csum);
}

/*
!!!!!!!!!!!!!!!!!!!!!!!
* determine if a BST is balanced
*/
bool isBalanced(Node* root) 
{
    int rtn = isBalancedHelp(root);
    return rtn != -1;
}
int isBalancedHelp(Node* root)
{
    if(!root)
    {
        return 0;
    }
    int leftHeight = isBalancedHelp(root->left);
    int rightHeight = isBalancedHelp(root->right);
    if(leftHeight == -1 || rightHeight == -1)
    {
        return -1;
    }
    if(std::abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }
    int maxHeight = std::max(leftHeight, rightHeight);
    return 1 + maxHeight;

}

/*
* https://leetcode.com/problems/path-sum/
*/
// main function for compilation
int main()
{
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
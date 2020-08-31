/* 
    File name: tree
    Created by: xiaojie chong    
    Created on: 10/31/2019
    Synopsis: This hw define a binary tress structure and implement some functions
*/ 

#include <iostream>
#include <cstddef>
#include <cassert>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

// Function declarations
int size(TreeNode* root);
int count(TreeNode* root, int target);
int height(TreeNode* root);
bool isSameTree(TreeNode* root1, TreeNode* root2);
bool hasPathSum(TreeNode* root, int target);
bool isBalanced(TreeNode* root);

// feel free to define your own helper functions
/* your code here */




// A helper function to build a tree, you do not need to modify it
// Inputs: 
//     nodeValues, a list of all node values from top to bottom, left to right. If no node at one place, use -1 as the placeholder
//     root, a pointer to the root node
//     i, set it to 0 when calling this function from outside
//     n, size of the 'nodeValues' array
// Postcondition: a tree is built with the second input argument as its root pointer
TreeNode* insertNodes(int nodeValues[], TreeNode* root, int i, int n);

int main(){
    // the binary trees in instruction examples
    TreeNode *root, *root2;
    int nodedatas[] = {1,2,3,4,5,6,7,8,1,-1,-1,-1,-1,-1,1};
    int nodedatas2[] = {1,2,3,4,5,6,7,8,1,-1,-1,-1,-1,1,-1};
    root = insertNodes(nodedatas, root, 0, 15);
    root2 = insertNodes(nodedatas2, root2, 0, 15);

    assert(size(root) == 10);
    assert(size(root->left) == 5);
    assert(count(root,1) == 3);
    assert(count(root,9) == 0);
    assert(height(root) == 3);
    assert(height(root->left->right) == 0);
    assert(hasPathSum(root,10) == true);
    assert(hasPathSum(root,1) == false);
    assert(isBalanced(root) == true);
    assert(isSameTree(root,root2) == false);
    assert(isSameTree(root->left,root2->left) == true);

    cout << "Congratulation!" << endl;
    return 0;
}

// A helper function to build the test cases. You do not need to modify it.
TreeNode* insertNodes(int nodeValues[], TreeNode* root, int i, int n){
    if(i<n && nodeValues[i]!=-1){
        root = new TreeNode;
        root->data = nodeValues[i];
        root->left = insertNodes(nodeValues, root->left, 2*i+1, n);
        root->right = insertNodes(nodeValues, root->right, 2*i+2, n);
    }
    else{
        root = NULL;
    }
    return root;
}

int size(TreeNode* root){           //if tree is null then 0 otherwise add one pre node
    /* your code here */
    if(root == NULL) return 0;
    else{
        return (1 + size(root->left) + size(root->right));
    }
}


int count(TreeNode* root, int target){  //if tree is null then 0 otherwise check root first and count left and right 
    /* your code here */
    if(root == NULL) return 0;
    else{
        if(root->data == target) return 1 + count(root->left,target) + count(root->right,target); 
        else return 0 + count(root->left,target) + count(root->right,target);
    } 
}


int height(TreeNode* root){      //if tree is null then 0 otherwise check root first and count the max hight between left and right 
    /* your code here */
    if(root == NULL) return -1;
    else{
        int left_height = height(root->left);
        int right_height = height(root->right);
        if(left_height>right_height) return left_height+1;
        else return right_height+1;
    }
}


bool isSameTree(TreeNode* root1, TreeNode* root2){   //if tree is null then 0 otherwise check root first and count root1 and root2 
    /* your code here */
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;
    else return isSameTree(root1->left,root2->left)&&isSameTree(root1->right,root2->right)&&root2->data == root1->data;

}


bool hasPathSum(TreeNode* root, int target){  //if tree is null then return target == 0 otherwise check root first and count left and right with target- root
    /* your code here */
    if(root==NULL) return target ==0;
    else{
        if(target-root->data ==0 && root->left ==NULL && root->right==NULL) return true;
        else return hasPathSum(root->left,target-root->data) || hasPathSum(root->right,target-root->data);
    }
}


bool isBalanced(TreeNode* root){        //use height function 
    /* your code here */
    if(root == NULL) return true;
    return (height(root->left)-height(root->right)>=-1 && height(root->left)-height(root->right)>=-1);
}


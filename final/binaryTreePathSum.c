// Created by Yellow on 2021/11/30.
// Name: Cuiting Huang
// CS5008 20018 Data Str, Algo & App in CmpSys SEC 03 Fall 2021 [VAN-2-HY]
// leetCode link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// [Binary Tree][DFS]
//
// 124. Binary Tree Maximum Path Sum [hard]
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
//in the sequence has an edge connecting them. A node can only appear in the sequence
//at most once. Note that the path does not need to pass through the root.
//
// The path sum of a path is the sum of the node's values in the path.
//
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

#include <malloc.h>
#include <stdio.h>
// =============== Definition for singly-linked list. ===============
// This definition is not allowed in the leetCode webpage.
// But in .c it is needed.

/**
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
*/

// =============== Helper Functions ===============
//Return the maximum between two integers.
int max(int a, int b) {
    if (a > b)return a;
    return b;
}

//Return 0, if the TreeNode is NULL.
//Assume one root node
//Find the left max tree node, which is a positive number or zero.
//Find the right max tree node, which is a positive number or zero.
//Use Recursion
//Use pointer total stores all others root node sum, find the max.
int maxNode(struct TreeNode *root, int *total) {
    if (root == NULL)return 0;

    int left = max(maxNode(root->left, total), 0);
    int right = max(maxNode(root->right, total), 0);

    *total = max(*total, root->val + left + right);

    return root->val + max(left, right);

}

// =============== Max Path Sum ===============
// Return total
int maxPathSum(struct TreeNode *root) {
    int *total = (int *) malloc(sizeof(int));
    *total = root->val;
    maxNode(root, total);
    return *total;
}

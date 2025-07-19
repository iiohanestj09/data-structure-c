#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode {
    int data;
    struct treeNode* firstChild;
    struct treeNode* nextSibling;
} TreeNode;

TreeNode* createNode(int value);
void addChild(TreeNode* parent, TreeNode* child);
TreeNode* searchNode(TreeNode* root, int value);
int getNodeDepth(TreeNode* root, TreeNode* target, int currentDepth);
int getNodeHeight(TreeNode* node);
void printTree(TreeNode* root, int level);
void printPreorder(TreeNode* root);
void destroyTree(TreeNode* root);
bool isLeaf(TreeNode* node);
bool isRoot(TreeNode* root, TreeNode* node);

#endif
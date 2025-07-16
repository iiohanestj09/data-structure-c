#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode* firstChild;
    struct treeNode* nextSibling; 
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->data = value;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    return node;
}

void addChild(TreeNode* parent, TreeNode* child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        TreeNode* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

void destroyTree(TreeNode* root) {
    if (root != NULL) {
        TreeNode* child = root->firstChild;
        while (child != NULL) {
            TreeNode* next = child->nextSibling;
            destroyTree(child);
            child = next;
        }

        free(root);
    }
}
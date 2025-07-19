#include "tree.h"

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

TreeNode* searchNode(TreeNode* root, int value) {
    if (root == NULL) return NULL;
    if (root->data == value) return root;

    TreeNode* found = searchNode(root->firstChild, value);
    if (found != NULL) return found;
    return searchNode(root->nextSibling, value);
}

int getNodeDepth(TreeNode* root, TreeNode* target, int currentDepth) {
    if (root == NULL) return -1;
    if (root == target) return currentDepth;

    int depth = getNodeDepth(root->firstChild, target, currentDepth + 1);
    if (depth != -1) return depth;
    return getNodeDepth(root->nextSibling, target, currentDepth);
}

int getNodeHeight(TreeNode* node) {
    if (node == NULL) return -1;

    int maxHeight = -1;
    TreeNode* child = node->firstChild;

    while (child != NULL) {
        int height = getNodeHeight(child);
        if (height > maxHeight) maxHeight = height;
        child = child->nextSibling;
    }

    return maxHeight + 1;
}

void printTree(TreeNode* root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++) printf("  ");
    printf("|-- %d\n", root->data);

    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

void printPreorder(TreeNode* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    printPreorder(root->firstChild);
    printPreorder(root->nextSibling);
}

void destroyTree(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* child = root->firstChild;
    while (child != NULL) {
        TreeNode* next = child->nextSibling;
        destroyTree(child);
        child = next;
    }

    free(root);
}

bool isLeaf(TreeNode* node) {
    return (node != NULL && node->firstChild == NULL);
}

bool isRoot(TreeNode* root, TreeNode* node) {
    return (root == node);
}
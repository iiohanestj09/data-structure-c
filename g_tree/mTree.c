#include "tree.h"

int main() {
    TreeNode* root = createNode(1);

    TreeNode* node2 = createNode(2);
    TreeNode* node3 = createNode(3);
    TreeNode* node4 = createNode(4);
    TreeNode* node5 = createNode(5);
    TreeNode* node6 = createNode(6);

    addChild(root, node2);
    addChild(root, node3);
    addChild(node2, node4);
    addChild(node2, node5);
    addChild(node3, node6);

    printTree(root, 0);

    printf("\nPreorder traversal: ");
    printPreorder(root);
    printf("\n");

    TreeNode* found = searchNode(root, 5);
    if (found) {
        printf("Node %d ditemukan\n", found->data);
        printf("Depth = %d\n", getNodeDepth(root, found, 0));
        printf("Height = %d\n", getNodeHeight(found));
        printf("IsLeaf = %d\n", isLeaf(found));
        printf("IsRoot = %d\n", isRoot(root, found));
    }

    printf("Tree Height: %d\n", getNodeHeight(root));

    destroyTree(root);
    return 0;
}
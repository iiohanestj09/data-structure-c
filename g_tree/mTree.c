#include <stdio.h>
#include "tree.h"

int main() {
    Tree myTree;
    initTree(&myTree);
    
    // Membuat struktur tree
    createRoot(&myTree, 10);  // Root dengan nilai 10
    
    // Menambahkan child ke root
    addChild(myTree.root, 5);
    addChild(myTree.root, 15);
    addChild(myTree.root, 20);
    
    // Mencari node dengan nilai 5 dan menambahkan child
    TreeNode *node5 = searchNode(&myTree, 5);
    if (node5 != NULL) {
        addChild(node5, 3);
        addChild(node5, 7);
        
        // Menambahkan child ke node dengan nilai 3
        TreeNode *node3 = searchNode(&myTree, 3);
        if (node3 != NULL) {
            addChild(node3, 1);
            addChild(node3, 4);
        }
    }
    
    // Mencari node dengan nilai 15 dan menambahkan child
    TreeNode *node15 = searchNode(&myTree, 15);
    if (node15 != NULL) {
        addChild(node15, 12);
        addChild(node15, 17);
    }
    
    // Cetak struktur tree
    printTree(&myTree);
    
    // Cetak traversal preorder
    printPreorder(&myTree);
    
    // Cek dan cetak informasi tentang beberapa node
    printf("\nInformasi tentang beberapa node:\n");
    
    TreeNode *nodeToCheck = searchNode(&myTree, 3);
    if (nodeToCheck != NULL) {
        printf("Node 3:\n");
        printf("- Depth: %d\n", getNodeDepth(&myTree, nodeToCheck));
        printf("- Height: %d\n", getNodeHeight(&myTree, nodeToCheck));
        printf("- Is leaf: %s\n", isLeaf(nodeToCheck) ? "Yes" : "No");
        printf("- Is root: %s\n", isRoot(&myTree, nodeToCheck) ? "Yes" : "No");
    }
    
    nodeToCheck = searchNode(&myTree, 1);
    if (nodeToCheck != NULL) {
        printf("\nNode 1:\n");
        printf("- Depth: %d\n", getNodeDepth(&myTree, nodeToCheck));
        printf("- Height: %d\n", getNodeHeight(&myTree, nodeToCheck));
        printf("- Is leaf: %s\n", isLeaf(nodeToCheck) ? "Yes" : "No");
        printf("- Is root: %s\n", isRoot(&myTree, nodeToCheck) ? "Yes" : "No");
    }
    
    printf("\nTree height: %d\n", getTreeHeight(&myTree));
    
    // Hapus tree sebelum keluar 
    destroyTree(&myTree);
    printf("\nTree has been destroyed\n");
    
    return 0;
}
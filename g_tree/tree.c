#include "tree.h"

/* ===== FUNGSI KONSTRUKTOR ===== */

/* Inisialisasi Tree kosong */
void initTree(Tree *tree) {
    tree->root = NULL;
    tree->size = 0;
}

/* Membuat node baru */
TreeNode* createNode(int data) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    
    return newNode;
}

/* ===== OPERASI DASAR TREE ===== */

/* Menambahkan node sebagai child dari parent */
void addChild(TreeNode *parent, int data) {
    if (parent == NULL) return;
    
    TreeNode *newNode = createNode(data);
    
    if (parent->firstChild == NULL) {
        // Jika parent belum memiliki anak
        parent->firstChild = newNode;
    } else {
        // Jika parent sudah memiliki anak, tambahkan sebagai sibling terakhir
        TreeNode *current = parent->firstChild;
        while (current->nextSibling != NULL) {
            current = current->nextSibling;
        }
        current->nextSibling = newNode;
    }
}

/* Membuat root dari Tree jika belum ada */
void createRoot(Tree *tree, int data) {
    if (tree->root == NULL) {
        tree->root = createNode(data);
        tree->size = 1;
    } else {
        printf("Tree already has a root\n");
    }
}

/* ===== FUNGSI PENCARIAN ===== */

/* Mencari node dengan nilai tertentu secara rekursif */
TreeNode* searchNodeRecursive(TreeNode *node, int data) {
    if (node == NULL) return NULL;
    
    // Jika node saat ini sesuai dengan yang dicari
    if (node->data == data) {
        return node;
    }
    
    // Cari di anak-anak node saat ini
    TreeNode *foundInChild = searchNodeRecursive(node->firstChild, data);
    if (foundInChild != NULL) {
        return foundInChild;
    }
    
    // Jika tidak ditemukan di anak, cari di sibling
    return searchNodeRecursive(node->nextSibling, data);
}

/* Fungsi pencarian yang dapat dipanggil dari luar */
TreeNode* searchNode(Tree *tree, int data) {
    return searchNodeRecursive(tree->root, data);
}

/* ===== FUNGSI UNTUK MENDAPATKAN INFORMASI DARI TREE ===== */

/* Mendapatkan kedalaman (depth) dari suatu node secara rekursif */
int getNodeDepthRecursive(TreeNode *root, TreeNode *node, int currentDepth) {
    if (root == NULL) return -1;
    
    if (root == node) {
        return currentDepth;
    }
    
    // Cari di anak-anak
    int depth = getNodeDepthRecursive(root->firstChild, node, currentDepth + 1);
    if (depth != -1) {
        return depth;
    }
    
    // Jika tidak ditemukan di anak, cari di sibling (tetap di level yang sama)
    return getNodeDepthRecursive(root->nextSibling, node, currentDepth);
}

/* Fungsi untuk mendapatkan depth node yang dapat dipanggil dari luar */
int getNodeDepth(Tree *tree, TreeNode *node) {
    return getNodeDepthRecursive(tree->root, node, 0);
}

/* Mendapatkan tinggi (height) dari suatu node secara rekursif */
int getNodeHeightRecursive(TreeNode *node) {
    if (node == NULL) return -1;
    
    int maxHeight = -1;
    TreeNode *child = node->firstChild;
    
    while (child != NULL) {
        int height = getNodeHeightRecursive(child);
        if (height > maxHeight) {
            maxHeight = height;
        }
        child = child->nextSibling;
    }
    
    return maxHeight + 1;
}

/* Fungsi untuk mendapatkan height node yang dapat dipanggil dari luar */
int getNodeHeight(Tree *tree, TreeNode *node) {
    if (node == NULL) return -1;
    return getNodeHeightRecursive(node);
}

/* Mendapatkan tinggi (height) dari Tree */
int getTreeHeight(Tree *tree) {
    return getNodeHeightRecursive(tree->root);
}

/* ===== FUNGSI CETAK ===== */

/* Mencetak tree secara rekursif dengan indentasi untuk visualisasi struktur */
void printTreeRecursive(TreeNode *node, int level) {
    if (node == NULL) return;
    
    // Cetak indentasi sesuai level
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    
    // Cetak nilai node
    printf("|-- %d\n", node->data);
    
    // Cetak anak-anak
    printTreeRecursive(node->firstChild, level + 1);
    
    // Cetak sibling
    printTreeRecursive(node->nextSibling, level);
}

/* Fungsi cetak tree yang dapat dipanggil dari luar */
void printTree(Tree *tree) {
    if (tree->root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    
    printf("Tree structure:\n");
    printf("%d (Root)\n", tree->root->data);
    printTreeRecursive(tree->root->firstChild, 1);
}

/* Mencetak node secara preorder (root, child, sibling) */
void printPreorderRecursive(TreeNode *node) {
    if (node == NULL) return;
    
    printf("%d ", node->data);
    printPreorderRecursive(node->firstChild);
    printPreorderRecursive(node->nextSibling);
}

/* Fungsi cetak preorder yang dapat dipanggil dari luar */
void printPreorder(Tree *tree) {
    printf("Preorder traversal: ");
    printPreorderRecursive(tree->root);
    printf("\n");
}

/* ===== FUNGSI DESTROY ===== */

/* Menghapus subtree secara rekursif */
void destroyNodeRecursive(TreeNode *node) {
    if (node == NULL) return;
    
    // Hapus anak-anak terlebih dahulu
    destroyNodeRecursive(node->firstChild);
    
    // Hapus sibling-sibling
    destroyNodeRecursive(node->nextSibling);
    
    // Hapus node itu sendiri
    free(node);
}

/* Fungsi destroy tree yang dapat dipanggil dari luar */
void destroyTree(Tree *tree) {
    destroyNodeRecursive(tree->root);
    tree->root = NULL;
    tree->size = 0; 
}

/* ===== FUNGSI UNTUK MENGECEK JENIS NODE ===== */

/* Mengecek apakah node adalah leaf (tidak memiliki anak) */
bool isLeaf(TreeNode *node) {
    return (node != NULL && node->firstChild == NULL);
}

/* Mengecek apakah node adalah root */
bool isRoot(Tree *tree, TreeNode *node) {
    return (tree->root == node);
}
#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Definisi struktur Node */
typedef struct TreeNode {
    int data;                  // Nilai/data pada node
    struct TreeNode *firstChild;  // Pointer ke anak pertama
    struct TreeNode *nextSibling; // Pointer ke saudara berikutnya (sibling)
} TreeNode;

/* Definisi struktur Tree */
typedef struct {
    TreeNode *root;  // Root (akar) dari Tree
    int size;        // Jumlah node dalam Tree
} Tree;

/* ===== PROTOTYPE FUNGSI ===== */

/* Fungsi Konstruktor */
void initTree(Tree *tree);
TreeNode* createNode(int data);

/* Operasi Dasar Tree */
void addChild(TreeNode *parent, int data);
void createRoot(Tree *tree, int data);

/* Fungsi Pencarian */
TreeNode* searchNodeRecursive(TreeNode *node, int data);
TreeNode* searchNode(Tree *tree, int data);

/* Fungsi untuk Mendapatkan Informasi dari Tree */
int getNodeDepthRecursive(TreeNode *root, TreeNode *node, int currentDepth);
int getNodeDepth(Tree *tree, TreeNode *node);
int getNodeHeightRecursive(TreeNode *node);
int getNodeHeight(Tree *tree, TreeNode *node);
int getTreeHeight(Tree *tree);

/* Fungsi Cetak */
void printTreeRecursive(TreeNode *node, int level); 
void printTree(Tree *tree);
void printPreorderRecursive(TreeNode *node);
void printPreorder(Tree *tree);

/* Fungsi Destroy */
void destroyNodeRecursive(TreeNode *node);
void destroyTree(Tree *tree);

/* Fungsi untuk Mengecek Jenis Node */
bool isLeaf(TreeNode *node);
bool isRoot(Tree *tree, TreeNode *node);

#endif /* TREE_H */
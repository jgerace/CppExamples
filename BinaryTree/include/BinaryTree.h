#ifndef BINARYTREE_H
#define BINARYTREE_H

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BinaryTree
{
    public:
        void insertData(int data);
        void deleteData(int data);
        bool findData(int data);
        int  getDepth();
        int  getDiameter();
        void deleteTree();
        void printInorder();

        BinaryTree();
        ~BinaryTree();
    protected:
    private:
        Node *head;
        Node *createNode(int data);
        Node *insertData(Node *root, int data);
        Node *findData(Node *root, int data);
        Node *deleteData(Node *root, int data);
        Node *getMinNode(Node *root);
        int  getDepth(Node *root);
        int  getDiameter(Node *root);
        void deleteTree(Node *root);
        void printInorder(Node *root);
};

#endif // BINARYTREE_H

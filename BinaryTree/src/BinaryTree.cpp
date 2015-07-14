#include <iostream>
#include <cstddef> // for NULL
#include <algorithm>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree()
{
    head = NULL;
}

BinaryTree::~BinaryTree()
{
    deleteTree(head);
}

Node *BinaryTree::createNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void BinaryTree::insertData(int data)
{
    head = insertData(head, data);
}

// let's say I'll only insert unique elements. no input checking here.
Node *BinaryTree::insertData(Node *root, int data)
{
    if(!root) {
        root = createNode(data);
    }
    else if(data < root->data) {
        root->left = insertData(root->left, data);
    }
    else if(data > root->data) {
        root->right = insertData(root->right, data);
    }

    return root;
}

void BinaryTree::deleteData(int data)
{
    head = deleteData(head, data);
}

// assume data is in the tree and NOT the root
Node *BinaryTree::deleteData(Node *root, int data)
{
    Node *temp = findData(root, data);

    // get parent node
    Node *parent = root;
    while(1) {
        if(parent->left == temp || parent->right == temp) {
            break;
        }
        else if(data < parent->data) {
            parent = parent->left;
        }
        else {
            parent = parent->right;
        }
    }

    // no children
    if(!temp->left && !temp->right) {
        delete temp;
        if(parent->left == temp) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
        return root;
    }

    // one child
    if(temp->left && !temp->right) {
        // node to delete HAS a left child
        if(parent->left == temp) {
            // node to delete IS a left child
            parent->left = temp->left;
        }
        else {
            // node to delete IS a right child
            parent->right = temp->left;
        }

        return root;
    }
    else if(!temp->left && temp->right) {
        // node to delete HAS a right child
        if(parent->left == temp) {
            // node to delete IS a left child
            parent->left = temp->right;
        }
        else {
            // node to delete IS a right child
            parent->right = temp->right;
        }

        return root;
    }

    // two children
    // get min of right subtree
    Node *min = getMinNode(temp->right);

    if(parent->left == temp) {
        parent->left = min;
    }
    else {
        parent->right = min;
    }

    min->left = temp->left;

    delete temp;
    return root;
}

Node *BinaryTree::getMinNode(Node *root)
{
    if(!root->left) {
        return root;
    }
    else {
        return getMinNode(root->left);
    }
}

bool BinaryTree::findData(int data)
{
    return (findData(head, data) != NULL);
}

Node *BinaryTree::findData(Node *root, int data)
{
    if(root->data == data) {
        return root;
    }
    else if(data < root->data && root->left != NULL) {
        return findData(root->left, data);
    }
    else if(data > root->data && root->right != NULL) {
        return findData(root->right, data);
    }

    return NULL;
}

int BinaryTree::getDepth()
{
    return getDepth(head);
}

int BinaryTree::getDepth(Node *root)
{
    if(!root) {
        return 0;
    }

    int ldepth = getDepth(root->left);
    int rdepth = getDepth(root->right);


    if(ldepth > rdepth) {
        return ldepth+1;
    }
    else {
        return rdepth+1;
    }
}

int BinaryTree::getDiameter()
{
    return getDiameter(head);
}

int BinaryTree::getDiameter(Node *root)
{
    if(root == NULL) {
        return 0;
    }

    int lHeight = getDepth(root->left);
    int rHeight = getDepth(root->right);

    int lDiam = getDiameter(root->left);
    int rDiam = getDiameter(root->right);

    return max(lHeight+rHeight+1, max(lDiam, rDiam));
}

void BinaryTree::deleteTree()
{
    deleteTree(head);
    head = NULL;
}

void BinaryTree::deleteTree(Node *root)
{
    if(!root) {
        return;
    }

    if(root->left) {
        deleteTree(root->left);
    }

    if(root->right) {
        deleteTree(root->right);
    }

    delete root;
    root = NULL;
}

void BinaryTree::printInorder()
{
    printInorder(head);
}

void BinaryTree::printInorder(Node *root)
{
    if(root->left) {
        printInorder(root->left);
    }

    cout << root->data << " ";

    if(root->right) {
        printInorder(root->right);
    }
}

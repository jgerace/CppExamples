#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree tree;

    cout << "tree depth: " << tree.getDepth() << endl;

    cout << "adding elements" << endl;
    tree.insertData(5);
    tree.insertData(8);
    tree.insertData(2);
    tree.insertData(1);
    tree.insertData(10);
    tree.insertData(7);

    cout << "tree depth: " << tree.getDepth() << endl;

    if(tree.findData(4)) {
        cout << "found 4" << endl;
    }

    if(tree.findData(10)) {
        cout << "found 10" << endl;
    }

    if(!tree.findData(20)) {
        cout << "NOT found 20" << endl;
    }

    cout << "tree diameter: " << tree.getDiameter() << endl;

    tree.printInorder();
    cout << endl;

    tree.deleteData(8);

    tree.printInorder();

    tree.deleteTree();
    return 0;
}

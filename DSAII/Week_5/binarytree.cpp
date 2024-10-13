#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *mid;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->mid = NULL;
    node->right = NULL;
    return (node);
};

void traverseInOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traverseInOrder(temp->left);
        traverseInOrder(temp->mid);
        cout << " " << temp->data;
        traverseInOrder(temp->right);
    }
}
void traversePreOrder(struct node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->mid);
        traversePreOrder(temp->right);
    }
}
void traversePostOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traversePostOrder(temp->right);
        traversePostOrder(temp->mid);
        traversePostOrder(temp->left);
        cout << " " << temp->data;
    }
}

int main()
{
    system("cls");
    // EX1
    // struct node *root = newNode(1);
    // root->left = newNode(2);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->right = newNode(3);
    // EX2
    // struct node *root = newNode(2);
    // root->left = newNode(7);
    // root->left->left = newNode(2);
    // root->left->right = newNode(6);
    // root->left->right->left = newNode(5);
    // root->left->right->right = newNode(11);
    // root->right = newNode(5);
    // root->right->right = newNode(9);
    // root->right->right->left = newNode(4);

    // EX4
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->mid = newNode(7);
    root->right = newNode(8);
    root->left->left = newNode(3);
    root->left->mid = newNode(6);
    root->left->left->left = newNode(4);
    root->left->left->mid = newNode(5);
    root->right->mid = newNode(9);
    root->right->right = newNode(12);
    root->right->mid->mid = newNode(10);
    root->right->mid->right = newNode(11);

    cout
        << "\nInorder traversal: ";
    traverseInOrder(root);
    cout << "\nPreorder traversal: ";
    traversePreOrder(root);
    cout << "\nPostorder traversal: ";
    traversePostOrder(root);
}
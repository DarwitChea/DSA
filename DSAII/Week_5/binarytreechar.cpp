#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *newNode(char data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
};

void traverseInOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traverseInOrder(temp->left);
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
        traversePreOrder(temp->right);
    }
}
void traversePostOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traversePostOrder(temp->right);
        traversePostOrder(temp->left);
        cout << " " << temp->data;
    }
}

int main()
{
    system("cls");
    // EX3
    struct node *root = newNode('A');
    root->left = newNode('B');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->left->left->left = newNode('H');
    root->left->left->right = newNode('I');
    root->right = newNode('C');
    root->right->left = newNode('F');
    root->right->right = newNode('G');
    cout
        << "\nInorder traversal: ";
    traverseInOrder(root);
    cout << "\nPreorder traversal: ";
    traversePreOrder(root);
    cout << "\nPostorder traversal: ";
    traversePostOrder(root);
}
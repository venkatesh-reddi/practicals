#include <stdio.h>
#include <stdlib.h>

struct btnode
{
    int data;
    struct btnode *left;
    struct btnode *right;
}*root = NULL, *temp = NULL, *t2, *t1;

void delete();
void insert();
void search(struct btnode *t);

void search(struct btnode *t)
{
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    temp = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element %d is present in the tree", temp->data);
            return;
        }
        else if (temp->data > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    printf("Element %d is not present in the tree", key);
}

void insert()
{
    int key;
    printf("Enter the element to be inserted: ");
    scanf("%d", &key);
    if (root == NULL)
    {
        temp = (struct btnode *)malloc(sizeof(struct btnode));
        temp->data = key;
        temp->left = temp->right = NULL;
        root = temp;
        return;
    }
    temp = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element already present in the tree");
            return;
        }
        else if (temp->data > key)
        {
            if (temp->left != NULL)
                temp = temp->left;
            else
            {
                t1 = (struct btnode *)malloc(sizeof(struct btnode));
                t1->data = key;
                t1->left = t1->right = NULL;
                temp->left = t1;
                return;
            }
        }
        else
        {
            if (temp->right != NULL)
                temp = temp->right;
            else
            {
                t1 = (struct btnode *)malloc(sizeof(struct btnode));
                t1->data = key;
                t1->left = t1->right = NULL;
                temp->right = t1;
                return;
            }
        }
    }
}

void delete ()
{
    int key;
    printf("Enter the element to be deleted: ");
    scanf("%d", &key);
    temp = root;
    t1 = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                if (t1->left == temp)
                    t1->left = NULL;
                else
                    t1->right = NULL;
                temp = NULL;
                free(temp);
                return;
            }
            else if (temp->left == NULL || temp->right == NULL)
            {
                if (temp->left == NULL)
                    t2 = temp->right;
                else
                    t2 = temp->left;
                if (t1->left == temp)
                    t1->left = t2;
                else
                    t1->right = t2;
                temp = NULL;
                free(temp);
                return;
            }
            else
            {
                t2 = root;
                if (temp->right != NULL)
                {
                    t2 = temp->right;
                    while (t2->left != NULL)
                        t2 = t2->left;
                    temp->data = t2->data;
                    t1 = t2;
                    t2 = t2->right;
                }
                else
                {
                    t2 = temp->left;
                    while (t2->right != NULL)
                        t2 = t2->right;
                    temp->data = t2->data;
                    t1 = t2;
                    t2 = t2->left;
                }
                if (t1->left == t2)
                    t1->left = NULL;
                else
                    t1->right = NULL;
                t2 = NULL;
                free(t2);
                return;
            }
        }
        t1 = temp;
        if (temp->data > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    printf("Element not found");
}

void main()
{
    int ch;
    printf("BST Operations");
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            search(root);
            break;
        case 4:    
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
}
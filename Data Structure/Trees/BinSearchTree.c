/*A programe to create a binary search tree and perform all the opeations*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;    
}node;
node *tree = NULL;

void create_tree(node *tree)
{
    tree = NULL;
}
node *insert(node *tree, int val)
{
    node *ptr, *nodeptr, *parentptr;
    ptr = (node *)malloc(sizeof(node));
    ptr -> data = val;
    ptr -> left = NULL;
    ptr -> right = NULL;
    if(tree == NULL)
    {
        tree = ptr;
        tree -> left = NULL;
        tree -> right =NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if(val < nodeptr -> data)
                nodeptr = nodeptr -> left;
            else
                nodeptr = nodeptr -> right;
        }
        if(val < parentptr -> data)
            parentptr -> left = ptr;
        else
            parentptr -> right = ptr;        
    }
    return tree;
}
node *delete(node *tree, int val)
{
    node *cur, *parent, *suc, *psuc, *ptr;
    if(tree -> left == NULL)
    {
        printf("\nThe tree is Empty.\n");
        return tree;
    }
    parent = tree;
    cur = tree -> left;
    while(cur != NULL && val != cur -> data)
    {
        parent = cur;
        cur = (val < cur -> data) ? cur -> left : cur -> right;
    }
    if(cur == NULL)
    {
        printf("\nThe value to be deleted is not preent in the Tree.\n");
        return tree;
    }
    if(cur -> left == NULL)
        ptr = cur -> right;
    else if(cur -> right == NULL)
        ptr = cur -> left;
    else
    {
        /*Find the in-order successor and its parent.*/
        psuc = cur;
        cur = cur -> left;
        while (suc -> left != NULL)
        {
            psuc = suc;
            suc = suc-> left;
        }
        if(cur == psuc)
        {
            /*Situation 1*/
            suc -> left = cur -> right;
        }        
        else
        {
            /*Situation 2*/
            suc -> left = cur -> left;
            psuc -> left = suc -> right;
            suc -> right = cur -> right;
        }
        ptr = suc;
    }
    /*Attach ptr to the parent node*/
    if(parent -> left == cur)
        parent -> left = ptr;
    else
        parent -> right = ptr;
    free(cur);
    return tree;
}
void preorder_traversal(node *tree)
{
    if(tree != NULL)
    {
        printf("| %d | ", tree -> data);
        preorder_traversal(tree -> left);
        preorder_traversal(tree -> right);
    }
}
void inorder_traversal(node *tree)
{
    if(tree != NULL)
    {
        inorder_traversal(tree -> left);
        printf("| %d | ", tree -> data);
        inorder_traversal(tree -> right);
    }
}
void postorder_traversal(node *tree)
{
    if(tree != NULL)
    {
        postorder_traversal(tree -> left);
        postorder_traversal(tree -> right);
        printf("| %d | ", tree -> data);
    }
}
node *FindSmallest(node *tree)
{
    if ((tree == NULL) || (tree -> right == NULL))
        return tree;
    else
        return FindSmallest(tree -> left);
}
node *FindLargest(node *tree)
{
    if ((tree == NULL) || (tree -> right == NULL))
        return tree;
    else
        return FindLargest(tree -> right);
}
int TotalNodes(node *tree)
{
    if(tree == NULL)
        return 0;
    else
        return(TotalNodes(tree -> left) + TotalNodes(tree -> right) + 1);
}
int TotalExternalNodes(node *tree)
{
    if(tree == NULL)
        return 0;
    else if((tree -> left == NULL) && (tree -> right == NULL))
        return 1;
    else
        return (TotalExternalNodes(tree -> left) + TotalExternalNodes(tree -> right));
}
int TotalInternalNodes(node *tree)
{
    if((tree == NULL) || ((tree -> left == NULL) && (tree -> right == NULL)))
        return 0;
    else
        return(TotalInternalNodes(tree -> left) + TotalInternalNodes(tree -> right) + 1);
}
int height(node *tree)
{
    int LeftHeight, RightHight;
    if(tree == NULL)
        return 0;
    else
    {

        LeftHeight = height(tree -> left);
        RightHight = height(tree  -> right);
        if(LeftHeight > RightHight)
            return (LeftHeight + 1);
        else
            return (RightHight + 1);
    }
}
node *deleteTree(node *tree)
{
    if(tree != NULL)
    {
        deleteTree(tree -> left);
        deleteTree(tree -> right);
        free(tree);
    }
}
node *mirrorImage(node *tree)
{
    node *ptr;
    if(tree != NULL)
    {
        mirrorImage(tree -> left);
        mirrorImage(tree -> right);
        ptr = tree -> left;
        ptr -> left = ptr -> right;
        tree -> right = ptr; 
    }
}
int main()
{
    int option, val;
    node *ptr;
    create_tree(tree);
    do
    {
        printf("\n***MAIN MENU***\n");
        printf("\n  1. Insert Element : ");
        printf("\n  2. Delete an Element : ");
        printf("\n  3. Preorder  Traversal : ");
        printf("\n  4. Inorder   Traversal : ");
        printf("\n  5. Postorder Traversal : ");
        printf("\n  6. Find The Smallest Element : ");
        printf("\n  7. Find The Largest Element : ");
        printf("\n  8. Count the Total number of Nodes : ");
        printf("\n  9. Count the Total number of External Nodes : ");
        printf("\n 10. Count the Total number of Internal Nodes : ");
        printf("\n 11. Determine the Height of the Tree : ");
        printf("\n 12. Find the Mirror Image of the Tree : ");
        printf("\n 13. Delete the Tree : ");
        printf("\n 14. Exit");
        printf("\n\n   Enter Your Option : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1: 
                    printf("\nEnter the value of the New Node : ");
                    scanf("%d", &val);
                    tree = insert(tree, val);
                    break;
            case 2:
                    printf("\nEnter the Element to be Deleted : ");
                    scanf("%d", &val);
                    tree = delete(tree, val);
                    break;
            case 3:
                    printf("\nThe elements of the Tree in Preorder Traversal are : \n");
                    preorder_traversal(tree);
                    break;
            case 4:
                    printf("\nThe elements of the Tree in Inorder Traversal are : \n");
                    inorder_traversal(tree);
                    break;
            case 5:
                    printf("\nThe elements of the Tree in Postorder Traversal are : \n");
                    postorder_traversal(tree);
                    break;
            case 6:
                    ptr = FindSmallest(tree);
                    printf("\nThe Smallest Element is : %d", ptr -> data);
                    break;
            case 7:
                    ptr = FindLargest(tree);
                    printf("\nThe Largest Element is : %d", ptr -> data);
                    break;
            case 8:
                    printf("\nTotal number of Nodes : %d", TotalNodes(tree));
                    break;
            case 9:
                    printf("\nTotal number of External Nodes : %d", TotalExternalNodes(tree));
                    break;
            case 10:
                    printf("\nTotal number of Internal Nodes : %d", TotalInternalNodes(tree));
                    break;
            case 11:
                    printf("\nThe Height of the tree is : %d", height(tree));
                    break;
            case 12:
                    tree = mirrorImage(tree);
                    break;
            case 13:
                    tree = deleteTree(tree);
                    break;
        }
    } while (option != 14);
    return 0;
}
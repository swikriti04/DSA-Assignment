#include <stdio.h>
#include <stdlib.h>
#define initmemory() (struct node*)malloc(sizeof(struct node))

struct node {
    
    int info;
    struct node *left;
    struct node *right;
    
};

struct node* insert(struct node* root, int info) {
        
    if(root == NULL) {
    
        struct node* node = initmemory();

        node->info = info;

        node->left = NULL;
        node->right = NULL;
        return node;
    
    } else {
            
        if(info <= root->info) { 
            root->left = insert(root->left, info);
        } 

        else {
            root->right = insert(root->right, info);;
        }
        return root;
    }
}
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
struct node* deleteNode(struct node* root, int info) 
{ 
    if (root == NULL) return root; 

    if (info < root->info) 
        root->left = deleteNode(root->left, info); 
 
    else if (info> root->info) 
        root->right = deleteNode(root->right, info); 
  
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
 
        struct node* temp = minValueNode(root->right); 
  
        root->info = temp->info; 
  
        root->right = deleteNode(root->right, temp->info); 
    } 
    return root; 
} 

int main(){
    int ans,info;
    struct node* root = NULL;
    while(1){
        printf("MENU\n1.insert an element\n2.delete an element\n3.exit\n");
        scanf("%d",&ans);
        switch(ans){
            case 1: {
                printf("enter the info to be inserted");
                scanf("%d",&info);
                insert(root,info);
                break;
            }
            case 2:{
                printf("enter the info to be deleted");
                scanf("%d",&info);
                deleteNode(root,info);
                break;
            }
            case 3:
            exit(0);break;
        }
    }
    return 0;
}

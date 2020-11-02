/*
*   © Erick Giffoni, 2020
*   University of Brasilia - UnB
*   =) Software Engineering
*   Problem : https : //moj.naquadah.com.br/contests/bcrEDA2-20201-6alista/preinpos.html
*   Compile : gcc pre_in_post_order.c -o preinpost.out
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int content;
    struct Node * left;
    struct Node * right;
} Node;

void preOrder(Node * node){
    if(node != NULL){
        printf("%d ", node->content);
        preOrder(node->left);
        preOrder(node->right);
    }
    return;
} //end pre order

void inOrder(Node * node){
    if(node != NULL){
        inOrder(node->left);
        printf("%d ", node->content);
        inOrder(node->right);
    }
    return;
} //end in order

void postOrder(Node * node){
    if(node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->content);
    }
    return;
} //end post order

Node * insertNode(Node * root, Node * son){
    if(root == NULL)
        return son;
    if(root->content > son->content)
        root->left = insertNode(root->left, son);
    else
        root->right = insertNode(root->right, son);
    return root;
}//end insert node

int main(){

    Node * node = (Node *) calloc(1, sizeof(Node));
    int number;
    scanf(" %d", &number);
    node->content = number;
    node->left = NULL;
    node->right = NULL;
    while(scanf(" %d", &number)!= EOF){
        //inserir na arvore
        Node * son = (Node *) calloc(1, sizeof(Node));
        son->content = number;
        son->left = NULL;
        son->right = NULL;
        node = insertNode(node, son);
    } //end while
    
    //print pre order
    preOrder(node);
    printf(".\n");
    //print in order
    inOrder(node);
    printf(".\n");
    //print post order
    postOrder(node);
    printf(".\n");

    return 0;
}

void postOrdem_ArvBin(Node *raiz){
    if(raiz == NULL)
        return;
    if(raiz != NULL){
        posOrdem_ArvBin(&((*raiz).left));
        posOrdem_ArvBin(&((*raiz).right));
        printf("%d\n",(*raiz).value);
    }
}

Tree *createTree(Tree *tree, int *number){
  Tree *temp = newEmptyTree();
  if(tree->root == NULL){
    tree->root = newEmptyNode();
    tree->root->value = *number;
    return tree;
  }
  else{
    if(*number > tree->root->value){
      temp->root = tree->root->right;
      temp = createTree(temp, number);
      tree->root->right = temp->root;
      return tree;
    }
    else{
      temp->root = tree->root->left;
      temp = createTree(temp, number);
      tree->root->left = temp->root;
      return tree;
    }
  }
}//createTree version 2

Tree *createTree(Tree *tree, int *number){
  Tree *temp = newEmptyTree(); //auxiliar
  if(temp == NULL){
    printf("createTree ERROR: not possible to create new temp empty tree\n\n");
    return NULL;
  }// se arvore temp auxiliar nao foi alocada
  //temp = tree;
  Node *node;
  //checar se a arvore tem raiz
  if(tree->empty == 0){
    tree->root = newEmptyNode();
    tree->root->value = *number;
    tree->root->right = NULL;
    tree->root->left = NULL;
    tree->empty = 1; //not empty anymore;
  }//nao tem raiz
  //caso tenha
  else{
    if(*number > tree->root->value){
      if(tree->root->right == NULL){
        node = newEmptyNode();
        if(node == NULL){
          printf("createTree ERROR: not possible to create empty node\n\n");
          return NULL;
        }//se o no nao foi alocado
        node->value = *number;
        printf("aqui\n\n");
        tree->root->right = node;
      }//if nao tem no depois da raiz
      else{
        temp->root = tree->root->right;
        temp = createTree(temp, number);
        tree->root->right = temp->root;
      }//tem no depois da raiz
    }//go right
    else{
      if(tree->root->left == NULL){
        node = newEmptyNode();
        if(node == NULL){
          printf("createTree ERROR: not possible to create empty node\n\n");
          return NULL;
        }//se o no nao foi alocado
        node->value = *number;
        tree->root->left = node;
      }//if nao tem no depois da raiz
      else{
        temp->root = tree->root->left;
        temp = createTree(temp, number);
        tree->root->left = temp->root;
      }//tem no depois da raiz
    }//else go left
  }//else tem raiz
  return tree;
}//end of createTree version 1

void showTree(Node *root){
  //dar um jeito de pegar os elementos da arvore e jogar num vetor
  int height = getHeight(root);//pega a altura
  int number_of_elements_in_tree = pow(2,height+1) -1; //numero de elementos = 2^nivel-maximo -1 || nivel-maximo = altura +1
  int *array = (int *)calloc(number_of_elements_in_tree, sizeof(int));//vetor com number_of_elements_in_tree posicoes
  //printf("number_of_elements_in_tree = %d\n", number_of_elements_in_tree);//vai contar os filhos nulos tambem
  int i, level;
  for(i=0; i<number_of_elements_in_tree; i++){//for percorre array
    //printf("%d ", array[i]);
    array[i] = getElement(root, i+number_of_elements_in_tree - number_of_elements_in_tree);//segundo parametro e o nivel do no, sendo nivel 0 a raiz da arvore
  }//end for percorre array
}//end of showTree

int getElement(Node *root, int level){
  // right_or_left - 0 ->left , 1 -> right
  if(root == NULL) return 0;//se nao ha um node, trata-se como se o valor dele fosse zero
  else{
    int value;//valor que estamos procurando
    if(level == 0) return root->value;
    else{//level not zero

    }//end level not zero
  }
}//end of getElement

void getElement(Node *root, int *array, int *position){
  // right_or_left - 0 ->left , 1 -> right
  if(root == NULL){
    array[*position] = 0;
    *position++;
    return;
  }//se nao ha um node, trata-se como se o valor dele fosse zero
  else{
    array[*position] = root->value;
    *position++;
    getElement(root->left, array, position);
    getElement(root->right, array, position);
  }
}//end of getElement















void showTree(Node *root){
  if(root == NULL){ //se a raiz for nula, retorna
    //printf("showTree ERROR: passing NULL node to function call\n\n");
    return;
  }//end raiz nula
  else{ //raiz nao nula
    printf("\t\t%d\n", root->value);
    printf("\t\t |\n\t   ------ ------\n");
    printf("\t  %d \t\t %d\n", root->left->value, root->right->value);
    //if(root->left && root->right){//se tem esquerda e direita
    //  printf("\t\t |\n\t   ------ ------\n");
    //  showTree(root->left);
    //  showTree(root->right);
    //}//end se tem esquerda e direita
    //else if(root->left && root->right == NULL){//se tem so esquerda
    //  printf("\t  ------ \n");
    //  showTree(root->left);
    //}//end se tem so esquerda
    //else if(root->left == NULL && root->right){//se tem so direita
    //  printf("\t         ------\n");
    //  showTree(root->right);
    //}//end se tem so direita
    //printf("/\\\n");
    showTree(root->left);
    showTree(root->right);
  }//end raiz nao nula
}//end of showTree

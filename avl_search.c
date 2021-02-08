#include "common.h"
#include "avl_search.h"

int get_max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct lib_data_avl *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

struct lib_data_avl *new_AVL_node(char *word)
{
    struct lib_data_avl *node = (struct lib_data_avl *)malloc(sizeof(struct lib_data_avl));
    char *new_word = (char *)malloc(strlen(word) + 1);
    
    /*Please implement this function.*/
    
    //if no node in left and right, height is equal to 0
    node->left = NULL; node->right = NULL;
    strcpy(new_word, word);
    node->word = new_word;
    node->height = 0;
    
    /**/

    return node;
}

lib_data_avl *rightRotate(lib_data_avl *y)
{
    struct lib_data_avl *x = y->left;
    struct lib_data_avl *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = get_max(height(y->left), height(y->right)) + 1;
    x->height = get_max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

lib_data_avl *leftRotate(lib_data_avl *x)
{
    lib_data_avl *y = x->right;
    lib_data_avl *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = get_max(height(x->left), height(x->right)) + 1;
    y->height = get_max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

int getBalance(lib_data_avl *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

lib_data_avl *insert_avl(lib_data_avl *node, char *word)
{
    /* Implement normal BST insertion */
    
    if(node == NULL){
        //insert node
        node = new_AVL_node(word);
    }
    else{
        if(strcmp(node->word, word) > 0){
            //if word is small in dictionary order, move to left tree
            node->left = insert_avl(node->left, word);
            //after inserting node, fix node height
            node->height = get_max(height(node->left), height(node->right)) + 1;
        }
        else{
            //if word is big in dictionary order, move to right tree
            node->right = insert_avl(node->right, word);
            //after inserting node, fix node height
            node->height = get_max(height(node->left), height(node->right)) + 1;
        }
    }
    /*Implement these cases*/
    // Left Left Case
    // ==>> left tree higher than right tree in terms of node and left node
    if(getBalance(node) > 1 && getBalance(node->left) > 0){
        //single right rotation
        node = rightRotate(node);
    }
    // Right Right Case
    // ==>> right tree higher than left tree in terms of node and right node
    if(getBalance(node) < -1 && getBalance(node->right) < 0){
        //single left rotation
        node = leftRotate(node);
    }
    // Left Right Case
    // ==>> left tree higher than right tree(node)
    //  and right tree higher than left tree(left node)
    if(getBalance(node) > 1 && getBalance(node->left) < 0){
        //double left-right rotation
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }
    // Right Left Case
    // ==>> right tree higher than left tree(node)
    //  and left tree higher than right tree(right node)
    if(getBalance(node) < -1 && getBalance(node->right) > 0){
        //double right-left rotation
        node->right = rightRotate(node->right);
        node = leftRotate(node);
    }
    
    /**/
    return node;
}

lib_data_avl *make_dictionary_AVL(const char *file_path)
{
    FILE *fp; //file pointer
    lib_data_avl *head = NULL;
    char temp_word[255]; // Temporal array for saving word.
    int i = 0;
    
    /*Implement a function to make a dictionary using the AVL tree here.*/

    if((fp = fopen(file_path, "r")) != NULL){
        while(fscanf(fp, "%s", temp_word) != EOF){//to end of the file
            head = insert_avl(head, temp_word);
        }
    }
    fclose(fp);
    
    /**/

    return head;
}

void print_candidates_AVL(lib_data_avl *root_node, const char *mnemonic_word)
{
    /*Implement a function to print candidates included in the dictionary file.*/

    //use recursion
    
    if(root_node==NULL); //do nothing

    //if the same word, print
    else if(strcmp(root_node->word, mnemonic_word) == 0) printf("%s ", mnemonic_word);
    //search left tree
    else if(strcmp(root_node->word, mnemonic_word) > 0) 
        print_candidates_AVL(root_node->left, mnemonic_word);
    //search right tree
    else
        print_candidates_AVL(root_node->right, mnemonic_word);
    
    /**/
}

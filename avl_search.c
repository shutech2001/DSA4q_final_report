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
        node = new_AVL_node(word);
    }
    else{
        if(strcmp(node->word, word) > 0){
            node->left = insert_avl(node->left, word);
            node->height = get_max(height(node->left), height(node->right)) + 1;
        }
        else{
            node->right = insert_avl(node->right, word);
            node->height = get_max(height(node->left), height(node->right)) + 1;
        }
    }
    /*Implement these cases*/
    // Left Left Case
    if(getBalance(node) > 1 && getBalance(node->left) > 0){
        node = rightRotate(node);
    }
    // Right Right Case
    if(getBalance(node) < -1 && getBalance(node->right) < 0){
        node = leftRotate(node);
    }
    // Left Right Case
    if(getBalance(node) > 1 && getBalance(node->left) < 0){
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }
    // Right Left Case
    if(getBalance(node) < -1 && getBalance(node->right) > 0){
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
        while(fscanf(fp, "%s", temp_word) != EOF){
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
    lib_data_avl* temp = root_node;
    while(temp != NULL){
        if(strcmp(temp->word, mnemonic_word) == 0){
            printf("%s ", mnemonic_word);
            break;
        }
        else if (strcmp(temp->word, mnemonic_word) > 0){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    /**/
}

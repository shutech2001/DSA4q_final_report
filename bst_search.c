#include "common.h"
#include "bst_search.h"


void insert_bst(lib_data_bst** root, char* word)
{
    lib_data_bst* new_node; 
    lib_data_bst* temp = *root;
    
    /*Implement a function to insert a bst node.*/

    if(temp==NULL){//create root node
        //allocate memory
        new_node = (lib_data_bst*)malloc(sizeof(lib_data_bst));
        char* new_word = (char*)malloc(strlen(word) + 1);
        
        //initialized new_node with word
        new_node->left = NULL; new_node->right = NULL;
        strcpy(new_word, word);
        new_node->word = new_word;
        *root = new_node;
    }
    else{
        if(strcmp(temp->word, word) > 0){
            //if word is small in dictionary order, move to left tree
            insert_bst(&(temp)->left, word);
        }
        else{
            //if word is big in dictionary order, move to right tree
            insert_bst(&(temp)->right, word);
        }
    }

    /**/
}

lib_data_bst* make_dictionary_BST(const char* file_path)
{
    FILE* fp; //file pointer
    lib_data_bst* head = NULL;
    char temp_word[255]; // Temporal array for saving word. 

    /*Implement a function to make a dictionary using the BST here.*/

    if((fp = fopen(file_path, "r"))!=NULL){
        while(fscanf(fp, "%s", temp_word) != EOF){//to end of the file
            insert_bst(&head, temp_word);
        }
    }
    fclose(fp);

    /**/
    return head;
}


void print_candidates_BST(lib_data_bst* root_node, const char* mnemonic_word)
{
    /*Implement a function to print candidates included in the dictionary file.*/

    //use recursion
    
    if(root_node==NULL); //do nothing

    //if the same word, print
    else if(strcmp(root_node->word, mnemonic_word) == 0) printf("%s ", mnemonic_word);
    //search left tree
    else if(strcmp(root_node->word, mnemonic_word) > 0) 
        print_candidates_BST(root_node->left, mnemonic_word);
    //search right tree
    else
        print_candidates_BST(root_node->right, mnemonic_word);
    
    /**/
}

#include "common.h"
#include "bst_search.h"


void insert_bst(lib_data_bst** root, char* word)
{
    lib_data_bst* new_node; 
    lib_data_bst* temp = *root;
    
    /*Implement a function to insert a bst node.*/
    new_node = (lib_data_bst*)malloc(sizeof(lib_data_bst));
    char* new_word = (char*)malloc(strlen(word) + 1);

    new_node->left = NULL; new_node->right = NULL;
    strcpy(new_word, word);
    new_node->word = new_word;

    if(temp==NULL){
        *root = new_node;
    }
    else{
        while(temp != NULL){
            if(strcmp(temp->word, new_word) > 0){
                if(temp->left == NULL){
                    temp->left = new_node;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right == NULL){
                    temp->right = new_node;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
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
        while(fscanf(fp, "%s", temp_word) != EOF){
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
    lib_data_bst* temp = root_node;
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

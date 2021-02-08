#include "common.h"
#include "linear_search.h"


lib_data_linear* make_dictionary_linear(const char* file_path)
{
	FILE* fp; //file pointer
	lib_data_linear* head = NULL;
    char temp_word[255]; // Temporal array for saving word. 
    int i = 0;
	/*Implement a function to make a dictionary using the linked list here.*/
    if((fp = fopen(file_path, "r"))!=NULL){
        while(fscanf(fp, "%s", temp_word) != EOF){
            insert_node(&head, temp_word);
        }
    }
    fclose(fp);
	/**/
	return head;
}

void insert_node(lib_data_linear** head_node, const char* word)
{
    lib_data_linear* new_node = (lib_data_linear*)malloc(sizeof(lib_data_linear));
    lib_data_linear* temp = *head_node;
    char* new_word = (char*)malloc(strlen(word) + 1);
    /*Implement a function to insert a new node here.*/
    new_node->next = NULL;
    strcpy(new_word, word);
    new_node->word = new_word;
    if(temp == NULL){//create linked-list
        *head_node = new_node;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    /**/
}

void print_candidates_linear(lib_data_linear* head_node, const char* mnemonic_word)
{
    lib_data_linear* temp = head_node;
    /*Implement a function to print candidates included in the dictionary file.*/
    while(temp != NULL){
        if(strcmp(temp->word, mnemonic_word) == 0){
            printf("%s ", mnemonic_word);
        }
        temp = temp->next;
    }
    /**/
}
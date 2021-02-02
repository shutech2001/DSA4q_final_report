#include "common.h"
#include "linear_search.h"


lib_data_linear* make_dictionary_linear(const char* file_path)
{
	FILE* fp; //file pointer
	lib_data_linear* head = NULL;
    char temp_word[255]; // Temporal array for saving word. 
    int i = 0;
	/*Implement a function to make a dictionary using the linked list here.*/
	//
	/**/

	return head;
}

void insert_node(lib_data_linear** head_node, const char* word)
{
    lib_data_linear* new_node = (lib_data_linear*)malloc(sizeof(lib_data_linear));
    lib_data_linear* temp = *head_node;
    char* new_word = (char*)malloc(strlen(word) + 1);
    
    /*Implement a function to insert a new node here.*/

    /**/
}

void print_candidates_linear(lib_data_linear* head_node, const char* mnemonic_word)
{
    lib_data_linear* temp = head_node;
    /*Implement a function to print candidates included in the dictionary file.*/
  
    /**/
}
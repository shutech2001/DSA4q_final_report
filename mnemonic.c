#include "common.h"
#include "mnemonic.h"

const char hash_table[10][5] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };


void insert_combination(mnemonic_list** head_node, const char* word)
{
	mnemonic_list* new_node = (mnemonic_list*)malloc(sizeof(mnemonic_list));
	mnemonic_list* temp = *head_node;
	char* new_word = (char*)malloc(strlen(word));

	memcpy(new_word, word, strlen(word));
	new_node->next = NULL;
	new_node->word = new_word;

	if (temp == NULL)
	{
		*head_node = new_node;
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = new_node;
}

void mnemonic(mnemonic_list** head_node, int number[], int curr_digit, char output[], int n)
{
	int i;
	if (curr_digit == n) 
	{
		insert_combination(head_node, output);
		return;
	}

	for (i = 0; i < strlen(hash_table[number[curr_digit]]); i++) 
	{
		output[curr_digit] = hash_table[number[curr_digit]][i];
		mnemonic(head_node, number, curr_digit + 1, output, n);
		if (number[curr_digit] == 0
			|| number[curr_digit] == 1)
			return;
	}
}

mnemonic_list* get_candidates_from_numbers(int number[], int n)
{
	mnemonic_list* head_node = 0;
	char* result = (char*)malloc(n + 1);
	result[n] = '\0';

	mnemonic(&head_node, number, 0, result, n);

	free(result);

	return head_node;
}
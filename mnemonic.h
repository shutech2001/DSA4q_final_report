#pragma once

typedef struct mnemonic_list
{
    char* word;
    struct mnemonic_list* next;
}mnemonic_list;

void insert_combination(mnemonic_list** head_node, const char* word);
void mnemonic(mnemonic_list** head_node, int number[], int curr_digit, char output[], int n);
mnemonic_list* get_candidates_from_numbers(int number[], int n);

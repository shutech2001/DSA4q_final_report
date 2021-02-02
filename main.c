#include <time.h>
#include "common.h"
#include "linear_search.h"
#include "bst_search.h"
#include "avl_search.h"

int main(int argc, char **argv)
{

	int *phone_number = NULL;

	mnemonic_list *candidates;
	char *dictionary_path = argv[1];

	int length = strlen(argv[2]);
	int num_of_iter = 5;

	if (argc != 3)
	{
		printf("Usage: ./final_project.out <dictionary file path> <phone number>\n");
		exit(1);
	}

	printf("Input phone number is ");
	phone_number = (int *)malloc(length * sizeof(int));
	for (int i = 0; i < length; i++)
	{
		printf("%c", argv[2][i]);
		phone_number[i] = argv[2][i] - '0';

		if (!(phone_number[i] > 1 && phone_number[i] < 10))
		{
			printf("\nOnly combinations of numbers 2~9 can be accepted.");
			exit(1);
		}
	}

	candidates = get_candidates_from_numbers(phone_number, length);

	printf("\nMake a dictionary...\n");
	lib_data_linear *dict_linear = make_dictionary_linear(dictionary_path);
	lib_data_bst *dict_bst = make_dictionary_BST(dictionary_path);
	lib_data_avl *dict_avl = make_dictionary_AVL(dictionary_path);

	print_all_combinations(candidates);

	printf("[Linear search]\n");
	clock_t tic = clock();
	for (int i = 0; i < num_of_iter; i++)
	{
		printf("iteration %d/%d\n", i + 1, num_of_iter);
		mnemonic_list *temp = candidates;
		do
		{
			print_candidates_linear(dict_linear, temp->word);
			temp = temp->next;
		}
		while (temp != NULL);
		printf("\n");
	}
	clock_t toc = clock();
	printf("Average Time: %f seconds [Linear]\n", ((double)(toc - tic) / CLOCKS_PER_SEC) / num_of_iter);

	printf("[BST search]\n");
	tic = clock();
	for (int i = 0; i < num_of_iter; i++)
	{
		printf("iteration %d/%d\n", i + 1, num_of_iter);
		mnemonic_list *temp = candidates;
		do
		{
			print_candidates_BST(dict_bst, temp->word);
			temp = temp->next;
		}
		while (temp != NULL);
		printf("\n");
	}
	toc = clock();
	printf("Average Time: %f seconds [BST]\n", ((double)(toc - tic) / CLOCKS_PER_SEC) / num_of_iter);

	printf("[AVL search]\n");
	tic = clock();
	for (int i = 0; i < num_of_iter; i++)
	{
		printf("iteration %d/%d\n", i + 1, num_of_iter);
		mnemonic_list *temp = candidates;
		do
		{
			print_candidates_AVL(dict_avl, temp->word);
			temp = temp->next;
		}
		while (temp != NULL);
		printf("\n");
	}
	toc = clock();
	printf("Average Time: %f seconds [AVL]\n", ((double)(toc - tic) / CLOCKS_PER_SEC) / num_of_iter);
}

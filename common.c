#include "common.h"

void delete_linechar(char* str)
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = 0;
}

void print_all_combinations(mnemonic_list* mnemonic)
{
    printf("<Combinations>\n");
	do
	{
		printf("%s, ", mnemonic->word);
		mnemonic = mnemonic->next;
	}
	while (mnemonic != NULL);
	printf("\n");
}
typedef struct BST_node
{
    char* word;
    struct BST_node* left;
    struct BST_node* right;
}lib_data_bst;

void insert_bst(struct BST_node** rootptr, char* word);
void print_candidates_BST(lib_data_bst* head_node, const char* mnemonic_word);
lib_data_bst* make_dictionary_BST(const char* file_path);
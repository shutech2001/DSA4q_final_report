typedef struct lib_data_avl
{
    char* word;
    struct lib_data_avl* left;
    struct lib_data_avl* right;
    int height;
}lib_data_avl;

int get_max(int a, int b);
int height(struct lib_data_avl* N);
struct lib_data_avl* new_AVL_node(char* word);
lib_data_avl* rightRotate(lib_data_avl* y);
lib_data_avl* leftRotate(lib_data_avl* x);
int getBalance(lib_data_avl* N);
lib_data_avl* insert_avl(lib_data_avl* node, char* word);
void preOrder(lib_data_avl* root);
lib_data_avl* make_dictionary_AVL(const char* file_path);
void print_candidates_AVL(lib_data_avl* root_node, const char* mnemonic_word);

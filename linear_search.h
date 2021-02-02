
typedef struct lib_data_linear {
    char* word;
    struct lib_data_linear* next;
} lib_data_linear;

lib_data_linear* make_dictionary_linear(const char* file_path);
void insert_node(lib_data_linear** head_node, const char* word);
void print_candidates_linear(lib_data_linear* head_node, const char* mnemonic_word);

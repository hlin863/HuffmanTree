struct HuffmanTreeNode{
    char character;
    int weight;
};

struct HuffmanTree{
    struct HuffmanTreeNode *root;
    struct HuffmanTree *left;
    struct HuffmanTree *right;
};

struct HuffmanTreeNode **createHuffmanTreeTable();

void displayHuffmanTreeTable(struct HuffmanTreeNode **huffmanTreeNode);

struct HuffmanTreeNode *createHuffmanTreeNode(char character, int weight);

struct HuffmanTree *createEmptyHuffmanTree();

struct HuffmanTree *createHuffmanTree(struct HuffmanTreeNode *root);

struct HuffmanTree *newNode(struct HuffmanTree *tree,struct HuffmanTreeNode *element);

void HuffmanTreeAlgorithm();

char *getInput(char *string);

void calculateUpperLevel(int *intArray, int length);

int *convertCharArrayToIntArray(char *string, struct HuffmanTreeNode **huffmanTable);
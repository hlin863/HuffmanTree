#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "huffman_tree.h"

struct HuffmanTreeNode **createHuffmanTreeTable(){
    // create a global variable to store an array of huffman tree nodes.
    struct HuffmanTreeNode **huffmanTreeNode = (struct HuffmanTreeNode **)malloc(sizeof(struct HuffmanTreeNode *) * 26);
    huffmanTreeNode[0] = createHuffmanTreeNode('A', 7);
    huffmanTreeNode[1] = createHuffmanTreeNode('B', 2);
    huffmanTreeNode[2] = createHuffmanTreeNode('C', 2);
    huffmanTreeNode[3] = createHuffmanTreeNode('D', 3);
    huffmanTreeNode[4] = createHuffmanTreeNode('E', 11);
    huffmanTreeNode[5] = createHuffmanTreeNode('F', 2);
    huffmanTreeNode[6] = createHuffmanTreeNode('G', 2);
    huffmanTreeNode[7] = createHuffmanTreeNode('H', 6);
    huffmanTreeNode[8] = createHuffmanTreeNode('I', 6);
    huffmanTreeNode[9] = createHuffmanTreeNode('J', 1);
    huffmanTreeNode[10] = createHuffmanTreeNode('K', 1);
    huffmanTreeNode[11] = createHuffmanTreeNode('L', 4);
    huffmanTreeNode[12] = createHuffmanTreeNode('M', 3);
    huffmanTreeNode[13] = createHuffmanTreeNode('N', 7);
    huffmanTreeNode[14] = createHuffmanTreeNode('O', 9);
    huffmanTreeNode[15] = createHuffmanTreeNode('P', 2);
    huffmanTreeNode[16] = createHuffmanTreeNode('Q', 1);
    huffmanTreeNode[17] = createHuffmanTreeNode('R', 6);
    huffmanTreeNode[18] = createHuffmanTreeNode('S', 6);
    huffmanTreeNode[19] = createHuffmanTreeNode('T', 8);
    huffmanTreeNode[20] = createHuffmanTreeNode('U', 4);
    huffmanTreeNode[21] = createHuffmanTreeNode('V', 1);
    huffmanTreeNode[22] = createHuffmanTreeNode('W', 2);
    huffmanTreeNode[23] = createHuffmanTreeNode('X', 1);
    huffmanTreeNode[24] = createHuffmanTreeNode('Y', 2);
    huffmanTreeNode[25] = createHuffmanTreeNode('Z', 1);

    return huffmanTreeNode;
}

void displayHuffmanTreeTable(struct HuffmanTreeNode **huffmanTreeNode){
    // display the huffman tree table.
    for(int i = 0; i < 26; i++){
        // format the output by giving 3 spaces for character and 5 spaces for weight.
        printf("%3c: %5d\n", huffmanTreeNode[i]->character, huffmanTreeNode[i]->weight);
    }
}

struct HuffmanTreeNode *createHuffmanTreeNode(char character, int weight){
    struct HuffmanTreeNode *node = malloc(sizeof(struct HuffmanTreeNode));
    node->character = character;
    node->weight = weight;
    return node;
}

struct HuffmanTree *createEmptyHuffmanTree(){
    struct HuffmanTree *tree = malloc(sizeof(struct HuffmanTree));
    tree->root = NULL;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

struct HuffmanTree *createHuffmanTree(struct HuffmanTreeNode *root){
    struct HuffmanTree *tree = malloc(sizeof(struct HuffmanTree));
    tree->root = root;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

struct HuffmanTree *newNode(struct HuffmanTree *tree,struct HuffmanTreeNode *element){
    if (tree == NULL){
        tree = createHuffmanTree(element);
        return tree;
    } else {
        if (tree->root->weight > element->weight){
            tree->left = newNode(tree->left, element);
        } else {
            tree->right = newNode(tree->right, element);
        }
        return tree;
    }
}

char *getInput(char *string){
    int continueInput = 1;

    while (continueInput == 1){
        char c;
        scanf("%c", &c);
        getchar();

        strncat(string, &c, 1);

        printf("Continue: ");
        scanf("%d", &continueInput);
        getchar();

        if (continueInput != 1){
            break;
        }
    }

    return string;
}

int *convertCharArrayToIntArray(char *string, struct HuffmanTreeNode **huffmanTable){
    int *intArray = malloc(sizeof(int) * strlen(string));
    for (int i = 0; i < strlen(string); i++){
        intArray[i] = huffmanTable[string[i] - 'A']->weight;
    }
    return intArray;
}

void calculateUpperLevel(int *intArray, int length){

    if (length == 1){
        // base case when the array has only 1 element.
        printf("%d\n", intArray[0]);
        return;
    } 
    // FIND the smallest two weights in the tree
    int smallestWeight = intArray[0];
    int secondSmallestWeight = intArray[1];

    for (int i = 0; i < length; i++){
        if (intArray[i] < smallestWeight){
            secondSmallestWeight = smallestWeight;
            smallestWeight = intArray[i];
        } else if (intArray[i] < secondSmallestWeight){
            secondSmallestWeight = intArray[i];
        }
    }

    // TEST function to check the smallest values in the Huffman tree.
    printf("Smallest weight: %d\n", smallestWeight);
    printf("Second smallest weight: %d\n", secondSmallestWeight);

    // initialise a tidied array
    int *tidiedArray = malloc(sizeof(int) * length);

    // copy the original array into the tidied array
    for (int i = 0; i < length - 1; i ++){
        tidiedArray[i] = intArray[i] + intArray[i + 1];
    }

    // substitute the next level for iteration until the top of the Huffman tree is reached. 
    calculateUpperLevel(tidiedArray, length - 1);

    for (int i = 0; i < length - 1; i++){
        printf("%d ", tidiedArray[i]);
    }

    printf("\n");
    
}

void HuffmanTreeAlgorithm(){

    int index = 0;

    char *input = (char*) malloc(sizeof(char) * 100);

    strcpy(input, "");

    input = getInput(input);

    printf("%s\n", input);

    // generated and displayed the Huffman tree table.
    struct HuffmanTreeNode **huffmanTreeNode = createHuffmanTreeTable();

    displayHuffmanTreeTable(huffmanTreeNode);

    // convert the input string to an array of integers.
    int *intArray = convertCharArrayToIntArray(input, huffmanTreeNode);

    calculateUpperLevel(intArray, strlen(input));
    for (int i = 0; i < strlen(input); i++){
        printf("%d ", intArray[i]);
    }
    printf("\n");

}

int main(){
    HuffmanTreeAlgorithm();
}

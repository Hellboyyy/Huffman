#include <stdlib.h>
#include <stdio.h>

typedef struct huffman_node huffman_node;
typedef struct linked_node linked_node;

struct huffman_node
{
	char chr;
	int cnt;
	huffman_node *left, *right;
};

struct linked_node
{
	linked_node *next;
	huffman_node *data;
};

huffman_node* make_huffman_tree(char *chrs, int *cnts, int amount);
huffman_node* make_huffman_node(char chr, int cnt);
void print_huffman_tree(huffman_node* root);
void free_huffman_tree(huffman_node* root);

linked_node* make_linked_node(huffman_node* data);
void add_linked_node(linked_node** root, linked_node* node);

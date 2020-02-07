#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "frequency.h"
#include "huffman_tree.h"

int main()
{
	FILE *input = fopen("dna.txt", "rt");
	frequency *freq = read_frequency_from_text(input);

	print_frequency(freq);

	huffman_node *tree = make_huffman_tree(freq->chrs, freq->cnts, freq->amount);
	print_huffman_tree(tree);

	free_huffman_tree(tree);
	free_frequency(freq);
	return 0;
}

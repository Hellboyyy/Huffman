#include "huffman_tree.h"

huffman_node* make_huffman_tree(char *chrs, int *cnts, int amount)
{
	if (amount == 0)
	{
		return NULL;
	}
	if (amount == 1)
	{
		return make_huffman_node(chrs[0], cnts[0]);
	}
	linked_node* root = NULL; // link to 1st linked_node
	for (int i = 0; i < amount; i++)
	{
		huffman_node* h_node = make_huffman_node(chrs[i], cnts[i]);
		// h_node - link to new huffman_node
		// (tmp variable for make_linked_node)
		linked_node* l_node = make_linked_node(h_node);
		// l_node - tmp variable for add_linked_node
		add_linked_node(&root, l_node); //TODO discuss &root
	}
	//TODO continue here
}

huffman_node* make_huffman_node(char chr, int cnt)
{
	huffman_node* node = malloc(sizeof(huffman_node));
	node->chr = chr;
	node->cnt = cnt;
	node->left = NULL;
	node->right = NULL;
	return node;
}

linked_node* make_linked_node(huffman_node* data) 
{
	linked_node* node = malloc(sizeof(linked_node));
	node->data = data;
	node->next = NULL;
	return node;
}

void print_huffman_tree_additonal(huffman_node* node, int lvl)
{
	if (node->right != NULL)
	{
		print_huffman_tree_additonal(node->right, lvl + 1);
	}
	for (int i = 0; i < lvl; i++)
	{
		printf("      ");
	}
	if (node->chr == '\n')
	{
		printf("\'\\n\': %i\n", node->cnt); // '\n': 31
	}
	else if (node->chr == EOF)
	{
		printf("\'\EOF\': %i\n", node->cnt);
	}
	else
	{
		printf("\'%c\': %i\n", node->chr, node->cnt);
	}
	if (node->left!= NULL)
	{
		print_huffman_tree_additonal(node->left, lvl + 1);
	}
}

void print_huffman_tree(huffman_node* root)
{
	print_huffman_tree_additonal(root, 0);
}

void free_huffman_tree(huffman_node* root)
{
	if (root->right != NULL)
	{
		free_huffman_tree(root->right);
	}
	if (root->left != NULL)
	{
		free_huffman_tree(root->left);
	}
	free(root);

}

void add_linked_node(linked_node** root, linked_node* node)
{
	if (*root == NULL)
	{
		*root = node;
	}
	else if ((node->data)->cnt < ((*root)->data)->cnt)
	{
		node->next = *root;
		*root = node;
	}
	else
	{
		add_linked_node(&((*root)->next), node);
		//CHECK add_linked_node(*root, node)
	}
}
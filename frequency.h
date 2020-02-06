#include <stdio.h>
#include <stdlib.h>

#define MAXN 256

typedef struct frequency frequency;
struct frequency {
	char* chrs;
	int* cnts;
	int amount;
};

frequency* read_frequency_from_text(FILE* input);
void print_frequency(frequency *data);
void free_frequency(frequency *data);
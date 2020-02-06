#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "frequency.h"

int main()
{
	FILE *input = fopen("dna.txt", "rt");
	frequency *freq = read_frequency_from_text(input);
	print_frequency(freq);
	free_frequency(freq);
	return 0;
}

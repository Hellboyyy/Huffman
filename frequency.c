#include "frequency.h"

frequency* read_frequency_from_text(FILE* input)
{
	int ascii[MAXN] = { 0 };
	int c = fgetc(input);
	int n = 0;
	while (c != EOF)
	{
		ascii[c]++;
		c = fgetc(input);
	}

	for (int i = 0; i < MAXN; i++)
		if (ascii[i] != 0)
			n++;

	char* chrs = (char *)malloc(sizeof(char) * n);
	int* cnts = (int*)malloc(sizeof(int) * n);

	for (int i = 0, j = 0; i < MAXN; i++)
		if (ascii[i] != 0)
		{
			chrs[j] = (char)i;
			cnts[j] = ascii[i];
			j++;
		}
	frequency* freq = (frequency*)malloc(sizeof(frequency));
	freq->chrs = chrs;
	freq->cnts = cnts;
	freq->amount = n;
	return freq;
}

void print_frequency(frequency *data)
{
	printf("%i\n", data->amount);
	for (int i = 0; i < data->amount; i++)
		printf("\'%c\':%i\n", data->chrs[i], data->cnts[i]);
}

void free_frequency(frequency *data)
{
	free(data->chrs);
	free(data->cnts);
	free(data);
}
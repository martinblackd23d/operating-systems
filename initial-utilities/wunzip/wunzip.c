#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int count;
	char ch;

	//no arguments
	if (argc == 1)
	{
		printf("wunzip: file1 [file2 ...]\n");
		return 1;
	}

	//loop through all files
	for (int i = 1; i < argc; i++)
	{
		// open file
		fp = fopen(argv[i], "r");
		if (fp == NULL)
		{
			printf("wunzip: cannot open file\n");
			return 1;
		}

		// read and uncrompress files
		while (fread(&count, sizeof(int), 1, fp) && fread(&ch, sizeof(char), 1, fp))
		{
			for (int j = 0; j < count; j++)
			{
				printf("%c", ch);
			}
		}
	}

	return 0;
}
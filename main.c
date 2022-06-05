#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileContentToStr(char* str, int buff, FILE* file);
int fileLen(FILE* file);

int main() {
	FILE* file;
	
	char* filename = malloc(100);

	if (filename == NULL) {
		while (filename == NULL) {
			char* filename = malloc(100);
		}
	}

	printf("Enter file name: ");
	scanf("%s", filename);

	if ((file = fopen(filename, "r")) == NULL) {
		printf("\nThere is no file named like that.");
        free(filename);
		return 1;
	}

	int fLen = fileLen(file);

	free(filename);

	if (fileLen == 0) {
		return 1;
	}

	char* fileContent = malloc(fLen);

	if (fileContent == NULL) {
		while (fileContent == NULL) {
			fileContent = malloc(fLen);
		}
	}

	fileContentToStr(fileContent, fLen, file);

	char grid[3000] = {0};
	char* ptr = grid;

	int i = 0;

	while (i < fLen) {
		switch (fileContent[i]) {
		case '>':
			if (ptr != (&grid[2999])) {
				ptr++;
			}
			i++;
			break;
		case '<':
			if (ptr != grid) {
				ptr--;
			}
			i++;
			break;
		case '+':
			(*ptr)++;
			i++;
			break;
		case '-':
			(*ptr)--;
			i++;
			break;
		case '.':
			printf("%c", *ptr);
			i++;
			break;
		case ',':
			*ptr = getch();
			i++;
			break;
		case '[':
			i++;
			continue;
			break;
		case ']':
			if (*ptr != 0) {
				while (fileContent[i] != '[') {i--;}
			}
			i++;
			break;
        default:
            i++;
            break;
        }
	}

	free(fileContent);
}

void fileContentToStr(char* str, int buff, FILE* file) {
	rewind(file);

	int i = 0;
	char ch = fgetc(file);

	for (i = 0; ch != EOF && i < buff; i++) {
		str[i] = ch;
        ch = fgetc(file);
	}
}

int fileLen(FILE* file) {
	rewind(file);

	int i = 0;
	char ch = fgetc(file);

	for (i = 0; ch != EOF; i++){ch = fgetc(file);}

	return i;
}
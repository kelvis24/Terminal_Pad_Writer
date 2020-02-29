#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getWordPrint(void);
void scanTransfer(void);
char **scanFile(char *key, int *j);
char **scanDoc(char *key, int *j);
char **compile(char **docs, int p, char **words, int q);



int main(void) {
	
	getWordPrint();
    scanTransfer();
	
	
	return 0;
}


void getWordPrint(void) {
    FILE *file = NULL;
	file = fopen("myJazz.txt", "w");
	int end = 1;
	char word[1000];
	
	while (end) {
       	printf("-> ");
	    fgets(word, 1000, stdin);
    	word[strlen(word) - 1] = '\0';
    	
	
	    if (strcmp(word, "save") == 0) {
		    end = 0;
			continue;
		}
		fprintf(file, "%s\n", word);
	}
	
	fclose(file);
}


char **scanDoc(char *key, int *j) {
	
	
	FILE *file = NULL;
	file = fopen(key, "r");
	int SIZE = 1000;
	char **lines = malloc(sizeof(char*) * SIZE);
	
	char buffer[1000];
	int i = 0;
	
	while (fgets(buffer, 1000, file)) {
		buffer[strlen(buffer)- 1] = '\0';
		
		if (i == SIZE) {
			SIZE += 1000;
			char **newlines = realloc(lines, SIZE * sizeof(char*));
			
			if (!newlines) {
				printf("Failed at position 1");
				exit(1);
			}
			
			lines = newlines;
			
		}
		
		
		
		int bufflength = 1 + strlen(buffer);
		
		char *line = malloc(bufflength * sizeof(char));
		
		if (!line) {
			printf("Error at point 2");
			exit(1);
		}
		
		strcpy(line, buffer);
		
		lines[i] = line;
		
		++i;
	}
	*j = i;/'
	return lines;
	fclose(file);
}



char **scanFile(char *key, int *j) {

	FILE *file = NULL;
	file = fopen(key, "r");
	int SIZE = 1000;
	char **lines = malloc(SIZE * sizeof(char*));
	
	char buffer[1000];
	unsigned int i = 0;
	
	while (fgets(buffer, 1000, file)) {
		buffer[strlen(buffer)- 1] = '\0';
		
		if (i == SIZE) {
			SIZE += 1000;
			char **newlines = realloc(lines, SIZE * sizeof(char*));
			
			if (!newlines) {
				printf("Failed at position 1");
				exit(1);
			}
			
			lines = newlines;
			
		}
		
		
		
		int bufflength = 1 + strlen(buffer);
		
		char *line = malloc(bufflength * sizeof(char));
		
		if (!line) {
			printf("Error at point 2");
			exit(1);
		}
		
		strcpy(line, buffer);
		
		lines[i] = line;
		
		++i;
	}
	*j = i;
	return lines;
	fclose(file);
}



void scanTransfer(void) {
	

	char Name[100];
	printf("\n\n\nPlease enter file name:     ");
	scanf("%s", &Name);
	
	char file[] = "myJazz.txt";
	
	int i = 0;
	int d = 0;
	
	
	char **words = scanFile(file, &i);
	int p = i + d;
	
	
	FILE *old = NULL;
	old = fopen(Name, "w");
	
	if (!old) {
		printf("Failded at point 3:");
		exit(1);
	}
	
	for (int k = 0; k < i; ++k) {
	    fprintf(old, "%s\n", words[k]);

	}
	
	printf("typed lines:      %d\n\n\n", i );
	fclose(old);
}



char **compile(char **docs, int p, char **words, int q) {
	int r = (p + q);
	char **lines = malloc(r * sizeof(char*));
	
	for (int i = 0; i < r; ++i) {
		if (i < p) {
		    lines[i] = docs[i];
		}else {
			lines[i] = words[i];
		}	
	}

	return lines;
}
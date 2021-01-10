#include <stdio.h> // input/output
#include <stdlib.h> // read/write in files
#include <string.h> // string functions
/*
	Specifiers:
	int - %d or %i
	char single charecter- %c 
	char string - %s
	long - %li
	float - %f
	double - %lf
*/

void read(char input_path[100]){
	FILE *fptr;
	fptr = fopen(input_path, "r");
	if(fptr == NULL){
		printf("File doesn't exist!\n");
		return;         
   	}
	char file_text[1000];
	fscanf(fptr, "%s", file_text);
	printf("%s", file_text);

	fclose(fptr);
}

void write(char input_file[100]){
	char input_content[1000] = {};

	FILE *fptr;
	fptr = fopen(input_file, "w");

	printf("What to type in the file?\n");
	scanf("%s", input_content);
	fprintf(fptr, "%s", input_content);

	fclose(fptr);

}

#define BUFFER_SIZE 1000
void append(char input_file[100]){
	char input_content[BUFFER_SIZE];
	FILE *fptr;
	fptr = fopen(input_file, "a+");

	printf("What to type in the file?\n");
	scanf("%s", input_content);
	fputs(input_content, fptr);

	char file_text[1000];
	fgets(file_text, BUFFER_SIZE, fptr);
	
	printf("Content appended! File now contains:\n");
	read(input_file);

	fclose(fptr);

}

/*char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}*/

int main(void){
	char command[5] = {};
	while(1){
		printf("Choose what to do with a file: \"r\" to read; \"w\" write \"a\" to append; \"c\" to close the program\n");
		scanf("%s", command);
		//printf("%d", strcmp(command, "w"));
		if((strcmp(command, "w") != 0)&&(strcmp(command, "r") != 0)&&(strcmp(command, "a") != 0)&&(strcmp(command, "c") != 0)){
			printf("Wrong command!\n Try again");
		}else{
			if(strcmp(command, "c") == 0){
				printf("Bye!\n");
				exit(1);
			} else{
				printf("Input file name:\n");
				char input_path[100];
				scanf("%s", input_path);
				if (strcmp(command, "r") == 0)
					read(input_path);
				else if(strcmp(command, "w") == 0)
					write(input_path);
				else if(strcmp(command, "a") == 0)
					append(input_path);
			}
		}

		printf("\n");
	};
    return 0;
}
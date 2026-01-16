/*
Program: Conky color changer
Author: Stanley Petrek
Date: 1.1.2013
Update: 6.10.2025

Terminal compile: gcc conkycolors.c -o conkycolors -lm	
Terminal run: ./conkycolors /.cache/wal/colors /.conkyrc
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------------------------------------------------------------
void readfile(char *inputfilename, char *outputfilename) {	
	FILE *fileInput = fopen(inputfilename, "r");	
	if (fileInput == NULL)
		exit(EXIT_FAILURE);

	printf("inputfilename:  %s\n", inputfilename);

	// Read colors from input file line by line to array
	int i = 0;
    char line[255];
    char word[16][24];
	while (fgets(line, sizeof(line), fileInput) != NULL) {
		sscanf(line, "%s", word[i]);
    	i++;
	}    
	fclose(fileInput);

	// Rewrite colors in output file
	FILE *fileOutput = fopen(outputfilename, "r+");
	if (fileOutput == NULL)
		exit(EXIT_FAILURE);

	printf("outputfilename: %s\n", outputfilename);	
	int fpos;
	while (fgets(line, sizeof(line), fileOutput) != NULL) {
		if(strstr(line, "default_color = '") != NULL) {		   
			fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[1]);
		} 
		if(strstr(line, "default_outline_color = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[1]);
		}
		if(strstr(line, "default_shade_color = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[1]);
		}
		if(strstr(line, "color1 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[1]);
		}
		if(strstr(line, "color2 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[2]);
		}
		if(strstr(line, "color3 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[3]);
		}
		if(strstr(line, "color4 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[4]);
		}
		if(strstr(line, "color5 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[5]);
		}
		if(strstr(line, "color6 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[6]);
		}
		if(strstr(line, "color7 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[7]);
		}
		if(strstr(line, "color8 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[8]);
		}
		if(strstr(line, "color9 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[9]);
		}
		if(strstr(line, "color10 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[10]);
		}
		if(strstr(line, "color11 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[11]);
		}
		if(strstr(line, "color12 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[12]);
		}
		if(strstr(line, "color13 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[13]);
		}
		if(strstr(line, "color14 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[14]);
		}
		if(strstr(line, "color15 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[15]);
		}
		if(strstr(line, "color16 = '") != NULL) {
		    fpos = ftell(fileOutput) - 10;
			fseek(fileOutput, fpos, SEEK_SET);			
			fprintf(fileOutput, "%s',\n", word[16]);
		}
	}
        
    fclose(fileOutput);    
}
//----------------------------------------------------------------------

int main(int argc, char **argv) {
	if (argc == 1) {
		printf("Program changing colors in file .conkyrc\n");
		printf(" Usage: ./conkycolors InputFile OutputFile\n");	
	} else if (argc == 3) {
		readfile(argv[1], argv[2]);
	}
	return 0;
}

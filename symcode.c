#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char symCode[8] = "symantec";

char *removeSpace(char *str)
{
    /* Remove leading white space */
    while(isspace((unsigned char)*str)) str++;
    /* string contain all spaces */
    if(!(*str))
        return str;

  /* Remove trailing white space*/
  char *last;
  last = str + strlen(str) - 1;
  while(last > str && isspace((unsigned char)*last)) last--;

  /* end the string */
  *(last+1) = 0;
  return str;
}

void main(int argc, char **argv)
{
    FILE * fp, *fpOut;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    if(argc != 2)
    {
        printf("Usage: %s inputFilePath\n",argv[0]);
        return;
    }

    fp = fopen(argv[1], "r");
    fpOut = fopen("output.txt", "w+");

    if (fp == NULL)
    {
        printf("Input File Open failed.. Please check the file\n");
        if(fpOut != NULL)
            fclose(fpOut);
        return;
    }

    if (fpOut == NULL)
    {
        printf("Not able to create an output file in the current directory");
        fclose(fp);
        return;
    }

    /* Read line by line */
    while ((read = getline(&line, &len, fp)) != -1) {
        int loop = 1;
        char prevPres;

        /*Remove Leading and trailing spaces*/
        char *str = removeSpace(line);
        int orgStrlen = strlen(str);
        if(orgStrlen == 0)
        {
            fprintf(fpOut, "\n");
            continue;
        }

        while((*str) != 0)
        {
            if((loop % 3) == 1)
            {
                fprintf(fpOut, "%c",symCode[(str[0] & 0xE0)>>5]);
                fprintf(fpOut, "%c",symCode[(str[0] & 0x1C)>>2]);
                prevPres = (str[0] & 0x03) << 1;
            }
            else if (loop % 3 == 2)
            {
                fprintf(fpOut, "%c",symCode[prevPres | (str[0] & 0x80)>>7]);
                fprintf(fpOut, "%c",symCode[(str[0] & 0x70)>>4]);
                fprintf(fpOut, "%c",symCode[(str[0] & 0x0E)>>1]);
                prevPres = (str[0] & 0x01) << 2;
            }
            else if (loop % 3 == 0)
            {
                fprintf(fpOut,"%c",symCode[prevPres | (str[0] & 0xC0)>>6]);
                fprintf(fpOut,"%c",symCode[(str[0] & 0x38)>>3]);
                fprintf(fpOut,"%c",symCode[str[0] & 0x07]);
            }
            loop++;
            str++;
        }

        if(orgStrlen % 3 == 2)
        {
            fprintf(fpOut, "%c$$",symCode[prevPres]);
        }
        else if (orgStrlen % 3 == 1)
        {
            fprintf(fpOut,"%c$$$$$",symCode[prevPres]);
        }
        fprintf(fpOut,"\n");
    }

    fclose(fp);
    fclose(fpOut);
    printf("Output successfully written to output.txt\n");
}

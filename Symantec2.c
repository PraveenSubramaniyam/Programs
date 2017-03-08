#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char symCode[8] = "symantec";
char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

void main()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char *pch;

    fp = fopen("symcode-in.txt", "r");
    if (fp == NULL)
        return;

    while ((read = getline(&line, &len, fp)) != -1) {
        int i = 1;
        char prevPres;
        int strl = 0;
        //printf("%s",line);
        char *str = trimwhitespace(line);

        if(strlen(str) == 0)
        {
            printf("\n");
            continue;
        }
        char *trimstr= str;
        printf("%s\n",str);
    }

    fclose(fp);
}

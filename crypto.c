#include <stdio.h>
#include <string.h>

void main()
{
  int loop;
  char arr[1024];
  char freq[26] = {0};
  char key[27] = {0};

  memset(arr,0,sizeof(arr));
  printf("Enter the Cipher Text <Only in Capital Letters MaxLength:1023>\n");
  
  fgets(arr, 1023, stdin);
  //printf("Your input: %s", file);
  for(loop = 0;loop<strlen(arr); loop++)
  {
    freq[arr[loop]-65]++;
  }

  printf("Frequency Matrix\n\n");
  for (loop=0;loop<26;loop++)
  {
    printf("%c: %d\n",(65+loop),freq[loop]);
  }
  
  printf("Enter the Key <Key is of 26 Characters.. Character at each position will replace the appropriate character in English alphabets\n");  
  fgets(key,27,stdin);
  
  printf("\nThe Cipher Text is %s\n",arr);
  printf("The Key is %s\n",key);
  for(loop=0;loop<strlen(arr);loop++)
  {
    arr[loop] = key[arr[loop]-65];
  }
  
  printf("The Plain Text is :%s\n\n",arr);
}


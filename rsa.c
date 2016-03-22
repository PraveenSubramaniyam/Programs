#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rsa.h"


void myPopen(char *cmd, char *output,size_t n)
{
  char tmp[512];
  FILE *fp;
  /* Open the command for reading. */
  fp = popen(cmd, "r");
  if (fp == NULL) {
    printf("Failed to run command %s\n",cmd);
    exit(1);
  }
  memset(tmp,0,sizeof(tmp));
  memset(output,0,n);
  /* Read the output a line at a time - output it. */
  while (fgets(tmp,sizeof(tmp)-1, fp) != NULL)
  {
    trimSlash(tmp);
    strncat(output,tmp,n-strlen(output)-1);
  }
  pclose(fp);
}

void divide(myInteger *num1 , myInteger *num2, myInteger *result,myInteger *remainder)
{
  myInteger r ;
  myInteger tmp;
  int i = 0, j = 0;
  memsetMyIntegertoZero(result);
  memsetMyIntegertoZero(&r);
  memsetMyIntegertoZero(&tmp);

  result->noOfDigits = num1->noOfDigits;
  for(i = num1->noOfDigits - 1; i>=0;i--)
  {
    leftshift(&r , 1);
    r.digits[0] = num1->digits[i];
    result->digits[i] = 0;
    stripZero(&r);
    while(ComparemyInteger(r,*num2) == 1 || ComparemyInteger(r,*num2) == -1)
    {
      result->digits[i]++;
      subtract(&r,0,num2,0,&tmp,0,0);
      stripZero(&tmp);
      r = tmp;
    }
    *remainder = r;
  }
  stripZero(remainder);
  stripZero(result);
}


void add(myInteger num1, int num1Count, myInteger num2,int num2count, myInteger *result,int resultcount,int carry)
{
  if(num1Count < num1.noOfDigits && num1Count < num2.noOfDigits)
  {
    int iTemp = num1.digits[num1Count] + num2.digits[num2count] + carry;
    result->digits[resultcount] = iTemp %10;
    result->noOfDigits = resultcount+1;
    carry = iTemp / 10;
    add(num1,num1Count + 1, num2, num2count + 1, result, resultcount + 1, carry);
  }
  else if(num2count < num2.noOfDigits)
  {
    result->digits[resultcount] = num2.digits[num2count] + carry;
    result->noOfDigits = resultcount+1;
    add(num1,num1Count, num2, num2count + 1, result, resultcount + 1, 0);
  }
  else if(num1Count < num1.noOfDigits)
  {
    result->digits[resultcount] = num1.digits[num1Count] + carry;
    result->noOfDigits = resultcount+1;
    add(num1,num1Count + 1, num2 , num2count, result, resultcount + 1, 0);
  }
  else if(carry != 0)
  {
    result->digits[resultcount] = carry;
    result->noOfDigits = resultcount + 1;
  }
}


void stripZero(myInteger *num)
{
  int loop = num->noOfDigits - 1 ;
  while(loop >=0)
  {
    if(num->digits[loop] != 0)
       break;
    num->noOfDigits--;
    loop --;
  }
  if(num->noOfDigits == 0){
    num->digits[loop] = 0;
    num->noOfDigits = 1;
  }
}

void leftshift(myInteger *num, int count)
{
  int i = 0;
  for (i=num->noOfDigits - 1; i>=0; i--)
    num->digits[i+count] = num->digits[i];

  for (i=0; i<count; i++)
    num->digits[i] = 0;

  num->noOfDigits += count;
  stripZero(num);
}

void generateMyInteger(myInteger *num, char *str)
{
  num->noOfDigits = strlen(str);
  int loop = num->noOfDigits -1, loopVar = 0;

  while(loop >= 0)
  {
    num->digits[loopVar] = str[loop] - '0';
    loop--;
    loopVar++;
  }
}

void generateOrgInteger(myInteger *myInt, char *src)
{
  int loop = myInt->noOfDigits - 1,loopVar =0;
  while (loop >=0)
  {
    src[loopVar] = myInt->digits[loop] + '0';
    loop-=1;
    loopVar+=1;
  }
}

void memsetMyIntegertoZero(myInteger *myInt)
{
  memset(myInt,0,sizeof(myInteger));
  myInt->noOfDigits = 1;
  myInt->digits[0] = 0;
}

void printmyInteger(myInteger intVal)
{
  int i = intVal.noOfDigits -1;
  while(i >=0)
  {
    printf("%d",intVal.digits[i]);
    i--;
  }
  printf("\n");
}

int ComparemyInteger(myInteger int1, myInteger int2)
{
  int i = 0;
  if(int1.noOfDigits < int2.noOfDigits){
    return 0;
  }
  else if(int1.noOfDigits > int2.noOfDigits){
    return 1;
  }
  else {
    for(i = int1.noOfDigits -1; i >= 0; i--){
      if(int1.digits[i] > int2.digits[i]){
        return 1;
      }
      else if(int1.digits[i] < int2.digits[i]){
        return 0;
      }
    }
  }
  return -1;
}

void multiply(myInteger *num1, myInteger *num2 , myInteger *result)
{
  myInteger r ;
  myInteger tmp;
  memsetMyIntegertoZero(result);
  memsetMyIntegertoZero(&tmp);
  int i = 0, j = 0;
  r = *num1;

  for(i = 0; i <= num2->noOfDigits-1; i++){
    for(j = 1; j <= num2->digits[i];j++){
      add(*result,0,r,0,&tmp,0,0);
      *result = tmp;
    }
    leftshift(&r , 1);
  }
  stripZero(result);
}

/* Function to remove slash and new line from the string */
void trimSlash(char *source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != '\\' && *i != '\n')
      i++;
  }
  *i = 0;
}



void subtract(myInteger *num1, int num1Count, myInteger *num2, int num2Count, myInteger *result, int resCount, int borrow)
{
  if(ComparemyInteger(*num1,*num2) == 0){
    printf("a value should be greater");
  }
  if(num1Count < num1->noOfDigits && num1Count < num2->noOfDigits){
    int op1 = num1->digits[num1Count] - borrow;
    int op2 = num2->digits[num2Count];
    if(op2 > op1)
    {
      op1 = op1 + 10;
      borrow = 1;
    }
    else
      borrow = 0;
    result->digits[resCount] = op1 - op2;
    result->noOfDigits = resCount+1;
    subtract(num1,num1Count + 1,num2,num2Count + 1, result, resCount + 1,borrow);
  }
  else if(num1Count < num1->noOfDigits){
    int op1 = num1->digits[num1Count] - borrow;
    result->digits[resCount] = op1;
    result->noOfDigits = resCount+1;
    borrow = 0;
    subtract(num1,num1Count + 1,num2,num2Count,result,resCount + 1, 0);
  }
  stripZero(result);
}

/* Function cuberoot
 * Input: String which contains the value for which cube root needs to be calculated
 * Output: Structure myInteger which contains the cube root value
 *       The function is used to find the cube root of the number., which works using
 *       divide and conquer method.
 */
myInteger cuberoot(char *num)
{
  int loop;
  myInteger tempNum;
  int cubeRootLen;
  myInteger lowerNum,upperNum;
  myInteger numTwo;
  myInteger cubeRootVal;

  memsetMyIntegertoZero(&tempNum);
  generateMyInteger(&tempNum,num);
  cubeRootLen = (tempNum.noOfDigits - 1) / 3 + 1;
  char lowerbound[cubeRootLen+1], upperbound[cubeRootLen +2];
  lowerbound[0] = '1';
  upperbound[0] = '1';
  for(loop = 1; loop < cubeRootLen; loop++) {
    lowerbound[loop] = '0';
    upperbound[loop] = '0';
  }

  upperbound[cubeRootLen] = '0';
  upperbound[cubeRootLen + 1] = '\0';
  lowerbound[cubeRootLen] = '\0';

  generateMyInteger(&lowerNum, lowerbound);
  generateMyInteger(&upperNum, upperbound);
  generateMyInteger(&numTwo,"2");

  while(1) {
      myInteger tempadd;
      myInteger temp,remainder;
      add(lowerNum,0,upperNum,0,&tempadd,0,0);
      divide(&tempadd,&numTwo,&temp,&remainder);
      myInteger tempmul;
      multiply(&temp,&temp,&tempmul);
      myInteger tempcube;
      multiply(&temp, &tempmul, &tempcube);
      if(ComparemyInteger(tempcube,tempNum) == -1) {
        cubeRootVal = temp;
        break;
      } else if(ComparemyInteger(tempcube,tempNum) == 1){
        upperNum = temp;
      } else {
        lowerNum = temp;
      }

    }
  return cubeRootVal;
}


void main()
{
  FILE *fp;
  char RSAcipherHex[1024];
  char RSAcipherDec[1024];
  char RSAplainDec[1024];
  char RSAplainHex[1024];
  char AESplainText[1024];
  char temp[1024];
  myInteger cubeRootVal;


  /* Converting lower case in Hex Num to Upper since bc (Basic Calculator) accepts only upper Case */
  memset(temp,0,sizeof(temp));
  snprintf(temp,sizeof(temp)-1,"echo %s | tr '[:lower:]' '[:upper:]'","c0eacf32dc0492464d9616fefc3d01f56589a137781bf6cf56784dea1c44ef52d61b1025655f370eb78646716f93e0a5");
  myPopen(temp,RSAcipherHex,sizeof(RSAcipherHex));

  printf("/******************** CUBE ROOT ATTACK ***********************/\n\n");
  printf("RSA CipherText Hex: %s\n",RSAcipherHex);

  /* Converting Hexadecimal Number to Decimal Number using bc utility */
  memset(temp,0,sizeof(temp));
  snprintf(temp,sizeof(temp)-1,"echo \"ibase=16; %s\"|bc",RSAcipherHex);
  myPopen(temp,RSAcipherDec,sizeof(RSAcipherDec));
  printf("RSA CipherText Dec: %s\n",RSAcipherDec);

  /* Calculating the cube root of the Decimal Number which is the RSA plain text*/
  cubeRootVal = cuberoot(RSAcipherDec);
  memset(RSAplainDec,0,sizeof(RSAplainDec));
  generateOrgInteger(&cubeRootVal,RSAplainDec);
  printf("CubeRoot of Cipher: %s\n",RSAplainDec);

  /* Converting Decimal to Hexadecimal Number to provide to AES decryption*/
  memset(RSAplainHex,0,sizeof(RSAplainHex));
  memset(temp,0,sizeof(temp));
  snprintf(temp,sizeof(temp)-1,"echo \"obase=16; %s\"|bc",RSAplainDec);
  myPopen(temp,RSAplainHex,sizeof(RSAplainHex));
  printf("AES Key Hex       : %s\n",RSAplainHex);

  /* Decrypting AES cipher text using AES Key */
  memset(temp,0,sizeof(temp));
  snprintf(temp,sizeof(temp)-1,"echo \"fd0b934c23288975648cd1d03ed3c5e2\" | xxd -r -ps | openssl aes-128-ecb -d -K %s -nopad",RSAplainHex);
  myPopen(temp,AESplainText,sizeof(AESplainText));
  printf("AES plain Text    : %s\n",AESplainText);
  printf("\n/********************    END     ***********************/\n\n");

}

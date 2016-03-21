#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1024
typedef struct {
  char digits[MAXLEN];
  int noOfDigits;
}myInteger;

void makezero(myInteger *a);
int leftshift(myInteger *a, int b);
void RemoveMSBZero(myInteger *a);
void add(myInteger * a,int aCounter, myInteger *b,int bCounter, myInteger *c,int cCounter,int carry);
void divide(myInteger *a , myInteger *b, myInteger *c,myInteger *m);
int ComparemyInteger(myInteger * a, myInteger *b);
int  subtract(myInteger *a, int aCounter , myInteger *b, int bCounter,myInteger *c, int cCounter , int borrow);

void add(myInteger * a,int aCounter, myInteger *b,int bCounter, myInteger *c,int cCounter,int carry)
{
  if(aCounter < a->noOfDigits && aCounter < b->noOfDigits){
			int iTemp = a->digits[aCounter] + b->digits[bCounter] + carry;
			c->digits[cCounter] = iTemp %10;
			c->noOfDigits = cCounter+1;
			carry = iTemp / 10;
			add(a,aCounter + 1, b , bCounter + 1, c, cCounter + 1, carry);
		}
		else if(bCounter < b->noOfDigits){
			c->digits[cCounter] = b->digits[bCounter] + carry;
			c->noOfDigits = cCounter+1;
			add(a,aCounter, b , bCounter + 1, c, cCounter + 1, 0);
		}
		else if(aCounter < a->noOfDigits){
			c->digits[cCounter] = a->digits[aCounter] + carry;
			c->noOfDigits = cCounter+1;
			add(a,aCounter + 1, b , bCounter, c, cCounter + 1, 0);
		}
		else if(carry != 0){
			c->digits[cCounter] = carry;
			c->noOfDigits = cCounter + 1;
		}
}

void divide(myInteger *a , myInteger *b, myInteger *c,myInteger *m)
{
	myInteger r ;
	myInteger tmp;
	int i = 0, j = 0;
	makezero(c);
	makezero(&r);
	makezero(&tmp);

	c->noOfDigits = a->noOfDigits;
	for(i = a->noOfDigits - 1; i>=0;i--){
		leftshift(&r , 1);

		//printmyInteger(&r);
		r.digits[0] = a->digits[i];
		c->digits[i] = 0;
		RemoveMSBZero(&r);
		while(ComparemyInteger(&r,b) == 1 || ComparemyInteger(&r,b) == -1){
			c->digits[i]++;
			subtract(&r,0,b,0,&tmp,0,0);
			RemoveMSBZero(&tmp);
			r = tmp;
			//c->noOfDigits = i;
			//printmyInteger(&tmp);
		}

		*m = r;
	}
	RemoveMSBZero(m);
	RemoveMSBZero(c);
}

void RemoveMSBZero(myInteger *a)
{
	int i = 0;
	int length = a->noOfDigits;
	for(i = a->noOfDigits - 1 ; i >=0;i--){
		if(a->digits[i] == 0){
			a->noOfDigits--;
		}
		else
			break;
	}
	if(a->noOfDigits == 0){
		a->digits[i] = 0;
		a->noOfDigits = 1;
	}
}

int leftshift(myInteger *a, int b){
	int i = 0;
	for (i=a->noOfDigits - 1; i>=0; i--)
		a->digits[i+b] = a->digits[i];

	for (i=0; i<b; i++)
		a->digits[i] = 0;

	a->noOfDigits += b;
	RemoveMSBZero(a);
}

void generateMyInteger(myInteger *a,char *b)
{
	int i = 0, j = 0;
	a->noOfDigits = strlen(b);

	for(i = a->noOfDigits - 1,j = 0 ; i >=0; i--,j++){
		a->digits[j] = b[i] - '0';
	}
}

void generateOrgInteger(myInteger *myInt, char *src)
{
  int loop,loopVar;
  for(loop = myInt->noOfDigits - 1,loopVar = 0 ; loop >=0; loop--,loopVar++){
    src[loopVar] = myInt->digits[loop] + '0';
  }
}

void makezero(myInteger *a)
{
	memset(a,0x00,sizeof(myInteger));
	a->noOfDigits = 1;
	a->digits[0] = 0;
}

void printmyInteger(myInteger *a)
{
	int i = 0;
	//printf("%d\r\n",a->length);

	for(i = a->noOfDigits -1; i >=0 ; i--){
		printf("%d",a->digits[i]);
	}
	printf("\r\n");
}

int ComparemyInteger(myInteger * a, myInteger *b)
{
  int i =0;
  if(a->noOfDigits > b->noOfDigits){
    return 1;
  }
  else if(a->noOfDigits < b->noOfDigits){
    return 0;
  }
  else {
    for(i = a->noOfDigits -1; i >= 0; i--){
      if(a->digits[i] > b->digits[i]){
        return 1;
      }
      else if(a->digits[i] < b->digits[i]){
        return 0;
      }
    }
  }
  return -1;
}

void multiply(myInteger * a, myInteger *b , myInteger *c)
{

	myInteger r ;
		myInteger tmp;
		makezero(c);
		makezero(&tmp);
		int i = 0, j = 0;
		r = *a;
		for(i = 0; i <= b->noOfDigits-1; i++){
			for(j = 1; j <= b->digits[i];j++){
				add(c,0,&r,0,&tmp,0,0);
				*c = tmp;
				//strcpy(c->number,tmp.number);
				//c->length += tmp.length;

			}

			leftshift(&r , 1);
		}
		RemoveMSBZero(c);


}

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

int  subtract(myInteger *a, int aCounter , myInteger *b, int bCounter,myInteger *c, int cCounter , int borrow){
	if(ComparemyInteger(a,b) == 0){
		printf("a value should be greater");
		return 0;
	}
	if(aCounter < a->noOfDigits && aCounter < b->noOfDigits){
		int op1 = a->digits[aCounter] - borrow;
		int op2 = b->digits[bCounter];
		if(op2 > op1)
		{
			op1 = op1 + 10;
			borrow = 1;
		}
		else
			borrow = 0;
		c->digits[cCounter] = op1 - op2;
		c->noOfDigits = cCounter+1;
		subtract(a,aCounter + 1, b , bCounter + 1, c, cCounter + 1,borrow);
	}
	else if(aCounter < a->noOfDigits){
		int op1 = a->digits[aCounter] - borrow;
		c->digits[cCounter] = op1;
		c->noOfDigits = cCounter+1;
		borrow = 0;
		subtract(a,aCounter + 1, b , bCounter, c, cCounter + 1, 0);
	}
	RemoveMSBZero(c);
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
  int newlength;
  myInteger m;
  int loop;



  memset(temp,0,sizeof(temp));
  snprintf(temp,sizeof(temp)-1,"echo %s | tr '[:lower:]' '[:upper:]'","c0eacf32dc0492464d9616fefc3d01f56589a137781bf6cf56784dea1c44ef52d61b1025655f370eb78646716f93e0a5");

  myPopen(temp,RSAcipherHex,sizeof(RSAcipherHex));

  printf("/******************** CUBE ROOT ATTACK ***********************/\n\n");
  printf("RSA CipherText Hex: %s\n",RSAcipherHex);
  memset(temp,0,sizeof(temp));
  snprintf(temp,sizeof(temp)-1,"echo \"ibase=16; %s\"|bc",RSAcipherHex);

  myPopen(temp,RSAcipherDec,sizeof(RSAcipherDec));
  printf("RSA CipherText Dec: %s",RSAcipherDec);
  printmyInteger(&m);
  makezero(&m);
  generateMyInteger(&m,RSAcipherDec);
  newlength = (m.noOfDigits - 1) / 3 + 1;
  char lowerbound[newlength+1], upperbound[newlength +2];
  lowerbound[0] = '1';
  upperbound[0] = '1';
  for(loop = 1; loop < newlength; loop++) {
    lowerbound[loop] = '0';
    upperbound[loop] = '0';
  }

  upperbound[newlength] = '0';
  upperbound[newlength + 1] = '\0';
  lowerbound[newlength] = '\0';
  myInteger lb,ub;
  generateMyInteger(&lb, lowerbound);
  generateMyInteger(&ub, upperbound);
  myInteger two;
  generateMyInteger(&two,"2");
  myInteger message;

  while(1) {
      myInteger tempadd;
      myInteger temp,remainder;
      add(&lb,0,&ub,0,&tempadd,0,0);
      divide(&tempadd,&two,&temp,&remainder);
      myInteger tempmul;
      multiply(&temp,&temp,&tempmul);
      myInteger tempcube;
      multiply(&temp, &tempmul, &tempcube);
      if(ComparemyInteger(&tempcube,&m) == -1) {
        message = temp;
        //exit(0);
        break;
      } else if(ComparemyInteger(&tempcube,&m) == 1){
        ub = temp;
      } else {
        lb = temp;
      }

    }

     memset(RSAplainDec,0,sizeof(RSAplainDec));
     generateOrgInteger(&message,RSAplainDec);

     printf("CubeRoot of Cipher: %s\n",RSAplainDec);
     memset(RSAplainHex,0,sizeof(RSAplainHex));

     memset(temp,0,sizeof(temp));
     snprintf(temp,sizeof(temp)-1,"echo \"obase=16; %s\"|bc",RSAplainDec);
     myPopen(temp,RSAplainHex,sizeof(RSAplainHex));
     printf("AES Key Hex       : %s\n",RSAplainHex);


     memset(temp,0,sizeof(temp));
     snprintf(temp,sizeof(temp)-1,"echo \"fd0b934c23288975648cd1d03ed3c5e2\" | xxd -r -ps | openssl aes-128-ecb -d -K %s -nopad",RSAplainHex);
     myPopen(temp,AESplainText,sizeof(AESplainText));
     printf("AES plain Text    : %s\n",AESplainText);
     printf("\n/********************    END     ***********************/\n\n");

}

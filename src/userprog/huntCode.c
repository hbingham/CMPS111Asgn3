#include "userprog/huntCode.h"
#include <debug.h>
#include <inttypes.h>
#include <round.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Decrements esp by 4 and pushes an address after
void decPushAddr(void **esp, void **saveAddr)
{
//	printf("Base Address: 0x%08x\n", *saveAddr);
	*esp-=4;
	*((void**) *esp) =  (*esp + 4);
}


void decPushInt(void **esp, int pushNum)
{
	*esp-=4;
	*((int*) *esp) = pushNum;
}


void setStack(const char *cmdline, void **esp)
{
    int argCount = 1;
    void* argAddys[argCount];
//    printf("Base Address: 0x%08x\n", *esp);
//Get length of cmdline argument, add 1 for empty space then
//decrement esp by that amount
    int len = strlen(cmdline)+1;
    *esp -= len;
    memcpy(*esp, cmdline,len);
    argAddys[0] = *esp;
//move esp to next memory spot that is a divisor of 4
    *esp = (void*) ((unsigned int) (*esp) & 0xfffffffc);
//move esp down 4 more for a null sentinel
    *esp-=4;
    *((uint32_t*) *esp) = 0;
//dec esp by size of address of first entry
//then copy the address there
    *esp-=4;
    *((void**) *esp) = (argAddys[0]);
//similar idea to last decrement
    decPushAddr(esp, esp);
//Decrement 4 and then place argcount
     decPushInt(esp, argCount);
//Fake return address
    *esp -=4;
    *((int*) *esp) = 0;
    *esp = (void*) ((unsigned int) (*esp) & 0xfffffffc);
}

int getArgc(char *cmdline)
{
   char *token, *save_ptr;
   int count = 0;
   for (token = strtok_r (cmdline, " ", &save_ptr); token != NULL; token = strtok_r (NULL, " ", &save_ptr))
{
      count++;
}
   return count;
}



void parseArgs(char *cmdline, void* retArgs[])
{
   char *token, *save_ptr;
   int count = 0;
   char ary[2];
   for (token = strtok_r (cmdline, " ", &save_ptr); token != NULL; token = strtok_r (NULL, " ", &save_ptr))
{
     count++;
//     printf ("'%s'\n", token);
     ary[count] = token;
     printf ("'%s'\n", ary[count]);
}

}










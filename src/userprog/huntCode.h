
//#ifndef USERPROG_PROCESS_H
//#define USERPROG_PROCESS_H

#include "threads/thread.h"
void decPushInt(void **esp, int pushNum);
void decPushAddr(void **esp, void **saveAddr);
void setStack(const char *cmdline, void **esp);
void parseArgs(char *cmdline, void* retArgs[]);
int getArgc(char *cmdline);
//#endif /* userprog/process.h */


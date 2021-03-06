#ifndef MENU_H
#define MENU_H

#include "jtime.h"

/* Set Input Prompt */
int SetPrompt(char *p);

/* add cmd to menu */
int MenuConfig(char *cmd, char *desc, int (*handler)(int argc, char *argv[]));

/* Menu Engine Execute */
int ExecuteMenu();

#endif

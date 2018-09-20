// Larbin
// Sebastien Ailleret
// 18-11-99 -> 21-05-01

#ifndef TEXT_H
#define TEXT_H

#include "gstring.h"

char lowerCase (char a);

int  startWith (char *a, char *b);

int robotsMatch (char *a, char *b);

int is_startWithIgnoreCase(char *amin, char *b);

int  endWith (char *a, char *b);


int endWithIgnoreCase(char *amin, char *b);


int  caseContain (char *a, char *b);

char *newString (char *arg);

char *readfile (int fds);

int  matchPrivExt(char *file);

int  matchContentType(char *ct);

#endif // TEXT_H

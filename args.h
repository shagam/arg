
//#include <iostream>
#include <string>
// bool isPrefix_(string const& s1, string const&s2);
#include <stdio.h>
#include <string.h>

static const char* STRING = "string";
static const char* INT = "int";
static const char* BOOL = "bool";

extern void utest ();

extern int isPrefix(char const * p, char const * q);

extern int isContain (char const *p, char c);

extern int bool_exist (char const * name, int argc, const char * const argv[], char const * description);

extern int search_String_arg (char const * param_name, int argc, char * argv[], char * res_value, char const * description) ;

extern int search_int_value (char const * param_name, int argc, const char * const argv[], char const * description);

extern int split (char const * name_value, char * name, char * value);

extern void args_report ();

int getCPUCount();
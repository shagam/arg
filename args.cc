

/*

The MIT License (MIT)

Copyright (c) <2012-2016> eli.shagam@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy of this software
and associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished 
to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */



#include <iostream>
#include "args.h"
#include <string>
#include <map>
//#include <string.h>

using namespace std;

//static char * s_argv[];

const int SIZ = 20;

std::map<string,string> param_map;
std::map<string,string> description_map;

int isPrefix(char const * prefix, char const * str)
{
    int p_len = strlen (prefix);
    int q_len = strlen (str);
    
    if (p_len > q_len)
        return 0;
                
    while (*prefix && *str) {
        if (*prefix++ != *str++)
            return 0;
    }
    return 1;
}

int isContain (char const *p, char c) {

    while (*p) {
        if (*p++ == c)
            return 1;
    }
    return 0;    
}

int isNumeric (char* str) {
    
    for (int n = 0; n < sizeof(str) - 1; n++) {
        if (str[n] == 0)
            return 1;
        if (! isdigit (str[n])) {
            fprintf (stderr, "\nbad numeric value=%s %s", str, "\n");            
            exit (1);
        }
    }
    return 1;
}

int bool_exist (char const * name, int argc, const char * const argv[], char const * description) {
//        if (s_args == null)
//            s_args = args;
    param_map.insert(std::pair<string,string>(name,BOOL));
    description_map.insert(std::pair<string,string>(name,description));    
    for (int n = 0; n < argc; n++) {
        if (isContain(argv[n],'='))
            continue;    
        if (isPrefix (argv[n], name)) {           
            return 1;
        }
    }
    return 0;
}

int split (char const * name_value, char * name, char * value) {
    int len = strlen (name_value);
    for (int n = 0; n < len; n++) {
        if (*(name_value + n) == '=') {
            if (len - n - 1 > 0) {
                memcpy (name, name_value, n);
                memcpy (value, name_value + n + 1, len - n - 1);
            }
            else {
                name[0] = 0;
                value[0] = 0;
            }
                
            return 1;
        }
    }
    return 0;    
    
}

int search_String_arg (char const * param_name, int argc, const char * const argv[], char * res_value, char const * description) {
    param_map.insert(std::pair<string,string>(param_name,STRING));
    description_map.insert(std::pair<string,string>(param_name,description));     
    for (int n = 0; n < argc; n++) {
        if (isContain (argv[n], '=')) {
            char name [SIZ] = {0};
            char value [SIZ] = {0};    

            int res = split (argv[n], name, value);
            if (res = 0)
                continue;

            int nameLen = strlen(name);
            int valueLen = strlen (value);

            if (nameLen == 0 || valueLen == 0)
                continue;

            if ( ! isPrefix(name, param_name))
                continue;
            //fprintf (stderr, "\nsearch_value=%s\n", value); 
            strcpy (res_value, value);            
            return 1;
        }
    }
    return 0;
}

int search_int_value (char const * param_name, int argc, const char * const argv[], char const * description) {
    
    char res_value [SIZ] = {0};
    int res = search_String_arg (param_name, argc, argv, res_value, description);
    param_map.erase (param_name);
    param_map.insert (std::pair<string,string>(param_name,INT));
    description_map.erase (param_name);
    description_map.insert(std::pair<string,string>(param_name,description));     
    
    if (res == 0)
        return -1;

    if (! isNumeric(res_value)) {
        //fprintf (stderr, "\nbad numeric value \n");
        exit (1);
    }
    int value = atoi(res_value);    
    return value;
}

void args_report () {
    char report [1000] = {0};
    int ptr = 0;
    std::cerr << "\nparams:  ";
    for(auto elem : param_map) {
        const int GAP = 15;
        int len;
     
        len = strlen (elem.first.c_str());
        if (elem.second == BOOL) {
            printf ("\n%s(%s)  ", elem.first.c_str(), elem.second.c_str());
            len += 2;
        }
        else {
            printf ("\n%s=<%s>", elem.first.c_str(), elem.second.c_str());
        }
        if (len < GAP) {
            for (int n = 0; n < GAP - len; n++)
                printf (" ");
        }
        
        auto search = description_map.find (elem.first);
        printf ("      %s", search->second.c_str());
        
    }
    std::cerr << "\n";
}

void utest () {
    
    int res = isContain ("aaa=bbbb", '=');
//    if (res)
//        fprintf (stderr, "contain\n");
    
    res = isPrefix ("aaa", "aaattt\n");
    if (res)
        fprintf (stderr, "prefix\n");
    
    
    
    //const int SIZ = 20;
    char name_value [] = "param=value";
    char name [SIZ];
    char value [SIZ];    
    
    res = split (name_value, name, value);
    int nameLen = strlen(name);
    int valueLen = strlen (value);
    
    if (res && valueLen > 0) {
        fprintf (stderr, "\nSplit   in:%s  name=%s %d   value=%s %d\n", name_value, name, nameLen, value, valueLen);
    }
    
    static const char *const days[] = { "mon", "tue", "wed", "thur",
                                       "fri", "sat", "sun" };
      
    static const char *const argv[] = {"nolock","pppp=4","cccc=8","param=123"};
    char str_result [SIZ] = {0};

    int argc = 1;
    res = search_String_arg ("ppppp", sizeof(argv), argv, str_result, "");
    fprintf (stderr, "\nvalue_str=%s   stat=%d\n", str_result, res);
    res = search_int_value ("ppppp", sizeof(argv), argv,"");
    fprintf (stderr, "\nvalue_int=%d\n", res);

    if (bool_exist ("nolock", sizeof(argv), argv,""))
        fprintf (stderr, "\nnolock__\n");        
}


int getCPUCount() {
 cpu_set_t cs;
 CPU_ZERO(&cs);
 sched_getaffinity(0, sizeof(cs), &cs);

 int count = 0;
 for (int i = 0; i < 20; i++)
 {
  if (CPU_ISSET(i, &cs))
   count++;
 }
 return count;
}
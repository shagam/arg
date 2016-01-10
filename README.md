# arg
Command line argumet parser for java and cpp applications


README v0.0 / 01 JAN 2016

# Project name:  arg

## Introduction

java and c++  line argumet parsers  Args.java  and args.cc args.h
Simple to use, no need to define parameters

The parser supports 3 types of arguments

integer     example:   threads=8
string      example:   file=/proc/cpuinfo
boolean     example:   verbose


## Usage

calling sequence
java -jar overgead.jar   string_value=/vasr/js/java.log0   integerValue=1000  booleanValue
java -jar <programName>  <stringName>=<strngValue>    <integerName>=<nuericValue>   <booleanName>

Argumets are seperated by spaces, no spaces between argument name and argument value

java and c parsing is very much the same.

No need to type the full arg_name, Argument prefix is  enogh as long as it is unique.
(prefix of one argument only)

        // boolean argument
        boolean copy = Args.bool_exist ("copy", args, "test==copy_memory (measure bandwidth)");
        assert copy;


        // string argument
        String file = Args.search_String_arg ("file", args, "file name");
        assert file != null;


        // integer argument 
        int threadCount;
        int threads = Args.search_int_value("threds", args, "number of concurrent threads");
        if (threads != Integer.MAX_VALUE)
            threadCount = threads;
        else
            threadCount = Runtime.getRuntime().availableProcessors();


        // print help and sanity check 
        Args.showAndVerify (true);


Argument help is created automatically
eli@l0:/$ java -jar ~/nb/overhead/dist/overhead.jar   tree  threa=8
optional args:   
threads=integer             number of concurrent threads
arrays=integer              number of arrays, accessed by threads
size=integer                size of each array/tree
printFilter=integer          print filter (fraction of loops that print)
tree(bool)                  test==tree
alloc(bool)                 test==alloc
noLock(bool)                tree no lock (Each thread has private array)
queue(bool)                 test==queue
hash(bool)                  test==hash
copy(bool)                  test==copy_memory (measure bandwidth)
prime(bool)                 test==prime
loops(bool)                 test==loops
verbose(bool)               print test param during run

actual args:  [tree, thr=8, ]


## Contributing


## Help              for help and bugs report, please email eli.shagam@gmail.com

## Installation      none

### Requirements     java or cpp project

### Installation

for java prohect:  copy Arg.java into your project
for cpp project:   copy arg.cc and arg.h into your project

Copy Args.utest()  into main()  and adapt the code to your need.
Follow the example and replace arguments name and description with your arguments.

For c project add relevant files to your build (Makefie)
 
### Configuration none

## Credits     none

## Contact     for help and bugs report, please email eli.shagam@gmail.com

## License     mit license 


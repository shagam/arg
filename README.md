# arg
Command line argument parser for java and c applications


README v0.0 / 01 JAN 2016

# Project name:  arg

## Introduction

 <br />
Simple to use, no need to define parameters. The help info is collected while the program parses the command line parametrs, and collects arguments valus.
 <br />
The parser supports 3 types of arguments
* integer     example:   threads=8
* string      example:   file=/proc/cpuinfo
* boolean     example:   verbose

## files
* Args.java  for java
* args.cc args.h  for c


## Usage

calling sequence
* java -jar overgead.jar   string_value=/vasr/js/java.log0   integerValue=1000  booleanValue

Argumets are seperated by spaces, no spaces between argument name and argument value

java and c parsing is very much the same.

No need to type the full arg_name, argument prefix is enough, as long as it is unique.
(prefix of one argument only)

        // boolean argument
        boolean copy = Args.bool_exist ("copy", args, "test==copy_memory (measure bandwidth)");

        // string argument
        String file = Args.search_String_arg ("file", args, "file name");


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
<br />$java -jar ~/nb/overhead/dist/overhead.jar   tree  threa=8
* optional args:
* threads=<integer>           number of concurrent threads
* arrays=<integer>            number of arrays, accessed by threads
* tree(bool)                  test==tree
* alloc(bool)                 test==alloc
* verbose(bool)               print test param during run

<br />actual args:  [tree, thr=8, ]


## Contributing


## Help
for help and bugs report, please email eli.shagam@gmail.com

## Installation
none

### Requirements
java or cpp project

### Installation
* for java project:  copy Arg.java into your project
* for c project:     copy arg.cc and arg.h into your project

Copy Args.utest()  into main()  and adapt the code to your need.
Follow the example and replace arguments name and description with your arguments.

For c project add relevant files to your build (Makefie)
 
### Configuration
none

## Credits
none

## Contact
for help and bugs report, please email eli.shagam@gmail.com

## License
mit license 


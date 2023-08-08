all: groot.c
 gcc groot.c -o groot
strip: all
 strip groot

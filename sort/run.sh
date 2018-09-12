#!/bin/bash

TEMP=`getopt -o i:c -l input:,clear -- "$@"`

eval set -- "$TEMP"

while true; do
    case $1 in
        -i|--input) cppFile=$2;shift 2;;
        -c|--clear) if [ "`ls -A build`" != "" ]; then `rm build/*.* && rm sort`;fi
            shift;exit;;
        --) shift;break;;
    esac
done


objName="build/"`basename $cppFile .cpp`".o"

g++ -c $cppFile -o $objName

lib="build/sort.a"

main="algorithm.cpp"

target="sort"

ar crv $lib $objName

g++ $main $lib -o $target

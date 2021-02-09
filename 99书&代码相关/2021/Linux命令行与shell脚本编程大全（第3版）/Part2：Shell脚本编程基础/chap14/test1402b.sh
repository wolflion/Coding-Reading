#!/bin/bash
# Testing parameters
#
if [ $# -ne 2 ]
then
    echo
    echo Usage: test1402.sh a b
    echo
else
    total=$[ $1 + $2 ]
    echo
    echo The total is $total
    echo
fi
#

#./test1402b.sh
#./test1402b.sh  10
#./test1402b.sh  10 15

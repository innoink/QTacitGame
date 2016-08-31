#!/bin/bash

OBJ_DIR=$PWD/obj_common
QMAKE=qmake

DIR_OPTIONS="--base-directory $PWD/common --directory $OBJ_DIR" #--directory obj_tests --directory tests

function error_exit
{
	echo "$1" 1>&2
	exit 1
}

$QMAKE "COVERAGE=1" && make VERBOSE=1

[ $? -ne 0 ] && error_exit "Compile step failed."

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/bin/
bin/tests

echo "done!"

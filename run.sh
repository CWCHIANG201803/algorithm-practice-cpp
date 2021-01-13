#!/bin/bash

BUILD_DIR=./build/bin

if [ -z "$1" ]
then
    ${BUILD_DIR}/main
elif [[ $1 -eq "test" ]]
then
    ${BUILD_DIR}/unit_tests
fi

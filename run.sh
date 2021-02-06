#!/bin/bash

BUILD_DIR=./build/bin


if [ -z "$1" ]
then
    ${BUILD_DIR}/main
fi

if [ "$1" == "test" ];
then
    ${BUILD_DIR}/unit_tests
fi


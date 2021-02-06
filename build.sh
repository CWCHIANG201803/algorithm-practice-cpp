#!/bin/bash


Generator=Ninja

DIR=build


[ ! -d ${DIR} ] && mkdir ${DIR}

cd build

cmake -G Ninja ..
Generator=$(echo "${Generator}" | tr '[:upper:]' '[:lower:]')
${Generator}

#!/bin/bash


Generator=Ninja
cd build

cmake -G Ninja ..
Generator=$(echo "${Generator}" | tr '[:upper:]' '[:lower:]')
${Generator}

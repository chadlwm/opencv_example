#!/bin/bash

rm -rf build
mkdir -p build
cd build

g++ ../canny.cpp -o Canny `pkg-config opencv --cflags --libs`
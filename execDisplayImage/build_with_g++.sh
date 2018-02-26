#!/bin/bash

rm -rf build
mkdir -p build
cd build

g++ ../DisplayImage.cpp -o DisplayImage `pkg-config opencv --cflags --libs`
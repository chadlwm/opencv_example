#!/bin/bash

rm -rf build
mkdir -p build
cd build

g++ ../videoCapture.cpp -o VideoCapture `pkg-config opencv --cflags --libs`
g++ ../videoWrite.cpp -o VideoWriter `pkg-config opencv --cflags --libs`
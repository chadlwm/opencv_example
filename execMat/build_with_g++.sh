#!/bin/bash

rm -rf build
mkdir -p build
cd build

for file in $(find ../ -maxdepth 1 -type f -name "*.cpp")
do 
  target=${file:3:-4}
  echo "build to $target from $file"
  g++ $file -o $target `pkg-config opencv --cflags --libs`
done
#!/bin/bash
echo your pattern please:
read pattern
echo dir please:
read dir
if find $dir -maxdepth 1 -type f -name "$pattern"
then
find $dir -maxdepth 1 -type f -name "$pattern">test.txt
fi
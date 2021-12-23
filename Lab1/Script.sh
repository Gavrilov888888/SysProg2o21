#!/bin/bash

cd $1
ls -la | grep "$2" >>  /e/lab2_Cherednyk/answer_list.txt

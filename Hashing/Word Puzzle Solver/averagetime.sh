#!/bin/bash

#Noal Zyglowicz (ntz3sw) 10/22/19

#read in dictionary file to variable
read -p "Specify dictionary file: " dictionaryFile;
#read in grid file to variable
read -p "Specify grid file: " gridFile;

echo ""

#run the program 5 times and record the runtime for each run
t1=`./a.out $dictionaryFile $gridFile | tail -1`
t2=`./a.out $dictionaryFile $gridFile | tail -1`
t3=`./a.out $dictionaryFile $gridFile | tail -1`
t4=`./a.out $dictionaryFile $gridFile | tail -1`
t5=`./a.out $dictionaryFile $gridFile | tail -1`

#echo out the runtimes to make sure that the time values for each run are being outputted in correct fashion and make sense
echo "5 individual runtimes in milliseconds"
echo $t1
echo $t2
echo $t3
echo $t4
echo $t5

echo ""

#calculates the average run time using the arithmetic as an argument
echo "Average runtime in milliseconds"
echo $((($t1 + $t2 + $t3 + $t4 + $t5) / 5))

#!/bin/bash
echo "Enter the semi-length of the square: (a positive integer)"
read i
echo "Enter the type of plot you want: (1, 2, 3)"
read option
g++ -Ofast UlamSpiral.cpp -o UlamSpiral
./UlamSpiral $i $option >UlamSpiral_$option
pdflatex UlamSpiral_$option
rm *.aux
rm *.log
rm UlamSpiral
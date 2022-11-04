#!/bin/bash
# Authors : Felipe Lima
# Date: 02/06/2020

#Problem 1 Code:
#Make sure to document how you are solving each problem!

echo "Enter a file name: "
read filename
echo "Enter a regular expression: "
read pattern
grep $pattern $filename

grep -c -E "[0-9]{3}-[0-9]{3}-[0-9]{3}" regex_practice.txt
grep -c -E "@" regex_practice.txt
grep -E "303" regex_practice.txt
grep -E "@geocities.com"  regex_practice.txt >> email_results.txt

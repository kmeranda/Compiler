#!/bin/sh

for testfile in good*.cminor
do
	if cminor -codegen $testfile $testfile.s > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

# no more bad cases
#for testfile in bad*.cminor
#do
#	if cminor -parse $testfile > $testfile.out
#	then
#		echo "$testfile success (INCORRECT)"
#	else
#		echo "$testfile failure (as expected)"
#	fi
#done

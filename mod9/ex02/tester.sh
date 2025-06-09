#!/bin/bash

BEGIN=$1
END=$2
TESTS=$3

if [ $BEGIN -lt 1 ]; then
	BEGIN=1
fi

echo "Testing PmergeMe. Sequence lengths: $BEGIN - $END. Tests each: $TESTS"

for ((i = BEGIN; i <= END; ++i)); do
	for ((j = 0; j < TESTS; ++j)); do
		INPUT=$(shuf -i 1-$END -n $i | tr "\n" " ")
		#echo "Test $i/$j/$LIMIT: ./PmergeMe $INPUT"
		./PmergeMe $INPUT

		if [ $? -ne 0 ]; then
			echo "Sort failed! i = $i j = $j"
			exit 1
		fi
	done
	percent=$((100 * (i - BEGIN) / (END - BEGIN)))
    echo -en "\rProgress: $percent%"
done
echo -e "\rAll sorts succeeded"

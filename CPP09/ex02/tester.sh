#!/bin/bash

echo "--- TEST: 5 Elements (Sanity Check) ---"
./PmergeMe `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
echo ""

echo "--- TEST: 100 Elements ---"
./PmergeMe `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
echo ""

echo "--- TEST: 3000 Elements (Standard) ---"
./PmergeMe `ruby -e "puts (1..3000).to_a.shuffle.join(' ')"`
echo ""

echo "--- TEST: 5000 Elements (Heavy) ---"
./PmergeMe `ruby -e "puts (1..5000).to_a.shuffle.join(' ')"`

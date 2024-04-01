#!/bin/bash

# Path to the file with RPN expressions and results
FILE_PATH="./rpn_expressions_and_results.txt"

# Assuming that an executable or script named RPN exists in the current directory or in the PATH
# This script will read each line containing an RPN expression, execute it, 
# and then read the next line to get the expected result, comparing the two.

while IFS= read -r line; do
    # Extract the RPN expression from the line (assuming the line format is ./RPN "<expression>")
    if [[ $line == ./RPN* ]]; then
        expression=$(echo "$line" | sed 's/.*"\(.*\)"/\1/')
        # Execute the RPN expression and capture the output
        output=$(./RPN "$expression")
        # Read the next line to get the expected result
        read -r expected_result_line
        expected_result=$(echo "$expected_result_line")

        # Compare the output with the expected result
        if [[ "$output" == "$expected_result" ]]; then
            echo -e "SUCCESS: Expression: $expression\n Result: $output\n"
    	else
            echo -e "FAIL: Expression: $expression\n Expected: $expected_result, Got: $output\n"
        fi
    fi
done < "$FILE_PATH"


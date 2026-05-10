#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No input file provided."
    echo "Usage: $0 <filename.tex>"
    exit 1
fi

make4ht --output-dir "./build/htmlOuts" --build-dir "./build" "$1" "svg, mathjax"
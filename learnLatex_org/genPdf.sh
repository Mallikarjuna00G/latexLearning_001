#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No input file provided."
    echo "Usage: $0 <filename.tex>"
    exit 1
fi

pdflatex -output-directory="./build" -output-format="pdf" "$1"
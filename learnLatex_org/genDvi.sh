#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No input file provided."
    echo "Usage: $0 <filename.tex>"
    exit 1
fi

latex -output-directory="./build" -output-format="dvi" "$1"
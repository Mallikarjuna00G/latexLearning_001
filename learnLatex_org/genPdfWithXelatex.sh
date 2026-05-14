#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No input file provided."
    echo "Usage: $0 <filename.tex>"
    exit 1
fi

BASENAME="${1%.tex}"
XELATEX_CMD="xelatex -synctex=1 -interaction=nonstopmode -output-directory=./build"

# Step 1: First xelatex pass — generates .idx index entries in ./build/
$XELATEX_CMD "$1"
$XELATEX_CMD "$1"

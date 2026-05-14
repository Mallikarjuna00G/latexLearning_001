#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No input file provided."
    echo "Usage: $0 <filename.tex>"
    exit 1
fi

BASENAME="${1%.tex}"
PDFLATEX_CMD="pdflatex -synctex=1 -interaction=nonstopmode -output-directory=./build -output-format=pdf"

# Step 1: First pdflatex pass — generates .idx index entries in ./build/
$PDFLATEX_CMD "$1"

# Step 2: Run makeindex on the .idx file inside ./build/
echo "[genPdfWithIndex] Running makeindex on ./build/${BASENAME}.idx ..."
makeindex "./build/${BASENAME}.idx"

# Step 3: Second pdflatex pass — incorporates the generated .ind index
$PDFLATEX_CMD "$1"

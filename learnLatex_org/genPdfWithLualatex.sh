#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No input file provided."
    echo "Usage: $0 <filename.tex>"
    exit 1
fi

BASENAME="${1%.tex}"
LUALATEX_CMD="lualatex --synctex=1 --interaction=nonstopmode --output-directory=./build --output-format=pdf"

# Step 1: First lualatex pass
$LUALATEX_CMD "$1"
# Step 2: Second lualatex pass — resolves cross-references
$LUALATEX_CMD "$1"

echo "LuaLaTeX run completed. PDF: ./build/${BASENAME}.pdf"

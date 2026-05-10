#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No input file provided."
    echo "Usage: $0 <filename.tex>"
    exit 1
fi

pdf_file="./build/${1%.tex}.pdf"

if [ ! -f "$pdf_file" ] || [ "$1" -nt "$pdf_file" ]; then
    # PDF doesn't exist or is older than the tex file, recompile first
    bash genPdf.sh "$1"
fi

# Generate the PNG
pdftoppm -singlefile -r 300 -png "$pdf_file" "./build/${1%.tex}"
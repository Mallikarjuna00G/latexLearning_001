#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No input file provided."
    echo "Usage: $0 <filename.tex>"
    exit 1
fi

dvi_file="./build/${1%.tex}.dvi"

if [ ! -f "$dvi_file" ] || [ "$1" -nt "$dvi_file" ]; then
    # DVI doesn't exist or is older than the tex file, recompile first
    bash genDvi.sh "$1"
fi

# Generate the SVG
dvisvgm --no-font --no-merge -o "./build/${1%.tex}_noFont.svg" "./build/${1%.tex}.dvi"
dvisvgm --no-merge -o "./build/${1%.tex}.svg" "./build/${1%.tex}.dvi"
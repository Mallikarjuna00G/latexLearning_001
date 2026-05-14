#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No input file provided."
    echo "Usage: $0 <filename.tex>"
    exit 1
fi

BASENAME="${1%.tex}"
PDFLATEX_CMD="pdflatex -synctex=1 -interaction=nonstopmode -output-directory=./build -output-format=pdf"

# Step 1: First pdflatex pass — generates .aux with citation keys
$PDFLATEX_CMD "$1"

# Step 2: Auto-detect bibliography backend from the preamble.
#   - Extract preamble (everything before \begin{document})
#   - Strip fully commented lines (lines starting with optional whitespace then %)
#   - If \usepackage{biblatex} is found AND backend=bibtex is NOT specified:
#       - Use biber (default backend for biblatex)
#   - Otherwise (natbib, or biblatex with backend=bibtex): use bibtex
PREAMBLE=$(sed '/\\begin{document}/q' "$1" | grep -v '^\s*%')

if echo "$PREAMBLE" | grep -q '\\usepackage.*{biblatex}' && \
   ! echo "$PREAMBLE" | grep '\\usepackage.*{biblatex}' | grep -q 'backend=bibtex'; then
    echo "[genPdfWithCitation] Detected biblatex package, using biber..."
    biber --input-directory=./build --output-directory=./build "${BASENAME}"
else
    echo "[genPdfWithCitation] Using bibtex..."
    bibtex "./build/${BASENAME}"
fi

# Step 3: Second pdflatex pass — incorporates bibliography data
$PDFLATEX_CMD "$1"

# Step 4: Third pdflatex pass — resolves all citation cross-references
$PDFLATEX_CMD "$1"

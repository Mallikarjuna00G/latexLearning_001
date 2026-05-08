#!/bin/bash

# Remove common LaTeX build artifacts
rm -f *.aux \
      *.bbl \
      *.blg \
      *.brf \
      *.fdb_latexmk \
      *.fls \
      *.idx \
      *.ilg \
      *.ind \
      *.lof \
      *.log \
      *.lot \
      *.out \
      *.synctex.gz \
      *.toc \
      *.pdf

echo "Cleaned LaTeX build artifacts."

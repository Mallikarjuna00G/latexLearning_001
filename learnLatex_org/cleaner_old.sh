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
      *.pdf \
      *.4ct \
      *.4tc \
      *.idv \
      *.lg \
      *.trc \
      *.xref \
      *.html \
      *.css \
      *.tmp \
      *.dvi

echo "Cleaned LaTeX, pdfLaTeX and make4ht build artifacts."

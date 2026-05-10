# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]
### Added
- Updated `.gitignore` to ignore `make4ht` generated files (`.html`, `.css`, `.tmp`).
- Created the foundational documentation structure (`README.md`, `JOURNAL.md`, `RELEASE_NOTES.md`, `CHANGELOG.md`, `AGENTS.md`).
- Added standard `.gitignore` for LaTeX environments.
- Created `latexIn30Min/` directory for following the Overleaf "Learn LaTeX in 30 minutes" tutorial.
- Created `doc_001.tex` as a basic introductory "Hello World" document.
- Added `cleaner.sh` script to automate removal of LaTeX build artifacts.
- Created `doc_002.tex` through `doc_007.tex` exploring text formatting, and image insertion.
- Created `doc_008.tex` through `doc_013.tex` learning about lists (unordered, ordered) and mathematical expressions.
- Created `doc_014.tex` through `doc_016.tex` covering basic document structure.
- Created `doc_017.tex` through `doc_021.tex` covering table creation and formatting.
- Completed the Overleaf "Learn LaTeX in 30 minutes" tutorial.
- Added `images/` directory for storing graphic assets.
- Started `learnLatex_org/` directory for exercises from learnlatex.org.
- Created `first.tex` and `first_comment.tex` as introductory files.
- Added `les04_01.tex` through `les04_03.tex` covering title, author, and date generation, as well as non-breaking spaces.
- Created `genDvi.sh` and `genPdf.sh` scripts for simplified LaTeX compilation, including argument checking to prevent hangs.
- Added `genSvg.sh` and `genPng.sh` for generating SVG and PNG images from LaTeX files.
- Completed learnlatex.org Lesson 04.
- Added various exercise and 'more' files (`les04_exrc_01.tex`, `les04_more_01.tex`, etc.) for Lesson 04.
- Updated shell scripts (`genDvi.sh`, `genPdf.sh`, `genSvg.sh`, `genPng.sh`) and `cleaner.sh` to leverage an isolated `build/` directory for cleaner project organization.
- Added `genHtml.sh` utilizing `make4ht` to generate HTML output directly into `build/htmlOuts/`.
- Created `gitClean.sh` wrapper script around `git clean -Xdf` to aggressively sweep ignored files and rebuild the `build/` structure.
- Modified `.gitignore` to un-ignore `*.pdf`, `*.ps`, and `*.eps` allowing tracking of static image assets.
- Updated `genSvg.sh` to simultaneously generate both a standard SVG and a path-embedded (`_noFont`) SVG.
- Completed learnlatex.org Lesson 05.
- Added exercise files (`les05_001.tex`, `les05_exrc_01_01.tex`, `les05_more_01.tex`, etc.) covering different document classes like `letter`.
- Completed learnlatex.org Lesson 06.
- Added files (`les06_*.tex`) exploring packages (`babel`, `geometry`, `lipsum`) and defining custom commands via `\newcommand` and `\NewDocumentCommand`.
- Completed learnlatex.org Lesson 07.
- Added files (`les07_*.tex`) exploring the `graphicx` package, image manipulation (`\includegraphics`), floating environments (`figure`), `\graphicspath`, and custom floats via the `float` and `trivfloat` packages.
- Added `images/` and `images2/` directories to demonstrate configuring multiple graphics paths.

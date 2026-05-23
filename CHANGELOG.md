# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.3.3] - 2026-05-23
### Added
- Implemented Title (<= 100 characters), Description (<= 5000 characters), and Tags (<= 500 characters, including separating commas) metadata length validations in `uploader.cpp` to halt execution before transmission on violation.
- Added a POST request call in `uploader.cpp` to the YouTube `playlistItems.insert` endpoint, enabling automatic playlist association if a `playlistId` is specified.
- Implemented warning logs for unsupported Shorts properties (such as `relatedVideoId`) which must be configured manually via YouTube Studio.
- Added new parameters to `video_metadata.json` including `playlistId`, `relatedVideoId`, `selfDeclaredMadeForKids`, `containsSyntheticMedia`, and `hasPaidProductPlacement` configurations.
- Added aspect ratio auto-detection using `ffprobe` to determine if the video is a Short (vertical/square) or normal (horizontal) video, updating the success output URL format accordingly.

### Changed
- Migrated video upload metadata from hardcoded C++ variables in `uploader.cpp` to the external JSON configuration file `video_metadata.json`.
- Updated `CMakeLists.txt` to use configure-time `configure_file` copying for `client_secrets.json` and `video_metadata.json` to the build output directory, ensuring changes to config/secrets automatically sync on build.
- Broadened OAuth scope in `get_refresh_token.cpp` to `"https://www.googleapis.com/auth/youtube"` to permit playlist management.

## [1.3.2] - 2026-05-22
### Added
- Added CMake configuration to compile the automation tools into native executables, featuring a default uploader target and a non-default token retriever target.
- Integrated CMake build instructions and direct binary execution guidelines into the manual's README.

## [1.3.1] - 2026-05-22
### Added
- Developed C++ scripts to partially automate uploading video demonstrations to YouTube (currently in testing mode).
- Added setup, compilation, and execution instructions for the upload tools in the manual's README.

### Changed
- Updated gitignore to exclude YouTube credentials, API secrets, and compiled binaries from version control.

## [1.3.0] - 2026-05-22
### Added
- Started Chapter 3 ("Tutorial: A Petri-Net for Hagen") of the TikZ & PGF manual.
- Covered setting up the environment in Linux for Hagen's Petri-net activity (section 3.2.1).
- Covered introduction to nodes (section 3.3).
- Covered placing nodes using at syntax (section 3.4).

## [1.2.0] - 2026-05-22
### Added
- Completed Chapter 2 ("Tutorial: A Picture for Karl's Students") of the TikZ & PGF manual.
- Covered adding text/nodes along paths and shapes (section 2.21).
- Covered using the `pic` and `angle` commands for drawing angles and decorations (section 2.22).

## [1.1.7] - 2026-05-20
### Added
- Continued TikZ & PGF manual Chapter 2 tutorial.
- Covered repeating things using for loops (section 2.20).
## [1.1.6] - 2026-05-20
### Added
- Continued TikZ & PGF manual Chapter 2 tutorial.
- Covered scoping (section 2.18).
- Covered coordinate transformations (section 2.19).
## [1.1.5] - 2026-05-19
### Added
- Continued TikZ & PGF manual Chapter 2 tutorial.
- Covered intersection of paths (section 2.16).
- Covered adding arrow tips to open paths (section 2.17).

## [1.1.4] - 2026-05-18
### Added
- Continued TikZ & PGF manual Chapter 2 tutorial.
- Added files for section 2.14 (Shading): `ch02/ch2p14_001.tex`, `ch02/ch2p14_002.tex`, and `ch02/ch2p14_003.tex`.
- Added files for section 2.15 (Specifying Coordinates): `ch02/ch2p15_001.tex`, `ch02/ch2p15_002.tex`, `ch02/ch2p15_003.tex`, `ch02/ch2p15_004.tex`, and `ch02/ch2p15_005.tex`.

## [1.1.3] - 2026-05-17
### Added
- Continued TikZ & PGF manual Chapter 2 tutorial.
- Added files for section 2.12 (Parabola and Sine Path Construction): `ch02/ch2p12_001.tex`, `ch02/ch2p12_002.tex`, and `ch02/ch2p12_003.tex`.
- Added files for section 2.13 (Filling and Drawing): `ch02/ch2p13_001.tex`, `ch02/ch2p13_002.tex`, and `ch02/ch2p13_003.tex`.

## [1.1.2] - 2026-05-16
### Added
- Continued TikZ & PGF manual Chapter 2 tutorial.
- Added files for section 2.10 (Arc Path Construction): `ch02/ch2p10_001.tex` and `ch02/ch2p10_002.tex`.
- Added file for section 2.11 (Clipping a Path): `ch02/ch2p11_001.tex`.

## [1.1.1] - 2026-05-15
### Added
- Continued TikZ & PGF manual Chapter 2 tutorial.
- Added file for section 2.6 (Rectangle Path Construction): `ch02/ch2p6_001.tex`.
- Added file for section 2.7 (Grid Path Construction): `ch02/ch2p7_001.tex`.
- Added files for section 2.8 (Styling Grids): `ch02/ch2p8_001.tex` and `ch02/ch2p8_002.tex`.
- Updated `tikzPgf_manual/README.md` with new project links.

## [1.1.0] - 2026-05-15
### Added
- Created `tikzPgf_manual/` directory for learning from the TikZ & PGF manual.
- Added Chapter 1 drawing: `ch01/drawing_001.tex`.
- Added Chapter 2 tutorial files: `ch02/ch2p2p1_001.tex`, `ch02/ch2p3.tex`, `ch02/ch2p4_001.tex`, `ch02/ch2p4_002.tex`, `ch02/ch2p5_001.tex`, and `ch02/ch2p5_002.tex`.
- Updated root `README.md` to include the new learning path.
- Updated `JOURNAL.md`, `RELEASE_NOTES.md`, and `CHANGELOG.md` for the new milestone.

## [1.0.0] - 2026-05-14
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
- Completed learnlatex.org Lesson 08.
- Added files (`les08_01.tex` through `les08_11.tex`) covering the `tabular` environment, column types (`l`, `c`, `r`, `p`), the `booktabs` package (`\toprule`, `\midrule`, `\bottomrule`, `\cmidrule`, `\addlinespace`), cell merging with `\multicolumn`, and simulated row spanning.
- Added files (`les08_more_01.tex` through `les08_more_17.tex`) exploring advanced table topics: column styling with `>{}` and `<{}` modifiers, inter-column spacing (`\tabcolsep`, `@{}`, `!{}`), vertical rules, customized `booktabs` rules, numeric alignment via `siunitx` (`S` column), total table width control (`tabular*`, `tabularx`), multi-page tables (`longtable`), table footnotes (`threeparttable`), narrow column typesetting (`ragged2e`), custom column types (`\newcolumntype`), nested tables, vertical alignment options, and `\arraystretch` for line spacing.
- Completed learnlatex.org Lesson 09.
- Added `les09_01.tex` covering the `\label` and `\ref` cross-referencing mechanism for sections and equations.
- Added `les09_more_01.tex` exploring the `hyperref` package to convert cross-references into clickable hyperlinks with the `[hidelinks]` option.
- Completed learnlatex.org Lesson 10.
- Added files (`les10_01.tex` through `les10_10.tex`) covering mathematics in LaTeX: inline math (`$...$`), display math (`\[...\]`), superscripts, subscripts, math functions (`\sin`, `\log`), integrals with `\int`, manual spacing (`\,`), custom `\diff` command for differentials, numbered equations (`equation` environment), the `amsmath` package for `align` and matrix environments (`matrix`, `pmatrix`, `bmatrix`), and math-mode font commands (`\mathbf`, `\mathit`, `\mathrm`, `\text`).
- Added files (`les10_more_01.tex` through `les10_more_08.tex`) exploring advanced mathematics topics: further `amsmath` alignment environments (`gather`, `multline`), multi-column math alignments, the `aligned` sub-environment with delimiter pairing and vertical positioning (`[t]`), bold mathematics using `\boldmath` and the `bm` package, the `mathtools` package for starred matrix environments (`pmatrix*[r]`), and Unicode math with `unicode-math` package via `lualatex`.
- Completed learnlatex.org Lesson 11.
- Added files (`les11_01.tex` through `les11_05.tex`) covering formatting in LaTeX: paragraph spacing with the `parskip` package (`[parfill]` option), explicit horizontal and vertical spacing (`\hspace`, `\vspace`), text formatting commands (`\textbf`, `\textit`, `\textrm`, `\textsf`, `\texttt`, `\textsc`), declaration-style font switching (`\itshape`, `\bfseries`) for running text, and font size commands (`\large`, `\small`) with `\par` for proper paragraph termination.
- Added `les11_more_01.tex` exploring `\noindent` for suppressing paragraph indentation on individual paragraphs.
- Completed learnlatex.org Lesson 12.
- Added `learnlatex.bib` bibliography database with sample `@article` and `@book` entries used across Lesson 12 exercises.
- Added `les12_01.tex` demonstrating the older BibTeX workflow with `natbib` package: `\cite`, `\citep` (parenthetical with optional page/prenote arguments), `\bibliographystyle{plainnat}`, and `\bibliography{learnlatex}`.
- Added `les12_02.tex` demonstrating the modern `biblatex` workflow with `biber` backend: `\addbibresource`, `\autocite`, `\parencite`, `\textcite`, `\citetitle`, and `\printbibliography` using the `authoryear` citation style.
- Created `genPdfWithCitation.sh` script for the 4-step bibliography compilation workflow (pdflatex → bibtex/biber → pdflatex → pdflatex), with auto-detection of the bibliography backend by inspecting the preamble for `\usepackage{biblatex}`.
- Completed learnlatex.org Lesson 13.
- Added `les13_01.tex` demonstrating structured document composition using `\input` for frontmatter/chapters/appendices and `\tableofcontents` with `biblatex`/`biber` for bibliography, compiled via `genPdfWithCitation.sh`.
- Added supporting chapter/structure files (`front.tex`, `chap1.tex`, `chap2.tex`, `append.tex`, `pref.tex`, `frontcover.tex`, `backcover.tex`, `copyright.tex`, `dedication.tex`) for the multi-file book document.
- Added `les13_more_01.tex` exploring the `imakeidx` package for index generation with `\index` entries and `\printindex`, using the `noautomatic` option to work correctly with the `build/` output directory.
- Created `genPdfWithIndex.sh` script for the 3-step index compilation workflow (pdflatex → makeindex → pdflatex), running `makeindex` on `./build/*.idx` to resolve the path mismatch caused by `-output-directory`.
- Refactored `genPdfWithCitation.sh` and `genPdfWithIndex.sh` to extract the repeated `pdflatex` invocation into a reusable `PDFLATEX_CMD` variable for DRY maintainability.
- Completed learnlatex.org Lesson 14.
- Added `les14_01.tex` exploring Unicode engines (XeTeX/LuaTeX) and the `fontspec` package, with multi-script support (Latin, Greek, Chinese, Kannada).
- Added `les14_more_01.tex` demonstrating Lua integration in LaTeX using `\directlua`.
- Created `genPdfWithXelatex.sh` and `genPdfWithLualatex.sh` build scripts for Unicode-aware compilation.
- Created `genPdfWithIndex.sh` script for the 3-step index compilation workflow (pdflatex → makeindex → pdflatex), running `makeindex` on `./build/*.idx` to resolve the path mismatch caused by `-output-directory`.
- Refactored `genPdfWithCitation.sh` and `genPdfWithIndex.sh` to extract the repeated `pdflatex` invocation into a reusable `PDFLATEX_CMD` variable for DRY maintainability.
- Completed learnlatex.org Lesson 14.
- Added `les14_01.tex` exploring Unicode engines (XeTeX/LuaTeX) and the `fontspec` package, with multi-script support (Latin, Greek, Chinese, Kannada).
- Added `les14_more_01.tex` demonstrating Lua integration in LaTeX using `\directlua`.
- Created `genPdfWithXelatex.sh` and `genPdfWithLualatex.sh` build scripts for Unicode-aware compilation.

# Release Notes

## [v0.12.0] - learnlatex.org Lesson 13 Completion

**Milestone Reached!**
Successfully completed Lesson 13 from the learnlatex.org tutorial series.

**Highlights:**
- **Document Structuring:** Learned to split large documents into multiple `.tex` files using `\input`, organizing content into frontmatter, chapters, appendices, and backmatter with a master `book`-class document.
- **Index Generation:** Explored the `imakeidx` package for creating document indices with `\index` entries and `\printindex`.
- **Build Script — `genPdfWithIndex.sh`:** Created a new 3-step compilation script (pdflatex → makeindex → pdflatex) to handle index generation, resolving the path mismatch where `makeindex` couldn't find `.idx` files in the `./build/` output directory.
- **Script Refactoring:** Extracted the repeated `pdflatex` invocation into a `PDFLATEX_CMD` variable in both `genPdfWithCitation.sh` and `genPdfWithIndex.sh` for DRY maintainability.

## [v0.11.0] - learnlatex.org Lesson 12 Completion

**Milestone Reached!**
Successfully completed Lesson 12 from the learnlatex.org tutorial series.

**Highlights:**
- **BibTeX Workflow (natbib):** Learned the older citation workflow using the `natbib` package with `bibtex` as the backend processor, including `\cite`, `\citep` (with optional page numbers and prenotes), `\bibliographystyle`, and `\bibliography`.
- **Biblatex Workflow (biber):** Practiced the modern citation workflow using the `biblatex` package with `biber` as the default backend, including `\addbibresource`, `\autocite`, `\parencite`, `\textcite`, `\citetitle`, and `\printbibliography`.
- **Bibliography Database:** Created a `.bib` file with `@article` and `@book` entry types as a shared citation source.
- **Build Automation:** Created `genPdfWithCitation.sh` to automate the 4-step compilation (pdflatex → bibtex/biber → pdflatex → pdflatex), with smart auto-detection of the correct backend by parsing the `.tex` preamble.

## [v0.10.0] - learnlatex.org Lesson 11 Completion

**Milestone Reached!**
Successfully completed Lesson 11 from the learnlatex.org tutorial series.

**Highlights:**
- **Paragraph Spacing:** Used the `parskip` package with the `[parfill]` option to switch from indentation-based to whitespace-based paragraph separation.
- **Explicit Spacing:** Learned `\hspace` and `\vspace` for inserting precise horizontal and vertical space within documents.
- **Text Formatting Commands:** Practiced argument-based font commands (`\textbf`, `\textit`, `\textrm`, `\textsf`, `\texttt`, `\textsc`) for inline formatting.
- **Declaration-style Formatting:** Used `\itshape` and `\bfseries` for applying font changes to running text across paragraph boundaries via grouping with braces.
- **Font Sizes:** Explored size-switching commands (`\large`, `\small`) and the importance of `\par` for proper paragraph termination before closing a size group.
- **Indent Control:** Used `\noindent` to suppress paragraph indentation for individual paragraphs.

## [v0.9.0] - learnlatex.org Lesson 10 Completion

**Milestone Reached!**
Successfully completed Lesson 10 from the learnlatex.org tutorial series.

**Highlights:**
- **Inline & Display Math:** Practiced both inline (`$...$`) and display (`\[...\]`) math modes, including superscripts, subscripts, and standard math functions like `\sin`.
- **Integrals & Spacing:** Typeset integrals with limits (`\int_{-\infty}^{+\infty}`), learned manual thin-space (`\,`) for differentials, and created a custom `\diff` command.
- **Numbered Equations:** Used the `equation` environment for automatically numbered display equations.
- **`amsmath` Package:** Explored the `align` environment for multi-line aligned equations, and matrix environments (`matrix`, `pmatrix`, `bmatrix`).
- **Math Fonts:** Learned math-mode font switching with `\mathbf`, `\mathit`, `\mathrm`, and `\text`, understanding the difference between each.
- **Advanced Alignments:** Used `gather`, `multline`, multi-column `align`, and the `aligned` sub-environment with delimiter pairing and `[t]` positioning.
- **Bold Math:** Explored `\boldmath`, `\mathbf` limitations, and the `bm` package for correctly bolding Greek letters and operators.
- **`mathtools` & Unicode Math:** Used `mathtools` for starred matrix environments with alignment options, and `unicode-math` with `lualatex` for OpenType math fonts and Unicode alphanumeric symbols (`\symfrak`, `\symbf`, `\symcal`, `\symscr`, `\symbb`).

## [v0.8.0] - learnlatex.org Lesson 09 Completion

**Milestone Reached!**
Successfully completed Lesson 09 from the learnlatex.org tutorial series.

**Highlights:**
- **Cross-Referencing:** Learned the `\label` / `\ref` mechanism for creating internal document references to sections, subsections, and equations.
- **Hyperlinks:** Used the `hyperref` package with `[hidelinks]` to turn all cross-references into clickable PDF hyperlinks without visual clutter.

## [v0.7.0] - learnlatex.org Lesson 08 Completion

**Milestone Reached!**
Successfully completed Lesson 08 from the learnlatex.org tutorial series.

**Highlights:**
- **Tables Fundamentals:** Mastered the `tabular` environment with column alignment specifiers (`l`, `c`, `r`), paragraph columns (`p{width}`), and the `*{n}{spec}` repetition shorthand.
- **Professional Rules:** Adopted the `booktabs` package for publication-quality horizontal rules (`\toprule`, `\midrule`, `\bottomrule`), partial rules (`\cmidrule` with trim options), and visual grouping via `\addlinespace`.
- **Cell Merging:** Used `\multicolumn` for spanning and overriding column preamble tokens.
- **Column Styling:** Leveraged `>{}` and `<{}` modifiers from the `array` package to apply per-column formatting (e.g., italic text, automatic punctuation).
- **Spacing Control:** Explored `\tabcolsep`, `@{}`, and `!{}` specifiers for fine-grained inter-column spacing adjustments.
- **Numeric Alignment:** Used the `siunitx` package's `S` column type for decimal-point-aligned numbers.
- **Table Width:** Controlled total table width via `tabular*` and `tabularx` environments.
- **Multi-page Tables:** Used `longtable` for tables spanning multiple pages.
- **Advanced Features:** Explored table footnotes (`threeparttable`), custom column types (`\newcolumntype`), nested tables, vertical alignment options (`[t]`/`[b]`), and global line spacing via `\arraystretch`.

## [v0.6.0] - learnlatex.org Lesson 07 Completion

**Milestone Reached!**
Successfully completed Lesson 07 from the learnlatex.org tutorial series.

**Highlights:**
- **Graphics Inclusion:** Mastered the `graphicx` package to import, resize, and crop images.
- **Float Management:** Explored floating environments (`figure`) and their placement specifiers to properly position graphics within the document flow.
- **Organization:** Configured `\graphicspath` to cleanly separate image assets into dedicated `images/` and `images2/` directories.
- **Advanced Floats:** Leveraged `float` and `trivfloat` packages for forced positioning (`[H]`) and creating custom float types.

## [v0.5.0] - learnlatex.org Lesson 06 Completion

**Milestone Reached!**
Successfully completed Lesson 06 from the learnlatex.org tutorial series.

**Highlights:**
- **Packages:** Learned how to extend LaTeX functionality using packages, specifically exploring `babel` for language support/hyphenation and `geometry` for precise margin control.
- **Dummy Text:** Discovered the `lipsum` package for quickly generating filler text to test document layouts.
- **Custom Commands:** Mastered creating custom macros with `\newcommand` and `\NewDocumentCommand`, including support for mandatory and optional arguments, enabling cleaner and more semantic LaTeX source code.

## [v0.4.0] - learnlatex.org Lesson 05 Completion

**Milestone Reached!**
Successfully completed Lesson 05 from the learnlatex.org tutorial series.

**Highlights:**
- **Document Classes:** Explored different document classes such as `letter` to understand structural differences in LaTeX beyond the standard `article` class.
- **Git Ignore Fixes:** Revised the `.gitignore` to un-ignore generic image extensions (`.pdf`, `.eps`, `.ps`), recognizing that the `build/` directory correctly handles generated artifacts, freeing us up to track actual static image assets.
- **Enhanced SVG Generation:** Updated `genSvg.sh` to simultaneously build two SVG versions (`.svg` and `_noFont.svg`), ensuring robust text rendering on any device by embedding text as vector paths.

## [v0.3.0] - learnlatex.org Lesson 04 Completion

**Milestone Reached!**
Successfully completed Lesson 04 from the learnlatex.org tutorial series.

**Highlights:**
- **Title and Metadata:** Learned how to generate document titles using `\title`, `\author`, `\date`, and `\maketitle`.
- **Typographical Conventions:** Gained an understanding of non-breaking spaces (ties) using the `~` character.
- **Build Automation Improvements:** Overhauled the compilation workflow. Created dedicated bash scripts (`genPdf.sh`, `genDvi.sh`, `genPng.sh`, `genSvg.sh`) with intelligent compilation logic (using timestamps) to convert `.tex` files into various output formats. All build artifacts are now cleanly isolated into a `build/` directory!

## [v0.2.0] - "Learn LaTeX in 30 Minutes" Completion

**Milestone Reached!**
Successfully completed the "Learn LaTeX in 30 minutes" tutorial from Overleaf (which practically took more than 5 hours to fully explore and practice).

**Highlights:**
- **Text & Structure:** Mastered the preamble, basic document structures, and text formatting.
- **Lists & Math:** Learned how to utilize itemize/enumerate environments and typeset mathematical equations.
- **Graphics & Tables:** Gained practical experience inserting images via the `graphicx` package and structuring data into tables.
- **Automation:** Created a custom `cleaner.sh` script to keep the repository free of LaTeX build artifacts (`.aux`, `.log`, etc.).

## [v0.1.0] - Project Inception

Welcome to the LaTeX learning repository! 

This repository was created to systematically learn and practice LaTeX typesetting. 

**Initial Highlights:**
- **Project Structure Established:** A clean foundation has been set up, including a proper `.gitignore` configuration tailored for LaTeX to keep the repository clean from build artifacts.
- **First Module Started:** We've kicked off the "Learn LaTeX in 30 Minutes" module, creating our very first plain-text TeX document.
- **Documentation Framework:** Introduced structured tracking files (`CHANGELOG.md`, `JOURNAL.md`, `RELEASE_NOTES.md`) to maintain clear visibility into learning progress and repository changes.

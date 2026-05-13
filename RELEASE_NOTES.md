# Release Notes

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

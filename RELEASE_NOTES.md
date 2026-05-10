# Release Notes

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

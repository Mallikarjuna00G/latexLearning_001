# LaTeX Learning Journal

## 2026-05-08
- **Project Setup:** Initialized the learning repository. Configured `.gitignore` for LaTeX projects to avoid tracking intermediate build files like `.aux`, `.log`, and `.out`.
- **Documentation Setup:** Decided to use standard documentation files including `CHANGELOG.md` for technical changes and `RELEASE_NOTES.md` for milestone summaries, in addition to this journal.
- **LaTeX in 30 Minutes:**
  - Started the [Overleaf "Learn LaTeX in 30 minutes"](https://www.overleaf.com/learn/latex/Learn_LaTeX_in_30_minutes) tutorial.
  - Wrote my first document (`latexIn30Min/doc_001.tex`) focusing on the absolute basics: the `\documentclass{article}` declaration and the `\begin{document} ... \end{document}` environment.
  - Explored text formatting, and figure insertion using the `graphicx` package (`doc_002.tex` through `doc_007.tex`).
  - Created a cleanup script `cleaner.sh` to quickly remove intermediate LaTeX build artifacts.
  - Explored lists (itemize, enumerate) and mathematical typesetting (`doc_008.tex` through `doc_013.tex`).

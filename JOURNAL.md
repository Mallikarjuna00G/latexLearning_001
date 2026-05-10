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
  - Learned about basic document structure (`doc_014.tex` through `doc_016.tex`).
  - Learned how to create and format tables (`doc_017.tex` through `doc_021.tex`).
  - **Milestone:** Successfully completed the "Learn LaTeX in 30 minutes" tutorial (fun fact: it actually took over 5 hours!).
  - **Configuration Update:** Updated `.gitignore` to include `make4ht` output files (`.html`, `.css`, `.tmp`) to prevent tracking web-related build artifacts.

## 2026-05-10
- **LearnLatex.org Tutorial:**
  - Started a new tutorial from [learnlatex.org](https://www.learnlatex.org/).
  - Created a new directory `learnLatex_org/` for these exercises.
  - Worked through initial documents (`first.tex`, `first_comment.tex`) and early lessons (`les04_01.tex` through `les04_03.tex`).
  - Learned about non-breaking spaces (ties) represented by the tilde `~` character, which prevent unwanted line breaks between connected words or initials (e.g., `A.~N.~Other`).
  - Created simple shell scripts (`genDvi.sh` and `genPdf.sh`) to streamline compiling `.tex` files, and added argument checking to them to prevent the compiler from hanging when no input file is provided.
  - Learned that the `-z` flag in bash conditional expressions checks if a string is empty (zero length), which is useful for verifying if script arguments are provided.
  - Wrote additional conversion scripts (`genSvg.sh` and `genPng.sh`) for rendering `.tex` output into images, learning basic bash syntax troubleshooting in the process.
  - Learned about Bash parameter expansion for suffix removal (`${1%.tex}`), which efficiently strips the `.tex` extension so it can be replaced with other extensions like `.dvi` or `.pdf`.
  - Added smart recompilation logic to `genPng.sh` using the Bash `-nt` operator (newer than) to only compile the PDF if the `.tex` file has been updated, otherwise just reusing the existing PDF.
  - Configured output directories for `dvisvgm` (using `-o`) and `pdftoppm` so that all generated images and intermediate files are cleanly routed to an isolated `build/` directory.
  - Added the `-singlefile` flag to `pdftoppm` in `genPng.sh` to prevent it from automatically appending page numbers (like `-1`) to the generated PNG filenames.
  - Experimented with HTML output using `make4ht` and encapsulated it in a `genHtml.sh` script, routing outputs to `build/htmlOuts/`.
  - Explored cleaning ignored files via `git clean -Xdf` and wrapped it inside `gitClean.sh` (along with recreating the `build/` directory) for a quick, aggressive workspace sweep.
  - **Milestone:** Successfully completed Lesson 04 from learnlatex.org, including additional exercises and more detailed document structures (`les04_exrc*.tex`, `les04_more*.tex`).
  - Modified `.gitignore` by explicitly removing global ignores for `*.pdf`, `*.ps`, and `*.eps` files. Since all auto-generated artifacts are now successfully caught by the `build/` folder ignore rule, this change allows git to track graphic vectors used as image inputs for documents.
  - Encountered an issue where `pdflatex` failed to run when using `--output-directory=build` because the `build` directory was missing; resolved it by recreating the directory.
  - Updated `genSvg.sh` to generate two variations of an SVG file per compile: one standard and one using `--no-font` to embed paths directly (`_noFont.svg`), ensuring robust scaling across different viewers.
  - **Milestone:** Successfully completed Lesson 05 from learnlatex.org, focusing on different document classes (like `letter`) and creating numerous structural exercise files (`les05_*.tex`).
  - **Milestone:** Successfully completed Lesson 06 from learnlatex.org, focusing on extending LaTeX.
  - Explored using packages to modify LaTeX's default behavior, particularly `babel` for multilingual support (hyphenation, naming) and `geometry` for margin and page layout control.
  - Used the `lipsum` package to generate dummy text for layout testing.
  - Learned how to define custom commands using `\newcommand` to encapsulate styling (like bold or colored text), including how to pass arguments and define optional arguments.
  - Briefly touched upon `\NewDocumentCommand` from the `xparse` package (integrated into modern LaTeX kernels) for creating more advanced custom commands.

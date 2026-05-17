# LaTeX Learning Journal

## 2026-05-17
- **TikZ & PGF Manual Study (continued):**
- **TikZ Expansion (Sections 2.12 - 2.13):**
  - Learned **Parabola and Sine Path Construction** in `ch02/ch2p12_001.tex`, `ch02/ch2p12_002.tex`, and `ch02/ch2p12_003.tex`.
  - Explored **Filling and Drawing** paths in `ch02/ch2p13_001.tex`, `ch02/ch2p13_002.tex`, and `ch02/ch2p13_003.tex`, learning how to fill areas and combine drawing with filling.

## 2026-05-16
- **TikZ & PGF Manual Study (continued):**
- **TikZ Expansion (Sections 2.10 - 2.11):**
  - Learned **Arc Path Construction** in `ch02/ch2p10_001.tex` and `ch02/ch2p10_002.tex`.
  - Explored **Clipping a Path** in `ch02/ch2p11_001.tex`, understanding how to restrict drawing to a specific region.

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
  - **Milestone:** Successfully completed Lesson 07 from learnlatex.org, focusing on including graphics and float positioning.
  - Learned to use the `graphicx` package to insert images (`\includegraphics`) and manipulate their appearance using parameters like `width`, `height`, `clip`, and `trim`.
  - Explored `figure` environments to make graphics "float" and understand position specifiers (`h`, `t`, `b`, `p`).
  - Configured LaTeX to look for image assets in specific subdirectories using `\graphicspath{{images/}{images2}}`.
  - Learned about the `float` package to force exact placement using the `[H]` specifier, and the `trivfloat` package to define custom float environments.

## 2026-05-13
- **LearnLatex.org Tutorial (continued):**
  - **Milestone:** Successfully completed Lesson 08 from learnlatex.org, focusing on tables.
  - Learned the basics of the `tabular` environment with column alignment specifiers (`l`, `c`, `r`) and the `&` column separator.
  - Explored the `p{width}` column type to handle long text with automatic paragraph wrapping inside cells.
  - Discovered the `*{n}{spec}` shorthand for repeating column preamble tokens.
  - Used the `booktabs` package for professional-quality horizontal rules (`\toprule`, `\midrule`, `\bottomrule`) instead of plain `\hline`.
  - Learned `\cmidrule` for partial-width rules spanning specific columns, including shortening with `(r)`, `(l)`, and `(rl)` trim options.
  - Explored `\addlinespace` from `booktabs` for adding visual separation between row groups.
  - Mastered cell merging with `\multicolumn{n}{align}{text}` and using it to override column preamble tokens (e.g., centering headers in a left-aligned column).
  - Learned that row spanning is not natively supported; instead, leaving cells blank simulates the effect, grouped with `\addlinespace`.
  - **More on Tables (advanced topics):**
  - Styled columns using `>{...}` (pre-column) and `<{...}` (post-column) modifiers from the `array` package (e.g., `>{\itshape}l<{:}`).
  - Manipulated inter-column spacing via `\tabcolsep`, the `@{...}` specifier (replaces default spacing), and the `!{...}` specifier (inserts content in the center of existing spacing).
  - Explored vertical rules using `|` in column specifiers.
  - Customized `booktabs` rule thickness (e.g., `\toprule[2pt]`).
  - Used the `siunitx` package's `S` column type for decimal-aligned numeric columns.
  - Learned to control total table width using `tabular*` with `\extracolsep{\fill}` and the `tabularx` package with the `X` column type.
  - Explored the `longtable` package for tables that span multiple pages.
  - Used `threeparttable` to attach footnotes directly to a table.
  - Learned about typesetting in narrow columns using `ragged2e` and its `\RaggedRight` command.
  - Defined custom column types using `\newcolumntype` (e.g., `\newcolumntype{B}{>{\bfseries}c}`).
  - Explored vertical tricks: nesting a `tabular` inside a cell, and using the optional `[t]`/`[b]` alignment argument for vertical baseline control.
  - Learned about `\arraystretch` for globally adjusting line spacing in tables.
  - **Milestone:** Successfully completed Lesson 09 from learnlatex.org, focusing on cross-referencing.
  - Learned the `\label` and `\ref` mechanism for creating internal document references to sections, subsections, and equations.
  - Used the tilde `~` (non-breaking space) before `\ref` to prevent line breaks between the reference label text and the reference number.
  - Explored the `hyperref` package to turn cross-references into clickable hyperlinks, using the `[hidelinks]` option for a clean visual appearance without colored boxes.
  - **Milestone:** Successfully completed Lesson 10 from learnlatex.org, focusing on mathematics.
  - Learned the two main math modes: inline math with `$...$` and display math with `\[...\]`, understanding how display math centers equations on their own line.
  - Practiced superscripts (`^{}`) and subscripts (`_{}`) notation, and used standard math functions like `\sin` and `\log`.
  - Typeset integrals (`\int`) with upper and lower limits, used `\infty` for infinity symbols, and learned the `\,` thin-space command for proper spacing before differentials like `dx`.
  - Created a custom `\diff` command using `\mathop{}` and `\!` for typographically correct differential notation, with options for both italic and upright `d`.
  - Used the `equation` environment for automatically numbered display equations, as opposed to unnumbered `\[...\]`.
  - Explored the `amsmath` package for advanced math typesetting: `align*` for multi-line aligned equations with `&` alignment markers, and `\binom{n}{k}` for binomial coefficients.
  - Learned the matrix environments from `amsmath`: `matrix` (plain), `pmatrix` (parenthesised), and `bmatrix` (bracketed).
  - Explored math-mode font commands: `\mathbf` for bold (Latin letters only), `\mathit` for math italic, `\mathrm` for upright Roman, and `\text` (which inherits surrounding text style — a subtle but important distinction).
  - **More on Mathematics (advanced topics):**
  - Used `gather` for centering multiple equations without alignment, and `multline` for breaking long single equations across lines.
  - Explored multi-column alignments with `align*` using multiple `&` pairs, and the `aligned` sub-environment for inline equation groups with delimiter pairing (`\left.\begin{aligned}...\end{aligned}\right\}`).
  - Learned about vertical positioning of `aligned` blocks using `[t]` to top-align with surrounding content like list items.
  - Used `\boldmath` for bolding entire expressions and the `bm` package for selectively bolding individual symbols including Greek letters (`\bm{\alpha}`), which `\mathbf` cannot handle.
  - Explored the `mathtools` package for enhanced matrix environments with alignment options (`pmatrix*[r]` for right-aligned entries).
  - Learned about `unicode-math` package used with `lualatex` engine for OpenType math fonts (`\setmathfont`) and Unicode math alphabet commands (`\symfrak`, `\symbf`, `\symcal`, `\symscr`, `\symbb`).
  - **Milestone:** Successfully completed Lesson 11 from learnlatex.org, focusing on formatting — fonts and spacing.
  - Learned to use the `parskip` package with the `[parfill]` option to replace paragraph indentation with vertical whitespace between paragraphs, which is a common preference for non-book documents.
  - Practiced explicit spacing commands: `\hspace{1cm}` for inserting horizontal space and `\vspace{10cm}` for inserting vertical space within the document flow.
  - Explored the argument-based font formatting commands: `\textbf` (bold), `\textit` (italic), `\textrm` (roman), `\textsf` (sans serif), `\texttt` (monospaced), and `\textsc` (small caps).
  - Learned the distinction between argument-based commands (e.g., `\textit{text}`) and declaration-style commands (e.g., `{\itshape text}`), understanding that declarations apply to all following text within their group and can span multiple paragraphs.
  - Used font size commands (`\large`, `\small`) within groups, learning the importance of ending a paragraph with `\par` before closing the group to ensure the size change applies to the entire last line (including line spacing).
  - Explored `\noindent` to suppress the default paragraph indentation for a single paragraph without globally changing the document's indentation behavior.
  - **Milestone:** Successfully completed Lesson 12 from learnlatex.org, focusing on citations and references.
  - Created `learnlatex.bib` as a shared bibliography database containing `@article` (Thomas2008) and `@book` (Graham1995) entries with fields like `author`, `title`, `journal`, `year`, `doi`, etc.
  - Learned the older **BibTeX workflow with `natbib`**: used `\cite` for basic citations, `\citep` for parenthetical citations (with optional `[page]` and `[prenote][page]` arguments), `\bibliographystyle{plainnat}` for formatting, and `\bibliography{learnlatex}` to generate the reference list.
  - Learned the modern **`biblatex` workflow with `biber`**: used `\addbibresource{learnlatex.bib}` in the preamble, `\autocite` for automatic context-dependent citations, `\parencite` for parenthetical, `\textcite` for textual/narrative citations, `\citetitle` for title-only citations, and `\printbibliography` to render the reference list.
  - Understood the key difference: `natbib` uses `bibtex` as backend, while `biblatex` uses `biber` by default (unless `backend=bibtex` is explicitly specified).
  - Discovered that `bibtex` cannot process `.aux` files generated by `biblatex` — they write auxiliary data in incompatible formats.
  - Learned that `biber` requires `--input-directory` and `--output-directory` flags when the build artifacts are in a separate directory (unlike `bibtex` which accepts a direct path to the `.aux` file).
  - Created `genPdfWithCitation.sh` to automate the 4-step citation compilation workflow, with preamble-based auto-detection of the bibliography backend (parsing for `\usepackage{biblatex}` while skipping commented lines and checking for `backend=bibtex` override).

## 2026-05-14
- **LearnLatex.org Tutorial (continued):**
  - **Milestone:** Successfully completed Lesson 13 from learnlatex.org, focusing on structuring longer documents.
  - Learned the `\input` command to split a large document into separate `.tex` files for frontmatter, chapters, appendices, and backmatter — creating a multi-file book structure.
  - Created `les13_01.tex` as a master document using `\documentclass{book}` with `\frontmatter`, `\mainmatter`, and `\appendix` sectioning, `\tableofcontents`, and `biblatex`/`biber` for bibliography.
  - Created supporting structure files: `front.tex`, `chap1.tex`, `chap2.tex`, `append.tex`, `pref.tex`, `frontcover.tex`, `backcover.tex`, `copyright.tex`, and `dedication.tex`.
  - Explored the `imakeidx` package for creating document indices using `\index{keyword}` entries and `\printindex`.
  - Discovered that `imakeidx`'s automatic `makeindex` invocation (via `\write18`) fails when using `-output-directory=./build` because `makeindex` looks for the `.idx` file in the current directory, not in `./build/`. Fixed by adding the `noautomatic` option to `\makeindex`.
  - Created `genPdfWithIndex.sh` to automate the 3-step index compilation workflow: pdflatex → makeindex (targeting `./build/*.idx`) → pdflatex.
  - Refactored both `genPdfWithCitation.sh` and `genPdfWithIndex.sh` to extract the repeated `pdflatex` command into a `PDFLATEX_CMD` variable, improving DRY maintainability — now any flag change only needs one edit per script.
  - **Milestone:** Successfully completed Lesson 14 from learnlatex.org, focusing on Fonts and Unicode Engines (XeTeX and LuaTeX).
  - Learned about the transition from 8-bit `pdflatex` to Unicode-aware engines like `xelatex` and `lualatex`.
  - Explored the `fontspec` package, which replaces `fontenc` for Unicode engines and allows easy use of system OpenType and TrueType fonts.
  - Learned the difference between font lookup by filename (e.g., `\setmainfont{texgyretermes-regular.otf}`) and by system font name (e.g., `\newfontfamily\kannadafont{Noto Serif Kannada}`).
  - Successfully typeset a multi-script document (`les14_01.tex`) containing Latin, Greek, Chinese (using Fandol fonts), and Kannada (using Noto Serif Kannada) scripts.
  - Explored the unique capability of LuaTeX to execute Lua code directly within the LaTeX document using `\directlua`, demonstrated in `les14_more_01.tex`.
  - Created `genPdfWithXelatex.sh` and `genPdfWithLualatex.sh` to automate the compilation workflow for these modern engines, routing all outputs to the isolated `build/` directory.
  - Fixed a flag mismatch in `genPdfWithXelatex.sh` (removed unsupported `-output-format=pdf`) and ensured `genPdfWithLualatex.sh` uses the correct `--output-directory` syntax.
  - **Milestone Reached:** Completed all lessons from learnlatex.org! The project has matured significantly, evolving from basic "Hello World" documents to complex multi-file structures with modern Unicode support and automated build pipelines.
  - **Future Outlook:** With the core fundamentals solidified, the next phase will focus on advanced technical illustrations using the TikZ package.

I might start with 
- [Drawing feature](https://www.learnlatex.org/en/extra-01#drawing) which use Tikz. For this, I plan to follow the pdf suggested which is available [here](https://texdoc.org/serve/tikz/0).

## 2026-05-15
- **TikZ & PGF Manual Study:**
  - Started the next major learning path: **TikZ & PGF** for technical drawings.
  - Created a new directory `tikzPgf_manual/` to house exercises from the official manual.
  - **Chapter 1: Introduction:**
    - Explored the basic concepts and wrote the first drawing script `ch01/drawing_001.tex`.
  - **Chapter 2: Tutorial: A Picture for Karl’s Students:**
    - Began the famous tutorial from the manual.
    - Worked through section 2.2 and 2.3, creating `ch02/ch2p2p1_001.tex` and `ch02/ch2p3.tex`.
    - Progressed through sections 2.4 and 2.5, implementing various drawing components in `ch02/ch2p4_001.tex`, `ch02/ch2p4_002.tex`, `ch02/ch2p5_001.tex`, and `ch02/ch2p5_002.tex`.
    - **TikZ Expansion (Sections 2.6 - 2.8):**
      - Implemented Rectangle Path Construction in `ch02/ch2p6_001.tex`.
      - Learned Grid Path Construction in `ch02/ch2p7_001.tex`.
      - Explored Styling Grids (colors, styles, help lines) in `ch02/ch2p8_001.tex` and `ch02/ch2p8_002.tex`.
  - **Documentation Maintenance:**
    - Updated the repository's core documentation (`README.md`, `CHANGELOG.md`, `RELEASE_NOTES.md`) and refined the TikZ manual's internal `README.md`.
    - Verified and updated `.gitignore` to ensure all LaTeX and TikZ-specific artifacts are correctly handled.
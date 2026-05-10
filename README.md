# Learning Latex

Learning Latex tool

1. [latexIn30Min](./latexIn30Min): 
- Source: [Learn LaTeX in 30 minutes](https://www.overleaf.com/learn/latex/Learn_LaTeX_in_30_minutes): Course from overleaf.

2. [learnLatex_org](./learnLatex_org/):
- Source: [https://www.learnlatex.org/en/](https://www.learnlatex.org/en/)
- Available in other languages too. Check [https://www.learnlatex.org/](https://www.learnlatex.org/)


## Environment setup instruction

1. Create `build` folder where you are running the bash scripts.

## Conversion tools

### `latex`

General usage: `latex <filename.tex>`
Project usage: `bash genDvi.sh <filename.tex>`
Generates `dvi` files.

```console
$ latex --version
pdfTeX 3.141592653-2.6-1.40.26 (TeX Live 2025/dev/Debian)
kpathsea version 6.4.0/dev
Copyright 2024 Han The Thanh (pdfTeX) et al.
There is NO warranty.  Redistribution of this software is
covered by the terms of both the pdfTeX copyright and
the Lesser GNU General Public License.
For more information about these matters, see the file
named COPYING and the pdfTeX source.
Primary author of pdfTeX: Han The Thanh (pdfTeX) et al.
Compiled with libpng 1.6.47; using libpng 1.6.48
Compiled with zlib 1.3.1; using zlib 1.3.1
Compiled with xpdf version 4.04
```

### `pdflatex`

General usage: `pdflatex <filename.tex>`
Project usage: `bash genPdf.sh <filename.tex>`
Generates `pdf` files.

```console
$ pdflatex --version
pdfTeX 3.141592653-2.6-1.40.26 (TeX Live 2025/dev/Debian)
kpathsea version 6.4.0/dev
Copyright 2024 Han The Thanh (pdfTeX) et al.
There is NO warranty.  Redistribution of this software is
covered by the terms of both the pdfTeX copyright and
the Lesser GNU General Public License.
For more information about these matters, see the file
named COPYING and the pdfTeX source.
Primary author of pdfTeX: Han The Thanh (pdfTeX) et al.
Compiled with libpng 1.6.47; using libpng 1.6.48
Compiled with zlib 1.3.1; using zlib 1.3.1
Compiled with xpdf version 4.04
```

### `dvisvgm`

Converts `dvi` files to `svg` files.
General usage: 
- `dvisvgm <filename.dvi>`
- `dvisvgm --no-font --no-merge <filename.dvi>`
Project usage: `bash genSvg.sh <filename.tex>`

```console
$ dvisvgm --version
dvisvgm 3.4.4
```

### `pdftoppm`

Converts `pdf` files to `png` files.
General usage: `pdftoppm -r 300 -png <filename.pdf> <output_name>`
Project usage: `bash genPng.sh <filename.tex>`

```console
$ pdftoppm -v
pdftoppm version 25.03.0
Copyright 2005-2025 The Poppler Developers - http://poppler.freedesktop.org
Copyright 1996-2011, 2022 Glyph & Cog, LLC
```

**Note:** At this instant we prefer `pdftoppm` tool to generate `png` files over `dvipng` which takes `dvi` files as input; because, quality of the output was better from `pdftoppm` and i do not have time to tinker with `dvipng`.
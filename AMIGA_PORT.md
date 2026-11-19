# Diamond Girl for GFOS

Lucy the Diamond Girl (Boulder Dash-like puzzle) for GFOS: AmigaOS 3.2 with GFOpenUp, on a 68040/68060 with FPU, using GFOpenUp's SDL2.module (SDL2_image / SDL2_mixer as needed) and GFOpenGPU.

Target: Cradle boards / os32-gcc16-open6 stove.

## Source

- Upstream: https://github.com/Peanhua/diamond-girl (GPL-2.0)
- Pin: master (as of 2026-11-19)
- Alternative historical: Joni Yrjana diamond-girl-2.0.1.tar.xz (GPL)

## Status

Source pinned. First stove build and packaging still to do.

## Build target

    STOVE=~/AmiCradle/stoves/os32-gcc16-open6

Uses shared OpenUp libraries (LIBS:GFOpenGPU/SDL2.module). Data path PROGDIR:. 68040 fit expected for this 2D title.

## Next

1. Fetch and vendor or submodule the pin.
2. Adapt autotools/Makefile for the stove (no host SDL; use OpenUp modules).
3. Package data under PROGDIR: and run first Cradle test (input, audio, exit).

Designed, tested and delivered by The AmiCradle Team.

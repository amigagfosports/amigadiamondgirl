# Diamond Girl for GFOS

Lucy the Diamond Girl (Boulder Dash-like puzzle) for GFOS: AmigaOS 3.2 with GFOpenUp, on a 68040/68060 with FPU, using GFOpenUp's SDL2.module and GFOpenGPU.

Target: Cradle boards / os32-gcc16-open6 stove.

## Source

- Upstream: https://github.com/Peanhua/diamond-girl (GPL-2.0)
- Pin: master (as of 2026-11-19)
- Build system: autotools. Main is SDL1.2.
- Upstream already contains `#if defined(AMIGA)` paths in get_data_filename.c and get_save_filename.c that use PROGDIR:.

## Status

Wiring done. Window-surface path in place:
- src/sdl1_to_sdl2.h — maps SDL_SetVideoMode, SDL_Flip, SDL_WM_SetCaption/Icon, events, surfaces
- src/dg_window.c — global window holder
- package/Makefile.amiga force-includes the shim (`-include ./src/sdl1_to_sdl2.h`) so every compile unit sees the mappings, and defines -DAMIGA so the upstream PROGDIR: paths activate
- package/build-amiga.sh now pins and fetches upstream into `upstream/`

Non-OpenGL path preferred for 68040.

Graphics presentation: the new overlay presentation offered via OpenLayout (with OpenGFX) is the preferred path for the Cradle boards. This reduces the need for full SDL surface emulation. The Makefile link step notes this; the surface path remains as a fallback while the overlay route is wired.

## Build target

    STOVE=~/AmiCradle/stoves/os32-gcc16-open6

Uses shared OpenUp libraries (LIBS:GFOpenGPU/SDL2.module). Data path PROGDIR: (activated by -DAMIGA). 68040 fit expected for this 2D title.

## Next

1. Run `package/build-amiga.sh` to fetch upstream into `upstream/`.
2. First stove build: `cd package && make -f Makefile.amiga` (compiles core sources with the shim; expand the UPSTREAM_SRCS list from upstream/src/Makefile.am as needed).
3. Route presentation through the OpenLayout overlay + OpenGFX path (preferred over full SDL surface).
4. Cradle lab test (input, audio, exit).

Designed, tested and delivered by The AmiCradle Team.

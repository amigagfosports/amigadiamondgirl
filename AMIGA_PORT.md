# Diamond Girl for GFOS

Lucy the Diamond Girl (Boulder Dash-like puzzle) for GFOS: AmigaOS 3.2 with GFOpenUp, on a 68040/68060 with FPU, using GFOpenUp's SDL2.module and GFOpenGPU.

Target: Cradle boards / os32-gcc16-open6 stove.

## Source

- Upstream: https://github.com/Peanhua/diamond-girl (GPL-2.0)
- Pin: master (as of 2026-11-19)
- Build system: autotools. Main is SDL1.2.

## Status

Port underway. Window-surface path in place:
- src/sdl1_to_sdl2.h — maps SDL_SetVideoMode, SDL_Flip, SDL_WM_SetCaption/Icon, events, surfaces
- src/dg_window.c — global window holder
Non-OpenGL path preferred for 68040. Data path adaptation and first stove build still to do.

## Build target

    STOVE=~/AmiCradle/stoves/os32-gcc16-open6

Uses shared OpenUp libraries (LIBS:GFOpenGPU/SDL2.module). Data path PROGDIR:. 68040 fit expected for this 2D title.

## Next

1. Include the shim in gfx.c / main.c and wire the window-surface path.
2. Adapt data paths to PROGDIR:.
3. First stove build and Cradle lab test (input, audio, exit).

Designed, tested and delivered by The AmiCradle Team.

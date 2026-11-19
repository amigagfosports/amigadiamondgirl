# Diamond Girl for GFOS

Lucy the Diamond Girl (Boulder Dash-like) for GFOS / OpenUp on Cradle boards.

## Status

Port in progress on this branch (`team3/diamondgirl-port-20261119`).

- Source pin: https://github.com/Peanhua/diamond-girl (GPL-2.0)
- Shim: `src/sdl1_to_sdl2.h` (SDL1.2 → SDL2 window surface)
- Preferred presentation: OpenLayout overlay + OpenGFX
- Build: `package/build-amiga.sh` then `cd package && make -f Makefile.amiga`
- Target stove: `os32-gcc16-open6`

See `AMIGA_PORT.md` for the full notes.

Designed, tested and delivered by The AmiCradle Team.

#!/bin/sh
# Diamond Girl for GFOS on OpenUp
# Target: Cradle boards / os32-gcc16-open6 stove
# Uses shared OpenUp libraries (SDL2.module / GFOpenGPU)
# Non-OpenGL window-surface path preferred for 68040
# Graphics presentation: OpenLayout overlay + OpenGFX (preferred on Cradle boards)

set -e
STOVE="${STOVE:-$HOME/AmiCradle/stoves/os32-gcc16-open6}"
UPSTREAM="https://github.com/Peanhua/diamond-girl.git"
PIN="master"   # pin as of 2026-11-19

echo "Diamond Girl — GFOS / OpenUp build"
echo "STOVE=$STOVE"
echo "Upstream: $UPSTREAM ($PIN)"

if [ ! -d "$STOVE/bin" ]; then
  echo "Stove not found at $STOVE — set STOVE= or install os32-gcc16-open6"
  exit 1
fi

# Vendor upstream once if missing
if [ ! -d upstream ]; then
  echo "Fetching upstream (one-time)..."
  git clone --depth 1 --branch "$PIN" "$UPSTREAM" upstream
else
  echo "upstream/ already present"
fi

echo "Next: cd package && make -f Makefile.amiga"
echo "Link uses OpenUp SDL2.module (-lSDL2 -lSDL2_image)"
echo "Data path: PROGDIR: (activated by -DAMIGA)"
exit 0

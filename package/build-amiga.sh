#!/bin/sh
# Diamond Girl for GFOS on OpenUp
# Target: Cradle boards / os32-gcc16-open6 stove
# Uses shared OpenUp libraries (SDL2.module / GFOpenGPU)

set -e
STOVE="${STOVE:-$HOME/AmiCradle/stoves/os32-gcc16-open6}"
echo "Diamond Girl build skeleton"
echo "STOVE=$STOVE"
echo "Next: fetch Peanhua/diamond-girl, adapt for OpenUp SDL2.module, package PROGDIR: data"
exit 0

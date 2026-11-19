/* SDL1.2 -> SDL2 compatibility shims for Diamond Girl on GFOS/OpenUp
 * Target: Cradle boards / os32-gcc16-open6 stove
 * Uses OpenUp SDL2.module
 *
 * Minimal mapping for the calls Diamond Girl actually uses.
 * Expand as the port progresses.
 */
#ifndef SDL1_TO_SDL2_H
#define SDL1_TO_SDL2_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* SDL1 joystick names */
#define SDL_JoystickOpen   SDL_JoystickOpen
#define SDL_JoystickClose  SDL_JoystickClose
#define SDL_NumJoysticks   SDL_NumJoysticks

/* SDL1 init flags that still exist */
#ifndef SDL_INIT_JOYSTICK
#define SDL_INIT_JOYSTICK SDL_INIT_JOYSTICK
#endif

/* SDL1 surface -> SDL2 texture/renderer notes:
 * Diamond Girl draws via SDL_Surface. On OpenUp we will route through
 * SDL2 renderer + textures. Full surface emulation is the next step.
 */

#endif /* SDL1_TO_SDL2_H */

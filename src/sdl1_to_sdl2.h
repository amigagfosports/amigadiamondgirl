/* SDL1.2 -> SDL2 compatibility shims for Diamond Girl on GFOS/OpenUp
 * Target: Cradle boards / os32-gcc16-open6 stove
 * Uses OpenUp SDL2.module
 *
 * Maps the SDL1 calls Diamond Girl actually uses.
 * Surface drawing still needs renderer/texture work.
 */
#ifndef SDL1_TO_SDL2_H
#define SDL1_TO_SDL2_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* Init / subsystem */
#define SDL_INIT_VIDEO     SDL_INIT_VIDEO
#define SDL_INIT_JOYSTICK  SDL_INIT_JOYSTICK

/* Joystick */
#define SDL_JoystickOpen   SDL_JoystickOpen
#define SDL_JoystickClose  SDL_JoystickClose
#define SDL_NumJoysticks   SDL_NumJoysticks
#define SDL_JoystickName   SDL_JoystickName

/* Events (most names unchanged) */
#define SDL_KEYDOWN        SDL_KEYDOWN
#define SDL_KEYUP          SDL_KEYUP
#define SDL_MOUSEBUTTONDOWN SDL_MOUSEBUTTONDOWN
#define SDL_MOUSEBUTTONUP  SDL_MOUSEBUTTONUP
#define SDL_MOUSEMOTION    SDL_MOUSEMOTION
#define SDL_JOYAXISMOTION  SDL_JOYAXISMOTION
#define SDL_JOYBUTTONDOWN  SDL_JOYBUTTONDOWN
#define SDL_JOYBUTTONUP    SDL_JOYBUTTONUP

/* Buttons */
#define SDL_BUTTON_LEFT    SDL_BUTTON_LEFT
#define SDL_BUTTON_MIDDLE  SDL_BUTTON_MIDDLE
#define SDL_BUTTON_RIGHT   SDL_BUTTON_RIGHT

/* Surface helpers that still exist or need stubs */
#define SDL_CreateRGBSurface SDL_CreateRGBSurface
#define SDL_FreeSurface    SDL_FreeSurface
#define SDL_LockSurface    SDL_LockSurface
#define SDL_UnlockSurface  SDL_UnlockSurface
#define SDL_FillRect       SDL_FillRect
#define SDL_BlitSurface    SDL_BlitSurface
#define SDL_ConvertSurface SDL_ConvertSurface
#define SDL_GetRGB         SDL_GetRGB
#define SDL_GetRGBA        SDL_GetRGBA
#define SDL_GetError       SDL_GetError

/* SDL1 Flip -> SDL2 RenderPresent (needs renderer context) */
/* TODO: provide a global renderer and map SDL_Flip to SDL_RenderPresent */

/* OpenGL path (optional; prefer non-GL for 68040) */
/* SDL_GL_* calls can be stubbed or routed through GFOpenGPU if needed */

#endif /* SDL1_TO_SDL2_H */

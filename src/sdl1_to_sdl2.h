/* SDL1.2 -> SDL2 compatibility shims for Diamond Girl on GFOS/OpenUp
 * Target: Cradle boards / os32-gcc16-open6 stove
 * Uses OpenUp SDL2.module
 *
 * Uses SDL2 window surface so existing SDL_Surface drawing can stay.
 * Non-OpenGL path preferred for 68040.
 */
#ifndef SDL1_TO_SDL2_H
#define SDL1_TO_SDL2_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* Global window for the surface path */
extern SDL_Window * dg_window;

/* SDL_SetVideoMode -> create window and return its surface */
static inline SDL_Surface * SDL_SetVideoMode(int w, int h, int bpp, Uint32 flags)
{
  (void)bpp;
  Uint32 wflags = SDL_WINDOW_SHOWN;
  if (flags & SDL_FULLSCREEN) wflags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
  if (!dg_window)
    dg_window = SDL_CreateWindow("Diamond Girl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, wflags);
  if (!dg_window) return NULL;
  return SDL_GetWindowSurface(dg_window);
}

/* SDL_Flip -> update the window surface */
static inline int SDL_Flip(SDL_Surface * screen)
{
  (void)screen;
  if (dg_window) return SDL_UpdateWindowSurface(dg_window);
  return -1;
}

/* SDL_WM_SetCaption -> window title */
static inline void SDL_WM_SetCaption(const char * title, const char * icon)
{
  (void)icon;
  if (dg_window) SDL_SetWindowTitle(dg_window, title);
}

/* SDL_WM_SetIcon -> window icon (optional) */
static inline void SDL_WM_SetIcon(SDL_Surface * icon, Uint8 * mask)
{
  (void)mask;
  if (dg_window && icon) SDL_SetWindowIcon(dg_window, icon);
}

/* Init / subsystem */
#define SDL_INIT_VIDEO     SDL_INIT_VIDEO
#define SDL_INIT_JOYSTICK  SDL_INIT_JOYSTICK

/* Joystick */
#define SDL_JoystickOpen   SDL_JoystickOpen
#define SDL_JoystickClose  SDL_JoystickClose
#define SDL_NumJoysticks   SDL_NumJoysticks
#define SDL_JoystickName   SDL_JoystickName

/* Events */
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

/* Surface helpers */
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

/* Stub OpenGL path for non-GL builds */
#define SDL_GL_SetAttribute(a,b) (0)
#define SDL_GL_SwapBuffers()     (0)

#endif /* SDL1_TO_SDL2_H */

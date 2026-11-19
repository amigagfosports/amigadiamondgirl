/* OpenLayout overlay presentation stub for Diamond Girl on GFOS/OpenUp
 * Preferred path on Cradle boards: present via OpenLayout + OpenGFX
 * rather than full SDL window-surface emulation.
 *
 * This is a placeholder. Once the overlay API is confirmed on the stove,
 * wire SDL_Flip / present here to push the game surface through OpenLayout.
 *
 * Fallback remains the SDL2 window surface path in sdl1_to_sdl2.h.
 */

#include "sdl1_to_sdl2.h"

/* Stub: called in place of (or after) SDL_UpdateWindowSurface when
 * OpenLayout overlay is available.
 */
int dg_openlayout_present(SDL_Surface *screen)
{
  (void)screen;
  /* TODO: OpenLayout overlay + OpenGFX blit of the game surface */
  if (dg_window)
    return SDL_UpdateWindowSurface(dg_window);
  return -1;
}

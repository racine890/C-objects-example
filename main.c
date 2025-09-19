/***
yellow Emoji, par kanok Burkina
Un joli petit projet en moins de 130 lignes de codes en mimant le modèle objet.
**/
#include "Classes.h"

int main ( int argc, char** argv )
{
    ///On initialise tout ce dont on a besoin
    SDL_Init( SDL_INIT_VIDEO );
    SDL_Event event;
    SDL_Surface* screen = SDL_SetVideoMode(200, 200, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    ///Maintenant, on prépare les 4 sprites de yellow
    SDL_Surface* down = SDL_LoadBMP("bas.bmp");
    SDL_Surface* up = SDL_LoadBMP("haut.bmp");
    SDL_Surface* left = SDL_LoadBMP("gauche.bmp");
    SDL_Surface* right = SDL_LoadBMP("droite.bmp");
    ///On les met dans un tableau,
    SDL_Surface *sprites[4] = {right, left, up, down};
    ///Puis on crée Yellow avec son tableau de sprites!
    Emoji yellow;
    E_init(&yellow, sprites);
    ///On l'affiche pour commencer
    print(&yellow, screen);

    int done = 1;
    ///La boucle infinie, comme d'hab
    while (done)
    {
        ///On aura pas besoin de PollEvent. Wait suffira
        SDL_WaitEvent(&event);
            switch (event.type)
            {
            case SDL_QUIT:
                done = 0;///On quitte
                break;
            case SDL_KEYDOWN:
                {
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            done = 0;///On quitte aussi
                            break;
                        case SDLK_UP:
                            move_up(&yellow);   ///yellow se déplace vers le haut
                            break;
                        case SDLK_DOWN:
                            move_down(&yellow); ///yellow se déplace vers le bas
                            break;
                        case SDLK_LEFT:
                            move_left(&yellow); ///yellow se déplace vers la gauche
                            break;
                        case SDLK_RIGHT:
                            move_right(&yellow);    ///yellow se déplace vers la droite
                            break;
                        default: break;
                }
            }
        }
    print(&yellow, screen); ///On l'affiche
    }
    ///On libère la RAM
    SDL_FreeSurface(left);
    SDL_FreeSurface(right);
    SDL_FreeSurface(down);
    SDL_FreeSurface(up);
    SDL_FreeSurface(screen);
    ///Ouf, c'est tout! Je suppose que vous avez déja des idées, pour faire des
    ///jeux!
    return 0;
    }

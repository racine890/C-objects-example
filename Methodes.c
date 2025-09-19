#include "Classes.h"

///Comme pour tout constructeur on initialise les valeurs.
///On choisit que le sprite soit en bas dès sa création
void E_init(Emoji *yellow,SDL_Surface *sprite[4])
{
    yellow ->e_positionx = downx;
    yellow ->e_positiony = downy;
    yellow ->e_sprite[DOWN] = sprite[DOWN];
    yellow ->e_sprite[UP] = sprite[UP];
    yellow ->e_sprite[LEFT] = sprite[LEFT];
    yellow ->e_sprite[RIGHT] = sprite[RIGHT];
    yellow ->e_actualSprite = sprite[DOWN];
}
///Pour le faire se déplacer, on change le sprite actuel, l'abcisse et l'oordonnée
void move_left(Emoji *yellow){
    yellow->e_actualSprite = yellow->e_sprite[LEFT];
    yellow ->e_positionx = leftx;
    yellow ->e_positiony = lefty;
}

void move_right(Emoji *yellow){
    yellow->e_actualSprite = yellow->e_sprite[RIGHT];
    yellow ->e_positionx = rightx;
    yellow ->e_positiony = righty;
}

void move_up(Emoji *yellow){
    yellow->e_actualSprite = yellow->e_sprite[UP];
    yellow ->e_positionx = upx;
    yellow ->e_positiony = upy;
}

void move_down(Emoji *yellow){
    yellow->e_actualSprite = yellow->e_sprite[DOWN];
    yellow ->e_positionx = downx;
    yellow ->e_positiony = downy;
}

/**
Affichons yellow! Remplissons l'écran de blanc pour éviter les traces,
chargeons le background, rendons yellow transparent et enfin affichons le!
On N'oublie pas de mettre à jour l'écran!
**/
void print(Emoji *yellow, SDL_Surface *screen)
{
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 100, 255, 255));
    SDL_Surface *bg = SDL_LoadBMP("background.bmp");
    SDL_Rect nul;
    nul.x = 0; nul.y = 0;
    SDL_BlitSurface(bg, NULL, screen, &nul);
    SDL_SetColorKey(yellow->e_actualSprite, SDL_SRCCOLORKEY, SDL_MapRGB
                    (yellow->e_actualSprite->format, 0, 0, 255));
    SDL_Rect pos;
    pos.x = yellow->e_positionx;
    pos.y = yellow->e_positiony;
    SDL_BlitSurface(yellow->e_actualSprite,NULL,screen,&pos);
    SDL_Flip(screen);
}

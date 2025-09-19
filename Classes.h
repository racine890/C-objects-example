#include <SDL/SDL.h>

///Fixons les positions de yellow
#define upx 49
#define upy 0
#define downx 49
#define downy 130
#define leftx -20
#define lefty 44
#define rightx 120
#define righty 44
///Puis on fait un petit enum super utile
enum{RIGHT, LEFT, UP, DOWN};

/**La classe Emoji. Il aura 4 sprites, un sprite à afficher à la fois, une abcisse
et une ordonnée.***/
typedef struct Emoji{
    SDL_Surface *e_sprite[4];
    SDL_Surface *e_actualSprite;
    int e_positionx;
    int e_positiony;
}Emoji;

///Ses méthodes, c'est déja vu!
void E_init(Emoji *yellow,SDL_Surface *sprite[]);
void move_left(Emoji *yellow);
void move_right(Emoji *yellow);
void move_down(Emoji *yellow);
void move_up(Emoji *yellow);
void print(Emoji *yellow, SDL_Surface *screen);

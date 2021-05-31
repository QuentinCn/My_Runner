/*
** EPITECH PROJECT, 2020
** my_runner.h
** File description:
** .h of my_runner
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>

typedef sfRenderWindow sfRW;
typedef sfVideoMode sfVM;

typedef struct info_sound
{
    sfSoundBuffer *buffer;
    sfSound *sound;
}t_sound;

typedef struct info_back
{
    sfSprite *S1;
    sfTexture *T1;
    sfSprite *S2;
    sfTexture *T2;
    sfSprite *S3;
    sfTexture *T3;
    sfSprite *S4;
    sfTexture *T4;
    sfVector2u size;
    sfVector2f scale;
}t_back;

typedef struct info_run
{
    sfSprite *Srun;
    sfTexture *Trun1;
    sfTexture *Trun2;
    sfTexture *Trun3;
    sfTexture *Trun4;
    sfTexture *Trun5;
    sfTexture *Trun6;
    sfVector2f scale;
    sfVector2f pos;
}t_run;

typedef struct info_jump
{
    sfSprite *Sjump;
    sfTexture *Tjump2;
    sfTexture *Tjump3;
    sfTexture *Tjump4;
    sfTexture *Tjump5;
    sfTexture *Tjump6;
    sfTexture *Tjump7;
    sfTexture *Tjump8;
    sfTexture *Tjump9;
    sfVector2f scale;
    sfVector2f pos;
}t_jump;

typedef struct info_explosion
{
    sfSprite *Sexplosion;
    sfTexture *T1;
    sfTexture *T2;
    sfTexture *T3;
    sfTexture *T4;
    sfTexture *T5;
    sfTexture *T6;
    sfTexture *T7;
    sfTexture *T8;
    sfTexture *T9;
    sfTexture *T10;
    sfTexture *T11;
    sfVector2f scale;
    sfVector2f pos;
}t_explosion;

typedef struct info_box
{
    sfSprite *Sbox;
    sfTexture *Tbox1;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f size;
}t_box;

typedef struct info_score
{
    sfText *point;
    int counter;
    sfVector2f score_pos;
    int len;
}t_score;

typedef struct info_list
{
    t_back back;
    sfVM video;
    sfRW *game;
    t_run run;
    t_jump jump;
    t_box box;
    sfSprite *copy;
    t_score score;
    t_sound st_sound;
    int i;
    int j;
    int k;
    int check_copy;
}t_list;

int my_getnbr(char const *str);
char *my_strcat(char *str1, char const *str2);
int my_strlen(char const *str);
char *my_itoc(int nb);
char *my_revstr(char *str);
int my_putstr(char *str);
int my_runner(char *buffer);
int gameplay(int *pos, int level, t_list *list);
sfRW *draw_back(t_back *back, sfRW *game, sfVM video, int level);
t_back create_back(t_back back);
t_run create_run(t_run run, sfVM video);
sfRW *make_run(t_run *run, sfRW *game, sfVM video, int i);
sfRW *replace_run(t_run *run, sfRW *game, sfVM video, int i);
t_jump create_jump(t_jump jump, sfVM video);
void make_jump(t_list *list, int level);
sfTexture *create_texture_box(int left, int top, int width, int height);
t_box create_box(t_box box, sfVM video);
void make_box(t_list *list, int *pos, int level);
sfText *create_play_button(sfText *play, sfVideoMode video);
sfText *create_level_button(sfText *level, sfVideoMode video);
sfText *create_exit_button(sfText *exit, sfVideoMode video);
int menu(t_list *list);
void do_explosion(t_list list);
void do_explosion_with_copy(t_list list);
int check_for_shock(t_list list);
t_score create_score(t_score score, sfVM video);
sfRW *display_score(t_list *list);
t_list create_list(t_list list, sfRW *game);
int loose(t_list *list);
int check_clic(sfRenderWindow *menu, sfText *button);
sfRW *draw_text(sfRW *menu, sfText *play, sfText *level, sfText *exit);
sfRW *draw_back_static(t_back *back, sfRW *game, sfVM video);
int handle_error(int ac, char **av);
int check_for_shock_with_copy(t_list list);
sfText *create_high_score(t_score score, sfVM video);
void modify_high_score(sfText *text, sfText *old);
void make_copy(t_list *list, int *pos, int level);
int find_level(sfRW *game);
t_explosion change_text_1(t_explosion explosion, int i);
t_explosion change_text_2(t_explosion explosion, int i);
t_sound play_sound(char *filename);
sfMusic *play_music(char *filename);
void destroy_sound(t_sound *st_sound);
int do_switch_my_runner(int level, char *buffer, int *pos, t_list *list);
int find_number_pos(char *buffer);
int *find_box_pos(int *pos, char *buffer);
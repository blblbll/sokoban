/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** ncurses rendering
*/
#include "./include/my.h"

void init_display(void)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    if (!has_colors())
        return;
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLUE);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_WHITE, COLOR_RED);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_GREEN, COLOR_BLACK);
}

static void draw_cell(char c, int target)
{
    int pair = 0;
    char *glyph = "  ";

    if (c == '#' && (pair = 1))
        glyph = "##";
    if (c == 'X' && (pair = (target ? 4 : 3)))
        glyph = "[]";
    if (c == 'P' && (pair = 5))
        glyph = "@@";
    if ((c == 'O' || (c == ' ' && target)) && (pair = 2))
        glyph = "::";
    attron(COLOR_PAIR(pair) | (pair ? A_BOLD : 0));
    printw("%s", glyph);
    attroff(COLOR_PAIR(pair) | A_BOLD);
}

static void draw_row(char *row, char *vrow, int y, int x)
{
    move(y, x);
    for (int j = 0; row[j] != '\0'; j++)
        draw_cell(row[j], vrow[j] == 'O');
}

static void display_status(char **map, char **van, int y, int won)
{
    int ok = 0;
    int total = 0;
    int cols = getmaxx(stdscr);
    char *help = "fleches: bouger   espace: recommencer   ctrl+c: quitter";

    for (int i = 0; van[i] != NULL; i++)
        for (int j = 0; van[i][j] != '\0'; j++) {
            total += (van[i][j] == 'O');
            ok += (van[i][j] == 'O' && map[i][j] == 'X');
        }
    attron(COLOR_PAIR(7) | A_BOLD);
    mvprintw(y, (cols - 22) / 2, "Caisses placees : %d/%d", ok, total);
    attroff(COLOR_PAIR(7) | A_BOLD);
    if (won)
        mvprintw(y + 1, (cols - 25) / 2, "*** NIVEAU TERMINE ! ***");
    else
        mvprintw(y + 1, (cols - my_strlen(help)) / 2, "%s", help);
}

void displaymap(char **map, char **van, int won)
{
    int h = collen(map);
    int w = my_strlen(map[0]) * 2;
    int y0 = (getmaxy(stdscr) - (h + 5)) / 2;
    int x0 = (getmaxx(stdscr) - w) / 2;

    y0 = (y0 < 0) ? 0 : y0;
    x0 = (x0 < 0) ? 0 : x0;
    erase();
    attron(COLOR_PAIR(6) | A_BOLD);
    mvprintw(y0, (getmaxx(stdscr) - 7) / 2, "SOKOBAN");
    attroff(COLOR_PAIR(6) | A_BOLD);
    for (int i = 0; i < h; i++)
        draw_row(map[i], van[i], y0 + 2 + i, x0);
    display_status(map, van, y0 + h + 3, won);
    refresh();
}

#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <stdlib.h>


/**
 * @brief Prints wave on term
 * 
 * @param orx x coordenate origin
 * @param ory y coordenate origin
 * @param shift accumulative value to make animation
 */
void print_wave(int orx, int ory, int shift)
{
    int x, y;
    for(int i = -314; i < 314; i++) 
    {
        x = (orx + i);
        y = (ory + roundf(8 * (sin(x * 50))));
        
        mvaddch(y, (x - shift) * 4, ACS_CKBOARD);   
    }
    refresh();
}

int main()
{
    WINDOW *win = initscr();
    curs_set(0); //don't show cursor
    noecho(); //don't show what i type
    cbreak(); //process user input as it happens, don't save in buffer
    nodelay(win, TRUE); //don't block on getch()

    int ory = getmaxy(win) / 2;
    int orx = getmaxx(win) / 2;
    int c  = 0;
    char ch;
    
    while (1)
    {
        ch = wgetch(win);
        if(ch == 'q' || ch == 'Q') //getch() will return ERR when nothing is pressed and nodelay() is set to true
        {
            endwin();
            exit(EXIT_SUCCESS);
        }
        print_wave(orx, ory, c);
        c = (c + 1) % 23; //somehow it loops after 23 frames
        delay_output(50); //delay the execution 50ms for slower animation
        clear(); //clear screen


    }

    endwin();

    return 0;
}
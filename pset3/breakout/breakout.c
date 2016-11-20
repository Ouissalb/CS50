//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// height and width of paddel
#define height 20
#define width 80

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // keep playing until game over
   
     // initial velocity 
      
      
        double Xvelocity = 2.0;
        double Yvelocity = drand48() + 2.0;
        
    while (lives > 0 && bricks > 0)
    {         
        updateScoreboard(window, label, points);
        
        // move ball along a random angle
        move(ball, Xvelocity, Yvelocity);
        
         // linger before moving again
        pause(10);
        
         // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                 
                // ensure the paddle follows top cursor
                double x = getX(event) - getWidth(paddle) / 2; 
                if ( x > 0  && x < 400-80)
                 {         
                setLocation(paddle, x,490);
                  }
            }
      } 
     
     GObject object = detectCollision(window,ball);
     if (object != NULL)
     {         
       if (object == paddle)
       { 
       Yvelocity = - Yvelocity;
                  }
     
      }
       
       // When the ball hits a block
       else if (strcmp(getType(object),"GRect") == 0)
       { 
           removeGWindow(window, object);
           Yvelocity = - Yvelocity;
           bricks--;
           points--;
       }
       
        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            Xvelocity = -Xvelocity;
        }

        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            Xvelocity = -Xvelocity;
        }

        // bounce off top edge of window
        else if (getY(ball) <= 0)
        {
            Yvelocity = -Yvelocity;
        }
        
        // bounce off bottom
        if(getY(ball) + getHeight(ball) >= getHeight(window))
        {
            setLocation(ball,190,290);
            setLocation(paddle,160, 490);
            waitForClick();
        }
        
        // loosing
        
        if(bricks >0)
        {
            GLabel game_over = newGLabel("Game Over, you lost");
            setColor(game_over, "RED");
            add(window, game_over);
            setLocation(game_over,20,250);
   }
        
        else
          {
            GLabel game_over = newGLabel("You Won!");
            setColor(game_over, "GREEN");
            add(window, game_over);
            setLocation(game_over,20,250);
   }
       }
    

    // wait for click before exiting
    waitForClick();
 
    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
 
void initBricks(GWindow window)
{
    GRect rect;
    int x = 1;
    int y = 20;
    
        for ( int j = 0 ; j < ROWS; j++)
        { 
        for ( int i = 0 ; i < COLS; i++)
        {    
        rect = newGRect(x, y,37,10);
        setFilled(rect, true);
        switch ( j )
        {
            case 0 : setColor(rect, "RED"); break;
            case 1 : setColor(rect, "Black"); break;
            case 2 : setColor(rect, "PINK"); break;
            case 3 : setColor(rect, "GREEN"); break;
            default : setColor(rect, "YELLOW");break;       
}
        add(window, rect);
        x = x + 40;
               
}
        y = y + 12;
        x = 1;
        
}
}
/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(190,290,15,15);
    setFilled(ball, true);
    setColor(ball, "RED");
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
 
GRect initPaddle(GWindow window)
{
      GRect paddle = newGRect(160, 490, width, height);
      setFilled(paddle, true);
      setColor(paddle, "PINK");
      add(window, paddle ); 
      return paddle;     
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel;
    setColor(label, "RED");
    setLocation(label, 20,250 );
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#ifdef main
#undef main
#endif

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define shape_width 50
#define shape_height 50
#define element_width 20
#define element_height 20
#define max_size 50
#include "global .h"
Uint32 flag_of_rend=SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
// open shapes randomly
SDL_Surface* random_shape(SDL_Surface *surface_temp,int ran)
{
    switch(ran)
    {
        case 0:
            surface_temp= SDL_LoadBMP("grey.bmp");
            return surface_temp;
            break;
        case 1:
            surface_temp= SDL_LoadBMP("blue.bmp");
            check_color[1]=1;
            shape[i].color=1;
            shape[i].number=default_shape_number;
            return surface_temp;
            break;
        case 2:
            surface_temp= SDL_LoadBMP("green.bmp");
            check_color[2]=1;
            shape[i].color=2;
            shape[i].number=default_shape_number;
            return surface_temp;
            break;
        case 3:
            surface_temp= SDL_LoadBMP("orange.bmp");
            check_color[3]=1;
            shape[i].color=3;
            shape[i].number=default_shape_number;
            return surface_temp;
            break;
        case 4:
            surface_temp= SDL_LoadBMP("purple.bmp");
            check_color[4]=1;
            shape[i].color=4;
            shape[i].number=default_shape_number;
            return surface_temp;
            break;
        case 5:
            surface_temp= SDL_LoadBMP("yellow.bmp");
            check_color[5]=1;
            shape[i].color=5;
            shape[i].number=default_shape_number;
            return surface_temp;
            break;
        case 6:
            surface_temp= SDL_LoadBMP("seahex.bmp");
            check_color[6]=1;
            shape[i].color=6;
            shape[i].number=default_shape_number;
            return surface_temp;
            break;
    }
}
// pick a color randomly
int color_random()
{
    int n=rand()%6+1;
    if(check_color[n]==1)
        color_random();
    else
        return n;

}
// find free space for drawing a shape
void find_free_space(int dir)
{
    int temp=3;
    switch (dir)
    {
        case 0:

            while(temp<=9)
            {
                if(check_x[shape[i-1].x- (temp*shape_width)])
                {
                    temp+=3;
                    continue;
                }

                else
                {
                    shape[i].x=shape[i-1].x- (temp*shape_width);
                    break;
                }

            }
            break;
        case 1:
            while(temp<=9)
            {
                if(check_x[shape[i-1].x+ (temp*shape_width)])
                {
                    temp+=3;
                    continue;
                }

                else
                {
                    shape[i].x=shape[i-1].x+ (temp*shape_width);
                    break;
                }

            }
            break;
        case 2:
            while(temp<=9)
            {
                if(check_y[shape[i-1].y- (temp*shape_width)])
                {
                    temp+=3;
                    continue;
                }

                else
                {
                    shape[i].y=shape[i-1].y- (temp*shape_width);
                    break;
                }

            }
            break;
        case 3:
            while(temp<=9)
            {
                if(check_y[shape[i-1].y+ (temp*shape_width)])
                {
                    temp+=3;
                    continue;
                }

                else
                {
                    shape[i].y=shape[i-1].y+ (temp*shape_width);
                    break;
                }

            }
            break;

    }
}
// king or enemy
void draw_king_enemy(SDL_Renderer* rend1,SDL_Rect *dsrect,int x,int y,int n)
{
    dsrect->x=x+15;
    dsrect->y=y+15;
    dsrect->h=element_height;
    dsrect->w=element_width;
    SDL_Surface *surface_temp;
    if(n==1)
        surface_temp= SDL_LoadBMP("enemy.bmp");
    else
        surface_temp= SDL_LoadBMP("king.bmp");
    SDL_Texture *texture_temp = SDL_CreateTextureFromSurface(rend1,surface_temp);
    SDL_RenderCopy(rend1, texture_temp, NULL, dsrect);
    SDL_FreeSurface(surface_temp);
    SDL_DestroyTexture(texture_temp);
}
//draw a single shape
void draw_shape(SDL_Renderer* rend1,SDL_Rect *dsrect,int y,int x,int color)
{
    dsrect->x=x;
    dsrect->y=y;
    dsrect->h=shape_height;
    dsrect->w=shape_width;
    SDL_Surface *surface_temp;
    switch(color)
    {
        case 0:
            surface_temp= SDL_LoadBMP("grey.bmp");
            break;
        case 1:
            surface_temp= SDL_LoadBMP("blue.bmp");
            check_color[1]=1;
            shape[i].color=1;
            shape[i].number=default_shape_number;
            break;
        case 2:
            surface_temp= SDL_LoadBMP("green.bmp");
            check_color[2]=1;
            shape[i].color=2;
            shape[i].number=default_shape_number;
            break;
        case 3:
            surface_temp= SDL_LoadBMP("orange.bmp");
            check_color[3]=1;
            shape[i].color=3;
            shape[i].number=default_shape_number;
            break;
        case 4:
            surface_temp= SDL_LoadBMP("purple.bmp");
            check_color[4]=1;
            shape[i].color=4;
            shape[i].number=default_shape_number;
            break;
        case 5:
            surface_temp= SDL_LoadBMP("yellow.bmp");
            check_color[5]=1;
            shape[i].color=5;
            shape[i].number=default_shape_number;
            break;
        case 6:
            surface_temp= SDL_LoadBMP("seahex.bmp");
            check_color[6]=1;
            shape[i].color=6;
            shape[i].number=default_shape_number;
            break;
    }
    SDL_Texture *texture_temp = SDL_CreateTextureFromSurface(rend1, surface_temp);
    SDL_FreeSurface(surface_temp);
    SDL_RenderCopy(rend1, texture_temp, NULL, dsrect);
    SDL_DestroyTexture(texture_temp);

}
//draw neutral area
void draw_around_shape(SDL_Renderer* rend1,SDL_Rect* dsrect,int color)
{
    shape[4*(i%5+1)+1].x=shape[i].x;
    shape[4*(i%5+1)+1].y=shape[i].y+shape_width;
    shape[4*(i%5+1)+1].color=0;
    shape[4*(i%5+1)+1].number=default_shape_number;
    draw_shape(rend1,dsrect,shape[i].y+shape_width,shape[i].x,color);
    shape[4*(i%5+1)+2].x=shape[i].x;
    shape[4*(i%5+1)+2].y=shape[i].y-shape_width;
    shape[4*(i%5+1)+2].color=0;
    shape[4*(i%5+1)+2].number=default_shape_number;
    draw_shape(rend1,dsrect,shape[i].y-shape_width,shape[i].x,color);
    shape[4*(i%5+1)+3].x=shape[i].x+shape_width;
    shape[4*(i%5+1)+3].y=shape[i].y;
    shape[4*(i%5+1)+3].color=0;
    shape[4*(i%5+1)+3].number=default_shape_number;
    draw_shape(rend1,dsrect,shape[i].y,shape[i].x+shape_width,color);
    shape[4*(i%5+1)+4].x=shape[i].x-shape_width;
    shape[4*(i%5+1)+4].y=shape[i].y;
    shape[4*(i%5+1)+4].color=0;
    shape[4*(i%5+1)+4].number=default_shape_number;
    draw_shape(rend1,dsrect,shape[i].y,shape[i].x-shape_width,color);


}
// find next enemy's shape's direction randomly
void direction(int dir,SDL_Renderer *rend1,SDL_Rect* dsrect)
{
    switch (dir)
    {
        case 0:

            if(check_x[shape[i-1].x+3*shape_width]==1)
                direction(rand()%4+0,rend1,dsrect);
            else
            {
                //check if it is out of screen or not
                if(shape[i-1].x+3*shape_width<=screen_width)
                    shape[i].x=shape[i-1].x+3*shape_width;
                else
                    find_free_space(0);
                shape[i].y=shape[i-1].y;
                draw_shape(rend1,dsrect,shape[i].y,shape[i].x,color_random());
                draw_king_enemy(rend1,dsrect,shape[i].x,shape[i].y,1);

            }
            break;

        case 1:
            if(check_x[shape[i-1].x-3*shape_width]==1)
                direction(rand()%4+0,rend1,dsrect);
            else
            {
                //check if it is out of screen or not
                if(shape[i-1].x-3*shape_width>=0)
                    shape[i].x=shape[i-1].x-3*shape_width;
                else
                    find_free_space(1);
                shape[i].y=shape[i-1].y;
                draw_shape(rend1,dsrect,shape[i].y,shape[i].x,color_random());
                draw_king_enemy(rend1,dsrect,shape[i].x,shape[i].y,1);

            }
            break;

        case 2:
            if(check_y[shape[i-1].y+3*shape_width]==1)
                direction(rand()%4+0,rend1,dsrect);
            else
            {
                //check if it is out of screen or not
                shape[i].x=shape[i-1].x;
                if(shape[i-1].y+3*shape_width<=screen_width)
                    shape[i].y=shape[i-1].y+3*shape_width;
                else
                    find_free_space(2);
                draw_shape(rend1,dsrect,shape[i].y,shape[i].x,color_random());
                draw_king_enemy(rend1,dsrect,shape[i].x,shape[i].y,1);

            }
            break;

        case 3:
            if(check_y[shape[i-1].y-3*shape_width]==1)
                direction(rand()%4+0,rend1,dsrect);
            else
            {
                //check if it is out of screen or not
                shape[i].x=shape[i-1].x;
                if(shape[i-1].y-3*shape_width>=0)
                    shape[i].y=shape[i-1].y-3*shape_width;
                else
                    find_free_space(3);
                draw_shape(rend1,dsrect,shape[i].y,shape[i].x,color_random());
                draw_king_enemy(rend1,dsrect,shape[i].x,shape[i].y,1);

            }
            break;

    }
}
void draw_map(SDL_Renderer* rend1)
{

    SDL_Rect *dsrect;
    for(int j=0;j<25;j++)
    {
        if(j!=4)
        {
            draw_shape(rend1,dsrect,shape[j].y,shape[j].x,shape[j].color);
            if(shape[j].color!=0&&shape[j].color==shape[0].color)
                draw_king_enemy(rend1,dsrect,shape[j].x,shape[j].y,0);
            else if(shape[j].color!=0&&shape[j].color!=shape[0].color)
                draw_king_enemy(rend1,dsrect,shape[j].x,shape[j].y,1);
        }

    }


}
void print_default_shape_number(SDL_Renderer* rend1)
{
    char temp[10];

    for(int i=0;i<25;i++)
    {   sprintf(temp,"%d",shape[i].number);
        stringColor(rend1,shape[i].x,shape[i].y,temp,0xff00ffff);
    }
}
void print_new_number(SDL_Renderer *rend2,int j1)
{

    if(shape[j1].number<max_size&&shape[j1].color!=0&&frame%6==0)
    {
        shape[j1].number++;
    }
    char temp[3];
    sprintf(temp,"%d",shape[j1].number);
    stringColor(rend2,shape[j1].x,shape[j1].y,temp,0xff00ffff);


}
int find_area(int Mouse_x,int Mouse_y)
{
    for(int i1=0;i1<25;i1++)
    {
        if(shape[i1].x+shape_width>Mouse_x&&shape[i1].x<Mouse_x&&shape[i1].y+shape_height>Mouse_y&&shape[i1].y<Mouse_y)
            return i1;
    }
}
void check_where_to_go(SDL_Renderer* rend1,int n,int f,int s) {
    int first_area;
    int second_area;
    if(n==1)
    {
        first_area= find_area(Mouse_x_first, Mouse_y_first);
        second_area = find_area(Mouse_x_second, Mouse_y_second);
    }
    else if(n==0)
    {
        first_area=f;
        second_area=s;
    }
    shape[first_area].on_going++;

    for (int j = 0; j <= shape[first_area].number; j++)
    {
        shape[first_area].army[j].enemy = second_area;
        shape[first_area].army[j].x_first = (double ) shape[first_area].x + 25;
        shape[first_area].army[j].x_second = (double ) shape[second_area].x + 25;
        shape[first_area].army[j].y_second = (double ) shape[second_area].y + 25;
        shape[first_area].army[j].y_first = (double ) shape[first_area].y + 25;
        shape[first_area].army[j].color=shape[first_area].color;
        if (shape[second_area].x - shape[first_area].x != 0)
        {
            shape[first_area].army[j].cos = (shape[second_area].x - shape[first_area].x)/(double) sqrt(pow((shape[second_area].y - shape[first_area].y),2)+pow((shape[second_area].x - shape[first_area].x),2))
                    ;
            shape[first_area].army[j].sin = (shape[second_area].y - shape[first_area].y)/(double) sqrt(pow((shape[second_area].y - shape[first_area].y),2)+pow((shape[second_area].x - shape[first_area].x),2))
                    ;
        } else {
            if (shape[second_area].y - shape[first_area].y < 0)
                shape[first_area].army[j].x_zero = -1;
            else if (shape[second_area].y - shape[first_area].y > 0)
                shape[first_area].army[j].x_zero = +1;
            else if (shape[second_area].y - shape[first_area].y == 0)
                shape[first_area].army[j].x_zero = 0;

        }

        if (shape[second_area].x - shape[first_area].x > 0) {
            shape[first_area].army[j].x_positive = 1;
        } else if (shape[second_area].x - shape[first_area].x < 0) {
            shape[first_area].army[j].x_positive = -1;
        }
    }
    shape[first_area].copy_number = shape[first_area].number;
    shape[first_area].number_going = 0;
    shape[first_area].not_finished = 1;
}
void army_color(int i,int j,SDL_Renderer* rend1)
{
    switch(shape[i].army[j].color)
    {
        case 1:
            filledCircleRGBA(rend1,(int)shape[i].army[j].x_first,(int)shape[i].army[j].y_first,5, 39,66,229,255);
            break;
        case 2:
            filledCircleRGBA(rend1,(int)shape[i].army[j].x_first,(int)shape[i].army[j].y_first,5, 51,229,39,255);
            break;
        case 3:
            filledCircleRGBA(rend1,(int)shape[i].army[j].x_first,(int)shape[i].army[j].y_first,5, 240,118,28,255);
            break;
        case 4:
            filledCircleRGBA(rend1,(int)shape[i].army[j].x_first,(int)shape[i].army[j].y_first,5, 240,28,227,255);
            break;
        case 5:
            filledCircleRGBA(rend1,(int)shape[i].army[j].x_first,(int)shape[i].army[j].y_first,5, 255,255,0,255);
            break;
        case 6:
            filledCircleRGBA(rend1,(int)shape[i].army[j].x_first,(int)shape[i].army[j].y_first,5, 14,6,100,255);
            break;
    }
}
void random_map(SDL_Renderer *rend1)
{
    SDL_Rect *dsrect;
    //set seed
    srand(time(0));
    //Initializing first main shape
    shape[i].x=400;
    shape[i].y=400;
    check_x[shape[i].x]=1;
    check_y[shape[i].y]=1;
    draw_shape(rend1,dsrect,shape[i].y,shape[i].x,color_random());
    draw_king_enemy(rend1,dsrect,shape[i].x,shape[i].y,0);
    draw_around_shape(rend1,dsrect,0);
    //build another shape in map
    for(int i1=0;i1<4;i1++)
    {
        i++;
        direction(rand()%4+0,rend1,dsrect);
        draw_around_shape(rend1,dsrect,0);
        check_y[shape[i].y]=1;
        check_x[shape[i].x]=1;
    }
    print_default_shape_number(rend1);
}
void check(int i,int j)
{
    if(shape[shape[i].army[j].enemy].number<=0)
    {
        shape[shape[i].army[j].enemy].color=shape[i].army[j].color;
    }
}
void check_homes(int i,int j)
{
    for(int i1=1;i1<=at_same_time;i1++)
    {
        if(shape[map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[i1].i].color!=shape[map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[i1-1].i].color)
        {
            shape[map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[i1].i].army[map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[i1].j].x_first=0;
            shape[map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[i1].i].army[map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[i1].j].y_first=0;
            shape[map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[i1-1].i].army[map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[i1-1].j].x_first=0;
            shape[map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[i1-1].i].army[map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[i1-1].j].y_first=0;
        }
    }
}
void move(SDL_Renderer *rend1,int i,int j)
{
    if(frame%2==0)
    {
        if((int)shape[i].army[j].x_first==shape[i].x+25&&(int)shape[i].army[j].y_first==shape[i].y+25&&shape[i].number_going<shape[i].copy_number-1)
        {
            shape[i].number_going++;
            shape[i].number--;
            if(shape[i].number<0)
                shape[i].number=0;
        }

        if(shape[i].army[j].x_zero==1&&shape[i].army[j].y_first!=shape[i].army[j].y_second)
        {
            shape[i].army[j].y_first+=5;
//            map[(int)shape[i].army[j-1].x_first][(int)shape[i].army[j-1].y_first].number=0;
//            map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].number++;
//            if(map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].number>1)
//            {
//                map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[at_same_time].i=i;
//                map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[at_same_time].j=j;
//                at_same_time++;
//                check_homes(i,j);
//            }
            army_color(i,j,rend1);
            if(shape[i].army[j].y_first==shape[i].army[j].y_second)
            {
                shape[i].army[j].y_second=0;
                shape[i].army[j].x_second=0;
                shape[i].army[j].x_zero=0;
                if(shape[shape[i].army[j].enemy].color==shape[i].army[j].color)
                    shape[shape[i].army[j].enemy].number++;
                else
                {
                    shape[shape[i].army[j].enemy].number--;
                    if(shape[shape[i].army[j].enemy].number<0)
                        shape[shape[i].army[j].enemy].number=0;
                }
                check(i,j);
                if(j==shape[i].copy_number-1)
                {
                    shape[i].not_finished=0;
                }
            }
        }
        else if (shape[i].army[j].x_zero==-1&&shape[i].army[j].y_first!=shape[i].army[j].y_second)
        {

            shape[i].army[j].y_first-=5;
//            map[(int)shape[i].army[j-1].x_first][(int)shape[i].army[j-1].y_first].number=0;
//            map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].number++;
//            if(map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].number>1)
//            {
//                map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[at_same_time].i=i;
//                map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[at_same_time].j=j;
//                at_same_time++;
//                check_homes(i,j);
//            }

            army_color(i,j,rend1);
            if(shape[i].army[j].y_first==shape[i].army[j].y_second)
            {
                shape[i].army[j].y_second=0;
                shape[i].army[j].x_second=0;
                shape[i].army[j].x_zero=0;
                if(shape[shape[i].army[j].enemy].color==shape[i].army[j].color)
                    shape[shape[i].army[j].enemy].number++;
                else
                {
                    shape[shape[i].army[j].enemy].number--;
                    if(shape[shape[i].army[j].enemy].number<0)
                        shape[shape[i].army[j].enemy].number=0;
                }
                check(i,j);
                if(j==shape[i].copy_number-1)
                {
                    shape[i].not_finished=0;
                }
            }
        }
        else
        {
            if(shape[i].army[j].x_positive==1&& shape[i].army[j].x_first<shape[i].army[j].x_second)
            {
                shape[i].army[j].x_first+= shape[i].army[j].cos*5;
                shape[i].army[j].y_first+= shape[i].army[j].sin*5;
//                map[(int)shape[i].army[j-1].x_first][(int)shape[i].army[j-1].y_first].number=0;
//                map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].number++;
//                if(map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].number>1)
//                {
//                    map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[at_same_time].i=i;
//                    map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[at_same_time].j=j;
//                    at_same_time++;
//                    check_homes(i,j);
//                }

                army_color(i,j,rend1);
                if(shape[i].army[j].x_first>=shape[i].army[j].x_second)
                {
                    shape[i].army[j].y_second=0;
                    shape[i].army[j].x_second=0;
                    if(shape[shape[i].army[j].enemy].color==shape[i].army[j].color)
                        shape[shape[i].army[j].enemy].number++;
                    else
                    {
                        shape[shape[i].army[j].enemy].number--;
                        if(shape[shape[i].army[j].enemy].number<0)
                            shape[shape[i].army[j].enemy].number=0;
                    }

                    check(i,j);
                    if(j==shape[i].copy_number-1)
                    {
                        shape[i].not_finished=0;
                    }
                }
            }
            else if(shape[i].army[j].x_positive==-1&& shape[i].army[j].x_first>shape[i].army[j].x_second)
            {
                shape[i].army[j].x_first+= shape[i].army[j].cos*5;
                shape[i].army[j].y_first+= shape[i].army[j].sin*5;
//                map[(int)shape[i].army[j-1].x_first][(int)shape[i].army[j-1].y_first].number=0;
//                map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].number++;
//                if(map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].number>1)
//                {
//                    map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[at_same_time].i=i;
//                    map[(int)shape[i].army[j].x_first][(int)shape[i].army[j].y_first].which_shape[at_same_time].j=j;
//                    at_same_time++;
//                    check_homes(i,j);
//                }

                army_color(i,j,rend1);
                if(shape[i].army[j].x_first<=shape[i].army[j].x_second)
                {
                    shape[i].army[j].y_second=0;
                    shape[i].army[j].x_second=0;
                    if(shape[shape[i].army[j].enemy].color==shape[i].army[j].color)
                        shape[shape[i].army[j].enemy].number++;
                    else
                    {
                        shape[shape[i].army[j].enemy].number--;
                        if(shape[shape[i].army[j].enemy].number<0)
                            shape[shape[i].army[j].enemy].number=0;
                    }
                    check(i,j);
                    if(j==shape[i].copy_number-1)
                    {
                        shape[i].not_finished=0;
                    }
                }
            }
        }
    }
    else
    {
        if(shape[i].army[j].x_positive==-1&& shape[i].army[j].x_first>=shape[i].army[j].x_second)
            army_color(i,j,rend1);
        else if(shape[i].army[j].x_positive==1&& shape[i].army[j].x_first<=shape[i].army[j].x_second)
            army_color(i,j,rend1);
        else if (shape[i].army[j].x_zero==-1&&shape[i].army[j].y_first!=shape[i].army[j].y_second)
            army_color(i,j,rend1);
        else if(shape[i].army[j].x_zero==1&&shape[i].army[j].y_first!=shape[i].army[j].y_second)
            army_color(i,j,rend1);
    }


}
void back(SDL_Renderer* rend1,SDL_Surface* background)
{
    SDL_Texture *texture3 = SDL_CreateTextureFromSurface(rend1, background);
    SDL_RenderCopy(rend1, texture3, NULL, NULL);
    SDL_DestroyTexture(texture3);
}
int check_not_finish()
{
    for(int i=0;i<24;i++)
    {
        if(shape[i].color!=0&&shape[i].color!=shape[0].color&&i!=4&&shape[i].not_finished==0)
            return 1;
    }
    return 0;
}
int check_if_finish()
{
    int count[7]={0};
    int count_color=0;
    for(int i=0;i<25;i++)
    {
        if(shape[i].color!=0)
            count[shape[i].color]=1;
    }
    int j;
    for(int i=1;i<7;i++)
    {
        if(count[i]!=0)
        {
            count_color++;
            j=i;
        }

    }
    if(count_color>1)
        return 0;
    else
        return j ;

}
int random_pick_first()
{
    int n=rand()%24+1;
    if(check_not_finish()==1)
    {
        if(shape[n].color!=0&&shape[n].color!=shape[0].color&&n!=4&&shape[n].not_finished==0)
            return n;
        else
            random_pick_first();
    }
    else
        return -1;

}
int random_pick_second(int first)
{
    int n=rand()%24+1;
    if(shape[n].color!=shape[0].color&&n!=4&&n!=first)
        return n;
    else
        random_pick_first();
}
void set_result_text(SDL_Rect* text_location)
{
    text_location->x=100;
    text_location->y=200;
    text_location->h=400;
    text_location->w=600;
}
void print_win(SDL_Renderer *rend1)
{
    SDL_Color winning_color={0, 150, 255};
    SDL_Color background_color={0,0,255,1};
    TTF_Font *main_font=TTF_OpenFont("COOPBL.ttf",60);
    SDL_Surface *text_introduction= TTF_RenderText_Shaded(main_font,"You won",winning_color,background_color);
    SDL_FreeSurface(text_introduction);
    TTF_CloseFont(main_font);
    SDL_Texture *texture2= SDL_CreateTextureFromSurface(rend1,text_introduction);
    SDL_Rect text_location;
    set_result_text(&text_location);
    SDL_RenderCopy(rend1,texture2,NULL,&text_location);
}
void print_lost(SDL_Renderer *rend1)
{
    SDL_Color winning_color={255, 0, 0};
    SDL_Color background_color={0,0,255,1};
    TTF_Font *main_font=TTF_OpenFont("COOPBL.ttf",60);
    SDL_Surface *text_introduction= TTF_RenderText_Shaded(main_font,"You lost",winning_color,background_color);
    TTF_CloseFont(main_font);
    SDL_FreeSurface(text_introduction);
    SDL_Texture *texture2= SDL_CreateTextureFromSurface(rend1,text_introduction);
    SDL_Rect text_location;
    set_result_text(&text_location);
    SDL_RenderCopy(rend1,texture2,NULL,&text_location);
}
void set_start_location(SDL_Rect *start_location)
{
    start_location->y=150;
    start_location->x=350;
    start_location->h=100;
    start_location->w=100;
}
void set_scoreboard_location(SDL_Rect *scoreboard_location)
{
    scoreboard_location->y=450;
    scoreboard_location->x=300;
    scoreboard_location->h=100;
    scoreboard_location->w=200;
}
void set_username_location(SDL_Rect* username_location)
{
    username_location->y=250;
    username_location->x=200;
    username_location->h=100;
    username_location->w=350;
}
void text_input_location(SDL_Rect* input_location,int x,int y)
{
    input_location->x=x;
    input_location->y=y;
    input_location->w=50;
    input_location->h=50;
}
void username_box_location(SDL_Rect* username_box)
{
    username_box->x=140;
    username_box->y=450;
    username_box->w=500;
    username_box->h=200;
}
void set_random_location(SDL_Rect* random)
{
    random->y=120;
    random->x=300;
    random->h=50;
    random->w=150;
}
void set_map1_location(SDL_Rect* map1)
{
    map1->y=320;
    map1->x=300;
    map1->h=50;
    map1->w=150;
}
void set_map2_location(SDL_Rect* map1)
{
    map1->y=520;
    map1->x=300;
    map1->h=50;
    map1->w=150;
}
void draw_map1(SDL_Renderer* rend1)
{
    SDL_Rect *dsrect;
    //set seed
    srand(time(0));
    //Initializing first main shape
    shape[i].x=400;
    shape[i].y=400;
    check_x[shape[i].x]=1;
    check_y[shape[i].y]=1;
    draw_shape(rend1,dsrect,shape[i].y,shape[i].x,2);
    draw_king_enemy(rend1,dsrect,shape[i].x,shape[i].y,0);
    draw_around_shape(rend1,dsrect,0);
    //build another shape in map
    for(int i1=0;i1<4;i1++)
    {
        i++;
        if(i1==3)
            direction(1,rend1,dsrect);
        else
            direction(0,rend1,dsrect);
        draw_around_shape(rend1,dsrect,0);
        check_y[shape[i].y]=1;
        check_x[shape[i].x]=1;
    }
    print_default_shape_number(rend1);
}

void draw_map2(SDL_Renderer *rend1)
{
    SDL_Rect *dsrect;
    //set seed
    srand(time(0));
    //Initializing first main shape
    shape[i].x=400;
    shape[i].y=400;
    check_x[shape[i].x]=1;
    check_y[shape[i].y]=1;
    draw_shape(rend1,dsrect,shape[i].y,shape[i].x,1);
    draw_king_enemy(rend1,dsrect,shape[i].x,shape[i].y,0);
    draw_around_shape(rend1,dsrect,0);
    //build another shape in map
    for(int i1=0;i1<4;i1++)
    {
        i++;
        if(i1==3)
            direction(2,rend1,dsrect);
        else
            direction(3,rend1,dsrect);
        draw_around_shape(rend1,dsrect,0);
        check_y[shape[i].y]=1;
        check_x[shape[i].x]=1;
    }
    print_default_shape_number(rend1);
}
void text(SDL_Renderer *rend1,char input[],SDL_Surface* surface,int x,int y,SDL_Event event)
{
    // set color
    SDL_Color white= {255,255,255};
    TTF_Font *main_font=TTF_OpenFont("CASTELAR.ttf",60);
    SDL_Color background_start={255,255,255,1};
    surface = TTF_RenderText_Shaded(main_font,event.text.text,white,background_start);
    SDL_Texture *input_text = SDL_CreateTextureFromSurface(rend1,surface);
    SDL_Rect input_location;
    text_input_location(&input_location,x,y);
    SDL_RenderCopy(rend1, input_text, NULL,&input_location);
    SDL_DestroyTexture(input_text);
}
void game_loop(SDL_Renderer* rend1,SDL_Surface* background,SDL_Surface* start_text)
{
    int menu=1;
    SDL_bool Exit = SDL_TRUE;
    int tem=0;
    //Initializing input_text
    char input[50]="";
    int x_name=120;
    int y_name=480;
    SDL_Color start={20,199,169};
    SDL_Color scoreboard={20,199,169};
    SDL_Color username={71,213,49};
    SDL_Color random={20,199,169};
    SDL_Color map1={20,199,169};
    SDL_Color map2={20,199,169};
    SDL_Rect map2_location;
    SDL_Rect start_location;
    SDL_Rect random_loaction;
    SDL_Rect map1_location;
    at_same_time=0;
    SDL_Rect scoreboard_location;
    SDL_Rect username_box;
    while (Exit == SDL_TRUE)
    {
        if(menu==0)
        {        if(check_if_finish()!=0)
            {
                SDL_RenderClear(rend1);
                if(check_if_finish()==shape[0].color)
                {
                    print_win(rend1);

                }
                else
                {
                    print_lost(rend1);
                }
                SDL_Delay(5000);
                Exit=SDL_FALSE;
            }
            SDL_RenderClear(rend1);
            back(rend1,background);
            draw_map(rend1);
//        check_homes();
            for(int j=0;j<25;j++)
            {
                if(j!=4)
                    print_new_number(rend1,j);

            }
            for(int i=0;i<25;i++)
            { if(shape[i].on_going!=0)
                {
                    for(int j=shape[i].number_going;j>=0;j--)
                    {
                        if(shape[i].army[j].x_second!=0&&shape[i].army[j].y_second!=0)
                        {
                            move(rend1,i,j);

                        }
                    }

                }

            }
            //opponent move
            if(frame%80==0)
            {
                int first=random_pick_first();
                if(first!=-1)
                {
                    int second=random_pick_second(first);
                    check_where_to_go(rend1,0,first,second);
                }

            }
        }
        else if(menu==1)
        {
            SDL_RenderClear(rend1);
            back(rend1,background);
            TTF_Font *main_font=TTF_OpenFont("COOPBL.ttf",60);
            SDL_Color background_start={255,255,255,1};
            start_text= TTF_RenderText_Shaded(main_font,"start",start,background_start);
            SDL_Texture *texture1= SDL_CreateTextureFromSurface(rend1,start_text);
            set_start_location(&start_location);
            SDL_RenderCopy(rend1,texture1,NULL,&start_location);
            SDL_DestroyTexture(texture1);
            start_text= TTF_RenderText_Shaded(main_font,"scoreboard",scoreboard,background_start);
            SDL_Texture *texture2= SDL_CreateTextureFromSurface(rend1,start_text);
            set_scoreboard_location(&scoreboard_location);
            SDL_RenderCopy(rend1,texture2,NULL,&scoreboard_location);
            SDL_DestroyTexture(texture2);
            TTF_CloseFont(main_font);
        }
        else if(menu==2)
        {
            SDL_RenderClear(rend1);
            back(rend1,background);
            TTF_Font *main_font=TTF_OpenFont("COOPBL.ttf",60);
            SDL_Color background_start={255,255,255,1};
            start_text= TTF_RenderText_Shaded(main_font,"Enter Your Username:",username,background_start);
            SDL_Texture *texture1= SDL_CreateTextureFromSurface(rend1,start_text);
            SDL_Rect username_location;
            set_username_location(&username_location);
            SDL_RenderCopy(rend1,texture1,NULL,&username_location);
            SDL_DestroyTexture(texture1);
            TTF_CloseFont(main_font);
            username_box_location(&username_box);
            SDL_RenderDrawRect(rend1, &username_box);
        }
        else if(menu==3)
        {
            SDL_RenderClear(rend1);
            back(rend1,background);
            TTF_Font *main_font=TTF_OpenFont("COOPBL.ttf",60);
            SDL_Color background_start={255,255,255,1};
            start_text= TTF_RenderText_Shaded(main_font,"Random Map",random,background_start);
            SDL_Texture *texture= SDL_CreateTextureFromSurface(rend1,start_text);
            set_random_location(&random_loaction);
            SDL_RenderCopy(rend1,texture,NULL,&random_loaction);
            SDL_DestroyTexture(texture);
            start_text= TTF_RenderText_Shaded(main_font,"Map1",map1,background_start);
            SDL_Texture *texture1= SDL_CreateTextureFromSurface(rend1,start_text);
            set_map1_location(&map1_location);
            SDL_RenderCopy(rend1,texture1,NULL,&map1_location);
            SDL_DestroyTexture(texture1);
            start_text= TTF_RenderText_Shaded(main_font,"Map2",map2,background_start);
            SDL_Texture *texture2= SDL_CreateTextureFromSurface(rend1,start_text);
            set_map2_location(&map2_location);
            SDL_RenderCopy(rend1,texture2,NULL,&map2_location);
            SDL_DestroyTexture(texture2);
            TTF_CloseFont(main_font);
        }
        SDL_Event sdlEvent;
        // listen for key events
        while (SDL_PollEvent(&sdlEvent))
        {

            if(sdlEvent.type==SDL_QUIT)
                Exit=SDL_FALSE;
            const  Uint8 *state= SDL_GetKeyboardState(NULL);
            //going to next page by pressing ENTER
            if(state[SDL_SCANCODE_RETURN])
            {
                SDL_RenderClear(rend1);

            }
            if(sdlEvent.type==SDL_MOUSEBUTTONDOWN)
                switch(sdlEvent.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        if(tem==0&&menu==0)
                        {
                            SDL_GetMouseState(&Mouse_x_first,&Mouse_y_first);
                            tem++;
                        }
                        else if(tem==1&&menu==0)
                        {
                            SDL_GetMouseState(&Mouse_x_second,&Mouse_y_second);
                            check_where_to_go(rend1,1,0,0);
                            tem=0;
                        }
                        else if(menu==1)
                        {
                            int x=sdlEvent.motion.x;
                            int y=sdlEvent.motion.y;
                            if(x>start_location.x&&x<start_location.x+start_location.w&&y>start_location.y&&y<start_location.y+start_location.h)
                            {
                                menu=2;
                            }
                        }
                        else if(menu==2)
                        {
                            int x=sdlEvent.motion.x;
                            int y=sdlEvent.motion.y;
                            if(x>username_box.x&&x<username_box.x+username_box.w&&y>username_box.y&&y<username_box.y+username_box.h)
                            {
                                    SDL_StartTextInput();
                                    SDL_Event event;
                                    bool flag = true;
                                    while (flag)
                                    {
                                        SDL_PollEvent(&event);
                                        if(event.type==SDL_QUIT)
                                            flag=false;
                                        if (event.type == SDL_TEXTINPUT) {
                                            strcat(input, event.text.text);
                                            x_name += 50;
                                            text(rend1, input, start_text, x_name, y_name, event);
                                            SDL_RenderPresent(rend1);
                                        }
                                        const Uint8 *state = SDL_GetKeyboardState(NULL);
                                        if (state[SDL_SCANCODE_RETURN])
                                        {
                                            flag = false;
                                        }
                                        event.type = NULL;
                                    }
                                    SDL_StopTextInput();

                                menu=3;
                            }

                        }
                        else if(menu==3)
                        {
                            int x=sdlEvent.motion.x;
                            int y=sdlEvent.motion.y;
                            if(x>random_loaction.x&&x<random_loaction.x+random_loaction.w&&y>random_loaction.y&&y<random_loaction.y+random_loaction.h)
                            {
                                //generating map
                                random_map(rend1);
                                menu=0;
                            }
                           else if(x>map1_location.x&&x<map1_location.x+map1_location.w&&y>map1_location.y&&y<map1_location.y+map1_location.h)
                            {
                                //generating map
                               draw_map1(rend1);
                                printf("1");
                                menu=0;
                            }
                            if(x>map2_location.x&&x<map2_location.x+map2_location.w&&y>map2_location.y&&y<map2_location.y+map2_location.h)
                            {
                                //generating map
                                draw_map2(rend1);
                                menu=0;
                            }
                        }
                        break;
                }
            if(sdlEvent.type==SDL_MOUSEMOTION) {
                int x=sdlEvent.motion.x;
                int y=sdlEvent.motion.y;
                if(menu==1&&x>start_location.x&&x<start_location.x+start_location.w&&y>start_location.y&&y<start_location.y+start_location.h)
                {

                    start.r=245;
                    start.g=146;
                    start.b=18;
                }
                else if(menu==1&&x>scoreboard_location.x&&x<scoreboard_location.x+scoreboard_location.w&&y>scoreboard_location.y&&y<scoreboard_location.y+scoreboard_location.h)
                {
                    scoreboard.r=245;
                    scoreboard.g=146;
                    scoreboard.b=18;
                }
                else if(menu==1)
                {
                    start.r=20;
                    start.g=199;
                    start.b=169;
                    scoreboard.r=20;
                    scoreboard.g=199;
                    scoreboard.b=169;
                }
                else if(menu==3&&x>random_loaction.x&&x<random_loaction.x+random_loaction.w&&y>random_loaction.y&&y<random_loaction.y+random_loaction.h)
                {
                    random.r=245;
                    random.g=146;
                    random.b=18;
                }
                else if(menu==3&&x>map1_location.x&&x<map1_location.x+map1_location.w&&y>map1_location.y&&y<map1_location.y+map1_location.h)
                {
                    map1.r=245;
                    map1.g=146;
                    map1.b=18;
                }
                else if(menu==3&&x>map2_location.x&&x<map2_location.x+map2_location.w&&y>map2_location.y&&y<map2_location.y+map2_location.h)
                {
                    map2.r=245;
                    map2.g=146;
                    map2.b=18;
                }
                else if(menu==3)
                {
                    map2.r=20;
                    map2.g=199;
                    map2.b=169;
                    map1.r=20;
                    map1.g=199;
                    map1.b=169;
                    random.r=20;
                    random.g=199;
                    random.b=169;
                }

            }

        }
        frame++;
        SDL_RenderPresent(rend1);

    }
}
void set_position_text(SDL_Rect* text_location )
{
    text_location->x=100;
    text_location->y=100;
    text_location->h=300;
    text_location->w=600;
}
int main() {
    //Initializing Setup
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    TTF_Init();
    //Creating new window
    SDL_Window *page= SDL_CreateWindow("first page",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screen_width,screen_height,SDL_WINDOW_OPENGL);
    //Creating first page by using an image
    SDL_Renderer *rend1= SDL_CreateRenderer(page,-1,flag_of_rend);
    SDL_Surface *first_surface= SDL_LoadBMP("first_Surface_image.bmp");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(rend1, first_surface);
    //Free memory
    SDL_FreeSurface(first_surface);
    SDL_RenderCopy(rend1, texture, NULL, NULL);
    SDL_DestroyTexture(texture);
    //crating introduction page
    SDL_Color introduction_color={255,255,56,0};
    SDL_Color background_color={0,0,255,1};
    int w=600;
    int h=300;
    TTF_Font *main_font=TTF_OpenFont("COOPBL.ttf",60);
    SDL_Surface *text_introduction= TTF_RenderText_Shaded(main_font,"State.io",introduction_color,background_color);
    TTF_CloseFont(main_font);
    SDL_Texture *texture2= SDL_CreateTextureFromSurface(rend1,text_introduction);
    SDL_Rect text_location;
    set_position_text(&text_location);
    SDL_RenderCopy(rend1,texture2,NULL,&text_location);
    SDL_RenderPresent(rend1);
    SDL_Delay(5000);
    //Free memory
    SDL_DestroyTexture(texture2);
    SDL_FreeSurface(text_introduction);
    //set background
    SDL_Surface *background= IMG_Load("background.jpg");
    SDL_Texture *texture3 = SDL_CreateTextureFromSurface(rend1, background);
    SDL_RenderCopy(rend1, texture3, NULL, NULL);
    SDL_DestroyTexture(texture3);
    SDL_RenderPresent(rend1);
    SDL_Delay(1000);
    //Initializing map
    for(int i=0;i<800;i++)
    {
        for(int j=0;j<800;j++)
        {
            map[i][j].number=0;
        }
    }
    //Initializing shapes
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<=shape[i].number;j++)
        {
            shape[i].army[j].x_first=(int)shape[i].x;
            shape[i].army[j].x_second=0;
            shape[i].army[j].y_first=(int)shape[i].y;
            shape[i].army[j].y_second=0;
        }
        shape[i].on_going=0;
        shape[i].number_going=0;
        shape[i].copy_number=0;
        shape[i].not_finished = 0;
    }
    //game loop
    SDL_Surface *start_text;
    game_loop(rend1,background,start_text);
    //free all things
    SDL_FreeSurface(background);
    SDL_RenderClear(rend1);
    SDL_DestroyRenderer(rend1);
    SDL_DestroyWindow(page);
    SDL_Quit();
    TTF_Quit();
    return 0;
}
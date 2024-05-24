//
// Created by rcc on 2/3/2022.
//
struct data2
{
    double x_first;
    double y_first;
    double x_second;
    double y_second;
    double sin;
    double cos;
    int x_positive;
    int x_zero;
    int color;
    int enemy;
};
struct data
{
    int x;
    int y;
    int not_finished;
    int color;
    struct data2 army[100];
    int number;
    int copy_number;
    int number_going;
    int on_going;
};
struct data3
{
    int i;
    int j;
};
struct data4
{
    struct data3 which_shape[5];
    int number;
};
int at_same_time;
int screen_height=800;
int screen_width=800;
int i=0;
struct data4 map[800][800];
int frame=0;
int j=0;
int x1=50;
struct data shape[25];
int check_x[800]={0};
int check_y[800]={0};
int check_color[7]={0};
int default_shape_number=20;
int Mouse_x_first;
int Mouse_y_first;
int Mouse_x_second;
int Mouse_y_second;
#ifndef MAIN_C_GLOBAL_H
#define MAIN_C_GLOBAL_H

#endif //MAIN_C_GLOBAL_H

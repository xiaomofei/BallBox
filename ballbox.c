/*=============================================================================
#     FileName: ballbox.c
#         Desc: 
#       Author: LiChenda
#        Email: lichenda1996@gmail.com
#     HomePage: https://github.com/LiChenda
#      Version: 0.0.1
#   LastChange: 2016-05-29 21:08:30
#      History:
=============================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define true 1
#define false 0

typedef struct _Ball {
  double x;
  double y;
  double r;
} Ball;

typedef struct _listNode {
  struct _listNode * next;
  Ball ball;
} listNode;


listNode *head = NULL;

void insert(Ball ball);
double distance(Ball b1, Ball b2);
double m_abs(double num);
int judge(Ball b);
void freeBox();
void putBall();


double step = 0.01;

int main(int argc, char *argv[])
{

  int n, i;
  while(scanf("%d", &n) != EOF)
  {
    for(i = 0; i < n; i ++)
    {
      putBall();
    }
    listNode *tmp = head;
    double R2 = 0;
    while (tmp) {
      printf("%lf, %lf, %lf\n",tmp->ball.x, tmp->ball.y, tmp->ball.r);
      R2 += tmp->ball.r * tmp->ball.r;
      tmp = tmp->next;
    }
    printf("R^2 if %lf\n", R2);
    freeBox();
  }


  return 0;
}
void freeBox()
{
  while(head)
  {
    listNode *tmp = head;
    head = tmp->next;
    free(tmp);
  }
}
void insert(Ball ball)
{
  listNode * node = (listNode *)malloc(sizeof(listNode));
  node->ball = ball;
  node->next = head;
  head = node;
}
void putBall()
{
  Ball ball = {-1 + step, -1 + step, 0};
  Ball maxBall = ball;
  int i, j;
  for (i = 0; ball.x < 1; ++i) {
    ball.x += step;
    ball.y = -1 + step;
    for (j = 0; ball.y < 1; ++j) {
      ball.y += step;
      ball.r = 0;
      double rstep = 0.1;
      while(rstep > 0.00001)
      {
        if(ball.r > maxBall.r)
        {
          maxBall = ball;
        }
        /*printf("%lf, %lf, %lf\n",ball.x, ball.y, ball.r);*/
        ball.r += rstep;
        if(!judge(ball))
        {
          ball.r -= rstep;
          rstep /= 10;
        }
      }
    }
  }
  if(judge(maxBall)){
    insert(maxBall);
  }
}

int judge(Ball b)
{
  if((m_abs(b.x) + b.r) > 1 || (m_abs(b.y) + b.r) > 1)
  {
    return false;
  }
  listNode *tmp = head;
  while(tmp)
  {
    Ball ball = tmp->ball;
    if(distance(b, ball) < b.r + ball.r )
    {
      return false;
    }
    tmp = tmp->next;
  }
  return true;
}
double m_abs(double num)
{
  if(num > 0)
    return num;
  return 0 - num;
}

double distance(Ball b1, Ball b2)
{
  double x1 = b1.x;
  double y1 = b1.y;
  double x2 = b2.x;
  double y2 = b2.y;
  return pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
}

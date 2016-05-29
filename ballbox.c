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
#include <math.h>
#include <stdio.h>
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
int judge(Ball b);
void putBall();
double step = 0.1;


int main(int argc, char *argv[])
{
  putBall(); 
  putBall();
  listNode *tmp = head;

  while (tmp) {
    printf("%lf, %lf, %lf\n",tmp->ball.x, tmp->ball.y, tmp->ball.r);
    tmp = tmp->next;
  }

  return 0;
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
      while(judge(ball))
      {
        if(ball.r > maxBall.r)
        {
          maxBall = ball;
        }
          /*printf("%lf, %lf, %lf\n",ball.x, ball.y, ball.r);*/
        ball.r += step;
      }
    }
  }
  if(judge(maxBall)){
  insert(maxBall);
  }
}

int judge(Ball b)
{
  if((abs(b.x) + b.r) > 1 || (abs(b.y) + b.r) > 1)
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

double distance(Ball b1, Ball b2)
{
  double x1 = b1.x;
  double y1 = b1.y;
  double x2 = b2.x;
  double y2 = b2.y;
  return pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
}

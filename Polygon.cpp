#include<iostream>
using namespace std;

//structure Point consisting the coordinates of polygon in 2-D
struct Point 
{
 float x, y;
};

//structure Line
struct Line 
{
 Point p1, p2;
};

//check whether point is on the line or not
bool onLine(Line line, Point point) 
{      
  if(point.x <= max(line.p1.x, line.p2.x) && point.x <= min(line.p1.x, line.p2.x) &&
    (point.y <= max(line.p1.y, line.p2.y) && point.y <= min(line.p1.y, line.p2.y)))
    return true;
  else
    return false;
}

//check the orientation of points as if they are in colinear, clockwise or anti-clockwise direction
int path(Point a, Point b, Point c) 
{
  int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
  if (val == 0)
    return 0;          //colinear
  else if(val < 0)
    return 1;          //clockwise direction
    return 2;          //anti-clockwise direction
}


//check whether the lines intersects or not
bool isIntersect(Line line1, Line line2) 
{
  //four path for two lines and points of other line
  int path1 = path(line1.p1, line1.p2, line2.p1);
  int path2 = path(line1.p1, line1.p2, line2.p2);
  int path3 = path(line2.p1, line2.p2, line1.p1);
  int path4 = path(line2.p1, line2.p2, line1.p2);

  if(path1 != path2 && path3 != path4)
    return true;           //lines are intersecting
  if(path1==0 && onLine(line1, line2.p1))        //when p2 of line2 are on the line1
    return true;
  if(path2==0 && onLine(line1, line2.p2))        //when p1 of line2 are on the line1
    return true;
  if(path3==0 && onLine(line2, line1.p1))        //when p2 of line1 are on the line2
    return true;
  if(path4==0 && onLine(line2, line1.p2))        //when p1 of line1 are on the line2
    return true;
  return false;
}

//check whether point lies inside or outside a polygon
bool isInside(Point polygon[], int n, Point point) 
{
  if(n < 3)
    return false;   //when polygon has less than 3 edges, then it is not polygon

  int count = 0, i = 0;
  Line exline = {point, {9999, point.y}};  //create a line at infinity, y is same as point

  do 
  {
    Line side = {polygon[i], polygon[(i+1)%n]}; //forming a line from two consecutive points of polygon
    if(isIntersect(side, exline)) 
    {          
      //if side intersects exline
      if(path(side.p1, point, side.p2) == 0)
        return onLine(side, point);
      count++;
    }
    i = (i+1) % n;
  } while(i != 0);
  return count%2 == 1;  // if count is oddwhen count is odd
}

int main() 
{
  Point polygon[] = {{1,0}, {8,3}, {8,8}, {1,5}};
  Point p = {3,5}; //Point p will lies inside
  int n = 4;

  //Point polygon[] = {{-3, 2}, {-2, -0.8}, {0, 1.2}, {2.2, 0}, {2,4.5}};
  //Point p = {0, 0};  //Point p will lies outside
  //int n = 5;

  if(isInside(polygon, n, p))
    cout << "True"; //True if Point p lies inside.
  else
    cout << "False"; //False if Point p lies outside.
}

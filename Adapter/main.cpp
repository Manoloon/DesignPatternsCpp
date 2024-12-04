#include <iostream>

struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}
  
  Point(const int x, const int y) : x{x}, y{y} {}
};

struct Line
{
  Point *start, *end;
  
  Line(Point* const start, Point* const end)
    : start(start), end(end)
  {
  }

  ~Line()
  {
    delete start;
    delete end;
  }

  Line deep_copy() const
  {
    // Create new Point objects for start and end
    Point* new_start = new Point(*start);
    Point* new_end = new Point(*end);
    
    // Return a new Line object with the new Point objects
    return Line(new_start, new_end);
  }
};

int main()
{
  Point* points1 = new Point(1,2);
  Point* points2 = new Point(3,4);
  Line line1{points1,points2};
  std::cout << "line 1 : " << line1.start->x << " : " << line1.end->y << std::endl;
  Line line2=line1.deep_copy();
  std::cout << "line 2 : " << line2.start->x << " : " << line2.end->y << std::endl;
    return 0;
}
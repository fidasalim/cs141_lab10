#include <iostream>
using namespace std;

// ********************************************************************
//  Declaration of class Point
// ********************************************************************

// class Point represents a two-dimensional point
class Point
{
public:
  // default class constructor (with no arguments):
  Point(); 

  // class constructor that sets the coordinates x, y to the values xval,
  // yval:
  Point(int xval, int yval);

  // member function for moving a point by dx, dy:
  void Move(int dx, int dy);

  // member functions for getting values of x, y:
  int Get_X() const;
  int Get_Y() const;

  // member functions for setting x, y to xval, yval respectively  
  void Set_X(int xval);
  void Set_Y(int yval);

//Lab 7 exercise 4.1. Add declaration of member function Print here:
  void print(int a,int b); 
// private data members x, y represent coordinates of the point:
private:
  int X;
  int Y;
};  


// ********************************************************************
//  Methods for class Point
// ********************************************************************

// class constructor sets X, Y to zero when no values are specified:
Point::Point()
{
  X = 0;
  Y = 0;
}

// class constructor sets X, Y to given values xval, yval:
Point::Point(int xval, int yval)
{
  X = xval;
  Y = yval;
}

// member function Move: increases the x coordinate by dx and the y
// coordinate by dy.
void Point::Move(int dx, int dy)
{
  X += dx;
  Y += dy;
}

// Get_X returns the value of the X coordinate
int Point::Get_X() const
{
  return X;
}

// Get_Y returns the value of the Y coordinate
int Point::Get_Y() const
{
  return Y;
}

// Set_X sets the value of X coordinate to xval
void Point::Set_X(int xval)
{
  X = xval;
} 

// Set_Y sets the value of Y coordinate to yval
void Point::Set_Y(int yval)
{
  Y = yval;
} 
    

//Lab 7 exercise 4.1. Add definition of member function print:
void Point::print(int a,int b)
{
    cout<<"("<<a<<","<<b<<")"<<endl;
}

// ********************************************************************
//  Declaration of class Rectangle
// ********************************************************************

//Lab 7 exercise 4.2, 4.3: Add class Rectangle declaration HERE: 
class Rectangle{
  public:
    // default class constructor (with no arguments):
    Rectangle();
    // class constructor thattakes two points as arguments and creates a rectangle with
    //the first point as the bottom left corner and the second as the top right corner
    
    Rectangle(Point pA1,Point pC1);
    //The print member function prints all 4 corners of the rectangle, using the member function print of the class Point. 
    void rectprint();
    //public member function to compute the area of the rectangle. 
    void rectarea();
    //two private member functions side1, side2 to the class Rectangle
    int side_1();
      int side_2();
     
    private:
      //// private data members of the class include all 4 corner points of the rectangle.
      Point pA;
      Point pB;
      Point pC;
      Point pD;
      //two private member functions side1, side2 to the class Rectangle 
      
};
// ********************************************************************
//  Methods for class Rectangle
// ********************************************************************

//Lab 7 exercise 4.2, 4.3. Add class Rectangle methods HERE: 
// class constructor sets A,B,C and D to (0,0), (1,0), (0,1), (1,1) when no values are specified:
Rectangle::Rectangle()
{
  pA.Set_X(0) ;
  pB.Set_X(0) ;
  pC.Set_X(1) ;
  pD.Set_X(1) ;
  pA.Set_Y(0) ;
  pB.Set_Y(0) ;
  pC.Set_Y(1) ;
  pD.Set_Y(1) ;
}
Rectangle::Rectangle(Point pA1,Point pC1)
{
    pA=pA1;
    pC=pC1;
    pB.Set_X(pC1.Get_X()) ;
    pB.Set_Y(pA1.Get_Y()) ;
    pD.Set_X(pA1.Get_X()) ;
    pD.Set_Y(pC1.Get_Y()) ;
}
void Rectangle::rectprint(){
    cout<<"For the rectangle ABCD,"<<endl;
    cout<<"A =";pA.print( pA.Get_X(), pA.Get_Y());
    cout<<"B =";pB.print( pB.Get_X(), pB.Get_Y());
    cout<<"C =";pC.print( pC.Get_X(), pC.Get_Y());
    cout<<"D =";pD.print( pD.Get_X(), pD.Get_Y());
}
int Rectangle::side_1()
{
    int len1=pC.Get_X()-pA.Get_X();
    return len1;
}
int Rectangle::side_2()
{
    int len2=pC.Get_Y()-pA.Get_Y();
    return len2;
}
void Rectangle::rectarea()
{
    int area=side_1()*side_2();
    cout<<"The area of the rectangle is "<<area<<endl;
}
    
// ********************************************************************
//  main() function for testing classes Point and Rectangle
// ********************************************************************

// Testing classes Point and Rectangle
int main()
{
// Declaring a point using default class constructor (x = y = 0):
  Point p1;
  cout<< "The x value for p1 is " << p1.Get_X() << endl;
  cout<< "The y value for p1 is " << p1.Get_Y() << endl;

// Declaring a point with coordinates X = 2, Y = 3:
  Point p2(2, 3);
  cout<< "The x value for p2 is " << p2.Get_X() << endl;
  cout<< "The y value for p2 is " << p2.Get_Y() << endl;

// Moving point p2 by (1, -1):
  p2.Move(1, -1);
  cout<< "After the move:" << endl;
  cout<< "The x value for p2 is " << p2.Get_X() << endl;
  cout<< "The y value for p2 is " << p2.Get_Y() << endl;

//Lab 7 exercise 4.1. Test member function print on points p1, p2:
  cout<<"The point p1 is ";p1.print( p1.Get_X(), p1.Get_Y());
  cout<<"The point p2 is ";p2.print( p2.Get_X(), p2.Get_Y());
//Lab 7 Exercises 4.2, 4.3. Testing of the class Rectangle goes here:  
  Rectangle rect1;
  rect1.rectprint();
  rect1.side_1();
  rect1.side_2();
  rect1.rectarea();
  Point pA1(2,1);
  Point pC1(4,8);
  Rectangle rect2(pA1,pC1);
  rect2.rectprint();
  rect2.side_1();
  rect2.side_2();
  rect2.rectarea();
  
  
  return 0;
}


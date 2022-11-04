#ifndef _POINT_H_ // header guard
#define _POINT_H_

/*
CSCI 3010, PE 1 example solution, Spring 2020
Felix Muzny
Two dimensional point with Distance and Translate methods.
*/

class Point {
public: 
    Point(); // 0-argument constructor
	Point(const int x, const int y);  // constructor
	
	int get_x() const { return x_; }  // inline member function
	int get_y() const { return y_; }  // inline member function

    void set_x(const int &x) { x_ = x; }  // inline member function
	void set_y(const int &y) { y_ = y; }  // inline member function

	double Distance(const Point &other) const;  // member function

	void Translate(const int &amt);  // member function


 private:
  int x_;  // data member, attribute, field
  int y_;  // data member, attribute, field

};  // class Point

#endif  // _POINT_H_


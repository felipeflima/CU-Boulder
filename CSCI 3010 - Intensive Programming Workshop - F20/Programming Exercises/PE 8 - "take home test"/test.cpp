#include <iostream>

// struct Point {
//   int x;
//   int y;

//   bool operator==(Point &other) {
// 		return (x == other.x && y == other.y);
//   }
// };

class Foo {
public:
    Foo(int bar) : bar_(bar) {}

    int CalculateMysteries(){
      std::cout << "CM" << std::endl;
    //   std::cout << &baz_ << std::endl;
      return 0;
    }

    static int TotalBars(){
      std::cout << "TB" << std::endl;
      return baz_;
    }

    // int getbar(){return a;}

private:
  int bar_;
//   const int a;

  static int baz_;
};


template <typename T>
void Swap(T &a, T &b){
    std::cout << "SWAP" << std::endl;
}

int main(){
    // Foo f(10);
    // f.TotalBars();
    // Foo::TotalBars();
    // std::cout << f.getbar() << std::endl;
    
    // Foo *ptr = new Foo(10);
    // ptr->CalculateMysteries();
    // f.CalculateMysteries();
    // f.TotalBars();
    // Foo::TotalBars;
    // Foo &ref = f;
    // ref.CalculateMysteries();

    int a = 5;
    int b = 7;
    Swap(a, b);

    std::string s = "hello";
    std::string t = "world!";
    Swap(s,t);

    // Swap(5,5);s

    // Swap(a, s);

}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;
void lower_bound_x(double& x, double lb){
  x = x<= lb ? lb:x;
}

int main(){
  auto f = bind(lower_bound_x, _1, 0.0);
  std::vector<double> x {-5, -2, 0, 1,2,3,5.5};


  for (auto& v:x)
    std::cout << v << std::endl;
  for_each(x.begin(), x.end(), f);
  for (auto& v:x)
    std::cout << v << std::endl;
  

  auto g = [](double &x){ x = x<= 0.0 ? 0.0:x ;};
  std::vector<double> y {-5, -2, 0, 1,2,3,5.5};
  for_each(y.begin(), y.end(), g);
  for (auto& v:y)
    std::cout << v << std::endl;
	      
}

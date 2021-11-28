#ifndef ISOLVER_H
#define ISOLVER_H
#include<iostream>
#include<cmath>
#include"Solver.h"

using namespace std;

template<class T, int n>
class ISolver: public Solver<T,n>
{
protected:
  T y[n];
  double error_tolerance;
public:
  ISolver():Solver<T,n>(), error_tolerance(0.01){};
  ISolver(Sparse<T,n> m1, T m2[n]): Solver<T,n>(m1,m2), y{}, error_tolerance(0.01){}
  void update_solver();
  int check_error();
};

template<class T, int n>
int ISolver<T,n>::check_error()
{
  for(int i=0; i<n; i++)
  {
    if(abs(Solver<T,n>::sol_matrix[i] - y[i]) < error_tolerance){}
    else
    {
      return 1;
    }
  }
  return 0;
}

template<class T, int n>
void ISolver<T,n>::update_solver()
{
  for(int i=0; i<n; i++)
  {
    Solver<T,n>::sol_matrix[i] = y[i];
  }
}
#endif
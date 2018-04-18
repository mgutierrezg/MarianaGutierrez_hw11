#include <iostream>

using namespace std;

//declaramos las funciones
double dx_dt(double t, double x, double v);
double dv_dt(double t, double x, double v);
void RK4(double t, double x, double v, double h);

double G;
double M;
double t1, x1, x_inicial, v1, h1;

//Funciones de las dos ecuaciones diferenciales 
double dx_dt(double t, double x, double v){
  return v;
}

double dv_dt(double t, double x, double v){
  return -(G*M)/(x*x);
}

//Funcion para resolverlas
void RK4(double t, double x, double v, double h){
 
  double kx_1, kx_2, kx_3, kx_4;
  double kv_1, kv_2, kv_3, kv_4;
  
  
  kx_1 = dx_dt(t, x, v);
  kv_1 = dv_dt(t, x, v);

  kx_2 = dx_dt(t + h/2, x + kx_1 * h/2, v + kv_1 * h/2);
  kv_2 = dv_dt(t + h/2, x + kx_1 * h/2, v + kv_1 * h/2);

  kx_3 = dx_dt(t + h/2, x + kx_2 * h/2, v + kv_2 * h/2);
  kv_3 = dv_dt(t + h/2, x + kx_2 * h/2, v + kv_2 * h/2);

  kx_4 = dx_dt(t + h, x + kx_3 * h, v + kv_3 * h);
  kv_4 = dv_dt(t + h, x + kx_3 * h, v + kv_3 * h);

  t1 = t + h;
  x1 = x + h * (kx_1 + 2*kx_2 + 2*kx_3 + kx_4)/6.0;
  v1 = v + h * (kv_1 + 2*kv_2 + 2*kv_3 + kv_4)/6.0;

}

int main(){
  G = 10;
  M = 1000;
 
  x_inicial = 100.0;
  x1 = x_inicial;
  t1 = 0.0;
  v1 = 0.0;
  h1 = 0.0001;
  
  while(x1>0.01*x_inicial){
    cout << t1 << "  " << x1 << "  " << v1  << endl;
    RK4(t1, x1, v1, h1);
  }

  return 0;
}

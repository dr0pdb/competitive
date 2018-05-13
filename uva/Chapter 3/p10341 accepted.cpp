#include<bits/stdc++.h> 
using namespace std;
#define EPS 1e-7
 
int p,q,r,s,t,u;
 
double f(double x){
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
 
double bisection(){
  double lo = 0, hi = 1;
  while (lo + EPS < hi){
    double x = (lo+hi)/2;
    if (f(lo) * f(x) <= 0){
      hi = x;
    } else {
      lo = x;
    }
  }
  return (lo+hi)/2;
}
 
int main(){
  while (scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF){
    if (f(0) * f(1) > 0){
     cout<<"No solution"<<"\n";
    } else {
      printf("%.4lf\n", bisection());
    }
  }
}

/*
  I dont know why this is not accepted :(

#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define EPS 1e-7
using namespace std;
int p,q,r,s,t,u;

double f(double x){
  return p*exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t *x*x + u;
}

int main(){
  while(cin>>p>>q>>r>>s>>t>>u){
    cout << std::setprecision(4) << std::fixed;

    if (f(0)*f(1) > 0)
    {
      cout<<"No solution"<<"\n";
      continue;
    }
    double a=0,b=1;
    double c;
    while((b-a)> EPS){
      c=(a+b)/2;

      if (!f(c))
      {
        break;
      }
      if (f(c)*f(a) < 0)
      {
        b=c;
      }else{
        a=c;
      }
    }
    cout<<c<<"\n";
  }
  return 0;
}



*/
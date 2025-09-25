#include<iostream>
using namespace std;
bool Settingsmap(int& x,int& y,int& varrange){
  
  //--MAP--
  cout<<"--Map--"<<endl;
  cout<<"(width)x=:";
  cin>>x;
  cout<<"(height)y=:";
  cin>>y;
  cout<<"(radius of variables)varrange=:";
  cin>>varrange;
  if ((x<>0) and (y<>0) and (varrange<>0)){
    return true;
  }else{
    return false;
  }  
};
int main(){
  bool debugging=true;
  int x=0,y=0,varrange=0;
  cout<<"Hello I app for fast create game."<<endl;
  
  if(debugging){
    cout<<"Let's start with the basic setup."<<endl;
    if(Settingsmap(x,y,varrange)){
      //
      cout<<"x="<<x<<" y="<<y<<" varrange="<<varrange<<endl;
    }
  }
  else{
    //main.cpp
  }
  return 0;
}

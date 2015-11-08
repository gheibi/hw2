#include <iostream>
#include <fstream>
//in fact this program writes the "x" value for the end "r" defined by r loop and puts in "output" file

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
        double Array[Nend-Nskip];// first added line

	for(double r=0; r <= 4; r += 0.01){
          ofstream out("output.dat");// second added line
	  x=x0;
	   for(int i=1; i <= Nskip; i++)
		   x = r*x*(1-x);
	   for(int i=Nskip+1; i <= Nend; i++){
	   		   x = r*x*(1-x);
	   		   //cout << r << "\t" << x << endl;
			   Array[i-Nskip-1]=x;//3rd added line
   	   }
   	    for(int i=0; i<Nend-Nskip; i++) out<< r << "\t" <<Array[i]<<endl;//4th added line
         out.close();//5th added line
	}
	return 0;
}

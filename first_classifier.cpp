#include "iostream"
#include "math.h"
using namespace std;

class ScrappyKNN{
	public:
		
		int tfeature1[9];
		int tfeature2[9];
		int tlabels[9];
		
		//Fit() remembers the training dataset
		
		int Fit(int feature1[9],int feature2[9],int labels[9]){
			for(int i=0;i<9;i++){
				tfeature1[i]=feature1[i];
		        tfeature2[i]=feature2[i];
				tlabels[i]=labels[i];
		    }
		}
		
		//Euc() calculates Euclidean distance
		
		int Euc(int a1[1],int a2[1],int b1[9],int b2[9],int x){
			
			return sqrt( pow((a1[0]-b1[x]),2) + pow((a2[0]-b2[x]),2));
		}
		
		//Closest() calculates the closest neighbor for the testing data
		
		int Closest(int testfeature1[1],int testfeature2[1]){
			
			int best_dist=Euc(testfeature1,testfeature2,tfeature1,tfeature2,0);
			int best_match=tlabels[0];
			int dist;
			for(int i=1;i<9;i++){
				dist=Euc(testfeature1,testfeature2,tfeature1,tfeature2,i);
				if(dist < best_dist){
					best_dist=dist;
					best_match=tlabels[i];
				}
			}
			return best_match;
		}
		
		//Predict() predicts the output of the the data entered by user
		
		void Predict(){
			int testfeature1[1];
			int testfeature2[1];
			
			cout<<"Enter the features of the car(Speed and no. of seats): ";
			for(int i=0;i<1;i++){
				cin>>testfeature1[i]>>testfeature2[i];
			}
			if(Closest(testfeature1,testfeature2) == 0) //0=minivan
			    cout<<"MiniVan";
			else if(Closest(testfeature1,testfeature2) == 1)//1=sedan
			    cout<<"Sedan";
			else if(Closest(testfeature1,testfeature2) == 2)//2=sporstcar
			    cout<<"SportsCar";
		}
};
		
int main(){
	
	int feature1[]={150,300,400,500,700,200,350,160,370}; //HorsePower, change if you find a better dataset 
	
	int feature2[]={8,4,2,2,2,8,4,8,4};//No. of seats, change if you find a better dataset
	
	int labels[]={0,1,2,2,2,0,1,0,1};//Labels respective to HP and no. of seats, change if you find a better dataset
	
	ScrappyKNN ob;
	ob.Fit(feature1,feature2,labels);
	ob.Predict();
	return 0;
}


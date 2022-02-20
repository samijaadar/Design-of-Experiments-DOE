//SAMI JAADAR 


#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h> 
using namespace std;
int n=8;//n nombre de lignes (experiences)
int i,j,k;
double optim=3;
double	X1[]={-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1};
double  X2[]={-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1};
double  X3[]={-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1};
double tab[][8]={
						{1,1,1,1,1,1,1,1},
						{-1,1,-1,1,-1,1,-1,1},
						{-1,-1,1,1,-1,-1,1,1},
						{-1,-1,-1,-1,1,1,1,1},
						{1,-1,-1,1,1,-1,-1,1},
						{1,-1,1,-1,-1,1,-1,1},
						{1,1,-1,-1,-1,-1,1,1},
						{-1,1,1,-1,1,-1,-1,1}
	};
double y[]={0.181,0.16,0.171,0.17,0.178,0.172,0.181,0.17};
//fonction d'affichage d'une table 3D
void afficher(double r[11][11][11]){
		for(k=0;k<11;k++){
			cout<<"pour X3 = "<<X3[k]<<endl;
			cout<<endl<<"========================================================================================"<<endl;
			for(i=0;i<11;i++){
				for(j=0;j<11;j++){
					cout<<setprecision(4)<<r[i][j][k]<<"\t ";
				}cout<<endl<<"========================================================================================"<<endl;
			}cout<<endl;
		}
}
//fonction de calcule des betas
double *cal_beta(){
	double *r=(double*)malloc(sizeof(double)*n);
	*(r+0)=0;	
				for(i=0;i<8;i++){
					for(j=0;j<n;j++){
						r[i]+=tab[i][j]*y[j];				
					}r[i]/=8;
				}	
return r;
}
//fontction du rechercher des valeurs entre min et max 
void Aff_valeur_min_max(double r[11][11][11],double min,double max){
	for (k=0;k<11;k++){
		for(i=0;i<11;i++){
			for(j=0;j<11;j++){
				if((r[i][j][k]>=min) && (r[i][j][k]<=max)){ //verifier si la valeur et entre min et max des tolérances
					cout<<"( X1= "<<X1[i]<<" \t X2= "<<X2[j]<<"  \t X3= "<<X3[k]<<")"<<endl;
				}
			}
		}
	}
}

void afficher_optimale(double r[11][11][11],double opti,double min, double max){
		for (k=0;k<11;k++){
			for(i=0;i<11;i++){
				for(j=0;j<11;j++){
					if((r[i][j][k]>=min) && (r[i][j][k]<=max)&& X1[i]+X2[j]+X3[k]==opti){ //verifier si la valeur et entre min et max des tolérances
					cout<<"( X1= "<<X1[i]<<" \t X2= "<<X2[j]<<"  \t X3= "<<X3[k]<<")"<<endl;
					}
				}
			}
		}
}

int main (){
double*B=cal_beta();
double min=17.49,max=17.5; //exemple pour lequel on chercher a determiner les valeurs entre 17.49 et 17.50



//cout<<"entrer min:"<<endl;
//cin>>min;
//cout<<"entrer max:"<<endl;
//cin>>max;

double r[11][11][11];//tableau 3D qui reçoit les valeurs des itérations sur Xi
	for (k=0;k<11;k++){
		for(i=0;i<11;i++){
			for(j=0;j<11;j++){
				r[i][j][k]=(B[0]+B[1]*X1[i]+B[2]*X2[j]+B[3]*X3[k]+B[4]*X1[i]*X2[j]+B[5]*X1[i]*X3[k]+B[6]*X2[j]*X3[k]+B[7]*X1[i]*X2[j]*X3[k])*100;
				
				if((r[i][j][k]>=min) && (r[i][j][k]<=max)){
					if ((X1[i]+X2[j]+X3[k])<=optim){
						optim=X1[i]+X2[j]+X3[k];
					}
				}
			}		
		}
	}
	//affichage des entrées
	cout<<"affichage des entrées Yi"<<endl;
	for(i=0;i<n;i++){
		cout<<"Y"<<i<<"= "<<y[i]*100<<endl;
	}
	//affichage des betas
	cout<<endl<<"calcule des betas:"<<endl;
	for(i=0;i<n;i++){
		cout<<"Beta"<<i<<"= "<<B[i]<<endl;
	}
	//Affichage des ensembles d'optimum
	cout<<endl<<"Les valeurs de Xi qui satisfait les conditions (Xi des valeurs entre "<<min<<" , "<<max<<")"<<endl;
	Aff_valeur_min_max(r,min,max);

	//Affichage des meilleurs optimum qui satisfait les conditions;
	cout<<endl<<"les valeurs du Xi les plus optimaux sont:"<<endl;
	afficher_optimale(r,optim,min,max);
	cout<<endl;
	
	//affichage des valeurs d'itération sur Xi
	afficher(r);
}

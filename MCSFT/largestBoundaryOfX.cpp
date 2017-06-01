/**
Description : Largest sub square surrounded by all X's.
**/
#include <bits/stdc++.h>
using namespace std;

#define r 6
#define c 6

int main(){
	int mat[r][c] =  {{'X', 'O', '0', 'X', 'X', 'X'},
                      {'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'X', 'O', 'X'},
                      {'O', 'X', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'O', 'X', 'O'},
                      {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
	int vert[r][c],hor[r][c],i,j;
	for(i=0; i<r; i++)for(j=0; j<c; j++){vert[i][j]=hor[i][j]=0;}
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			if(mat[i][j]=='X'){
				if(i==0){vert[i][j]=1;}
				else vert[i][j]=vert[i-1][j] + 1;
				if(j==0){hor[i][j]=1;}
				else hor[i][j] = hor[i][j-1] + 1;
				}
			else{
				hor[i][j] = vert[i][j] = 0;
				}
			}
		}
	//for(i=0; i<r; i++){for(j=0; j<c; j++)cout<<vert[i][j]<<" "; cout<<endl;}
	int ans=0;
	for(i=r-1; i>=1; i--){
		for(j=c-1; j>=1; j--){
			int mini = min(vert[i][j], hor[i][j]);
			//cout<<mini<<" "<< vert[i][j-mini+1] <<" "<< hor[i-mini+1][j] <<endl;
			while(mini > ans){
				if(mini > ans && vert[i][j-mini+1]>=mini && hor[i-mini+1][j]>=mini){
					ans = mini;
					}
				mini--;
				}
			}
		}
	cout<<"Answer is : "<<ans;
	return 0;
	}

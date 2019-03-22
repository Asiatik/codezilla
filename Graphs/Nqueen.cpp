#include <bits/stdc++.h>
using namespace std;

bool board[11][11];

bool possible(int n , int row, int colum){
  for(int i=row-1;i>=0;i--)
    if(board[i][colum] == 1)
      return false;
  for(int i=row-1,j=colum-1;j>=0 && i>=0;j--,i--)//dono i and j decrement kr rhe
    if(board[i][j] == 1)
      return false;
  for(int i=row-1,j=colum+1;i>=0 && j<n;i--,j++)//i decrement kr rha aar j badh rha
    if(board[i][j] == 1)
      return false;
  return true;
}

void helpQueen(int n, int row){
  if(row == n){
    //print
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        cout<<board[i][j]<<" ";
    cout<<endl;

	}
	exit(0);
    return;
  }
  
  for(int j=0;j<n;j++){
    if(possible(n,row,j)){
      board[row][j] = 1;
      helpQueen(n,row+1);
      board[row][j] = 0;
    }
  }
  return;
}


void placeNQueens(int n){

	memset(board,0,11*11*sizeof(bool));
  	helpQueen(n,0);

}

int main()
{
	int n;
	cin>>n;
	placeNQueens(n);
	return 0;
}
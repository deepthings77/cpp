#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printAdjList(vector<int> adjList[] , int v){
    for(int i = 0 ; i < v ; i ++){
        cout << i << "-> " << "{"; 
        for(auto it : adjList[i]){
            cout << it << " " ; 
        }
        cout << "}";
        cout << endl;
    }

}
void printAdjMat( vector<vector<int>> &adjMat , int v){
    for(int i = 0 ; i < v ; i++){
        for(int j = 0 ; j < v ; j++){
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

}

void transList(vector<int> adjList[] ,vector<int> adjRevList[], int v){
    for(int i= 0 ; i < v ; i++){
        for(auto it : adjList[i]){
            adjRevList[it].push_back(i);
        }
    }

}
void transMat(vector<vector<int>> &adjMat ,vector<vector<int>> &adjRevMat,  int v){
    for(int i = 0; i < v ; i++){
        for(int j = 0 ; j < v ; j++){
            if(adjMat[i][j] == 1){
                adjRevMat[j][i] = 1 ;
            }
        }
    }
}


int main(){

int n , m ;
cout << "Enter Total nodes" << endl ;
cin >> n ;
cout << endl;
cout << "Enter total edges" << endl;
cin >> m;
cout << endl;

//int adjMat[n+1][n+1]; // adj matrix
vector<vector<int>> adjMat(n+1, vector<int> (n+1 , 0));
vector<int> adjList[n+1]; // adj List
vector<int> adjRevList[n+1]; // Reverse Adj List
vector<vector<int>> adjRevMat(n+1, vector<int> (n+1 , 0));


//directed graph
for(int i = 0 ; i < m ; i++){
    int u , v ;
    cout << "Enter Edges "<< endl;
    cin >> u >> v ;
    adjList[u].push_back(v) ; 
    adjMat[u][v] = 1 ;
}


printAdjList(adjList , n);
cout << endl;
printAdjMat(adjMat , n);
cout<<endl;
transList(adjList, adjRevList, n);
transMat(adjMat , adjRevMat , n);

cout<< " Transpose " <<endl;
printAdjList(adjRevList , n);
cout<<endl;
printAdjMat(adjRevMat , n);


    return 0;
}
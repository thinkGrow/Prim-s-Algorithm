

#include<iostream>
#include<limits.h>
using namespace std;
int n=5;

//Min Node will return the node having minimum weight
int min_node(int matrix[5][5],bool visited[5]){
    int result;
    int min_value=INT_MAX;

    for(int i=0;i<n;i++){
        if(visited[i]){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<min_value && !visited[j]){//If the node is not in visited array then consider it,otherwise not,
                                                            //to avoid the loop in the minimum spanning tree
                    min_value=matrix[i][j];//update the min value
                    result=i*10 + j;
                }//endl inner if structure
            }//end inner for loop
        }//end outer if structure
    }//end outer for loop

    return result;
}

int main(){
cout<<"Hello world\n";
int matrix[5][5]={
                    {0,18,15,0,0},
                    {18,0,12,0,13},
                    {15,12,0,20,0},
                    {0,0,20,0,11},
                    {0,13,0,11,0}
                };

//Display the matrix
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
        cout<<matrix[i][j]<<"\t";


     cout<<"\n";
}

//Make the disconnected node weight = MAX
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(matrix[i][j]==0)
            matrix[i][j]=INT_MAX;
    }
}

//Take an visited array
bool visited[5];
//Make all the entries of visited array false
for(int i=0;i<5;i++)
    visited[i]=false;

int source;
cout<<"Enter the source vertex\n";
cin>>source;

visited[source]=true;

//Tree having 'n' vertices will have 'n-1' edges in the minimum spanning tree
int t=4;
while(t>0){
    int result=min_node(matrix,visited);
    int i=result/10;
    int j=result%10;
    visited[j]=true;//Now add the new node the visited, to consider the its edeges in the condition
    cout<<"Path "<<i<<"- "<<j<<" ="<<matrix[i][j]<<endl;

t--;
}

return 0;
}

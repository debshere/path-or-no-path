#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
/*the appraoch followed in this solution is DFS*/


using std::vector;
using std::stack;
using std::pair;

int check(vector<vector<int> > &adj,vector<int>&row,vector<int>&visited,int y,stack<int> &toVisit){
  
  //base case
    for (const auto &item : row) {//check if the desired node is present in the immediate neighbourhood of given node
        if (item == y) {
            return 1;
           
        }
    }
    //if not, go through the following
    int prevLength=toVisit.size();//this is to see if new elements are added or not into the to visit list.
    // i.e, to check if there are any neighbours of the nodr
  
    for (const auto &item : row){//for every node in the neighbourhood of the given node
    //first see if the neighbour node is already visited or not
      if(std::find(visited.begin(), visited.end(), item) != visited.end()){
        //if it is already visited, skip that neighbour
        continue;
      }  
      else{//else, that node is to be visited next. hence insert that as a valid neighbour to be visited
        toVisit.push(item); 
      }
       

    }
    int result=0;
    
        
        while(prevLength!=toVisit.size()){//if there are valid nodes that are to be visited, 
        //and keep checking if the desired node is a neighbour, as we traverse deep, for all the immediate unvisited neighbours 
        //of the given starting node
          int a=toVisit.top();//pick the top to Visit element in th eto visit list, and store it in a variable
          visited.push_back(toVisit.top());//mark it as it is being currently visited
          toVisit.pop();//take it away from the toVisit list
          result=check(adj,adj[a],visited,y,toVisit);//call the function again to check if the desired node is present in this current neighbour
          
          
          if(result==1){
            return result;
            break;
          }
          

        }
        
        return result;

    
  
}
int reach(vector<vector<int> > &adj, int x, int y) {
 
  stack <int> toVisit;//make a stack to keep a track of the nodes that you need to check/visit.
  toVisit.push(x);//first insert the given node, as this node needs to be checked/visited first.
  vector<int> visited;//make a vector to list all the nodes that have been checked to have a possible path to the desired node
  visited.push_back(x);//since this is visited, mark visited for the same
  return check(adj,adj[x],visited,y,toVisit);//now check if their exists a path between the currently visiting and the desired node

}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x;
    int y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  int x;//desired node
  int y;//given node
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}

//Normal Comparators 
//functors Comparators 
//Lambda Comparators

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<pair<int,int> >& vec){
    for(pair<int,int> p : vec){
        cout << p.first << " " << p.second << " " << ":";
    }
    cout << endl;
}
bool myComp(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.first == p2.first){
        if(p1.second > p2.second) return true; //descending order me sort 
        else
            return false;
    }
    return p1.first > p2.first;
}

//functors 
struct myComp{

  bool operator()(pair<int, int> p1, pair<int,int> p2){
      return p1.first > p2.first;
  }
};

void printVec(vector<int>& vec1){
    for(auto &vc : vec1){
        cout << vc << " ";
    }
    cout << endl;
}



int main()
{
    vector<pair<int,int>> vec = {{2, 3}, {3, 4}, {3, 1}};
    
    // sort(begin(vec), end(vec), myComp); 
    
    // functors  
    // sort(begin(vec), end(vec), myComp()); 
    
    //Lambda expression 
    vector<int> vec1 = {2, 3, 5, 6};
    
    auto myLamda = [](int a, int b){
        return a > b;
    }; //ye bhul jata ho lagana 
    sort(vec1.begin(), vec1.end(), myLamda);
    
    
    // print(vec); 
    printVec(vec1);
    

    return 0;
}

#include<iostream>

#include<vector>
using namespace std;
int linearsearch(int key){
    long int n;
    std::cout << "no of elements in array ;" << std::endl;
    cin>>n;
    vector<int>a(n);
    std::cout << "enter the array" << std::endl;
    for (int i = 0; i < n; i++)
    
    { 
        cin>>a[i];
    }
   
   for (int i = 0; i <n; i++)
   {if(a[i]==key){
    cout<<"key found at"<<i<<endl;
   }else{
    cout<<"key not found"<<endl;
   }
    
   }
   return 0;
}
int main(){
    int key;
    std::cout <<"enter the key" << std::endl;
    cin>>key;
    
   linearsearch(key);
    
}
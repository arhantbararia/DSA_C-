#include <iostream>
#include<list>
using namespace std;


list<int> :: iterator find(list<int>::iterator start , list<int>::iterator end , int x )
{
    list<int> :: iterator it ;
    for(it = start ; it != end ; it++)
    {
        if(*it == x)
        {
            return it;
        }
    }
    return end;

}

int main() {

    list<int> L;

    for(int i = 0 ; i < 7 ; i++)
    {
        L.push_back(i);
    }

    auto itr = find(L.begin() , L.end() , 6);


    if(itr != L.end())
    {

    std::cout<<*itr;
    }
    else 
    {
        cout<<"element not found"<<endl;
    }
    return 0;
}

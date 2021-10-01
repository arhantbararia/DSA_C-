#include <iostream>
#include <list>

using namespace std;

void showlist(list<int> g )
{
    list<int> :: iterator it;
    for(it = g.begin(); it != g.end() ; ++it)
    {
        cout<<"\t"<<*it;
        
    }
    cout<<"\n";
}

list<int> Union(list<int> L1 , list<int> L2)
{
    list<int>::iterator it1 , it2 , it3;
    list<int> result;

    for(it1 = L1.begin() ;  it1 != L1.end() ; it1++)
    {
        result.push_back(*it1);

    }
    for(it2 = L2.begin() ; it2 != L2.end() ; it2++)
    {
        for(it3 = L1.begin() ; it3 != L1.end() ; it3++)
        {
            if(*it2 != *it3)
            {
                result.push_back(*it2);
                break;

            }
        }
    }

    return result;
}


int main() {

    list<int> L1;
    list<int> L2;
    
    for(int i = 1 ; i <= 10; i++)
    {
        L1.push_back(i*2);
        L2.push_back(i*3);
    }

    list<int> L3;

    L3 = Union(L1 , L2);
    showlist(L1);
    showlist(L2);
    showlist(L3);
    
    
    return 0;
}

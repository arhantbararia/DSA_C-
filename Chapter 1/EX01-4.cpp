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


list<int> intersection(list<int> L1 , list<int> L2)
{
    list<int> L3;
    list<int>::iterator it1;
    list<int>:: iterator it2;

    for(it1 = L1.begin() ; it1 != L1.end() ; it1++)
    {
        for(it2 = L2.begin() ; it2 != L2.end() ; it2++)
        {
            if(*it2 == *it1 )
            {
                L3.push_back(*it1);

            }
        }
    }

    return L3;

}

int main() {

    list<int> E , O , result;
    for(int i = 0 ; i < 20 ; i++)
    {
        E.push_back(i*2);
        O.push_back(i*3);

    }
    cout<<"list 1: "<<endl;
    showlist(E);
    cout<<"List 2: " <<endl;
    showlist(O);

    cout<<"intersection of l1 , l2 "<<endl;
    result = intersection(E , O);
    showlist(result);
    
    return 0;
}

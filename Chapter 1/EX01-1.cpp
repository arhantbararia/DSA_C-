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

void printLots(list<int> L , list<int> P)
{
    list<int> :: iterator it1;
    list<int> :: iterator it2;

    int i = 0;
	
	
	/*
	n1 = N(P);
	n2 = N(L);
	
	O(n1 X n2);
	
	*/
    for(it1 = P.begin() ; it1 != P.end() ; ++it1)
    {
		int i = 0;
        for(it2 = L.begin(); it2 != L.end(); it2++ )
        {
            if(i == *it1 )
            {
                cout<<"  "<<*it2;

            }
            i++;

        }   

    }

}

int main() {


    list<int> L , P;
    
    for(int i = 0 ; i < 20 ; i++)
    {
        L.push_back(i);
    }

    P.push_back(1);
    P.push_back(3);
    P.push_back(4);
    P.push_back(6);
    // enter any element [1 , 20]



    showlist(P);

    return 0;
}
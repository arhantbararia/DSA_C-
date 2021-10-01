#include <iostream>
using namespace std;

class cirque
{
    int size;

public:

    class person
    {
    public:
        int id;
        person* next;

        person(int i = 0 ,person* n = NULL): id(i) , next(n){

        }

        ~person()
        {
            delete this;
        }
    };

    person *head, *tail;

    cirque()
    {
        size =0;
        head = new person;
        tail = new person;

        head->next = tail;
        tail->next = head;  
    }

    void insert(int i)
    {
        person *temp = new person(i);

        if(size == 0)
        {
            head->next = temp;
            temp->next = tail;
           
        }
        else{
            person* n = new person;
            n = head;
            while( n != tail)
            {
                n = n->next;

            }
            n->next = temp;
            n = n->next;
            n->next = tail;            
        }
        size++;
    }

    void kick(int i)
    {
        
        if(size == 1)
        {
            cout<<head->next->id<<"is the winner"<<endl;
            
        }
        else{
            person* temp = new person;
            temp = head;
            int j = 0;
            while(j != i)
            {
                temp = temp->next;
                j++;

            }
            cout<<temp->next<<"kicked! ";
            temp->next = temp->next->next;
            delete temp;
            size--;

        }
    }

    void see()
    {
        if(size == 0)
        {
            cout<<"no one is playing"<<endl;

        }
        else 
        {
            person* temp = new person;
            temp = head->next;
            while(temp != tail)
            {
                cout<<temp->id<<"--";
                temp = temp->next;
            }
        }
    }
};


int main() {

    cirque circle;
    int n;cin>>n;
   // int m;cin>>m;

    for(int i = 1 ; i <= n; i++)
    {
        circle.insert(i);
    }

    circle.see();


    
    return 0;
}
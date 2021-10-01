#include <iostream>
using namespace std;

class cirque
{
    

public:

    class person
    {
    public:
        int id;
        person* next;
        person* prev;

        person(int i = 0 ,person* n = NULL ): id(i) , next(n){
                prev = NULL;

        }

        ~person()
        {
            delete this;
        }
    };


    //data members
    person *head, *tail;
    int size;
    int start = 1;

    cirque()
    {
        size =0;
        head = new person;
        tail = new person;

        head->next = tail;
        tail->next = head;  
        tail->prev = head;
    }

    void insert(int i)
    {
        person *temp = new person(i);

        if(size == 0)
        {
            head->next = temp;
            temp->next = tail;
            tail->prev = temp;
           
        }
        else{
            tail->prev->next = temp;
            
            tail->prev = temp;
            temp->next = tail;

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
            temp = head->next;
            int j = 1;
            while(j != i*start)
            {
                temp = temp->next;
                j++;

            }
            
            cout<<temp->id<<"kicked! \n";
            temp = temp->next->next;
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
    int m;cin>>m;

    for(int i = 1 ; i <= n; i++)
    {
        circle.insert(i);

    }


    circle.see();

    while(circle.size != 1)
    {
        circle.kick(m%n);
        circle.start++;

        
        circle.see();
    }


    
    return 0;
}
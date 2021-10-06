#include <iostream>
using namespace std;

class cirque
{
    

public:

    class person
    {
    public:
        char id;
        person* next;
        person* prev;

        person(char i ,person* n = NULL ): id(i) , next(n){
                prev = NULL;

        }

        
    
    };


    //data members
    person *head;
    person *next_to_kicked;

    int size;
    int start = 1;

    cirque()
    {
        size =0;
       
    }

    void insert(char i)
    {
        person *temp = new person(i);

        if(size == 0)
        {
            head = temp;
            head->next = head;
            next_to_kicked = head;
        }
        else{
            person *temp1 = head;
            while(temp1->next != head)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
            temp->next = head ;


        }
        size++;
    }

    void kick(int k)
    {
        if(size == 1 )
        {
            std::cout<<head->id<<" Wins! "<<std::endl;
            size--;


        }
        else 
        {
            
            
            if(k ==0)
            {   
                person* temp = head;

                std::cout<<temp->id<<" kicked! "<<std::endl;
                while(temp->next != head)
                {
                    temp = temp->next;
                }
                //person* temp1 = temp->next;
                //std::cout<<temp1->id<<std::endl;
                head = head->next;
                temp->next = head;
                size--;

                return;

            }
            else
            {   person* temp = next_to_kicked;

                for(int i = 0 ; i < k-1 ; i++)
                {
                    temp = temp->next;

                }
                std::cout<<"\n"<<temp->next->id<<" kicked! " <<std::endl;
                
                next_to_kicked = temp->next->next;
                std::cout<<next_to_kicked->id<<std::endl;

                temp->next = temp->next->next;
                size--;

            }
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
            person* temp = head ;
            while(temp->next != head)
            {
                std::cout<<temp->id<<"--";
                temp = temp->next;
            }
            std::cout<<temp->id;
        }
    }
};


int main() 
{

    cirque circle;
    int n;cin>>n;
    int m;cin>>m;

    for(int i= 1 ; i <= n; i++)
    {
        circle.insert((char)(i+64));

    }

    circle.see();

    
    while(circle.size != 0)
    {
        circle.kick((m % circle.size ));
        
        circle.see();
    }
    
    

    
    return 0;
}
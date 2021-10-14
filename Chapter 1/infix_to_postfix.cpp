#include <iostream>
#include<stack>
#include<string>


using namespace std;


stack<char> mystack;

void POP()
{
    cout<<mystack.top()<<" ";
    mystack.pop();
}


string operators = { '-' , '+' , '*' , '/' , '(' , ')'};

int prec(char a)
{
   
    for(int i = 0 ; i< operators.length(); i++)
    {
        if(a == operators[i])
        {
            //cout<<"precedence of"<<a<<": "<<i<<endl;
            return i;
        }
    }
}

int main() {

    string str;
    cin>>str;

    for(int i =0 ; i< str.length() ; i++)
    {
        // display operand
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
        {
            cout<<str[i]<<" ";
        }

        else if (mystack.empty() )
        {
            mystack.push(str[i]);
        }
        else if(prec(str[i]) > prec(mystack.top()))
        {
            mystack.push(str[i]);
        }
        else if(prec(str[i]) < prec(mystack.top())) {
            while(!mystack.empty())
            {
                POP();
            }
            mystack.push(str[i]);
        }
    }
        while(!mystack.empty())
                    {
                        POP();
                    }
    
    
    return 0;
}
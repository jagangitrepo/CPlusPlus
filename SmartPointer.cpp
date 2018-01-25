#include <iostream>
using namespace std;

template<class T>
class SP
{
    private:
        T* refObjPtr;
    
    public:
        SP(T* refPtr):refObjPtr(refPtr){}
        ~SP(){ delete(refObjPtr); }
        T& operator *()
        {
            return ((refObjPtr)?*refObjPtr:NULL);
        }
        
        T* operator ->()
        {
            return ((refObjPtr)?refObjPtr:NULL);
        }
};

class Node{
public:
    Node(int d):data(d){ cout<<"constr Called"<<endl; }
    ~Node(){cout<<"dest Called"<<endl;}
    int data;
    Node* next;
};

int main()
{   
    {
        SP<Node> smart(new Node(8));
    }
    return 0;
}

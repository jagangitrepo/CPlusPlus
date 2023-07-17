#include <iostream>

using namespace std;



template<class T>
class SP
{
    
    private:
        T* refObjPtr;
        
    
    public:
    static int count;
        SP(T* refPtr):refObjPtr(refPtr){ count++;}
        SP(const SP& refObj){
            this->refObjPtr = refObj.refObjPtr;
            count++;
            }
            
        SP& operator =(const SP& refObj)
        {
            if(this != &refObj)
            {
                this->refObjPtr = refObj.refObjPtr;
                count++;
            }
            return *this;
        }
        ~SP(){ count--; if(count==0) delete(refObjPtr); }
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

template<class T>
int SP<T>::count=0;

int main()
{
    
    {
        SP<Node> smart(new Node(8));
        SP<Node> smart1(new Node(9));
    }
    return 0;
}

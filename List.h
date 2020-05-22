#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
using namespace std;

template <typename T>
struct Node
    {
        T  data;
        Node *prev;
        Node *next;
    };
template <typename T>
class List
{
private:
    Node<T> *Head;
    Node<T> *Tail;
    size_t Count;
    Node<T> *temp;
public:
    List():Head(NULL),Tail(NULL)
    {
        Count = 0;
    }
    List(Node<T> Count)
    {
         if(Head < 1)
        {
            Head = 1;
        }
        this->Head = Head;
        this->Tail = 0;
        this->Count= 0;
    }
    List(const List &s)
    {
        this->Head = s.Head;
        this->Tail = s.Tail;
        this->Count= s.Count;
        this->data = new T;
    }
    ~List()
    {
        while(Head!=NULL)
        {
        Tail=Head->next;
        delete Head;
        Head=Tail;
        Count=0;
        }
    }
 /*   List<T>&operator= (const List<T> &s)
    {
        if (this == &s)
            return *this;
        delete [] this->data;
        this->Head = s.Head;
        this->Count= s.Count;
        this->data = new T[s.data];
    }*/
    void insertLast(const  T &l)
    {
  /*      if (isEmpty())
        Head = Tail = new Node<T>;
    else
    {
        Node<T> *newNode = new Node<T>;
        Tail->next = newNode; // new node is successor of tail
        Tail = newNode ;      // new tail is new node
    }
    }*/
            Node<T>*temp = new Node<T>;
            temp->next = 0;
            temp->data = l;
            temp->prev = Tail;
            if(Tail != 0)
            {
            Tail->next = temp;
            }
            if(Count == 0)
            {
                Head = Tail = temp;
            }
            else
            {
                Tail = temp;
            }
            Count++;
}
    bool insertFirst(const T &f)
    {
 /*       if (isEmpty())
        Head = Tail = new Node<T>;
    else
    {
        Node<T> *newNode = new Node<T>;
        Head->prev = newNode; // new node is predecessor of head
        Head = newNode ;          // new head is new node
    }*/
        Node<T> *temp=new Node<T>;
        temp->prev = 0;
        temp->data=f;
        temp->next = Head;
        if(Head!=NULL)
           {
        Head->prev=temp;
           }
        if(Count == 0)
        {
        Head = Tail = temp;
        }
        else
        {
        Head = temp;
        }
        Count++;
        }
    void insertAtPos(const  T &p)
    {
    if(p == 0)
    {
     return false;
    }
    if(p < 1 || p > Count + 1)
    {
        insertAtPos (p);
        return true;
    }
    if(p == Count + 1)
    {
      insertLast(p);
      return true;
    }
    else if(p == 1)
    {
      insertFirst(p);
      return true;
    }
    int i = 1;
    Node<T> * Ins = Head;
    while(i < p)
    {
      Ins = Ins->next;
      i++;
    }
    Node<T> * PrevIns = Ins->prev;
    Node<T> * temp = new Node<T>;
    temp->data=p;
    if(PrevIns != 0 && Count != 1)
    {
      PrevIns->next = temp;
    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;
    Count++;
    }
    }
    void deleteLast()
    {
        if(Tail)
         {
            Node<T> * cur=Tail;
            Tail=Tail->prev;
            if(Tail)
            Tail->next=NULL;
            delete cur;
         }
         if (!Tail)
        return;
        Count--;
    }
    void deleteFirst()
    {
        if(Head)
         {
            Node<T> * cur=Head;
            Head=Head->next;
            if(Head)
            Head->prev=NULL;
            delete cur;
         }
         if (!Head)
        return;
        Count--;
    }
    void deleteAtPos(size_t pos)
    {
    Node<T> *temp=Head;
    Node<T> *h;
    if(temp!=0 && pos<=Count)
        {
        for(int i=0; i!=pos; i++)
        {
            h=temp;
            temp=temp->next;
        }
        if(temp==Head)
            {
            Head=temp->next;
            }
        else
            {
            h->next=temp->next;
            }
        delete temp;
        }
Count--;
    }
    void clear()
    {
    while (Count!=0)
    deleteAtPos(0);
    }
    int getLast()
    {
    if(Tail!=NULL)
        {
       return Tail->data;
        }
    }
    int getFirst()
    {
    if(Head!=NULL)
        {
       return Head->data;
        }
    }
    bool isContains (T value)
    {
    Node<T> *pt;
    pt = Head;
    while (pt != NULL)
    {
        if (value == pt->data)
        {
        return true;
        }
    else
        pt = pt->next;
        }
      return false;
        }
    bool isEmpty()
        {
         if (Head ==NULL)
            {

            return true;
            }
        else return false;
        }
    int size()
    {
        return Count;
    }
    void print() const
    {
    if(Count != 0)
   {
      Node<T> * temp = Head;
      cout << "( ";
      while(temp->next != 0)
      {
          cout << temp->data << ", ";
          temp = temp->next;
      }

      cout << temp->data << " )\n";
   }
    }
};
#endif // LIST_H_INCLUDED

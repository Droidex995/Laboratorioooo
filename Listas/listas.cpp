#include "listas.h"
#include <iostream>
using namespace std;

template<class T>
IntSLList<T>::~IntSLList(){
    for(IntNode<T> *p;!isEmpty();){
	p=head->next;
	delete head;
        head=p;
    }
}
template<class T>
void IntSLList<T>::addToTail(const T& el){
	if(tail!=0){
		tail->next=new IntNode<T>(el);
		tail=tail->next;
        }
	else head=tail=new IntNode<T>(el);
}

template<class T>
void IntSLList<T>::addToHead(const T& el){
	head=new IntNode<T>(el,head);
	if(tail==0)
		tail=head;

}


template <class T>
T *IntSLList<T>::deleteFromHead(){
	if(!isEmpty()){
        T *el=new T(head->info);
        IntNode<T>*tmp=head;
        if(head==tail)
            head=tail=0;
        else head =head->next;
        delete tmp;
        return el;
	}
	else return 0;
}

template<class T>
T IntSLList<T>::deleteFromTail(){
	T el=tail->info;
	if(head==tail){
		delete head;
		head=tail=0;
	}
	else {
		IntNode<T> *tmp;
		for(tmp=head;tmp->next !=tail;tmp=tmp->next);
		delete tail;
		tail=tmp;
		tail->next=0;
	}
	return el;
}

template<class T>
void IntSLList<T>::deleteNode(const T& el){
  if(head !=0){
	if(head==tail && el==head->info){
		delete head;
		head=tail=0;
	}
	else if(el==head->info){
		IntNode<T> *tmp=head->next;
		head=head->next;
		delete tmp;
	}
    	else{
	      IntNode<T> *pred, *tmp;
	      for(pred=head,tmp=head->next;
              tmp !=0 && !(tmp->info==el);
              pred =pred->next,tmp=tmp->next);
              pred->next=tmp->next;
              delete tmp;
	     
	}
   }
}


template<class T>
void IntSLList<T>::print_list(){
	IntNode<T> *p;
	for(p=head;!(p==NULL);p=p->next){				 
		cout<<p->info << " ";

	}
}

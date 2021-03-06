#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
template<class T>
class IntNode{
	public:
	     	T info;
     		IntNode<T> *next;
     		IntNode(const T&el, IntNode *ptr= 0){
	         	info=el;next=ptr;
	    	 }


	};
template<class T>
class IntSLList{
	public:
		IntSLList(){
		  head=tail=0;
		}
                ~IntSLList();
		T isEmpty(){
		  return head==0;
		}
		void print_list();
		void addToHead(const T&);
		void addToTail(const T&);
		T* deleteFromHead();
		T deleteFromTail();
		void deleteNode(const T&);
		
		bool isInList(const T&) const;
		
	private:
		IntNode<T> *head, *tail;

        };
	#endif

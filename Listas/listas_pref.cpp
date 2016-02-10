#include "listas_pref.h"
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;

template<class T>
Pilap<T>::~Pilap(){
   for(Nodpre<T> *p;(primero)!=NULL;){
	p=primero->next;
	delete primero;
        primero=p;
    }
   for(Nodpre<T> *pc;(primero)!=NULL;){
	pc=primeroc->next;
	delete primeroc;
        primeroc=pc;
    }
   for(Nodpre<T> *ps;(primeros)!=NULL;){
	ps=primeros->next;
	delete primeros;
        primeros=ps;
    }
   for(Nodpre<T> *psc;(primerosc)!=NULL;){
	psc=primerosc->next;
	delete primerosc;
        primerosc=psc;
    }
    for(Nodpre<T> *p;(primerosci)!=NULL;){
	p=primerosci->next;
	delete primerosci;
        primerosci=p;
    }
}


template<class T>
void Pilap<T>::push(const T& el){
	if(primero!=0){
		primero=new Nodpre<T>(el,primero,0);
		primero->next->prev=primero;
	}	
	else ultimo=primero=new Nodpre<T>(el,0,0);
	
}


//template<class T>
/*
void Pilap<T>::pop(){
	for(Nodpre<T> *p;!isEmpty();){
	cout<<primero->info<<" ";
	p=primero->next;	
	delete primero;
        primero=p;
	
    }
    cout<<endl;z
}
*/

template<class T>
void Pilap<T>::push_pref(string b){
	//int y1;
	//int x=0;
	//int in=0;
	//int inc=0;
	//char num[12];
	string acum;
	string s;
	string s1;
	//string b="((10+2)*4)";
	//string b="(100*26+10)";
	//string b="(16*5/4)";
	int tam=b.length();
	//char b[20]="((10+2)*4)";
	//cout<<b[tam-1]<<endl;	
	char ac[20]; 
	int par=0;
	cout<<"Expresion normal : "<<b<<endl;
	for(int t=0;t<tam;t++){
		if(b[t]=='('|| b[t]==')')
			par++;
	}
	if(par%2!=0){
		cout<<"Amigo falta parentesis pero igual lo resolveremos"<<endl;
	}
	for(int i=0;i<tam;i++){
		if(b[i]=='0'|| b[i]=='1'|| b[i]=='2' || b[i]=='3'|| b[i]=='4'|| b[i]=='5'|| b[i]=='6'|| b[i]=='7'|| b[i]=='8' || b[i]=='9'){
		      if(b[i+1]!='0'&& b[i+1]!='1'&& b[i+1]!='2' && b[i+1]!='3'&& b[i+1]!='4'&& b[i+1]!='5' && b[i+1]!='6'&& b[i+1]!='7'&& b[i+1]!='8' && b[i+1]!='9'){
			//cout<<"VALORRRRRRRRRRR"<<endl;
			ac[0]=b[i];
			stringstream ss;
			char c = ac[0];
			ss << c;
			ss >> s;
			acum=s;
			}
		if(b[i+1]=='0'|| b[i+1]=='1'|| b[i+1]=='2' || b[i+1]=='3'|| b[i+1]=='4'|| b[i+1]=='5'|| b[i+1]=='6'|| b[i+1]=='7'|| b[i+1]=='8' || b[i+1]=='9' || b[i+1]=='.'){		
			
			stringstream ss;
			char c = b[i];
			ss << c;
			ss >> s;
			acum=s;
	while (b[i+1]=='0'|| b[i+1]=='1'|| b[i+1]=='2' || b[i+1]=='3'|| b[i+1]=='4'|| b[i+1]=='5'|| b[i+1]=='6'|| b[i+1]=='7'|| b[i+1]=='8' || b[i+1]=='9' || b[i+1]=='.'){
	
			stringstream ss;
			char c = b[i+1];
			ss << c;
			ss >> s;
			acum=acum+s;
			i++;
			//cout<<acum<<endl;
			}
		}	
			

			if(primeroc!=0){
				primeroc=new Nodpre<string>(acum,primeroc,0);
				//cout<<primeroc->info<<endl;			
				primeroc->next->prev=primeroc;
			
			}	
			else{
				 ultimoc=primeroc=new Nodpre<string>(acum,0,0);	
				//cout<<primeroc->info<<endl;
			}		
		//cout<<"3333"<<endl;	
		}
	
     if(b[i]!='0'&& b[i]!='1'&& b[i]!='2' && b[i]!='3' && b[i]!='4' && b[i]!='5' && b[i]!='6' && b[i]!='7' && b[i]!='8' && b[i]!='9'){ 

	if(b[i]!=')'){
		ac[0]=b[i];
		stringstream ss;
		char c = ac[0];
		ss << c;
		ss >> s;
		acum=s;
		if(primero!=0){
			primero=new Nodpre<string>(acum,primero,0);
			//cout<<acum<<"es un parenteis todo mnos "<<endl;
			primero->next->prev=primero;
		}	
		else {
			ultimo=primero=new Nodpre<string>(acum,0,0);	
			//cout<<acum<<"es un parenteis todos mnios "<<endl;
		}
	}
	if(b[i]==')'){
		//cout<<"hola"<<endl;
		ac[0]=b[i];
		stringstream ss;		
		char c = ac[0];
		ss << c;
		ss >> s;
		acum=s;			
		if(primero!=0){
			primero=new Nodpre<string>(acum,primero,0);
			//cout<<acum<<"es"<<endl;
			primero->next->prev=primero;
		}	
		else {
			ultimo=primero=new Nodpre<string>(acum,0,0);	
			//cout<<acum<<"es un parenteis todos mnios "<<endl;
		}
		//cout<<"he aqui el error"<<endl;
		//cout<<a[i]<<endl;
		Nodpre<T> *p;
	   
	    for(;(primero->info)!="(";){
		//cout<<primero->info<<endl;
		//cout<<"wwww"<<endl;
		if((primero->info)!=")"&& (primero->info)!="("){
			//cout<<"wwww"<<endl;
		      if(primeroc!=0){
			primeroc=new Nodpre<string>(primero->info,primeroc,0);
			//cout<<primeroc->info<<endl;
			primeroc->next->prev=primeroc;
			}	
		        else {
				ultimoc=primeroc=new Nodpre<string>(primero->info,0,0);	
				//cout<<primeroc->info<<endl;
			}			
		}
		//cout<<primero->info<<endl;
		p=primero->next;	
		delete primero;	
		primero=p;		
	    }
		//cout<<primero->info<<endl;
		p=primero->next;	
		delete primero;	
		primero=p;
		
	}
	//cout<<primeroc->info<<endl;
   }	
  }	
}




template<class T>
void Pilap<T>::pop_pref(){
	//int t=0;	
	int cont=0;
	float oper;
	//char ope[20];
	//char pl[13];
	Nodpre<T>*p;
	//Nodpre<int>*o;
	for(p=ultimoc;!(p==NULL);p=p->prev){
		
	  if(p->info!="*" && p->info!="/" && p->info!="-" && p->info!="+") {
		
		if(primerosc!=NULL){
			primerosc=new Nodpre<string>(p->info,primerosc,0);
			//cout<<primerosc->info<<endl;
			primerosc->next->prev=primerosc;
		    }	
		    else {
			ultimosc=primerosc=new Nodpre<string>(p->info,0,0);
			//cout<<primerosc->info<<endl;	
		} 
	   }
    	  if(p->info=="*" || p->info=="+" || p->info=="/" || p->info=="-") {
		if(primerosc!=NULL){
			primerosc=new Nodpre<string>(p->info,primerosc,0);
			//cout<<primerosc->info<<endl;
			primerosc->next->prev=primerosc;
		    }	
		    else {
			ultimosc=primerosc=new Nodpre<string>(p->info,0,0);
			//cout<<primerosc->info<<endl;	
		} 
		Nodpre<T> *pi;
		for(int y=0;y<3;y++){
		    if(primerosci!=NULL){
			primerosci=new Nodpre<string>(primerosc->info,primerosci,0);
			//cout<<primerosc->info<<endl;
			primerosci->next->prev=primerosci;
		    }	
		    else {
			ultimosci=primerosci=new Nodpre<string>(primerosc->info,0,0);
			//cout<<primerosci->info<<endl;	
		    } 
				pi=primerosc->next;	
				delete primerosc;
        			primerosc=pi;
				cont++;		
			 }		

			string myStream =primerosci->info;
			//cout<<myStream<<endl;
			istringstream buffer1(myStream);
			float value;
			buffer1 >> value;   // value = 45 
			//cout<<value<<endl;
			string myStream1 =primerosci->next->info;
			//cout<<myStream1<<endl;
			istringstream buffer(myStream1);
			float value1;
			buffer >> value1;   // value = 45
			//cout<<value1<<endl; 
		
		
		if(primerosci->next->next->info=="+")
			oper=(value)+(value1);
		if(primerosci->next->next->info=="*")
			oper=(value)*(value1);
		if(primerosci->next->next->info=="/")
			oper=(value)/(value1);
		if(primerosci->next->next->info=="-")
			oper=(value)-(value1);
		//cout<<oper<<endl;
		stringstream sss;
		sss << oper;
		string str = sss.str();
		//cout<<oper<<endl;
		//if(oper>=10)
		//if(oper>=100)
		//if(oper>=1000)
		if(primerosc!=NULL){
				primerosc=new Nodpre<string>(str,primerosc,0);
				//cout<<oper<<endl;
			        primerosc->next->prev=primerosc;
			}
			else{		
		    		ultimosc=primerosc=new Nodpre<string>(str,0,0);
		    		//cout<<oper<<endl;	
			}

	     }
	 }
	cout<<"Resultado : "<<oper<<endl;
  }



/*
template<class T>
void Pilap<T>::print_pila(){
	Nodpre<T> *p;
	for(p=ultimo;!(p==NULL);p=p->prev){				 
		cout<<p->info;

	
	}
	cout<<endl;
	
}
*/
template<class T>
void Pilap<T>::print_pilap(){
	Nodpre<T> *pr;
	cout<<"Expresion infija : ";
	for(pr=ultimoc;!(pr==NULL);pr=pr->prev){				 
		cout<<pr->info;

	}
	cout<<endl;
}

/*
template<class T>
void Pilap<T>::print_pilasc(){
	Nodpre<T> *psc;
	for(psc=ultimosc;!(psc==NULL);psc=psc->prev){				 
		cout<<psc->info;

	
	}
	cout<<endl;
	
	
}
*/
/*
template<class T>
void Pilap<T>::print_pilas(){
	Nodpre<T> *ps;
	for(ps=ultimos;!(ps==NULL);ps=ps->prev){				 
		cout<<ps->info;

	
	}
	cout<<endl;
}
*/


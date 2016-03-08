#include <bits/stdc++.h>

using namespace std;

int n;
int action, v;
bool q,pq,s;

queue<int> fila;
priority_queue<int> pfila;
stack<int> pilha;

int main(){

   while(scanf("%d",&n) != EOF){
	q = pq = s = true;
	while(!fila.empty()) fila.pop();
	while(!pfila.empty()) pfila.pop();
	while(!pilha.empty()) pilha.pop();

	for(int i = 0 ; i < n ; i++){
	   scanf("%d %d",&action,&v);
		   
	   if(action == 1){
		fila.push(v);	      
	      	pfila.push(v);
		pilha.push(v);
	   }
	   else{
		if(q){
		   q = (fila.front() == v); fila.pop();
		}	
		if(pq){ pq = (pfila.top() == v); pfila.pop();
		}
		if(s){ s = (pilha.top() == v); pilha.pop();}
	   }
	}
    
    if((q && pq) || (pq && s))
	printf("not sure\n");
    else if(pq)
	printf("priority queue\n");
    else if(s)
	printf("stack\n");
    else if(q)
	printf("queue\n");
    else
	printf("impossible\n");
   }

   return 0;
}

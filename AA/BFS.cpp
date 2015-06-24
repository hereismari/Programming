#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<int,int> BFS(int s, vector< vector<int> > adj_list){
	
	int i,j,k;
	map<int,int> level;
	map<int,int> parent;
	vector<int> frontier;
	vector<int> next_;
	
	
	level[s] = 0;
	parent[s] = s;
	i = 1;
	frontier.push_back(s);
	while (!frontier.empty()){
		next_.clear();
		for (std::vector<int>::iterator it = frontier.begin() ; it != frontier.end(); ++it){
			j = *it;
			for (std::vector<int> ::iterator it2 = adj_list[j].begin() ; it2 != adj_list[j].end(); ++it2)
			{		
				k = *it2;
				if(level.find(k) == level.end())
					{
						level[k] = i;
						parent[k] = j; 
						next_.push_back(k);
						}
				
				}
			}
		frontier = next_;
		i++;
		}
	return level;
	}

int main(){
	
	vector< vector<int> > adj_list(50);
	map<int,int> resposta;
	int rodada = 1;
	int i,x,y;
	int V,E,I,L;
	
	while(true){
		
		scanf("%d %d %d %d",&V,&E,&I,&L);
		
		if (V == 0 && E == 0 && I == 0 && L == 0)
			break;
			
		for(i=0;i<E;i++)
		{
			scanf("%d %d",&x,&y);
			adj_list[x].push_back(y);
			adj_list[y].push_back(x);
			}
		
		
		
	printf("Teste %d\n",rodada++);
	resposta = BFS(I,adj_list);
	for (std::map<int,int>::iterator it = resposta.begin(); it != resposta.end(); ++it){
		
		if (it -> second <= L && it -> second != 0)
			printf("%d ",it -> first);
		}
		printf("\n\n");
}
	return 0;
	}


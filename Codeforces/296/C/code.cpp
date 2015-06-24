#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int w,h,n;
char c;
int k;
int maior,area;
vector< pair< pair<int,int>, pair<int,int> > > retangulos;

int main(){

	scanf("%d %d %d",&w,&h,&n);
	retangulos.push_back(make_pair(make_pair(0,0),make_pair(w,h)));
	for(int i = 0 ; i < n ; i++){
		maior = 0;
		scanf("\n%c %d\n",&c,&k);
		if(c == 'V')
		{
			for(vector< pair < pair <int,int>, pair<int,int> > >:: iterator it=retangulos.begin(); it!=retangulos.end(); it++)
			{
				if( k > (*it.first).first && k < (*it.second).first)
					retangulos.erase(it,it+1);
				retangulos.push_back(make_pair((*it.first).first,(*it.first).second),make_pair((*it.second).first-k,(*it.second).second));
				retangulos.push_back(make_pair((*it.first).first+k,(*it.first).second),make_pair((*it.second).first,(*it.second).second));
			}
		}
		else if(c == 'H'){
		
			for(vector< pair < pair <int,int>, pair<int,int> > >:: iterator it=retangulos.begin(); it!=retangulos.end(); it++)
			{
				if( k > (*it.first).second && k < (*it.second).second)
					retangulos.erase(it,it+1);
				retangulos.push_back(make_pair((*it.first).first,(*it.first).second),make_pair((*it.second).first,(*it.second).second-k));
				retangulos.push_back(make_pair((*it.first).first+k,(*it.first).second+k),make_pair((*it.second).first,(*it.second).second));
			}
		}
		
		for(vector < pair < pair <int,int>, pair<int,int> > >:: iterator it=retangulos.begin(); it!=retangulos.end(); it++){
			area = ((*it.second).first - (*it.first).first)*((*it.second).second - (*it.first).second);
			if(area > maior)
				maior =  area;

	}	

		printf("%d\n",maior);
	}
	return 0;
}

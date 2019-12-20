#include<bits/stdc++.h>
using namespace std;
using Data = pair<long long,vector<int>>;
typedef struct{
  long long flavor;
  int i;
  int j;
  int k;
}vect;

int longsort(const void *a,const void *b){
	long long *A=(long long *)a;
	long long *B=(long long *)b;
	if(*A>*B) return -1;
	if(*A<*B) return 1;
	return 0;
}

int main(){
  int x,y,z,K,i,j,k,l;
  long long a[1000]={0},b[1000]={0},c[1000]={0};
  vect t;
  scanf("%d",&x);
  scanf("%d",&y);
  scanf("%d",&z);
  scanf("%d",&K);

  for(i=0;i<x;i++){
    scanf("%lld",&a[i]);
  }
  qsort(a,1000,sizeof(long long),longsort);
  for(i=0;i<y;i++){
    scanf("%lld",&b[i]);
  }
  qsort(b,1000,sizeof(long long),longsort);
  for(i=0;i<z;i++){
    scanf("%lld",&c[i]);
  }
  qsort(c,1000,sizeof(long long),longsort);

  priority_queue<Data> que;
  set<Data> se;
  auto tt=Data(a[0]+b[0]+c[0],vector<int>({0,0,0}));
  que.push(tt);
  auto cnt=se.insert(tt);

  for(l=0;l<K;l++){
    tt=que.top();
    t.i=tt.second[0];
    t.j=tt.second[1];
    t.k=tt.second[2];
    printf("%lld\n",tt.first);
    que.pop();
    if(t.i+1<x){
      auto next=Data(a[t.i+1]+b[t.j]+c[t.k],vector<int>({t.i+1,t.j,t.k}));
      cnt=se.insert(next);
      if(cnt.second)que.push(next);
    }
    if(t.j+1<y){
      auto next=Data(a[t.i]+b[t.j+1]+c[t.k],vector<int>({t.i,t.j+1,t.k}));
      cnt=se.insert(next);
      if(cnt.second)que.push(next);
    }
    if(t.k+1<z){
      auto next=Data(a[t.i]+b[t.j]+c[t.k+1],vector<int>({t.i,t.j,t.k+1}));
      cnt=se.insert(next);
      if(cnt.second)que.push(next);
    }
  }
  return 0;
}

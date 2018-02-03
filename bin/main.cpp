#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> a[45];
std::vector<pair<int,int>> r1, r2;
void process(int l, int r, std::vector<pair<int,int>> &rr){
  std::vector<pair<int,int>> v;
  for(int i = l; i<=r; i++){
    v.push_back(a[i]);
  }
  int n = v.size();
  for(int bm = 0; bm<(1<<n); bm++){
    int sr=0, sm=0, k=0;
    for(int j = 0; j<n; j++){
      if(bm&(1<<j)) k++, sr+=v[j].first;
      else --k, sm+=v[j].second;
    }
    std::cout << bitset<5>(bm) << " -> ";
    printf("(%d, %d)\n", sm-sr, k);
    rr.push_back({{sm-sr, k},bm});
  }
}
bool cmp(pair<int,int> a, pair<int,int> b){
  if(a.first==b.first){
    return __builtin_popcount(a.second)<__builtin_popcount(b.second);
  }
  return a.first<b.first;
}
int main(){
  cin >> n;
  for(int i = 0; i<n; i++) cin >> a[i].first >> a[i].second;
  int res = 1e7;
  process(0, n/2-1, r1);
  printf("-------------\n");
  process(n/2, n-1, r2);
  sort(r2.begin(), r2.end(), cmp);
  for(auto e : r1){
    int diff = e.first;
    int bits1 = __builtin_popcount(e.second);
    int p = lower_bound(r2.begin(), r2.end(), pair<int,int>(-diff, -1e7))-r2.begin();
    if(p==r2.size()) continue;
    // int bits2 = r2[].second;
 
    printf("e = (%d, %d), p = %d=>(%d, %d)\n", e.first, e.second, p, r2[p].first, r2[p].second  );
    if(!(diff+r2[p].first)){
 
    }
    // printf("p = %d\n", p);
 
  }
  // for(auto e: r1){
  //   printf("(%d, %d)\n", e.first, e.second);
  // }
  // printf("-------------\n");
  // for(auto e: r2){
  //   printf("(%d, %d)\n", e.first, e.second);
  // }
}

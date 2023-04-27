#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main(){
  int N,M;cin >> N >> M;
  vector<vector<int>> G(N);     //隣接リスト
  for(int i = 0;i < M;i++){
    int A,B;cin >> A >> B;
    A--;B--;                    // 0Indentにする
    G[A].push_back(B);
    G[B].push_back(A);
  }

  //BFS
  vector<int> dist(N,-1);       //訪れていない頂点は-1で初期化
  queue<int> Q;
  dist[0] = 0;                  //始点の始点からの距離は0
  Q.push(0);

  int cnt = 0;

  while(!Q.empty()){
    int pos = Q.front();        //キューの先頭の要素を取得
    Q.pop();                    //キューの先頭の要素を削除
    for(int i = 0;i < (int)G[pos].size();i++){
      int next = G[pos][i];        
      if(dist[next] != -1)continue;//すでに発見されていた

      dist[next] = dist[pos]+1;  
      Q.push(next);             //キューの最後尾に要素を追加    
    }
  }
  cout << cnt<< endl;

  for(int i = 0;i < N;i++){
    if(dist[i] == -1){          //たどり着けなかったということ
      cout << -1 << endl;
    }else{
      cout << dist[i] << endl;
    }
  }
}
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
int main(){
    int dest_x, dest_y;
    cin >> dest_x >> dest_y;
    map<pair<int,int>, pair<int,int> >m;
    m[mp(0,0)] = mp(-1, -1);
    int x = 0, y = 0;
    queue< pair<pair<int,int>,int> >q;
    q.push(mp(mp(0,0),0));
    bool still = true;
    while(still){
        still = true;
        pair<int, int>curr = q.front().first;
        if(curr.first == dest_x && curr.second == dest_y){
            break;
        }
        int level = q.front().second;
        q.pop();
        pair<int, int>next = curr;
        next.first += 1 << level;
        if(m.find(next) == m.end()){
            q.push(mp(next, level + 1));
            m[next] =  curr;
            if(next.first <= dest_x || next.second<=dest_y){
            still = true;
        }
        }
        
        next.first -= 1 << level;
        next.first -= 1 << level;
        if(m.find(next) == m.end()){
            q.push(mp(next, level + 1));
            m[next] =  curr;

            if(next.first <= dest_x || next.second<=dest_y){
            still = true;
            }
        }
        next.first += 1 << level;

        next.second += 1 << level;
        if(m.find(next) == m.end()){
            q.push(mp(next, level + 1));
            m[next] =  curr;
            if(next.first <= dest_x || next.second<=dest_y){
                still = true;
            }
        }
       
        next.second-= 1 << level;
        next.second -= 1 << level;
        if(m.find(next) == m.end()){
            q.push(mp(next, level + 1));
            m[next] =  curr;
            if(next.first <= dest_x || next.second<=dest_y){
                still = true;
            }
        }
    }
    if(m.find(mp(dest_x, dest_y)) == m.end()){
        cout << "IMPOSSIBLE\n";
    }
    else{
        string ans;
        pair<int,int>p = mp(dest_x, dest_y);
        while(p.first != 0 || p.second != 0){
            pair<int,int>parent = m[p];
          //  cout << p.first << " "<< p.second << "\n";
            if(parent.first == p.first){
                ans.push_back((parent.second - p.second) < 0 ? 'N':'S');
            }
            if(parent.second == p.second){
                ans.push_back((parent.first - p.first) < 0 ? 'E':'W');
            }
            p = parent;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}
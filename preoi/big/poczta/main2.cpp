// by Marek

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
constexpr int MAXN = 100020;

struct block{
    long long min_happy;
    long long net_profit;

    void update_min(){
        min_happy = max(min_happy, -net_profit);
    }
};

long long n, h;

vector<int> vec[MAXN];

queue<block> q[MAXN];

priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long, int>>> prio;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    int k;
    int temp;
    for(int j=0; j<n; j++){
        cin >> k;
        vec[j].reserve(k);
        for(int i=0; i<k; i++){
            cin >> temp;
            vec[j].push_back(temp);
        }
    }
    for(int j=0; j<n; j++){
        int vecsize = vec[j].size();
        for(int i=0; i<vecsize;){
            block curr = {0,0};
            while(i<vecsize && curr.net_profit<= 0){
                curr.net_profit += vec[j][i];
                curr.update_min();
                //cout << "Q: " << j << " i: " << i << " -> " <<curr.min_happy << " " << curr.net_profit << '\n';
                i++;
            }
            if(curr.net_profit > 0){
                //cout << "q: " << j << " pushed block: {" << curr.min_happy << ", " << curr.net_profit << "}\n";
                q[j].push(curr);
            }
        }
        if(!q[j].empty()){
            prio.push({q[j].front().min_happy,j});
        }
    }
    int indx;
    long long max_h = h;
    while(!prio.empty()){
        if(prio.top().first <= h){
            indx = prio.top().second;
            h += q[indx].front().net_profit;
            max_h = max(max_h, h);
            q[indx].pop();
            prio.pop();
            if(!q[indx].empty())    
                prio.push({q[indx].front().min_happy, indx});
        }
        else{
            break;
        }
    }
    cout << max_h << "\n";
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;



// Kattis Bard
int main(){
    ios_base::sync_with_stdio(false);
    int n, e;
    cin >> n >> e;

    unordered_map<int, vector<int>> villager_songs; 
    int total_songs = 0;


    for(int i = 0; i < e; i++){
        int k;
        cin >> k;           
        set<int> villagers; // only the villagers present in that evening
        bool bard_here = false;
        for(int j = 0; j < k; j++){
            int person;
            cin >> person;
            villagers.insert(person);

            if(person == 1){
                bard_here = true;
            }
        }

        if(bard_here){
            total_songs++;
            for(int villager : villagers){
                villager_songs[villager].push_back(total_songs); // all vilagers present know the new song
            }
        }
        else {
            set<int> songs; // merge all the songs together
            for(int villager : villagers){
                songs.insert(villager_songs[villager].begin(), villager_songs[villager].end());
            }
            vector<int> merged_songs;
            for (auto song : songs){
                merged_songs.push_back(song);
            }
            for(int villager : villagers){
                villager_songs[villager] = merged_songs;
            }
        }
    }

    vector<int> ans;
    for(auto e : villager_songs){
        if(e.second.size() == total_songs){
            ans.push_back(e.first); 
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    
    return 0;
}
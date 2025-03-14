/*

*/

#include <bits/stdc++.h>
using namespace std;

struct card{
    int color, shape, filling, number;
    string out(){
        //todo
    }
};

int main(){
    // intro todo

    vector<card> deck(81);
    for(int i = 0; i<81; i++){
        deck[i] = card{i/27, (i%27)/9, (i%9)/3, i%3};
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(deck.begin(), deck.end(), rng);
    
    vector<card> table(12);

    auto set = [](card a, card b, card c) -> bool{
        if(((a.color == b.color && b.color == c.color) || (a.color != b.color && b.color != c.color && c.color != a.color)) &&
        ((a.filling == b.filling && b.filling == c.filling) || (a.filling != b.filling && b.filling != c.filling && c.filling != a.filling)) &&
        ((a.shape == b.shape && b.shape == c.shape) || (a.shape != b.shape && b.shape != c.shape && c.shape != a.shape))&&
        ((a.number == b.number && b.number == c.number) || (a.number != b.number && b.number != c.number && c.number != a.number))){
            return true;
        }
        return false;
    };

    auto output = [&](){
        //todo
    };

    copy(deck.begin(), deck.begin()+12, table.begin());
    output();
    int idx = 12;
    while(idx < 81){
        vector<array<int, 2>> cor(3);
        for(int i = 0; i<3; i++){
            cin >> cor[i][0] >> cor[i][1];
        }
        if(set(table[cor[0][0]*4+cor[0][1]], table[cor[1][0]*4+cor[1][1]], table[cor[2][0]*4+cor[2][1]])){
            table[cor[0][0]*4+cor[0][1]] = deck[idx++];
            table[cor[1][0]*4+cor[1][1]] = deck[idx++];
            table[cor[2][0]*4+cor[2][1]] = deck[idx++];
        }
        else{
            cout << "non è un set\n";
        }
    }
}
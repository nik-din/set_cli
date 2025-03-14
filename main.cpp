/*

*/

#include <bits/stdc++.h>
using namespace std;

struct card{
    int color, shape, filling, number;
    /* string out(){
        //todo
    } */
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

    string none = "\033[0m";
    vector<string> color = {"\033[0;31m", "\033[0;32m", "\033[0;34m"};

    vector<vector<string>> figure= {{
        "       |",
        "   *   |",
        "  ***  |",
        " ***** |",
        "  ***  |",
        "   *   |",
        "_______|",},
        {
       "       |",
       "  ***  |",
       " ***** |",
       " ***** |",
       " ***** |",
       "  ***  |",
       "_______|",
        },
        {
       "       |",
       "  ***  |",
       " ***   |",
       "  ***  |",
       "   *** |",
       "  ***  |",
       "_______|",
    },
    };
    vector<char> fill = {'*', '|', '-'};
    vector<char> nm = {'1', '2', '3'};

    auto output = [&](){
        //todo
        
        vector<string> mat(7*3+1, string(8*4+1, ' '));
        for(int i = 0; i<33; i++){
            mat[0][i] = '_';
        }
        for(int i = 1; i<22; i++){
            mat[i][0] = '|';
        }
        for(int i = 0; i<3; i++){
            for(int j = 0; j<4; j++){
                char fl = fill[table[i*4+j].filling];
                for(int k = 0; k<7; k++){
                    for(int l = 0; l<8; l++){
                        mat[i*7+k+1][j*8+l+1] = figure[table[i*4+j].shape][k][l];
                        if(mat[i*7+k+1][j*8+l+1] == '*') mat[i*7+k+1][j*8+l+1] = fl;
                    }
                }
                mat[i*7+3+1][j*8+3+1] = nm[table[i*4+j].number];
                //for(int i = 1; i<6; i++) 
            }
        }
        for(int i = 0; i<22; i++){
            cout << mat[i] << '\n';
        }
    };

    copy(deck.begin(), deck.begin()+12, table.begin());
    
    int idx = 12;
    while(idx < 81){
        cout.clear();
        output();
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
    cout.clear();
    output();
    cout << "la partita è (circa) finita\n";
}
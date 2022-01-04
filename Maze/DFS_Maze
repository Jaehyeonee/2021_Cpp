#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

//s -> x
//지나간 점은 . -> *

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

class Maze {
    char board[5][5];
    void dfs(int x, int y);
public:
    void play(string name);
    friend ostream& operator <<(ostream& out, const Maze& d);

};

ostream& operator<<(ostream& out, const Maze& d) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << d.board[i][j] << " ";
        }
        cout << endl;
    }
    return out;
}


void Maze::play(string name) {

    int sx, sy;
    cout << "Please enter input file name: " << endl;
    cin >> name;
    ifstream ist{ name };
    if (!ist) cout << "can't open" << endl;
    else {
        string temp;
        getline(ist, temp);
        int n, m;
        ist >> n >> m;
        //int c = atoi(temp.c_str());
        string line[5];
        for (int i = 0; i < 5; i++)
        {
            getline(ist, line[i]);
            cout << line[i] << endl;
            for (int j = 0; j < 5; j++)
            {
                board[i][j] = line[i][j];

                if (line[i][j] == 's') {
                    sx = i;
                    sy = j;
                }
            }
        }
    }

    dfs(sx, sy);

};



void Maze::dfs(int x, int y) {
    board[x][y] = '*';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
            if (board[nx][ny] == '.') {
                dfs(nx, ny);
            }
        }
    }

}




int main() {

    Maze mymaze;
    mymaze.play("map.txt");
    cout << mymaze << endl;

}

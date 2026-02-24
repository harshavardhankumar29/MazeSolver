#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
using namespace std;

const int n = 10, m = 10;
const int cellSize = 50;

int maze[n][m] = {0};

// 0 = empty, 1 = wall
vector<pair<int,int>> walls = {
{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},
{1,8},{2,8},{3,8},{4,8},{5,8},{6,8},{7,8},{8,8},
{8,1},{8,2},{8,3},{8,4},{8,5},{8,6},{8,7},
{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},
{2,2},{2,3},{2,4},{2,5},{2,6},
{3,6},{4,6},{5,6},
{6,2},{6,3},{6,4},{6,5}
};

int main() {
    for(auto w : walls)
        maze[w.first][w.second] = 1;

    pair<int,int> start = {0,0};
    pair<int,int> end = {9,9};

    sf::RenderWindow window(sf::VideoMode(m*cellSize, n*cellSize), "Maze Solver");

    vector<vector<bool>> visited(n, vector<bool>(m,false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m,{-1,-1}));

    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    bool solved = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // BFS step-by-step
        if(!q.empty() && !solved) {
            auto [x,y] = q.front();
            q.pop();

            if(make_pair(x,y) == end) {
                solved = true;
            }

            for(int i=0;i<4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m &&
                   !visited[nx][ny] && maze[nx][ny]==0) {
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x,y};
                    q.push({nx,ny});
                }
            }
        }

        window.clear();

        // Draw grid
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sf::RectangleShape cell(sf::Vector2f(cellSize-2, cellSize-2));
                cell.setPosition(j*cellSize, i*cellSize);

                if(maze[i][j] == 1)
                    cell.setFillColor(sf::Color::Black);
                else if(make_pair(i,j) == start)
                    cell.setFillColor(sf::Color::Green);
                else if(make_pair(i,j) == end)
                    cell.setFillColor(sf::Color::Red);
                else if(visited[i][j])
                    cell.setFillColor(sf::Color::Blue);
                else
                    cell.setFillColor(sf::Color::White);

                window.draw(cell);
            }
        }

        // Draw final path
        if(solved) {
            auto cur = end;
            while(cur != start) {
                auto [x,y] = cur;

                sf::RectangleShape cell(sf::Vector2f(cellSize-2, cellSize-2));
                cell.setPosition(y*cellSize, x*cellSize);
                cell.setFillColor(sf::Color::Yellow);

                window.draw(cell);

                cur = parent[x][y];
            }
        }

        window.display();
        sf::sleep(sf::milliseconds(50)); // animation speed
    }

    return 0;
}
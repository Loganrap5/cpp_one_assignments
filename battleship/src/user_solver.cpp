#include <iostream>
#include <set>
#include <queue>
#include "../include/user_solver.h"

//void UserSolver::solve(Board &board) {
//    // Your Implementation goes here
//    ReturnType t = guess(1, 1, board);
//    std::cout << t << std::endl;
//}

void UserSolver::solve(Board& board) {
    size_t width = board.getX();
    size_t height = board.getY();
    size_t shipCount = board.getShipCount();

    size_t found = 0;
    std::vector<std::vector<bool>> visited(width, std::vector<bool>(height, false));

    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (size_t x = 0; x < width && found < shipCount; ++x) {
        for (size_t y = 0; y < height && found < shipCount; ++y) {
            if (visited[x][y]) continue;

            ReturnType res = guess(x, y, board);
            visited[x][y] = true;

            if (res == ReturnType::hit) {
                ++found;
            } else if (res == ReturnType::near_miss) {
                for (const auto& d : dirs) {
                    int nx = static_cast<int>(x) + d[0];
                    int ny = static_cast<int>(y) + d[1];

                    if (nx >= 0 && ny >= 0 && static_cast<size_t>(nx) < width &&
                        static_cast<size_t>(ny) < height && !visited[nx][ny]) {
                        ReturnType neighborRes = guess(nx, ny, board);
                        visited[nx][ny] = true;

                        if (neighborRes == ReturnType::hit) {
                            ++found;
                        }
                    }
                }
            }
        }
    }
}

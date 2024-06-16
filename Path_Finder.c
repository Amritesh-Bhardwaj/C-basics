#include <stdio.h>

void findShortestPath(int cr, int cc, int er, int ec, char path[], int pathLen, char shortestPath[], int *shortestPathLen) {
    if (cr == er && cc == ec) { // base case: reached the end point
        path[pathLen] = '\0'; // Null-terminate the path string
        if (pathLen < *shortestPathLen) {
            *shortestPathLen = pathLen;
            for (int i = 0; i <= pathLen; i++) {
                shortestPath[i] = path[i];
            }
        }
        return;
    }
    
    if (cr < er) { // move down if not at the last row
        path[pathLen] = 'D';
        findShortestPath(cr + 1, cc, er, ec, path, pathLen + 1, shortestPath, shortestPathLen);
    }
    
    if (cc < ec) { // move right if not at the last column
        path[pathLen] = 'R';
        findShortestPath(cr, cc + 1, er, ec, path, pathLen + 1, shortestPath, shortestPathLen);
    }
}

int main() {
    int n; // number of rows
    printf("Enter number of rows of the maze: ");
    scanf("%d", &n);
    
    int m; // number of columns
    printf("Enter number of columns of the maze: ");
    scanf("%d", &m);

    int startX, startY, endX, endY;

    // Input starting coordinates
    printf("Enter the starting row: ");
    scanf("%d", &startX);
    printf("Enter the starting column: ");
    scanf("%d", &startY);

    // Input ending coordinates
    printf("Enter the ending row: ");
    scanf("%d", &endX);
    printf("Enter the ending column: ");
    scanf("%d", &endY);

    char path[n + m]; // buffer to store the current path
    char shortestPath[n + m]; // buffer to store the shortest path
    int shortestPathLen = 1000; // initialize the shortest path length to a large value

    findShortestPath(startX, startY, endX, endY, path, 0, shortestPath, &shortestPathLen);

    if (shortestPathLen == 1000) {
        printf("No path found!\n");
    } else {
        printf("Shortest path: %s\n", shortestPath);
    }
    
    return 0;
}

#include <stdio.h>
#include <string.h>
// cc=current column | cr=current row | rr = required row | rc = required column
void findShortestPath(int cr, int cc, int rr, int rc, char path[], int pathLen, char shortestPath[], int *shortestPathLen)
{
    if (cr == rr && cc == rc)
    { // base case: reached the end point
        path[pathLen] = '\0';
        // if the latest path found is shorter than the current stored one
        if (pathLen < *shortestPathLen)
        {
            *shortestPathLen = pathLen;
            strcpy(shortestPath, path);
        }
        return;
    }

    if (cr < rr)
    { // move down if not at the last row
        path[pathLen] = 'D';
        findShortestPath(cr + 1, cc, rr, rc, path, pathLen + 1, shortestPath, shortestPathLen);
    }

    if (cc < rc)
    { // move right if not at the last column
        path[pathLen] = 'R';
        findShortestPath(cr, cc + 1, rr, rc, path, pathLen + 1, shortestPath, shortestPathLen);
    }
}

int main()
{
    int n; // number of rows
    printf("Enter number of rows of the maze: ");
    scanf("%d", &n);

    int m; // number of columns
    printf("Enter number of columns of the maze: ");
    scanf("%d", &m);

    int startX, startY, desX, desY;
    printf("Enter the starting coordinates (x, y): ");
    scanf("(%d, %d)", &startX, &startY);
    printf("Enter the ending coordinates (x, y): ");
    scanf("(%d, %d)", &desX, &desY);

    char path[n + m];           // stores the current path
    char shortestPath[n + m];   // stores the shortest path
    int shortestPathLen = 1000; // initialize the shortest path length to a large value

    findShortestPath(startX, startY, desX, desY, path, 0, shortestPath, &shortestPathLen);

    if (shortestPathLen == 1000)
    {
        printf("No path could be found :[ !\n");
    }
    else
    {
        printf("Shortest path: %s\n", shortestPath);
    }

    return 0;
}

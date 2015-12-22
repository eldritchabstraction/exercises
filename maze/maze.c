#include <stdio.h>

// 2D arrays are read as [down][right]

int simple_maze[9][9] = {
 0, 1, 1, 1, 0, 0, 0, 0, 0,
 0, 1, 1, 1, 0, 1, 1, 1, 0,
 0, 1, 1, 1, 0, 1, 1, 1, 0,
 0, 1, 1, 1, 0, 1, 1, 1, 0,
 0, 1, 1, 1, 0, 1, 1, 1, 0,
 0, 1, 0, 0, 0, 1, 1, 1, 0,
 0, 1, 0, 1, 1, 1, 1, 1, 0,
 0, 1, 0, 1, 1, 1, 1, 1, 0,
 0, 0, 0, 1, 1, 1, 1, 1, 0
};

int complex_maze[9][9] = {
 0, 1, 1, 1, 0, 0, 0, 0, 0,
 0, 0, 0, 1, 0, 1, 1, 1, 0,
 0, 1, 1, 1, 0, 1, 1, 1, 0,
 0, 1, 0, 1, 0, 1, 1, 1, 0,
 0, 1, 0, 1, 0, 1, 1, 1, 0,
 0, 1, 0, 0, 0, 1, 1, 1, 0,
 0, 1, 0, 1, 1, 1, 1, 1, 0,
 0, 1, 0, 1, 1, 0, 1, 1, 0,
 0, 0, 0, 0, 0, 0, 0, 1, 0
};

// We don't allow for backtracking
int u = 0x1;
int r = 0x2;
int d = 0x4;
int l = 0x8;

int traverse (int x, int y, int tried) {
    int rc = 0;
    if (x == 8 && y == 8) {
        return 1;
    }

    if (complex_maze[y][x]) {
        return 0;
    }

    // Go up
    if (!rc && y > 0 && !(tried & d)) {
        rc = traverse(x, y - 1, tried = u);
    }

    // Go right
    if (!rc && x < 8 && !(tried & l)) {
        rc = traverse(x + 1, y, tried = r);
    }

    // Go down
    if (!rc && y < 8 && !(tried & u)){
        rc = traverse(x, y + 1, tried = d);
    }

    // Go left
    if (!rc && x > 0 && !(tried & r)){
        rc = traverse(x - 1, y, tried = l);
    }

    return rc;
}

int main(void) {
    if (traverse(0,0,0)) {
        printf("We were able to traverse the maze\n");
    } else {
        printf("We were unable to traverse the maze\n");
    }
}

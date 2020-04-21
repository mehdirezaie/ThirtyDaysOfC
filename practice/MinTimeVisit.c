/*
On a plane there are n points with integer 
coordinates points[i] = [xi, yi]. 
Your task is to find the minimum time in seconds to visit all points.

You can move according to the next rules:

In one second always you can either move vertically, 
horizontally by one unit or diagonally 
(it means to move one unit vertically and one unit horizontally in one second).
You have to visit the points in the same order as they appear in the array.
*/

int max(int x, int y){
    if (x > y){
        return x;
    } else{
        return y;
    }
}

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    
    int count = 0;
    for (int i; i<pointsSize-1; i++){
        int xi = points[i][0];
        int yi = points[i][1];
        
        int xj = points[i+1][0];
        int yj = points[i+1][1];
        
        int dx = xj - xi;
        int dy = yj - yi;
        
        if (dx < 0) dx *= -1;
        if (dy < 0) dy *= -1;
                
        count += max(dx, dy);    
    }
    return count;
}




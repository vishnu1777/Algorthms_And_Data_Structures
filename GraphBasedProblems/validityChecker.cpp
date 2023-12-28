bool isValid(int r,int c,int n,int m){
    return r>=0 and r<n and c>=0 and c<m;
}

    // Direction vectors
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};

// 8 directions;
int dr[8] = {0,0,1,-1,1,-1,1,-1};
int dc[8] = {1,-1,0,0,1,-1,-1,1};
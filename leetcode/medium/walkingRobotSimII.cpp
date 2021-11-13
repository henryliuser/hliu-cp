class Robot {
public:
    int N, M;
    int perim;
    int p = 0;
    bool moved = false;
    int corners[4] = {0,0,0,0};
    Robot(int width, int height) {
        M = height;
        N = width;
        perim = 2 * N + 2 * (M-2);
        corners[1] = N-1;
        corners[2] = N+M-2;
        corners[3] = N+M+N-3;
    }

    void move(int num) {
        p = (p + num) % perim;
        moved = true;  // not sure if this matters
    }

    vector<int> getPos() {
        if (p <= corners[1]) return {p, 0};
        if (p > corners[1] && p <= corners[2]) return {N-1, p-corners[1]};
        if (p > corners[2] && p <= corners[3]) return {N-p+corners[2]-1, M-1};
        else return {0, M-p+corners[3]-1};
    }

    string getDir() {
        if (!moved) return "East";  // maybe not useful
        if (p == 0) return "South";
        if (p > 0 && p <= corners[1]) return "East";
        else if (p > corners[1] && p <= corners[2]) return "North";
        else if (p > corners[2] && p <= corners[3]) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

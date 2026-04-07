class Robot {
public:
    vector<pair<pair<int,int>, string>> path;
    int idx = 0;
    bool isOrigin = true;

    Robot(int width, int height) {
        // bottom row (left → right)
        path.push_back({{0,0}, "South"});
        for(int i = 1; i < width; i++) {
            path.push_back({{i,0}, "East"});
        }

        // right column (bottom → top)
        for(int j = 1; j < height; j++) {
            path.push_back({{width-1,j}, "North"});
        }

        // top row (right → left)
        for(int i = width-2; i >= 0; i--) {
            path.push_back({{i,height-1}, "West"});
        }

        // left column (top → bottom)
        for(int j = height-2; j > 0; j--) {
            path.push_back({{0,j}, "South"});
        }
    }

    void step(int num) {
        isOrigin = false;
        idx = (idx + num) % path.size();
    }

    vector<int> getPos() {
        return {path[idx].first.first, path[idx].first.second};
    }

    string getDir() {
        if(isOrigin) return "East";
        return path[idx].second;
    }
};
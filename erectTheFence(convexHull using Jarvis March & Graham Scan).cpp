class Solution {
public:
    //Graham Scan Algorithm: 
    int orientation(vector<int> p, vector<int> q, vector<int> r) {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }
    int distance(vector<int> p, vector<int> q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }

    vector<int> bottomLeft(vector<vector<int>> points) {
        vector<int> bottomLeft = points[0];
        for (auto p: points)
            if (p[1] < bottomLeft[1])
                bottomLeft = p;
        return bottomLeft;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if(points.size() <= 1)
            return points;
        vector<int> bm = bottomLeft(points);
        sort(points.begin(), points.end(), [&](const vector<int>& p,const vector<int>& q) {
                double diff = orientation(bm, p, q) - orientation(bm, q, p);
                if (diff == 0)
                    return distance(bm, p) < distance(bm, q);
                else
                    return diff < 0;
            });
        int i = points.size() - 1;
        while (i >= 0 && orientation(bm, points[points.size() - 1], points[i]) == 0)
            i--;
        for (int l = i + 1, h = points.size() - 1; l < h; l++, h--) {
            vector<int> temp = points[l];
            points[l] = points[h];
            points[h] = temp;
        }
        stack<vector<int>> st;
        st.push(points[0]);
        st.push(points[1]);
        for (int j = 2; j < points.size(); j++) {
            vector<int> top = st.top();
            st.pop();
            while (orientation(st.top(), top, points[j]) > 0){
                top = st.top();
                st.pop();
            }
            st.push(top);
            st.push(points[j]);
        }
        vector<vector<int>> ans;
        while(!st.empty()){
            auto p = st.top();
            ans.push_back({p[0], p[1]});
            st.pop();
        }
        return ans;
    }
};
/* Jarvis March Algorithm is giving TLE, thus using Graham Scan algorithm
class Solution {
public:
    struct Point{
        int x;
        int y;
    };
    vector<vector<int>> findConvexHull(vector<Point> points){
        Point start = points[0];
        for(int i = 1; i < points.size(); i++){
            if(points[i].x < start.x)
                start = points[i];
        }
        Point current = start;
        set<vector<int>> res;
        res.insert({start.x, start.y});
        vector<Point> collinearPoints;
        while(true){
            Point nextTarget = points[0];
            for(int i = 1;  i < points.size(); i++){
                if(points[i].x == current.x && points[i].y == current.y){
                    continue;
                }
                int val = crossProduct(current, nextTarget, points[i]);
                if(val > 0){
                    nextTarget = points[i];
                    collinearPoints.clear();
                }
                else if(val == 0){
                    if(distance(current, nextTarget, points[i]) < 0){
                        collinearPoints.push_back(nextTarget);
                        nextTarget = points[i];
                    }
                    else
                        collinearPoints.push_back(points[i]);
                }
            }
            for(auto p : collinearPoints)
                res.insert({p.x, p.y});
            if(nextTarget.x == start.x && nextTarget.y == start.y)
                break;
            res.insert({nextTarget.x, nextTarget.y});
            current = nextTarget;
        }
        vector<vector<int>> R(res.begin(), res.end());
        return R;
    }
    int distance(Point a, Point b, Point c){
        int y1 = a.y - b.y;
        int y2 = a.y - c.y;
        int x1 = a.x - b.x;
        int x2 = a.x - c.x;
        return (y1*y1 + x1 * x1) - (y2*y2 + x2*x2);
    }
    int crossProduct(Point a, Point b, Point c){
        int y1 = a.y - b.y;
        int y2 = a.y - c.y;
        int x1 = a.x - b.x;
        int x2 = a.x - c.x;
        return y2*x1 - y1*x2;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<Point> points(trees.size());
        for(int i = 0; i < trees.size(); i++){
            points[i].x = trees[i][0];
            points[i].y = trees[i][1];
        }
        vector<vector<int>> ans = findConvexHull(points);
        // vector<vector<int>> a;
        // for(auto p : ans){
        //     a.push_back({p.x, p.y});
        // }
        return ans; 
    }
}; */

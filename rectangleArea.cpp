class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int arA = (ay2-ay1)*(ax2-ax1);
        int arB = (by2-by1)*(bx2-bx1);
        int x = min(ax2, bx2) - max(ax1, bx1);
        int y = min(ay2, by2) - max(ay1, by1);
        int arOverlap = 0;
        if(x > 0 && y > 0)
            arOverlap = x*y;
        return arA + arB - arOverlap;
    }
};

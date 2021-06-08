class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        /*
        Before we do it in 2D plane, let's try it in 1D.
        Given 2 segment (left1, right1), (left2, right2), how can we check whether they overlap?
        If these two intervals overlap, it should exist an number x,

        left1 < x < right1 && left2 < x < right2

        left1 < x < right2 && left2 < x < right1

        left1 < right2 && left2 < right1

        This is the sufficient and necessary condition for two segments overlap.


        Explanation:
        For 2D, if two rectancle overlap both on x and y, they overlap in the plane.
        */
        int x1 = max(rect1[0], rect2[0]);
        int x2 = min(rect1[2], rect2[2]);
        int y1 = max(rect1[1], rect2[1]);
        int y2 = min(rect1[3], rect2[3]);
        return x1 < x2 && y1 < y2;
    }
};

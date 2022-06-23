class Solution {
public:
    bool static cmp(vector<int>&a, vector<int>& b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        /* 
        Main approach is to do the courses whose deadline is shorter and if we cant complete it before the deadline then see if the time taken can be minimised by previous longest course. 
        */
        sort(courses.begin(), courses.end(), cmp); // sorting based on deadline
        priority_queue<int> pq;
        int ans = 0, score = 0;
        for(auto course : courses){
            if(score + course[0] <= course[1]){ // this course can be done
                pq.push(course[0]);
                score += course[0];
            }
            else if(!pq.empty() && pq.top() > course[0]){ // checking if any course can be replaced by this course to minimise time. If yes, then replace
                score += course[0] - pq.top();
                pq.pop();
                pq.push(course[0]);
            }
        }
        return pq.size(); // returning the no. of courses which can be done
    }
};

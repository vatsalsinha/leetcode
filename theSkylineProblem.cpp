class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // create event points
        // each event point has an coordinate and height associated with it
        vector<pair<int, int> > events;
        vector<vector<int>> contour;
        // tracks the max height 
        multiset<int> heights;
        // to track the height of each building, we create
        // two kinds of events for each building
        // left pt: We make the height -ve(so that sorting puts it in front)
        // right pt: We make the height +ve, this is just to help us know 
        // we have reached the end of building
        for(const vector<int>& building: buildings) {
            // left point
            events.emplace_back(make_pair(building[0], -1 * building[2]));
            // right point
            events.emplace_back(make_pair(building[1], building[2]));
        }
        
        // sort the event points by coordinate
        sort(events.begin(), events.end());
        int max_height_so_far = 0, curr_height = 0;
        
        // height of lst contour point
        heights.emplace(0);
        for(const pair<int, int>& event: events) {
            // add the event point if it is left, remove the event point if right
            if(event.second < 0)
                heights.emplace(-1 * event.second);
            else
                heights.erase(heights.find(event.second));
            
            // get the max height of the building seen so far
            // that still hasn't reached its end
            curr_height = *heights.rbegin();
            // if we get a height greater than the height seen so far,
            // that means that building will create a contour point
            if(curr_height != max_height_so_far) {
                contour.emplace_back(vector<int>{event.first, curr_height});
                max_height_so_far = curr_height;
            }
        }
        
        return contour;
	/*
	vector<pair<int, int>> edges;
        int left, right, height;
        for(int i = 0; i < buildings.size(); i++){
            left = buildings[i][0];
            right = buildings[i][1];
            height = buildings[i][2];
            edges.push_back(make_pair(left, -height));
            edges.push_back(make_pair(right, height));
        }
        sort(edges.begin(), edges.end());
        vector<vector<int>> result;
        multiset<int> m;
        m.insert(0);
        int pre = 0, cur = 0;
        for(int i = 0; i < edges.size(); i++){
            pair<int, int> e = edges[i];
            if(e.second < 0)
                m.insert(-e.second);
            else
                m.erase(m.find(e.second));
            cur = *m.rbegin();
            if(cur != pre){
                result.push_back({e.first, cur});
                pre = cur;
            }
        }
        return result;
	*/
    }
};

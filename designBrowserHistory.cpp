class BrowserHistory {
public:
    vector<string> h;
    int pos = 0;
    BrowserHistory(string homepage) {
        h.push_back(homepage);
    }
    
    void visit(string url) {
        ++pos;
        h.resize(pos);
        h.push_back(url);
    }
    
    string back(int steps) {
        pos = max(pos-steps, 0);
        return h[pos];
    }
    
    string forward(int steps) {
        pos = min((int)h.size()-1, pos+steps);
        return h[pos];
    }
};
/*  //approach 2
class BrowserHistory {
public:
    stack<string> f, b;
    //string u;
    BrowserHistory(string homepage) {
        //u = homepage;
        b.push(homepage);
        f = stack<string>();
    }
    
    void visit(string url) {
        b.push(url);
        f = stack<string>();
    }
    
    string back(int steps) {
        while(steps && b.size() > 1){
            string g = b.top();
            f.push(g);
            b.pop();
            steps--;
        }
        return b.top();
    }
    
    string forward(int steps) {
        while(steps && f.size() > 0){
            string g = f.top();
            b.push(g);
            f.pop();
            steps--;
        }
        return b.top();
    }
};
*/

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

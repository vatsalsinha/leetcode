class Solution {
public:
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Simple hash combining technique
        return h1 ^ h2;
    }
};
    bool isPathCrossing(string path) {
        unordered_map<char, int> mp;
        mp['N'] = 1;
        mp['S'] = -1;
        mp['W'] = -1;
        mp['E'] = 1;
        unordered_set<pair<int, int>, pair_hash> vis;
        vis.insert({0,0});
        pair<int, int> curr = {0,0};
        for(char c : path){
            if(c == 'N' || c == 'S')
                curr.second += mp[c];
            else
                curr.first += mp[c];
            if(vis.find(curr) != vis.end())
                return 1;
            vis.insert({curr});
        }
        return 0;
    }
};
/*
struct pair_hash: This declares a structure named pair_hash.

template <class T1, class T2>: This begins a template declaration for a hash function that can hash pairs of arbitrary types T1 and T2.

std::size_t operator () (const std::pair<T1, T2>& p) const {: This declares the operator() function, which is the function call operator. It takes a std::pair<T1, T2> as a parameter and returns a std::size_t, which is the type expected for a hash value.

auto h1 = std::hash<T1>{}(p.first);: This creates a hash value h1 for the first element of the pair (p.first). It uses std::hash<T1>{} to obtain a hash function for type T1.

auto h2 = std::hash<T2>{}(p.second);: Similarly, this creates a hash value h2 for the second element of the pair (p.second). It uses std::hash<T2>{} to obtain a hash function for type T2.

return h1 ^ h2;: This combines the two hash values (h1 and h2) using the XOR (^) operator. This is a simple technique to mix the hash values, reducing the chance of collisions.

}: This concludes the definition of the operator() function.

This pair_hash struct can be used as the second template parameter for std::unordered_set<std::pair<T1, T2>, pair_hash> to create an unordered set of pairs with a custom hash function. It ensures that pairs with the same elements will have the same hash value, allowing them to be stored and retrieved correctly in the unordered set.
*/

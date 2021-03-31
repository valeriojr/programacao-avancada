//
// Created by Valerio Nogueira on 10/03/2021.
//

#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by Valerio Nogueira on 10/03/2021.
//

#ifndef CONTEST_ABC193_UNION_FIND_H
#define CONTEST_ABC193_UNION_FIND_H

#include <vector>
#include <unordered_map>

template<typename T = int>
class UnionFind {
private:
    std::vector<T> parent;
    std::vector<T> rank;
public:
    UnionFind(T n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0;i < n;i++) {
            parent[i] = i;
        }
    }

    T find(const T& v) {
        if (v != parent[v]) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    void make_union(const T& r, const T& s) {
        auto rParent = parent[r];
        auto sParent = parent[s];

        if (rank[rParent] > rank[sParent]) {
            parent[sParent] = rParent;
        }
        else if (rank[rParent] < rank[sParent]) {
            parent[rParent] = sParent;
        }
        else{
            parent[rParent] = sParent;
            rank[sParent]++;
        }
    }

    std::ostream& debug(std::ostream& s) const {
        s << "Parent: ";
        for(auto& p : parent){
            s << p << " ";
        }
        s << std::endl;
        s << "Rank: ";
        for(auto& r : rank){
            s << r << " ";
        }
        s << std::endl;
        return s;
    }
};

#endif //CONTEST_ABC193_UNION_FIND_H


using namespace std;

struct Edge {
    int cost;
    int src;
    int dst;

    Edge(int src, int dst, int cost) : src(src), dst(dst), cost(cost) {}
};

vector<pair<int, int>> dir = {
        {1,  0},
        {1,  0},
        {-1, 0},
        {0,  -1}
};


ostream& operator<<(ostream& s, const pair<int, int>& p) {
    s << "(" << p.first << ", " << p.second << ")";
    return s;
}

template <typename T>
std::ostream& operator<<(std::ostream& s, const UnionFind<T>& unionFind){
    return unionFind.debug(s);
}

template <typename T> int sign(T val) {
    return (T(0) < val) - (val < T(0));
}

void garden_of_the_sun() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> garden(n, vector<char>(m));

    int emptyCount = 0;
    vector<pair<int, int>> emptyCells;

    // cout << "Reading garden" << endl;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            // cout << i << " " << j << endl;
            cin >> garden[i][j];
            if (garden[i][j] == 'X') {
                emptyCount++;
                emptyCells.push_back({i, j});
            }
        }
    }

    // cout << "Creating union find" << endl;
    UnionFind unionFind(emptyCount);
    vector<Edge> edges;

    for (int i = 0;i < emptyCount;++i) {
        for (int j = i + 1;j < emptyCount;++j) {
            int dx = abs(emptyCells[i].first - emptyCells[j].first);
            int dy = abs(emptyCells[i].second - emptyCells[j].second);
            edges.push_back(Edge(i, j, dx + dy));
        }
    }

    sort(edges.begin(), edges.end(), [](auto& x, auto& y) { return x.cost < y.cost; });
    /*
    for (auto& e : emptyCells) {
        cout << e << " ";
    }
    cout << endl;

    for (auto& e : edges) {
        auto src = emptyCells[e.src];
        auto dst = emptyCells[e.dst];

        cout << "cost: " << e.cost << " " << src << " <-> " << dst << endl;
    }
    */
    // Kruskal algorithm
    // cout << "Kruskal algorithm" << endl;
    for(auto& e : edges){
        auto srcParent = unionFind.find(e.src);
        auto dstParent = unionFind.find(e.dst);
        auto isConnected = srcParent == dstParent;
        // printf("%d and %d are connected?\n", e.src, e.dst);
        // cout << unionFind;

        if(!isConnected){
            // printf("Connecting %d and %d\n", e.src, e.dst);
            unionFind.make_union(e.src, e.dst);

            auto srcCell = emptyCells[e.src];
            auto dstCell = emptyCells[e.dst];

            if(srcCell.first == dstCell.first){
                auto delta = sign(dstCell.second - srcCell.second);
                for (int j = srcCell.second;j <= dstCell.second;j += delta){
                    garden[srcCell.first][j] = 'X';
                }
            }
            else if(srcCell.second == dstCell.second){
                auto delta = sign(dstCell.first - srcCell.first);
                for(int j = srcCell.first;j <= dstCell.first;j += delta){
                    garden[j][srcCell.second] = 'X';
                }
            }
            else{
                auto deltaFirst = sign(dstCell.first - srcCell.first);
                auto deltaSecond = sign(dstCell.second- srcCell.second);
                for (int j = srcCell.second;j <= dstCell.second;j += deltaSecond){
                    garden[srcCell.first][j] = 'X';
                }
                for(int j = srcCell.first;j <= dstCell.first;j += deltaFirst){
                    garden[j][srcCell.second] = 'X';
                }
            }
        }
    }


    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            cout << garden[i][j];
        }
        cout << endl;
    }

    // cout << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0;i < t;++i) {
        garden_of_the_sun();
    }

    return 0;
}
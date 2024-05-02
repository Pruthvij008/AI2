#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

// Define a structure to represent each city in the map
struct City {
    string name;
    unordered_map<string, int> neighbors;
};

// Define the map of Romania as a graph with a subset of cities
unordered_map<string, City> romania_map = {
    {"Arad", {"Arad", {{"Sibiu", 140}, {"Timisoara", 118}}}},
    {"Sibiu", {"Sibiu", {{"Arad", 140}, {"Fagaras", 99}}}},
    {"Timisoara", {"Timisoara", {{"Arad", 118}, {"Lugoj", 111}}}},
    {"Fagaras", {"Fagaras", {{"Sibiu", 99}, {"Bucharest", 211}}}},
    {"Bucharest", {"Bucharest", {{"Fagaras", 211}}}}
};

// Heuristic function (Euclidean distance) for A* algorithm
int heuristic(const string& city, const string& goal) {
    unordered_map<string, pair<int, int>> coordinates = {
        {"Arad", {91, 492}},
        {"Sibiu", {207, 457}},
        {"Timisoara", {94, 410}},
        {"Fagaras", {305, 449}},
        {"Bucharest", {400, 327}}
    };

    int dx = coordinates[city].first - coordinates[goal].first;
    int dy = coordinates[city].second - coordinates[goal].second;
    return sqrt(dx * dx + dy * dy);
}

// A* algorithm function
vector<string> astar_search(const string& start, const string& goal) {
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> frontier;
    unordered_map<string, int> cost_so_far;
    unordered_map<string, string> came_from;

    frontier.push({0, start});
    cost_so_far[start] = 0;

    while (!frontier.empty()) {
        string current = frontier.top().second;
        frontier.pop();

        if (current == goal) {
            break;  // Reached the goal
        }

        for (const auto& neighbor : romania_map[current].neighbors) {
            string next_city = neighbor.first;
            int new_cost = cost_so_far[current] + neighbor.second + heuristic(next_city, goal);

            if (!cost_so_far.count(next_city) || new_cost < cost_so_far[next_city]) {
                cost_so_far[next_city] = new_cost;
                int priority = new_cost + heuristic(next_city, goal);
                frontier.push({priority, next_city});
                came_from[next_city] = current;
            }
        }
    }

    // Reconstruct path from start to goal
    vector<string> path;
    string current = goal;
    while (current != start) {
        path.push_back(current);
        current = came_from[current];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    string start = "Arad";
    string goal = "Fagaras";

    vector<string> path = astar_search(start, goal);

    if (!path.empty()) {
        cout << "Path from " << start << " to " << goal << ":" << endl;
        for (const auto& city : path) {
            cout << city << " ";
        }
        cout << endl;
    } else {
        cout << "No path found!" << endl;
    }
    return 0;
}
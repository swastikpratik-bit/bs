#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_NODES = 500005;

vector<int> adjacency_array(MAX_NODES);
vector<int> distances(MAX_NODES);
queue<int> bfs_queue;

void bfs(int start_node) {
    fill(distances.begin(), distances.end(), -1);
    bfs_queue.push(start_node);
    distances[start_node] = 0;

    while (!bfs_queue.empty()) {
        int current_node = bfs_queue.front();
        bfs_queue.pop();
        for (int j = 1; j <= adjacency_array[current_node]; j++) {
            int next_node = current_node + j;
            if (next_node <= distances.size() && distances[next_node] == -1) {
                distances[next_node] = distances[current_node] + 1;
                bfs_queue.push(next_node);
            }
        }
    }
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int num_nodes, num_queries;
        cin >> num_nodes >> num_queries;
        adjacency_array.resize(num_nodes + 1);
        distances.resize(num_nodes + 1);
        for (int i = 1; i <= num_nodes; i++) {
            cin >> adjacency_array[i];
        }

        while (num_queries--) {
            int start_node, end_node;
            cin >> start_node >> end_node;
            bfs(start_node);
            cout << (distances[end_node] == -1 ? -1 : distances[end_node]) << endl;
        }
    }

    return 0;
}
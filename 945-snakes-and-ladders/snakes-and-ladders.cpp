class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        // Step 1: Create a clean board representation with snake pattern flattened
        vector<vector<int>> cboard;
        for (int j = 0; j < n; j++) {
            vector<int> row = board[n - 1 - j];  // Rows from bottom to top
            if (j % 2 == 1) reverse(row.begin(), row.end());  // Zigzag pattern
            cboard.push_back(row);
        }

        // Step 2: Initialize distance tracker
        vector<int> min_rolls(n * n + 1, -1);  // Tracks minimum rolls to each cell
        queue<int> q;  // BFS queue

        // Start at square 1
        min_rolls[1] = 0;
        q.push(1);

        // Step 3: Perform BFS
        while (!q.empty()) {
            int x = q.front(); q.pop();  // Current square number

            // Try all dice rolls from 1 to 6
            for (int i = 1; i <= 6 && x + i <= n * n; i++) {
                int t = x + i;  // Tentative square number

                // Convert to 2D position in cboard
                int r = (t - 1) / n;
                int c = (t - 1) % n;

                // Check if there is a ladder or snake
                int v = cboard[r][c];
                int y = (v == -1) ? t : v;  // Go to v if present, else stay at t

                // If we reach the end, return the move count
                if (y == n * n) return min_rolls[x] + 1;

                // If this square has never been visited
                if (min_rolls[y] == -1) {
                    min_rolls[y] = min_rolls[x] + 1;
                    q.push(y);  // Explore this square next
                }
            }
        }

        // If unreachable
        return -1;
    }
};

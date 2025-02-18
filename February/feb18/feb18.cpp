vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Sort the points based on their Euclidean distance from the origin (0,0)
    sort(points.begin(), points.end(), [&](const vector<int>& A, const vector<int>& B) {
        // Compute squared distances to avoid unnecessary square root calculations
        int distA = A[0] * A[0] + A[1] * A[1];
        int distB = B[0] * B[0] + B[1] * B[1];
        return distA < distB; // Sort in ascending order of distance
    });

    // Return the first 'k' closest points
    return vector<vector<int>>(points.begin(), points.begin() + k);
}

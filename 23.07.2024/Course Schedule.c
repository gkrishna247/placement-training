bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* inDegree = calloc(numCourses, sizeof(int));
    int** graph = malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        graph[i] = malloc(numCourses * sizeof(int));
        memset(graph[i], 0, numCourses * sizeof(int));
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        int dest = prerequisites[i][0];
        int src = prerequisites[i][1];
        graph[src][dest] = 1;
        inDegree[dest]++;
    }
    int queue[10000], front = 0, rear = 0;
    for (int i = 0; i < numCourses; i++)
        if (inDegree[i] == 0)
            queue[rear++] = i;
    int count = 0;
    while (front != rear) {
        int course = queue[front++];
        count++;
        for (int i = 0; i < numCourses; i++) {
            if (graph[course][i] == 1 && --inDegree[i] == 0)
                queue[rear++] = i;
        }
    }
    return count == numCourses;
}

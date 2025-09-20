class Solution:
    # JUST STOLE SOLUTION FROM https://www.youtube.com/watch?v=EgI5nU9etnU. I NEED TO COME BACK TO THIS TASK LATER!!!!
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        preMap = {i: [] for i in range(numCourses)}
        for course, prer in prerequisites:
            preMap[course].append(prer)

        visitedSet = set()
        def dfs(crs):
            if crs in visitedSet:
                return False

            if preMap[crs] == []:
                return True

            visitedSet.add(crs)

            for course in preMap[crs]:
                if dfs(course) is False:    return False

            visitedSet.remove(crs)
            preMap[crs] = []
            return True

        for i in range(numCourses):
            if not dfs(i):
                return False
        return True

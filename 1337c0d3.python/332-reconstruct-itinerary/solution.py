from __future__ import print_function

class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        import bisect
        def dfs_visit(G, u, visited, vpath):
            if u not in G:
                return
            for v in G[u]:
                if (u, v) not in visited:
                    visited[(u, v)] = True
                    vpath.append((v))
                    dfs_visit(G, v, visited, vpath)
        graph, visit, vpath = dict(), dict(), list()
        for t in tickets:
            if t[0] not in graph: graph[t[0]] = []
            bisect.insort(graph[t[0]], t[1])
        dfs_visit(graph, 'JFK', visit, vpath)
        vpath.insert(0, 'JFK')
        return vpath

if __name__ == "__main__":
    # tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    # tickets = [["JFK", "ATL"], ["JFK", "SFO"], ["SFO", "MUC"], ["MUC", "JFK"]]
    s = Solution()
    print(s.findItinerary(tickets))

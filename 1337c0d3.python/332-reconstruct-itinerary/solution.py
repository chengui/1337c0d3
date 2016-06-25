from __future__ import print_function

class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        def dfs_visit(G, u, visited, vpath):
            if u not in G:
                G[u] = ['JFK']
            visited[u] = True
            vpath.append(u)
            for v in G[u]:
                if v not in visited:
                    dfs_visit(G, v, visited, vpath)
        vpath = list()
        visited = dict()
        graph = reduce(lambda d, l: d.update({l[0]: d.get(l[0], []) + [l[1]]}) or d, tickets, {})
        dfs_visit(graph, 'JFK', visited, vpath)
        return vpath

if __name__ == "__main__":
    # tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    s = Solution()
    print(s.findItinerary(tickets))

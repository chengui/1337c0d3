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
                print(">>> ", visited, vpath)
                return
            visited[u] = True
            vpath.append(u)
            for v in G[u]:
                if v not in visited:
                    dfs_visit(G, v, visited, vpath)
            return vpath
        tomap, graph = dict(), dict()
        for n, t in enumerate(tickets):
            if t[0] not in tomap: tomap[t[0]] = []
            bisect.insort(tomap[t[0]], (t[1], n))
        for n, t in enumerate(tickets):
            if t[1] not in tomap:
                graph[n] = []
            else:
                graph[n] = map(lambda x: x[1], tomap[t[1]])
        for to, i in tomap['JFK']:
            visit, vpath = dict(), list()
            dfs_visit(graph, i, visit, vpath)
            if len(vpath) == len(tickets):
               return ['JFK'] + map(lambda x: tickets[x][1], vpath)
        return ['JFK'] + map(lambda x: tickets[x][1], vpath)

if __name__ == "__main__":
    # tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    # tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    # tickets = [["JFK", "ATL"], ["JFK", "SFO"], ["SFO", "MUC"], ["MUC", "JFK"]]
    tickets = [["EZE","TIA"],["EZE","HBA"],["AXA","TIA"],["JFK","AXA"],["ANU","JFK"],["ADL","ANU"],["TIA","AUA"],["ANU","AUA"],["ADL","EZE"],["ADL","EZE"],["EZE","ADL"],["AXA","EZE"],["AUA","AXA"],["JFK","AXA"],["AXA","AUA"],["AUA","ADL"],["ANU","EZE"],["TIA","ADL"],["EZE","ANU"],["AUA","ANU"]]
    s = Solution()
    print(s.findItinerary(tickets))

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    long euclid(pair<int, int>& p1, pair<int, int>& p2)
    {
        return (p1.first-p2.first) * (p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
    }

    int numberOfBoomerangs(vector<pair<int, int> >& points) {
        int size = points.size();
        if (size <= 1)
            return 0;

        int boomerangs = 0;
        long distances[500][500];

        for (int i = 0; i < size; i++)
        {
            distances[i][i] = 0;
            for (int j = i+1; j < size; j++)
            {
                long distance = euclid(points[i], points[j]);
                distances[i][j] = distance;
                distances[j][i] = distance;
            }

            map<int, int> counts;
            for (int j = 0; j < size; j++)
            {
                if (counts.count(distances[i][j]))
                    counts[distances[i][j]]++;
                else if (distances[i][j] != 0)
                    counts[distances[i][j]] = 1;
            }

            for (map<int, int>::iterator it = counts.begin(); it != counts.end(); it++)
            {
                if (it->second > 1)
                    boomerangs += it->second * (it->second - 1);
            }
        }
        return boomerangs;
    }
};

int main()
{
    vector<pair<int, int> > points;
    points.push_back(make_pair<int, int>(0, 0));
    points.push_back(make_pair<int, int>(1, 0));
    points.push_back(make_pair<int, int>(2, 0));
    Solution s = Solution();
    cout << s.numberOfBoomerangs(points) << endl;
}

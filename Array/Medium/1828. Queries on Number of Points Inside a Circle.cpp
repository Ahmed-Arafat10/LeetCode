class Solution
{
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
    {
        vector<int> res(queries.size());
        for(int i =0; i<points.size(); i++)
        {
            for(int j = 0; j<queries.size(); j++)
            {
                int x1 = points[i][0], y1 = points[i][1], cx = queries[j][0], cy = queries[j][1],raduis = queries[j][2];
                int eq = pow(x1 - cx,2) + pow(y1 - cy,2);
                if(eq <= pow(raduis,2)) res[j]++;
            }
        }
        return res;
    }
};
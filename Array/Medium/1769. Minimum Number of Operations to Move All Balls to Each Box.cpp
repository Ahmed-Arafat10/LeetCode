//O(n^2)
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int>res(boxes.size());
        int cnt = 0, tot = 0;
        for(int i =0; i<boxes.size(); i++)
        {
            tot += cnt;
            res[i] = tot;
            if(boxes[i] == '1') cnt++;
        }
        cnt = 0, tot = 0;
        for(int i = boxes.size()-1; i>=0; i--)
        {
            tot += cnt;
            res[i] += tot;
            if(boxes[i] == '1') cnt++;
        }
        return res;
    }
};

//O(n)
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int>res(boxes.size()),v1;
        for(int i =0; i<boxes.size(); i++)
        {
            if(boxes[i] == '1') v1.push_back(i);
        }
        for(int i =0; i<boxes.size(); i++)
        {
            for(int j =0; j<v1.size(); j++)
            {
                res[i]+= abs(i - v1[j]);
            }
        }
        return res;
    }
};

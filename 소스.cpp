#include <string>
#include <vector>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries)
{
    long long answer = 0;

    long TargetPosition[2] = { x,y };
    for (long k = 0; k < queries.size(); k++)
    {
        switch (queries[queries.size() - 1 - k][0])
        {
        case 1:
            TargetPosition[1] -= queries[queries.size() - 1 - k][1];
            if (TargetPosition[1] < 0)
            {
                TargetPosition[1] = 0;
            }
            break;
        case 0:
            TargetPosition[1] += queries[queries.size() - 1 - k][1];
            if (TargetPosition[1] >= m)
            {
                TargetPosition[1] = m - 1;
            }
            break;
        case 3:
            TargetPosition[0] -= queries[queries.size() - 1 - k][1];
            if (TargetPosition[0] < 0)
            {
                TargetPosition[0] = 0;
            }
            break;
        case 2:
            TargetPosition[0] += queries[queries.size() - 1 - k][1];
            if (TargetPosition[0] >= n)
            {
                TargetPosition[0] = n - 1;
            }
            break;
        }
    }

    long RowNum = 0;
    for (long i = TargetPosition[0] + 1; i < n; i++)
    {
        long Position[2] = { i,TargetPosition[1] };
        for (long k = 0; k < queries.size(); k++)
        {
            switch (queries[k][0])
            {
            case 0:
                Position[1] -= queries[k][1];
                if (Position[1] < 0)
                {
                    Position[1] = 0;
                }
                break;
            case 1:
                Position[1] += queries[k][1];
                if (Position[1] >= m)
                {
                    Position[1] = m - 1;
                }
                break;
            case 2:
                Position[0] -= queries[k][1];
                if (Position[0] < 0)
                {
                    Position[0] = 0;
                }
                break;
            case 3:
                Position[0] += queries[k][1];
                if (Position[0] >= n)
                {
                    Position[0] = n - 1;
                }
                break;
            }
        }
        if (Position[0] != x || Position[1] != y)
        {
            if (i == TargetPosition[0] + 1)
            {
                break;
            }
            else
            {
                i = (i + TargetPosition[0]) / 2;
            }
        }
        else if (Position[0] == x && Position[1] == y)
        {
            RowNum = i;
            i = (i + n) / 2;
        }
    }
    for (long i = TargetPosition[0] - 1; i >= 0; i--)
    {
        long Position[2] = { i,TargetPosition[1] };
        for (long k = 0; k < queries.size(); k++)
        {
            switch (queries[k][0])
            {
            case 0:
                Position[1] -= queries[k][1];
                if (Position[1] < 0)
                {
                    Position[1] = 0;
                }
                break;
            case 1:
                Position[1] += queries[k][1];
                if (Position[1] >= m)
                {
                    Position[1] = m - 1;
                }
                break;
            case 2:
                Position[0] -= queries[k][1];
                if (Position[0] < 0)
                {
                    Position[0] = 0;
                }
                break;
            case 3:
                Position[0] += queries[k][1];
                if (Position[0] >= n)
                {
                    Position[0] = n - 1;
                }
                break;
            }
        }
        if (Position[0] != x || Position[1] != y)
        {
            break;
        }
        else if (Position[0] == x && Position[1] == y)
        {
            RowNum++;
        }
    }

    long ColNum = 0;
    for (long i = TargetPosition[1]; i < m; i++)
    {
        long Position[2] = { TargetPosition[0],i };
        for (long k = 0; k < queries.size(); k++)
        {
            switch (queries[k][0])
            {
            case 0:
                Position[1] -= queries[k][1];
                if (Position[1] < 0)
                {
                    Position[1] = 0;
                }
                break;
            case 1:
                Position[1] += queries[k][1];
                if (Position[1] >= m)
                {
                    Position[1] = m - 1;
                }
                break;
            case 2:
                Position[0] -= queries[k][1];
                if (Position[0] < 0)
                {
                    Position[0] = 0;
                }
                break;
            case 3:
                Position[0] += queries[k][1];
                if (Position[0] >= n)
                {
                    Position[0] = n - 1;
                }
                break;
            }
        }
        if (Position[0] != x || Position[1] != y)
        {
            break;
        }
        else if (Position[0] == x && Position[1] == y)
        {
            ColNum++;
        }
    }
    for (long i = TargetPosition[1]-1; i >= 0; i--)
    {
        long Position[2] = { TargetPosition[0],i };
        for (long k = 0; k < queries.size(); k++)
        {
            switch (queries[k][0])
            {
            case 0:
                Position[1] -= queries[k][1];
                if (Position[1] < 0)
                {
                    Position[1] = 0;
                }
                break;
            case 1:
                Position[1] += queries[k][1];
                if (Position[1] >= m)
                {
                    Position[1] = m - 1;
                }
                break;
            case 2:
                Position[0] -= queries[k][1];
                if (Position[0] < 0)
                {
                    Position[0] = 0;
                }
                break;
            case 3:
                Position[0] += queries[k][1];
                if (Position[0] >= n)
                {
                    Position[0] = n - 1;
                }
                break;
            }
        }
        if (Position[0] != x || Position[1] != y)
        {
            break;
        }
        else if (Position[0] == x && Position[1] == y)
        {
            ColNum++;
        }
    }

    answer = RowNum * ColNum;
    return answer;
}
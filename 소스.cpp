#include <string>
#include <vector>

using namespace std;

// 아이디어만 알면 매우 간단한 문제였다.
// 문제자체는 단순하지만 연산량을 줄이는 방법에 초점을 둔 문제이다.
// 처음에는 O(n) X O(n) 연산을 모두 다 하게 하였고 예상대로
// 작은 스케일은 맞게 나오지만 큰 스케일은 시간 초과가 떴다.
// 연산을 줄이기 위한 방법으로 나온 아이디어는 매우 단순하다.
// 우선 목표위치로 부터 역추적을 한다. 여기서 이론을 몇개 알아야한다.
// 
// <문제 조건에 맞는 위치들을 모아보면 무조건 직사각형 형태를 띈다>.
// ㄴ당연한 논리인게 어느 한부분만 튄다면 그 튀는 부분에 대해
// ㄴ이동이 한번 더 이루어져야 하는데 나머지 부분은 왜 이동을 안하는가?
// ㄴ논리적 모순이다.
// 
// <역추적 위치는 반드시 직사각형 영역의 꼭짓점에 위치한다.>
// 이 논리는 감각적인 부분이라 이해가 어려울 수도 있다.
// ㄴ만약 왼쪽 벽에 100번 부딪히고 목표 위치에 도달하는 케이스를 생각해보자.
// ㄴ역추적을 하게되면 왼쪽 벽으로 가는게 아닌 오른쪽으로 이동을 하게 된다.
// ㄴ오른쪽으로 100번을 이동하게 역추적이 되는데 만약 목표위치랑 
// ㄴ오른쪽으로 101칸 떨어져있는 위치는 목표위치에 도달할 수 있는가?
// ㄴ당연히 안된다. 세로 방향도 마찬가지이기 때문에 역추적 위치는 항상 
// ㄴ직사각형 영역의 꼭짓점에 해당된다.
// 
// <역추적 위치가 반드시 목표위치로 갈 수 있는건 아니다.>
// ㄴ간단한 예로 목표위치가 오른쪽에서 한칸 떨어져 있고
// ㄴ>>><<><><<라는 쿼리가 주어지면 역추적은 할 수 있지만 그 역추적 위치로 부터
// ㄴ목표위치로 갈 수 없다.
// 
// <역추적 위치에서 다시 추적하여 목표위치로 갔을 때 벽 바로 앞까지 가지 않으면>
// 답은 1개다.
// ㄴ이 문제의 가장 큰 변수는 벽의 부딪힘인데 벽에 부딪히지 않고 목표 위치에 
// ㄴ왔다면 그 위치가 유일한 위치가 돼야한다. 왜냐하면 쿼리는 바뀌지 않고
// ㄴ정해져있기 때문에, 즉 경로가 유일하기 때문에 답이 1개다.
// ㄴ>>>>>>>>>>> 해서 목표위치에 도달했다. 벽 부딪힘 없이 다른 위치가 존재 하는가?
// ㄴ아니다.
// 
// <역추적 위치가 목표위치로 갈 수 없다면 갈 수 있는 위치는 존재하지 않는다.>
// ㄴ위 논리가 다 맞다면 특수한 경우에서 역추적 위치는 유일한 해이고
// ㄴ그 유일한 해 조차 답이 될 수 없다면 당연히 그 외에는 답이 존재하지 않는다.
// 
// <역추적 위치에서 추적 중 벽에 부딪히면 역추적 위치부터 벽까지 모든 위치가 해다>
// ㄴ해의 모임은 직사각형이라고 하였고 역추적 위치가 꼭짓점이라면 나머지 꼭짓점이
// ㄴ어디인가가 문제를 풀 마지막 키워드이다. 여기서 위의 논리들을 잘 생각해보면
// ㄴ벽에 부딪혀야 해가 여러개 생기는데 역추적 위치부터 벽까지의 모든 위치가
// ㄴ벽에 부딪히는 경우를 발생한다. 예로 역추적 위치에서 오른쪽으로 10번가면 딱 벽앞이다.
// ㄴ그러면 역추적 위치에서 왼쪽으로는 오른쪽 벽에 닿을 수 없다. 그리고 역추적
// ㄴ위치에서 오른쪽 위치들은 모두 오른쪽 벽에 닿을수 있으므로 그 모든 위치가 해가
// ㄴ된다. 똑같은 논리로 세로 방향도 가능하니 직사각형의 가로 세로 길이를 알 수 있고
// ㄴ총 위치의 갯수를 알 수 있게 된다.
//


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

    int RowMin = 0;
    int RowMax = 0;
    int ColMin = 0;
    int ColMax = 0;
    long Position[2] = { TargetPosition[0],TargetPosition[1] };
    for (long k = 0; k < queries.size(); k++)
    {
        switch (queries[k][0])
        {
        case 0:
            Position[1] -= queries[k][1];
            if (Position[1] <= 0)
            {
                Position[1] = 0;
                ColMin = 1;
            }
            break;
        case 1:
            Position[1] += queries[k][1];
            if (Position[1] >= m - 1)
            {
                Position[1] = m - 1;
                ColMax = 1;
            }
            break;
        case 2:
            Position[0] -= queries[k][1];
            if (Position[0] <= 0)
            {
                Position[0] = 0;
                RowMin = 1;
            }
            break;
        case 3:
            Position[0] += queries[k][1];
            if (Position[0] >= n - 1)
            {
                Position[0] = n - 1;
                RowMax = 1;
            }
            break;
        }
    }
    if (Position[0] != x || Position[1] != y)
    {
        return answer;
    }

    long RMax = TargetPosition[0]+1;
    long RMin = TargetPosition[0];
    long CMax = TargetPosition[1]+1;
    long CMin = TargetPosition[1];
    if (RowMax)
    {
        RMax = n;
    }
    if (RowMin)
    {
        RMin = 0;
    }
    if (ColMax)
    {
        CMax = m;
    }
    if (ColMin)
    {
        CMin = 0;
    }

    answer = (RMax - RMin) * (CMax - CMin);

    return answer;
}
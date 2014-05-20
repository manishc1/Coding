/*
Given a m*n grid starting from (1, 1). At any point (x, y), you has two choices for the next move: 1) move to (x+y, y); 2) move to (x, y+x); From point (1, 1), how to move to (m, n) in least moves? (or there's no such a path)
*/

int minpath(int m, int n)
{
    int count = 0;
    while (true)
    {
        if (m == 1 && n == 1)
            break;

        if (m > n)
        {
            m -= n;
            count++;
        }
        else if (m < n)
        {
            n -= m;
            count++;
        }
        else
        {
            count = -1;
            break;
        }
    }

    return count;
}
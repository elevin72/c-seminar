
int func(int a)
{
    return a-2;
}

int main()
{
    int a;
    if (2 == func(4))
        a = 1;
    else
        a = 0;
    return 0;
}

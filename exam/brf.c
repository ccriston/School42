#include <unistd.h>
#include <stdio.h>

int		brackets(char *av, int i)
{
	int a;

	if (av[i] == ']')
	{
		i--;
		while (!(av[i] == '[' && a == 0))
		{
			if (av[i] == '[')
				a++;
			else if (av[i] == ']')
				a--;
			i--;
		}
		i--;
	}
	else if (av[i] == '[')
	{
		i++;
		while (!(av[i] == ']' && a == 0))
		{
			if (av[i] == ']')
				a++;
			else if (av[i] == '[')
				a--;
			i++;
		}
		i--;
	}
	return (i);
}

void    brf(char *av)
{
    int i;
    char arr[2048];
    int k;
    int t;
    int l;

    i = -1;
    while (++i < 2048)
        arr[i] = '\0';
    i = 0;
    k = 0;
    t = 0;
    while (av[i])
    {
        if (av[i] == '>')
            k++;
        else if (av[i] == '<')
            k--;
        else if (av[i] == '+')
            arr[k]++;
        else if (av[i] == '-')
            arr[k]--;
        else if (av[i] == '.')
            write(1, &arr[k], 1);
        else if (av[i] == '[')
        {
          if (arr[k] == 0)
			  i = brackets(av, i);
		}
        else if (av[i] == ']')
        {
         	if (arr[k] != 0)
			 	i = brackets(av, i);	
		}
        i++;
    }
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        brf(av[1]);
    }
    return (0);
}

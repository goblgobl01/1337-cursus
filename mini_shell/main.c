#include "header.h"

void	treat_token(char *str, int start, int end, t_tokens *token_stream)
{
	// int		i;
	int		len;
	char	*substring;

	len = end - start;
	substring = ft_substr(str, start, len);

	(void)substring;
	(void)token_stream;
}

// int outside_set(char c)
// {
// 	char	*set = "|<>\n\t\v\f\r ";
// 	int		i;

// 	i = 0;
// 	while(set[i])
// 	{
// 		if (c == set[i])
// 			return(0);
// 		i++;
// 	}
// 	return (1);
// }

void scan_token(char *str, t_tokens *token_stream)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	while(str[i])
	{
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
		start = i;
		while (str[i] != '|' && str[i] != '>' && str[i] != '<' && str[i])
			i++;
		end = i;
		treat_token(str, start, end, token_stream);
	}
}

int main()
{
	char		*str = "ss>>>>s";
	char		**arguments;

	arguments = ft_split(str);
	while(*arguments)
	{
		printf("%s\n", *arguments);
		arguments++;
	}
	// t_tokens	*token_stream;

	// token_stream = NULL;
	// scan_token(str, token_stream);
	return (0);
}

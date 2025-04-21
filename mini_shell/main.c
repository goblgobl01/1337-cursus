#include "header.h"

int main()
{
	char *str;
	t_tokens *token_stream;

	token_stream = malloc(sizeof(t_tokens));
	if(!token_stream)
		return (0);
	while(1)
	{
		str = readline("$> ");
		token_stream->arguments = ft_split(str);
		// while(*token_stream->arguments)
		// {
		// 	printf("%s\n", *token_stream->arguments);
		// 	fflush(stdout);
		// 	token_stream->arguments++;
		// }
	}
	return (0);
}

#include "header.h"

void	parse_pipe(t_tokens	*token_stream)
{
	t_cmd	*a;


	a = parse_redirection(token_stream);
}

void	parse_redirection(t_tokens	*token_stream)
{
	t_cmd	*a;

	a = parse_command(token_stream);
	if (token_stream->next_token->type == REDIR)
	{
		scan_token(token_stream);

	}
}

t_cmd	*parse_command(t_tokens *token_stream)
{
	if(token_stream->token->type == EXEC)
		return (token_stream->token);
}

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

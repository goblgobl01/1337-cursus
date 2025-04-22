/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:28:04 by codespace         #+#    #+#             */
/*   Updated: 2025/04/21 21:28:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void scan_token(t_tokens *token_stream)
{
	char	**arg;

	arg = token_stream->arguments;
	if (*arg[token_stream->flag] == '|' || *arg[token_stream->flag] == '>' || *arg[token_stream->flag] == '<')
	{
		if(*arg[token_stream->flag] == '|')
			token_stream->token_type = PIPE;
		else
			token_stream->token_type = REDIR;
		token_stream->token = arg[token_stream->flag];
		token_stream->flag++;
	}
	else
	{
		token_stream->token_type = EXEC;
		token_stream->token = arg[token_stream->flag];
		token_stream->flag++;
	}
	if (*arg[token_stream->flag] == '|' || *arg[token_stream->flag] == '>' || *arg[token_stream->flag] == '<')
	{
		if(*arg[token_stream->flag] == '|')
			token_stream->next_token_type = PIPE;
		else
			token_stream->next_token_type = REDIR;
		token_stream->next_token = arg[token_stream->flag];
	}
	else
	{
		token_stream->next_token_type = EXEC;
		token_stream->next_token = arg[token_stream->flag];
	}
}
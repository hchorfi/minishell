/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:16:51 by hchorfi           #+#    #+#             */
/*   Updated: 2021/05/24 17:39:04 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, PATH_MAX);
	ft_putstr_fd(cwd, 1);
	write(1, "\n", 1);
	return (g_data.ret = 0);
}

void	free_3(char *tmp_free, char *tmp_in, char *file)
{
	free(tmp_free);
	free(tmp_in);
	free(file);
}

void	int_error(void)
{
	ft_putstr_fd("bash: : No such file or directory\n", 2);
	g_data.ret = 1;
}

void	out_error(char c, char **file)
{
	char	*tmp_free;

	if (c != '\'')
	{
		tmp_free = *file;
		*file = get_other_variables(*file);
		if (*(*file) == '\0')
		{
			ft_putstrs_er(
				"minishell: ", tmp_free, ": ambiguous redirect\n", NULL);
			g_data.ret = 1;
		}
		free(tmp_free);
	}
}

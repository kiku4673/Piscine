/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:51:26 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/14 10:55:37 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
			new_word = 0;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
			new_word = 0;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			new_word = 0;
		else if (str[i] >= '0' && str[i] <= '9')
			new_word = 0;
		else
			new_word = 1;
		i++;
	}
	return (str);
}

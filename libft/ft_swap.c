/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:40:10 by jumiguel          #+#    #+#             */
/*   Updated: 2014/12/10 17:05:20 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(void *a, void *b)
{
	void	*tmp;

	tmp = a;
	a = b;
	b = tmp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:30:39 by mstoneho          #+#    #+#             */
/*   Updated: 2020/11/24 18:30:41 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_FT_PRINTF_H
# define PROJECT_FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h> // удоли

int		ft_printf(const char *text, ...);
#endif
